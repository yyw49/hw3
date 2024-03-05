#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>
template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : mArity_(m), comp_(c){};

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap(){};

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  void printArray() const
  {
    for (auto e: vec_)
    {
      std::cout << e << " ";
    }
  }
private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vec_;
  int mArity_;
  PComparator comp_;
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty())
  {
    throw std::underflow_error("Heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return vec_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty())
  {
    throw std::underflow_error("Heap is empty");
  }

  std::swap(vec_[0], vec_[int(vec_.size())-1]);
  vec_.pop_back();

  int index = 0;
  int firstChild = 0;
  int bestChild = firstChild;

  while(true)
  {
    firstChild = mArity_ * index + 1;
    bestChild = firstChild;

    if (firstChild > int(vec_.size())-1)
    {
      break;
    }
    else
    {
      for (int i = firstChild +1; i < firstChild + mArity_; ++i)
      {
        if (i > int(vec_.size())-1)
        {
          break;
        }
        else if (comp_(vec_[i], vec_[bestChild]))
        {
          bestChild = i;
        }
      }

      if (comp_(vec_[bestChild], vec_[index]))
      {
        std::swap(vec_[index], vec_[bestChild]);
        index = bestChild;
      }
      else
      {
        return;
      }
    }
  }

}

template<typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& val)
{
  vec_.push_back(val);
  std::size_t index = int(vec_.size())-1;
  while(index != 0)
  {
  std::size_t parent_index = (index-1) / mArity_;
  T& current = vec_[index];
  T& parent = vec_[parent_index];
  if (comp_(current, parent))
  {
    std::swap(current, parent);
  index = parent_index;
  }
  else
  {
  break;
  }
}
}
template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const 
{
  return vec_.empty();
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const 
{
  return vec_.size();
}


#endif
