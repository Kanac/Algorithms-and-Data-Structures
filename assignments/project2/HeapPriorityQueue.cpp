//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::put_in(PuzzleState *elem) {
  // TODO:  Put your code here!
  heap.push_back(elem);
  int currIndex = (int)heap.size() - 1;
  int parentIndex = parent(currIndex);
  
  while (parentIndex >= 0 && heap.at(parentIndex)->getBadness() > heap.at(currIndex)->getBadness()){
     PuzzleState* parentTmp = heap.at(parentIndex);
     heap.at(parentIndex) = heap.at(currIndex);
     heap.at(currIndex) = parentTmp;
     currIndex = parentIndex;
     parentIndex = parent(currIndex);
  }
}

PuzzleState * HeapPriorityQueue::take_out() {
  assert(!is_empty());

  // TODO:  Put your code here!
  PuzzleState* min = heap.at(0);
  heap.front() = heap.back(); 
  int currIndex = 0;
  while(true){
     int leftIndex = first_child(currIndex); 
     int rightIndex = leftIndex + 1;
     if (leftIndex >= (int)heap.size())  // No child case (done)
	return min;

     int minChildIndex = leftIndex; // Just assume its at left for now. If there is a right child, check it next
     if (rightIndex < (int)heap.size() && heap.at(rightIndex)->getBadness() < heap.at(minChildIndex)->getBadness())
	minChildIndex = rightIndex;
     
     if (heap.at(currIndex)->getBadness() > heap.at(minChildIndex)->getBadness()){  // Swap if needed
	PuzzleState* minChildTemp = heap.at(minChildIndex);
	heap.at(minChildIndex) = heap.at(currIndex);
        heap.at(currIndex) = minChildTemp;
        currIndex = minChildIndex;
     }
     else return min; // Return if no swap (done)
  }
}


bool HeapPriorityQueue::is_empty() {
  return (heap.size() == 0);
}

int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif
