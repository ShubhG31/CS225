/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim> &first,
                                const Point<Dim> &second, int curDim) const
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
    if(first<second)return true;
    return false;

}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim> &target,
                                const Point<Dim> &currentBest,
                                const Point<Dim> &potential) const
{
  /**
   * @todo Implement this function!
   */
  double potential_check = 0;
  double currentBest_check = 0;
  for (int i = 0; i < Dim; i++)
  {
    potential_check += (potential[i] - target[i]) * (potential[i] - target[i]);
    currentBest_check += (currentBest[i] - target[i]) * (currentBest[i] - target[i]);
  }
  if (potential_check<currentBest_check) {
    return true;
  } else if(potential_check>currentBest_check) {
    return false;
  } else if (potential<currentBest) {
    return true;
  }
  return false;

}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>> &newPoints)
{
  /**
   * @todo Implement this function!
   */
  if(newPoints.empty())root=NULL;
  vector<Point<Dim>> points = newPoints;
  buildTree(points, 0, 0, points.size() - 1, root);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim> &other)
{
  /**
   * @todo Implement this function!
   */
  delete(root);
  copyTree(root,other);

}

template <int Dim>
const KDTree<Dim> &KDTree<Dim>::operator=(const KDTree<Dim> &rhs)
{
  /**
   * @todo Implement this function!
   */
  if(&rhs==this)return;
  deleteTree(root);
  copyTree(root,rhs);
  return *this;
}

template <int Dim>
void KDTree<Dim>::copyTree(KDTreeNode*& root, KDTreeNode*& copyRoot){
    if(root==NULL){
      return;
    }
    copyTree(root, copyRoot->left);~
    copyTree(root, copyRoot->right);
    copyRoot= new KDTreeNode(root->point);
}

template <int Dim>
KDTree<Dim>::~KDTree()
{
  /**
   * @todo Implement this function!
   */
  if(root!=NULL) deleteTree(root);
}
template <int Dim>
void KDTree<Dim>::deleteTree(KDTreeNode *subRoot){
    if(subRoot==NULL)return;
    deleteTree(subRoot->right);
    deleteTree(subRoot->left);
    delete(subRoot);

}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &query) const
{
  /**
   * @todo Implement this function!
   */
  return findNearestNeighbor(query, 0, root);
  // return Point<Dim>();
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim> &query, int dim, KDTreeNode *curRoot) const
{
  Point<Dim> nearest = curRoot->point;
  bool recurseLeft= false;
  bool recurseRight=false;
  if (curRoot->right == NULL && curRoot->left == NULL){
    return curRoot->point;
  }
  if (curRoot->left != NULL && smallerDimVal(query, curRoot->point, dim))
  // if (smallerDimVal(query, curRoot->point, dim))
  {
    // if(curRoot->left != NULL){
    nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->left);
    recurseLeft=true;
    // }
  }
  else{ 
    if (curRoot->right != NULL){
      nearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
      recurseRight=true;
    }
  }
  double radius = 0;
  if (shouldReplace(query, nearest, curRoot->point)){
    nearest = curRoot->point;
  }
  for (int i = 0; i < Dim; i++){
    radius += (nearest[i] - query[i]) * (nearest[i] - query[i]);
  }
  double splitDist = (curRoot->point[dim] - query[dim]) * (curRoot->point[dim] - query[dim]);
  Point<Dim> tempNearest = nearest;
  if (radius >= splitDist)
  {

      if(recurseLeft && curRoot->right != NULL){
      tempNearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->right);
      }
      else if (recurseRight && curRoot->left != NULL)
      {
      tempNearest = findNearestNeighbor(query, (dim + 1) % Dim, curRoot->left);
      }

  }
    if(shouldReplace(query, nearest, tempNearest))
    {
      nearest = tempNearest;
    }
  return nearest;
}


template <int Dim>
void KDTree<Dim>::buildTree(vector<Point<Dim>> &points, int dim, int left, int right, KDTreeNode *&curRoot)
{

  if (points.empty() || left > right)
  {
    return;
  }

  int middle = (left + right) / 2;
  Point<Dim> temp = (select(points, left, right, middle, dim));
  curRoot = new KDTree<Dim>::KDTreeNode(temp);
  buildTree(points, (dim + 1) % Dim, left, middle - 1, curRoot->left);
  buildTree(points, (dim + 1) % Dim, middle + 1, right, curRoot->right);
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>> &list, int left, int right, int pivotIndex, int dim)
{
  Point<Dim> pivotValue = list[pivotIndex];
  swap(list[pivotIndex], list[right]);
  int storeIndex = left;
  for (int i = left; i <= right - 1; i++)
  {
    if (smallerDimVal(list[i], pivotValue, dim))
    {
      swap(list[storeIndex], list[i]);
      storeIndex++;
    }
  }

  swap(list[right], list[storeIndex]);
  return storeIndex;
}

template <int Dim>
Point<Dim> KDTree<Dim>::select(vector<Point<Dim>> &list, int left, int right, int k, int dim)
{
  if (left == right)
  {
    return list[left];
  }
  int pivotIndex = (left + right) / 2;
  pivotIndex = partition(list, left, right, pivotIndex, dim);
  if (k == pivotIndex)
  {
    return list[k];
  }
  else if (pivotIndex > k)
  {
    return select(list, left, pivotIndex - 1, k, dim);
  }
  else
  {
    return select(list, pivotIndex + 1, right, k, dim);
  }
}
