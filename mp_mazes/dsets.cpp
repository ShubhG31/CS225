/* Your code here! */
#include "dsets.h"
using namespace std;

void DisjointSets::addelements(int num){
    for(int i = 0; i < num; i++){
        elements.push_back(-1);
    }
    return;
}

int DisjointSets::find(int elem){
    if(elements[elem]<0){
        return elem;
    }
    else{
        return find(elements[elem]);
    }
}

void DisjointSets::setunion(int a, int b){
    int root_A = find(a);
    int root_B = find(b);
    if(root_A == root_B){
        return;
    }
    if(root_A > root_B){
        elements[root_B] = elements[root_A] + elements[root_B];
        elements[root_A] = root_B;
    }
    else{
        elements[root_A] = elements[root_A] + elements[root_B];
        elements[root_B] = root_A;
    }

}

int DisjointSets::size(int elem){
    int elements_size = (-1)*elements[find(elem)];
    return elements_size;
}