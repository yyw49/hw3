#include "heap.h"
using namespace std;
#include <iostream>
#include <functional>



int main()
{
  Heap<int> myHeap(3);

  myHeap.push(1);
  myHeap.push(2);
  myHeap.push(3);
  myHeap.push(4);
  myHeap.push(5);
  
  myHeap.pop();
  myHeap.pop();

  myHeap.printArray();
}