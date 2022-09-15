#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"
const string ERR = "error";
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
/**
* Adds a new value to the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::push_back(const std::string& val){
  if (size_ == 0){
    ULListStr::Item* head = new Item();
    head_ = head;
    tail_ = head;
  }
  if (tail_->last == ARRSIZE){
    ULListStr::Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 1;
    newItem->val[0] = val;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    
  }else tail_->val[tail_->last++] = val;
  size_++;
  
  return;
}

/**
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back(){
  if (size_ == 0) return;
  tail_->last -= 1;
  if (tail_->first >= tail_->last){
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
  }
  size_--;
  return;
}

/**
* Adds a new value to the front of the list.
* If there is room before the 'first' value in
* the head node add it there, otherwise, 
* allocate a new head node.
*   - MUST RUN in O(1)
*/
void ULListStr::push_front(const std::string& val){
  if (size_ == 0){
    ULListStr::Item* head = new Item();
    head_ = head;
    tail_ = head;
    head_->first = 1;
    head_->last = 1;
  }
  if (head_->first == 0){
    ULListStr::Item* newItem = new Item();
    newItem->first = ARRSIZE-1;
    newItem->last = ARRSIZE;
    newItem->val[ARRSIZE-1] = val;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;

  }else head_->val[--(head_->first)] = val;
  size_++;
  return;
}

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front(){
  if (size_==0) return;
  head_->first += 1;
  if (head_->first >= head_->last){
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
  }
  size_--;
  return;
}

/**
* Returns a const reference to the back element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::back() const{
  if (size_==0) return ERR;
  return tail_->val[tail_->last-1];
}

/**
* Returns a const reference to the front element
*   - MUST RUN in O(1)
*/
std::string const & ULListStr::front() const{
  if (size_==0) return ERR;
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_) return nullptr;
  Item* cur = head_;
  while(cur != nullptr){
    if (cur->last - cur->first > loc){
      return &(cur->val[cur->first + loc]);
    }else{
      loc -= cur->last - cur->first;
      cur = cur->next;
    }
  }
  return nullptr;
}
