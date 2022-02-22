/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */
#include "List.h"

template <class T>
List<T>::List() { 
  // @TODO: graded in MP3.1
    // ListNode* head_ = NULL;
  head_=NULL;
  tail_ = NULL;
    length_=0;

}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
  /// @todo Graded in MP3.1
  // for(ListIterator it = begin(); it != end(); ++it){

  // }
  ListNode *temp;
  while(head_!=NULL){
    temp=head_->next;
    delete head_;
    head_=temp;
  }
  head_ = NULL;
  tail_=NULL;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;
  
  if (head_ != NULL) {
    head_ -> prev = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
  }
  head_=newNode;

  length_++;
  return;
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
    // ListNode *end = tail_->next;
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = NULL;
  newNode -> prev = tail_;
  if (tail_ != NULL) {
    tail_->next = newNode;
  }
  if (head_ == NULL) {
    head_ = newNode;
  }
  tail_=newNode;
  length_++;
  return;

}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  ListNode * curr = start;
  // if(splitPoint==0)return start;
  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL && curr->prev !=NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return curr;
  
}

/**
  * Modifies List using the rules for a TripleRotate.
  *
  * This function will to a wrapped rotation to the left on every three 
  * elements in the list starting for the first three elements. If the 
  * end of the list has a set of 1 or 2 elements, no rotation all be done 
  * on the last 1 or 2 elements.
  * 
  * You may NOT allocate ANY new ListNodes!
  */
template <typename T>
void List<T>::tripleRotate() {
  // @todo Graded in MP3.1
  if(length_<3) return;
  ListNode *tempHead=head_;
  ListNode *Node1;
  ListNode *Node2;
  ListNode *Node3;
  ListNode *next;
  ListNode *prev;
  head_=head_->next;
  for(int i=0;i+3<=length_;i+=3){
    prev=tempHead->prev;
    Node3=tempHead;
    tempHead=tempHead->next;
    Node1= tempHead;
    tempHead=tempHead->next;
    Node2=tempHead;
    tempHead=tempHead->next;
    next=tempHead;


    Node1->prev=prev;
    if(Node1->prev!=NULL){
      Node1->prev->next=Node1;
    }
    Node1->next=Node2;
    Node2->prev=Node1;
    Node2->next=Node3;
    Node3->prev=Node2;
    Node3->next=next;
    if(Node3->next!=NULL){
      Node3->next->prev=Node3;
    }
  }
  tail_=next;
  return;
}


/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() { 
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2
  if (startPoint == endPoint) {return;}
  ListNode *front=startPoint;
  ListNode *back=endPoint;
  // ListNode *End=endPoint;
  ListNode *temp;
  ListNode * curr = startPoint;
  ListNode* before=front->prev;
  ListNode* after=back->next;
  // int i=0;
  while(curr!=back){
    temp=curr->next;
    curr->next=curr->prev;
    curr->prev=temp;
    curr=temp;
    // i++;
    
  }
  temp=curr->next;
  curr->next=curr->prev;
  curr->prev=temp;
  
  // std::swap(startPoint,endPoint);
  if(before!=NULL){
    before->next=back;
  }
  back->prev=before;
  front->next=after;
  if(after!=NULL){
    after->prev=front;
  }
  // std::swap(startPoint->prev,endPoint->next);
  // startPoint->prev->next=startPoint;
  // if(endPoint->next!=NULL){
  // endPoint->next->prev=endPoint;
  // }
  // if(startPoint->prev!=NULL){
  // startPoint->prev->next=startPoint;
  // }
  if(startPoint==head_){
    head_=back;
  }
  if(endPoint==tail_){
    tail_=front;
  }
  if (startPoint != head_ && endPoint != tail_) {
    std::swap(startPoint,endPoint);
  }
  // head_=endPoint;
  // tail_=startPoint;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2
  if(n==0 && n==1) return;
  ListNode *start=head_;
  int size=length_;
  ListNode *end=start;
  int i=0;
 while(end!=NULL){
    if(i==n-1 || end==tail_){
        reverse(start,end);
        if(end==tail_)return;
        start=end->next;
        end=end->next;

        i=0;
        continue;
    }
    end=end->next;
    i++;
  }
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <typename T>
typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode* second) {
  // @todo Graded in MP3.2

ListNode *f=first;
ListNode *s=second;
ListNode *result;

  if(s->data < f->data) {
    result=s;
    s=s->next;
  }
  else{
    result=f;
    f->prev=result;
    f=f->next;
    }
  ListNode* start=result;

  while(s!=NULL && f!=NULL){
        if(s->data<f->data){
          result->next=s;
          s->prev=result;
          s=s->next;
          result=result->next;


          // if(s!=NULL){
          //   // s=s->next;
          //   s->prev->next=NULL;
          //   s->prev->prev=result;
          //   s->prev=NULL;
          }
        else{
          result->next=f;
          f->prev=result;
          f=f->next;
          result=result->next;
          }
  }
  if(f==NULL && s!=NULL){
    result->next=s;
    s->prev=result;
    s=s->next;
  }
  if(f!=NULL && s==NULL){
    result->next=f;
    f->prev=result;
    f=f->next;
  }
  return start;
}


/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2
  if(chainLength<=1){
    return start;
  }
int split=chainLength/2;
  ListNode* second=start;
  int i=0;
  // split(start,chainLength/2);
  // for(int i =0; i<split && second!=NULL;i+=1){
  while(i<split && second!=NULL){
    // cout << i << " " << split << endl;
    second=second->next;
    i++;
  }
  if(second!=NULL){
  second->prev->next=NULL;
  second->prev=NULL;
  }
  // int split=chainLength/2;
  // ListNode* second= split()
  ListNode* first = mergesort(start,split);
  ListNode* s = mergesort(second,chainLength-split);
  ListNode* r= merge(first,s);
  return r;
}
// template <typename T>
// List< T >::ListIterator List< T >::begin()	const{
//   return head_;
// }
// template <typename T>
// bool List< T >::empty	()	const{
//     NULL;
// }
