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
  Heap(int m=2, PComparator c = PComparator());

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
  T const &top() const;

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

  void heapify(int idx);

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data_;
  int m_;
  PComparator comp_;


};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
  : data_(), m_(m), comp_(c)
{
  if (m_ < 2) m_ = 2;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() = default;


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("can't call top on an empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data_.front();

}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("can't call pop on an empty heap");
  }
  // replace first item with last item
  data_.front() = data_.back();
  // remove back item
  data_.pop_back();
  // trickleDown top item (if any left)
  if (!empty()) heapify(0);
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return data_.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  // insert at the end and bubble up to maintain heap property
  data_.push_back(item);
  // percolate up from last index
  size_t child = data_.size() - 1;
  while (child > 0) {
    size_t parent = (child - 1) / m_;
    // if child has higher priority than parent, swap
    if (comp_(data_[child], data_[parent])) {
      std::swap(data_[child], data_[parent]);
      child = parent;
    } else {
      break;
    }
  }
}


template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if (this->size() == 0) {
    return true;
  } else {
    return false;
  } 
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int idx) {
  if (idx < 0) return;
  size_t n = this->size();
  size_t i = idx;

  size_t firstChild = m_ * i + 1;
  if (firstChild >= n) return; // no children

  // pick best child according to comp_
  size_t best = firstChild;
  size_t lastChild = firstChild + m_ - 1;
  if (lastChild >= n) lastChild = n - 1;

  for (size_t c = firstChild + 1; c <= lastChild; ++c) {
    if (comp_(data_[c], data_[best])) best = c;
  }

  // if child has higher priority, swap and recurse
  if (comp_(data_[best], data_[i])) {
    std::swap(data_[i], data_[best]);
    heapify(best);
  }
}


#endif

