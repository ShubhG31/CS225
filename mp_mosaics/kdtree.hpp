/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    if(first[curDim]<second[curDim]){
      return true;
    }
    else if(first[curDim]>second[curDim]){
      return false;
    }
    else if(first<second)return true;
    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     float potential_check=0;
     float currentBest_check=0;
     for(int i=0;i<Dim;i++){
      potential_check+=(potential[i]-target[i])*(potential[i]-target[i]);
      currentBest_check+=(currentBest[i]-target[i])*(currentBest[i]-target[i]);
     }
     if(potential_check<currentBest_check) return true;
     if(potential_check==currentBest_check){
       if(currentBest<potential)return false;
       return true;
     }
     return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */

    vector<Point<Dim>> points = newPoints;
    buildTree(points,0, 0, points.size()-1, root );

}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */

}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    findNearestNeighbor(query, 0, root);
    return Point<Dim>();
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query, int dim, KDTreeNode * curRoot) const{
  Point<Dim> nearest=curRoot->point;
  if(curRoot->right ==NULL && curRoot->left==NULL){
      return curRoot->point;
    }
  if(curRoot->left !=NULL && smallerDimVal(query,curRoot->left->point,dim)){
    nearest = findNearestNeighbor(query, (dim+1)%Dim,curRoot->left);
  }
  else if(curRoot->right!=NULL){
    nearest = findNearestNeighbor(query, (dim+1)%Dim,curRoot->right);
  }
  if(curRoot!=NULL && shouldReplace(query, nearest, curRoot->point)){
    nearest=curRoot->point;
  }
  double radius=0;
      for(int i= 0; i<dim;i++){
        radius+=(curRoot->point[i]-query[i])*(curRoot->point[i]-query[i]);
      }
  float splitDist = (curRoot -> point[dim] - query[dim])* (curRoot -> point[dim] - query[dim]);
  Point<Dim> tempNearest;
  if(radius>=splitDist){
      if(smallerDimVal(query,curRoot->left->point,dim)){
          tempNearest=findNearestNeighbor(query, (dim+1)%Dim,curRoot->right);
      }
      else{
          tempNearest=findNearestNeighbor(query, (dim+1)%Dim,curRoot->left);
      }
      if(shouldReplace(query, nearest, tempNearest)){
        nearest=tempNearest;
      }
  }
  return nearest;
}
template <int Dim>
void KDTree<Dim>::buildTree(vector<Point<Dim>>&points, int dim, int left, int right, KDTreeNode * &curRoot){

  if(points.empty()||left>right){
    return;
  }

   int middle= (left+right)/2;
    Point<Dim> temp = (select(points, left, right, middle,dim));
    curRoot=new KDTree<Dim>::KDTreeNode(temp);
    buildTree(points, (dim+1)%Dim, left, middle-1, curRoot->left);
    buildTree(points, (dim+1)%Dim, middle+1, right, curRoot->right);
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>&list, int left, int right, int pivotIndex, int dim){
  Point<Dim> pivotValue= list[pivotIndex];
  swap(list[pivotIndex],list[right]);
  int storeIndex = left;
  for(int i=left; i<=right-1;i++){
    if(smallerDimVal(list[i],pivotValue,dim)){
      swap(list[storeIndex],list[i]);
      storeIndex++;
    }
  }

  swap(list[right],list[storeIndex]);
  return storeIndex;
 }


template <int Dim>
Point<Dim> KDTree<Dim>::select(vector<Point<Dim>>&list, int left, int right, int k, int dim){
    if(left==right){
      return list[left];
    }
    int pivotIndex = (left + right)/2;
    pivotIndex = partition(list, left, right, pivotIndex, dim);
    if(k==pivotIndex){
      return list[k];
    }
    else if(pivotIndex>k){
      return select(list, left, pivotIndex-1, k, dim);
    }
    else{
       return select(list, pivotIndex+1, right, k, dim);
    }
}