//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
LinkedListQueue::LinkedListQueue()
{
  // TODO
  head = NULL;
  tail = NULL;
  size = 0;
}

void LinkedListQueue::put_in(PuzzleState *elem)
{
  // TODO
  if (! head) {
    tail = new node;
    tail->data = elem;
    tail->next = NULL;
    head = tail;
  } else {
    tail->next = new node;
    tail = tail->next;
    tail->data = elem;
    tail->next = NULL;
  }

}

PuzzleState *LinkedListQueue::take_out()
{
  // TODO
  assert(! is_empty());
  PuzzleState *elem = head->data;
  node* temp = head;
  head = head->next;
  delete temp;
  if (! head) {
    tail = NULL;
  }
  return elem;
}

bool LinkedListQueue::is_empty()
{
  // TODO
  return (! head) && (! tail);
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO
  while (head != tail) {
    take_out();
  }
}

#endif

