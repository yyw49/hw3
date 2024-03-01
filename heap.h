#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
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
  ~Heap();

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

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> vec_;
  int mArity_;
  PComparator comp_;
  void bubbleDown(size_t index);
  void bubbleUp(size_t index);
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

  return vec_.at(0);
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

  vec_[0] = vec_.back();
  vec_.pop_back();
  bubbleDown(0);
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

template<typename T, typename PComparator>
void Heap<T, PComparator>::bubbleDown(size_t index)
{
  size_t child = mArity_ * index + 1;
  while (child < vec_.size())
  {
    size_t min_max_child = child;
    for (int i = 1; i < mArity_ && child + i < vec_.size(); ++i)
    {
      if (comp(vec_[min_max_child], vec_[index]))
      {
        min_max_child = child + i;
      }
    }

    if (comp(vec_[min_max_child], vec_[index]))
    {
      std::swap(vec_[min_max_child], vec_[index]);
      index = min_max_child;
      child = mArity_ * index + 1;
    }
    else
    {
      break;
    }
  }
}

template<typename T, typename PComparator>
void Heap<T, PComparator>::bubbleUp(size_t index)
{
  while (index > 0 && comp(vec_[index], vec_[(index-1)/mArity_]))
  {
    std::swap(vec_[index], vec_[(index - 1) / mArity_]);
    index = (index-1) / mArity_;
  }
}
#endif
