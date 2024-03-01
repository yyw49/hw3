#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void append(Node*& head, Node*& newNode)
{
  if (head == nullptr)
  {
    head = newNode;
    return;
  }
  else if(head->next == nullptr)
  {
    head->next = newNode;
    return;
  }

  append(head->next, newNode);

}

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if (head == nullptr)
  {
    return;
  }
  Node* toInsert = head;
  toInsert->next = nullptr;
  if (head->val <=pivot)
  {
    append(smaller, toInsert);
  }
  else
  {
    append(larger, toInsert);
  }

  llpivot(head->next, smaller, larger, pivot);
}
