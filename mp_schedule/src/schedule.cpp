/**
 * @file schedule.cpp
 * Exam scheduling using graph coloring
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>

#include "schedule.h"
#include "utils.h"
#include <algorithm>

#include <string>
#include <sstream>
using namespace std;
/**
 * Takes a filename and reads in all the text from the file
 * Newline characters are also just characters in ASCII
 * 
 * @param filename The name of the file that will fill the string
 */
std::string file_to_string(const std::string& filename){
  std::ifstream text(filename);

  std::stringstream strStream;
  if (text.is_open()) {
    strStream << text.rdbuf();
  }
  return strStream.str();
}

/**
 * Given a filename to a CSV-formatted text file, create a 2D vector of strings where each row
 * in the text file is a row in the V2D and each comma-separated value is stripped of whitespace
 * and stored as its own string. 
 * 
 * Your V2D should match the exact structure of the input file -- so the first row, first column
 * in the original file should be the first row, first column of the V2D.
 *  
 * @param filename The filename of a CSV-formatted text file. 
 */
V2D file_to_V2D(const std::string & filename){
    // Your code here!
    // std::ifstream fin(filename,std::ifstream::in);
    // std::string file_string = file_to_string(filename);
    // V2D CSV_vector;
    // Trim(file_string);
    // while(file_string){
    //   SplitString(file_string,',',CSV_vector);
    //   std::cout<<line<<std::endl;
    // }
    //  V2D sc;
    // return sc;
    std::string file_string = file_to_string(filename);
    V2D parsed;
    file_string = Trim(file_string);
    std::vector<std::string> lines;
    std::vector<std::string> word;

    //size contains the number of lines in the CSV file
    // lines is a vector contains each line from the CSV file 
    int size= SplitString(file_string, '\n',lines);
    //for loop to traverse the number of lines 
    for(int i=0; i<size;i++){
      //words contains the number of words are in the line 
      //word is a vector that contains all the words from line
      int words = SplitString(lines[i],',',word);
      std::vector<std::string> parsed2;
        for(int j= 0; j<words; j++){
          word[j] = Trim(word[j]);
          // std::cout<<word[j]<<std::endl;
          parsed2.push_back(word[j]);
        }
        parsed.push_back(parsed2);
        word.clear();

    }
    return parsed;
}

/**
 * Given a course roster and a list of students and their courses, 
 * perform data correction and return a course roster of valid students (and only non-empty courses).
 * 
 * A 'valid student' is a student who is both in the course roster and the student's own listing contains the course
 * A course which has no students (or all students have been removed for not being valid) should be removed
 * 
 * @param cv A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param student A 2D vector of strings where each row is a student ID followed by the courses they are taking
 */
V2D clean(V2D & cv, V2D & student){
    // YOUR CODE HERE
  V2D clean_schedule; 

  for(unsigned long i=0; i < cv.size();i++){
    std::vector<std::string> temp;
    temp.push_back(cv[i][0]);
    for(unsigned long l=1 ; l< cv[i].size();l++){
      for(unsigned long j=0; j<student.size();j++){
        if(cv[i][l]==student[j][0]){
          for(unsigned long m=1; m<student[j].size();m++){
            if(cv[i][0]==student[j][m]){
              temp.push_back(student[j][0]);
            }
          }
        }
        // auto lookup = std::find(temp.begin(), temp.end(),student[j][0]);
        // auto student_lookup = std::find(student[j].begin(), student[j].end(),cv[i][0]);
        // for(unsigned long k=0; k<){
        //   auto student_check = std::find(student[j][0].begin(), student[j].end(),)
        // }
        // if(lookup!=temp.end() && student_lookup==student[j].end()){
        //   // if(std::find(temp.begin(),temp.end(),cv[i][0])==temp.end()) {
        //   //   temp.push_back(cv[i][0]);
        //   //   std::cout<<cv[i][0]<<" ";
        //   //   }
        //   temp.erase(lookup);
        }
    }
    if(temp.size()>1) clean_schedule.push_back(temp);
    temp.clear();
    }
  return clean_schedule;
}



/**
 * Given a collection of courses and a list of available times, create a valid scheduling (if possible).
 * 
 * A 'valid schedule' should assign each course to a timeslot in such a way that there are no conflicts for exams
 * In other words, two courses who share a student should not share an exam time.
 * Your solution should try to minimize the total number of timeslots but should not exceed the timeslots given.
 * 
 * The output V2D should have one row for each timeslot, even if that timeslot is not used.
 * 
 * As the problem is NP-complete, your first scheduling might not result in a valid match. Your solution should 
 * continue to attempt different schedulings until 1) a valid scheduling is found or 2) you have exhausted all possible
 * starting positions. If no match is possible, return a V2D with one row with the string '-1' as the only value. 
 * 
 * @param courses A 2D vector of strings where each row is a course ID followed by the students in the course
 * @param timeslots A vector of strings giving the total number of unique timeslots
 */
V2D schedule(V2D courses, std::vector<std::string> timeslots){
    // Your code here!
    V2D schedule;
    // std::map<std::string, std::string> colored;
    for(unsigned int i=0; i<timeslots.size();i++){
      schedule.push_back(std::vector<std::string>());
      schedule[i].push_back(timeslots[i]);
    }
    sMap adjacency_map;
    V2B adjacency_matrix = adjacency(courses);
    
    //std::set<long, > uncolored;
    for(unsigned long i = 0; i<adjacency_matrix.size();i++){
      adjacency_map[courses[i][0]]=vector<string>();
      for(unsigned long j =0; j<adjacency_matrix.size();j++){ 
        if(adjacency_matrix[i][j]){
          adjacency_map[courses[i][0]].push_back(courses[j][0]);
        }
      }
      // uncolored[courses[i][0]] = -1* ((long) adjacency_map[courses[i][0]].size());
    }
    // string maxAdjIn = (*uncolored.begin()->first);
    // colored[maxAdjIn]=0;
    for (unsigned long start = 0; start < courses.size();++start){
      map<string,int> colored;
      for(unsigned long i = 0; i<courses.size();i++){
        colored[courses[i][0]]=-1;
      }
      colored[courses[start][0]] = 0;
    
      for(unsigned long i = 0; i<courses.size();i++){
        if(i!= start){
          vector<int> present_colors;
          vector<string> neighbors = adjacency_map[courses[i][0]];
          for (string n : neighbors){
            if(colored[n]!=-1){
              present_colors.push_back(colored[n]);
            }
          }

      // for(unsigned long j =0; j<neighbors.size();j++){
      //   if(std::find(present_colors.begin(),present_colors.end(),colored[neighbors[j]])==present_colors.end() && colored[neighbors[j]]!= -1){
      //     present_colors.push_back(colored[neighbors[j]]);
      //   }
      //   cout<<colored[neighbors[j]]<<endl;
      // }
          cout<<""<<endl;

          for(unsigned long l =0; l<timeslots.size();l++){
            //l<present_colors.size() && 
            if(std::find(present_colors.begin(),present_colors.end(),l)==present_colors.end()){
              colored[courses[i][0]]=(int)l;
              cout<<colored[courses[i][0]];
              break;
            }
          }
        }
      }
      bool found  = true;
      for(pair<string,int> nodes : colored){
        if(nodes.second == -1){
          found = false;
          break;
        }
      }
      if(found){
        for(pair<string,int> n : colored){
          schedule[n.second].push_back(n.first);
        }
        return schedule;
      }
    }
    return V2D{{"-1"}};
}

V2B adjacency(V2D courses){
  int node = courses.size();
  V2B matrix;
  matrix.resize(node, std::vector<bool>(node));

  for(int i =0; i< node;i++){
    for(int j=0; j<node;j++){
      matrix[i][j]=false;
    }
  }
  for(int l=0; l<node;l++){
    for(int k=l+1; k<node;k++){
      std::vector<std::string> temp;
      std::sort(courses[l].begin(),courses[l].end());
      std::sort(courses[k].begin(),courses[k].end());
      std::set_intersection(courses[l].begin(),courses[l].end(),courses[k].begin(),courses[k].end(),std::back_inserter(temp));
      temp.size()>0 ? matrix[l][k]=true:matrix[l][k]=false;
      temp.size()>0 ? matrix[k][l]=true:matrix[k][l]=false;
    }
  }
  for(unsigned long i=0;i<matrix.size();i++){
    for(unsigned long j=0; j<matrix[i].size();j++){
      cout<<matrix[i][j];
    }
    cout<<""<<endl;
  }
  return matrix;
}
