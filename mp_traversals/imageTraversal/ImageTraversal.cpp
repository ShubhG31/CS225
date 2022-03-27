#include <cmath>
#include <iterator>
#include <iostream>
#include <map>


#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  flag=true;
  traversalType=NULL;
}
ImageTraversal::Iterator::Iterator(ImageTraversal* traversalType_, Point startPoint_, PNG image_, double Tolerance_){
  traversalType=traversalType_;
  startPoint=startPoint_; 
  current=startPoint;
  image=image_;
  Tolerance=Tolerance_;
  visited.resize(image_.width(),std::vector<bool>(image_.height()));

  for(unsigned x=0 ; x<image.width();x++){
    for(unsigned y=0; y<image.height();y++){
      visited[x][y]=false;
    }
  }


}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
  //check queue or stack if point has been visited or not
  flag=true;
  Point point;
  visited[current.x][current.y]=true;

  traversalType->add(current);

  if(inBounds(Point(current.x+1, current.y)) &&  Tolerance>calculateDelta(image.getPixel(startPoint.x, startPoint.y),image.getPixel(current.x+1,current.y))){
    traversalType->add(Point(current.x+1, current.y));
  }
  if(inBounds(Point(current.x, current.y+1))&&  Tolerance>calculateDelta(image.getPixel(startPoint.x, startPoint.y),image.getPixel(current.x,current.y+1))){
    traversalType->add(Point(current.x, current.y+1));
  }
  if(inBounds(Point(current.x-1, current.y)) && Tolerance>calculateDelta(image.getPixel(startPoint.x, startPoint.y),image.getPixel(current.x-1,current.y))){
    traversalType->add(Point(current.x-1, current.y));
  }
  if(inBounds(Point(current.x, current.y-1)) && Tolerance>calculateDelta(image.getPixel(startPoint.x, startPoint.y),image.getPixel(current.x,current.y-1))){
    traversalType->add(Point(current.x, current.y-1));
  }
  point=traversalType->pop();
  while(!traversalType->empty() && visited[point.x][point.y]){
      point=traversalType->pop();
  }
  
if(!traversalType->empty()){
  flag=false;
  current=point;
} 
return *this;

}
bool ImageTraversal::Iterator::inBounds(Point point){
  if(point.x>=image.width()|| point.y>=image.height()|| point.x<0 || point.y<0) return false;
  return true;
}
// bool ImageTraversal::Iterator::checkTolerance(Point point){

// }

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
	return !(flag && other.flag);
}

