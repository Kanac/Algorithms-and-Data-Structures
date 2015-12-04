#ifndef _ARRAYQUEUE_CPP
#define _ARRAYQUEUE_CPP

//ArrayQueue.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp file) is here to help get you
// started, but you are free to change function signatures, etc. as
// long as ArrayQueue is derived from BagOfPuzzleStates.
ArrayQueue::ArrayQueue() : front(0), back(0), num_items(0)
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor
  size = INIT_SIZE;
  array = new PuzzleState*[INIT_SIZE];
}

void ArrayQueue::put_in(PuzzleState *elem)
{
  // TODO: implement put_in method
  ensure_capacity(num_items + 1);
  array[back] = elem;
  back = (back + 1) % size;
  ++num_items; 
}

PuzzleState *ArrayQueue::take_out()
{
  assert(!is_empty());
  PuzzleState *elem = array[front];
  front = (front + 1) % size;
  --num_items;
  return elem; 

  // TODO: remove this line.
  // TODO: implement take_out method
}

bool ArrayQueue::is_empty()
{
  return (front == back);
  // TODO: implement is_empty method
}
// TODO: implement ensure_capacity (but leave this to last.. just
// start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
  if ( size < n /* TODO: if there's not already enough room */) {
    // Make plenty of room.
    int target_capacity = (n > 2*size)? n : (2*size); /* TODO: the larger of n and twice the current capacity */;

    // TODO: Set the current array aside and make room for the new one.
    PuzzleState **old_array = array;
    array = new PuzzleState*[target_capacity];

    // TODO: Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?
    int j = front;
    for (int i = 0; i < num_items; ++i) {
      array[i] = old_array[j];
      j = (j + 1) % size;
    } 

    // TODO: Fix front and back and capacity so they correspond to the new array.
    front = 0;
    back = num_items;
    size = target_capacity;

    // TODO: Delete the old array.
    delete[] old_array;
  }
}

ArrayQueue::~ArrayQueue()
{
  // TODO: implement the destructor

  // do any cleanup like deallocating
  // any dynamically allocated memory
  delete[] array; 
}

#endif
