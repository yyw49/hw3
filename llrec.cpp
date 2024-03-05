#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

/*void append(Node*& head, Node*& newNode)
{
  if (head == nullptr)
  {
    newNode->next = nullptr;
    head = newNode;
    return;
  }
  else if(head->next == nullptr)
  {
    newNode->next = nullptr;
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
  //toInsert->next = nullptr;
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
 
 */

 

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) 
{
  if (head == nullptr)
  {
    smaller = nullptr;
    larger = nullptr;
    return;
  }    

  Node* curr = head;
  head = head->next;

  if (curr->val <= pivot)
  {
    smaller = curr;
    smaller->next = nullptr;
    llpivot(head, smaller->next, larger, pivot);
  }
  else
  {
    larger = curr;
    larger->next = nullptr;
    llpivot(head, smaller, larger->next, pivot);
  }
}
