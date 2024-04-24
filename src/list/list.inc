#include <initializer_list>
#include <limits>

#include "list.h"

namespace stlb {

template <typename T>
list<T>::list() {
  size_ = 0;
  InitEndNode();
}

template <typename T>
void list<T>::InitEndNode() {
  end_ = new ListNode<T>;
  end_->next_ = end_->prev_ = nullptr;
}

template <typename T>
list<T>::list(size_type n) {
  InitEndNode();

  size_ = n;
  if (size_ == 0) return;

  ListNode<T> *node = new ListNode<T>;
  end_->next_ = node;
  node->prev_ = end_;

  for (size_type i = 1; i < size_; ++i) {
    ListNode<T> *new_node = new ListNode<T>;
    new_node->prev_ = node;
    node->next_ = new_node;
    node = new_node;
  }

  node->next_ = end_;
  end_->prev_ = node;
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const &items) {
  InitEndNode();

  size_ = items.size();
  if (size_ == 0) return;

  const value_type *ptr_init_list = items.begin();

  ListNode<T> *node = new ListNode<T>;
  node->value_ = *ptr_init_list;
  node->prev_ = end_;
  ++ptr_init_list;
  end_->next_ = node;

  for (size_type i = 1; i < size_; ++i, ++ptr_init_list) {
    ListNode<T> *new_node = new ListNode<T>;
    new_node->value_ = *ptr_init_list;
    new_node->prev_ = node;
    node->next_ = new_node;
    node = new_node;
  }

  node->next_ = end_;
  end_->prev_ = node;
}

template <typename T>
list<T>::list(const list &other) {
  InitEndNode();
  size_ = 0;
  if (other.size_ == 0) return;
  CopyList(other);
}

template <typename T>
list<T>::list(list &&other) {
  InitEndNode();
  MoveList(std::move(other));
}

template <typename T>
list<T>::~list() {
  clear();
  delete end_;
}

template <typename T>
typename list<T>::list &list<T>::operator=(const list &other) {
  if (end_ == other.end_) return *this;
  clear();

  CopyList(other);

  return *this;
}

template <typename T>
typename list<T>::list &list<T>::operator=(list &&other) {
  if (end_ == other.end_) return *this;
  clear();

  MoveList(std::move(other));

  return *this;
}

template <typename T>
void list<T>::CopyList(const list &other) {
  size_ = other.size_;

  list<T>::const_iterator iter_other = other.begin();

  ListNode<T> *node = new ListNode<T>;
  node->value_ = *iter_other;
  ++iter_other;
  node->prev_ = end_;
  end_->next_ = node;

  for (size_type i = 1; i < size_; ++i, ++iter_other) {
    ListNode<T> *new_node = new ListNode<T>;
    new_node->value_ = *iter_other;
    new_node->prev_ = node;
    node->next_ = new_node;
    node = new_node;
  }

  node->next_ = end_;
  end_->prev_ = node;
}

template <typename T>
void list<T>::MoveList(list &&other) {
  other.end_->next_->prev_ = end_;
  other.end_->prev_->next_ = end_;

  end_->next_ = std::exchange(other.end_->next_, nullptr);
  end_->prev_ = std::exchange(other.end_->prev_, nullptr);
  size_ = std::exchange(other.size_, 0);
}

template <typename T>
void list<T>::clear() {
  size_ = 0;
  ListNode<T> *node = end_->next_;
  if (node != nullptr) {
    while (node != end_) {
      ListNode<T> *next_node = node->next_;
      delete node;
      node = next_node;
    }
  }
}

template <typename T>
typename list<T>::reference list<T>::front() {
  if (end_->next_ == nullptr) return end_->value_;
  return end_->next_->value_;
}

template <typename T>
typename list<T>::const_reference list<T>::front() const {
  if (end_->next_ == nullptr) return end_->value_;
  return end_->next_->value_;
}

template <typename T>
typename list<T>::reference list<T>::back() {
  if (end_->prev_ == nullptr) return end_->value_;
  return end_->prev_->value_;
}

template <typename T>
typename list<T>::const_reference list<T>::back() const {
  if (end_->prev_ == nullptr) return end_->value_;
  return end_->prev_->value_;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  if (end_->next_ == nullptr) return end();
  return iterator(end_->next_);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  if (end_->next_ == nullptr) return end();
  return const_iterator(end_->next_);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(end_);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return const_iterator(end_);
}

template <typename T>
bool list<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() const {
  return size_;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() const {
  return std::numeric_limits<size_type>::max();
}

template <typename T>
typename list<T>::iterator list<T>::insert(const_iterator pos,
                                           const_reference value) {
  ListNode<T> *new_node = new ListNode<T>;
  new_node->value_ = value;

  if (empty()) {
    end_->next_ = end_->prev_ = new_node;
    new_node->prev_ = new_node->next_ = end_;
  } else {
    new_node->prev_ = pos.node_->prev_;
    pos.node_->prev_->next_ = new_node;
    pos.node_->prev_ = new_node;
    new_node->next_ = pos.node_;
  }

  ++size_;

  return iterator(new_node);
}

template <typename T>
void list<T>::erase(iterator pos) {
  if (empty()) return;
  pos.node_->prev_->next_ = pos.node_->next_;
  pos.node_->next_->prev_ = pos.node_->prev_;
  delete pos.node_;
  --size_;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  insert(end(), value);
}

template <typename T>
void list<T>::pop_back() {
  erase(iterator(end_->prev_));
}

template <typename T>
void list<T>::push_front(const_reference value) {
  insert(begin(), value);
}

template <typename T>
void list<T>::pop_front() {
  erase(iterator(end_->next_));
}

template <typename T>
void list<T>::swap(list &other) {
  std::swap(end_, other.end_);
  std::swap(size_, other.size_);
}

template <typename T>
void list<T>::merge(list &other) {
  if (other.end_ == end_ || other.empty()) return;
  if (empty()) {
    swap(other);
    return;
  }

  list<T>::iterator iter_this = begin();
  list<T>::iterator iter_other = other.begin();
  list<T> new_list;

  list<T>::iterator iter_new = new_list.begin();
  while (iter_this != end() && iter_other != other.end()) {
    list<T>::iterator &merge_iter =
        *iter_this <= *iter_other ? iter_this : iter_other;

    merge_iter.node_->prev_ = iter_new.node_;
    iter_new.node_->next_ = merge_iter.node_;
    ++merge_iter;
    ++iter_new;
  }

  list<T>::iterator &merge_iter = iter_this != end() ? iter_this : iter_other;
  ListNode<T> *merge_end = iter_this != end() ? end_ : other.end_;

  iter_new.node_->next_ = merge_iter.node_;
  merge_iter.node_->prev_ = iter_new.node_;
  new_list.end_->prev_ = merge_end->prev_;
  new_list.end_->prev_->next_ = new_list.end_;

  new_list.size_ = size_ + other.size_;

  end_->next_ = end_->prev_ = nullptr;
  other.end_->next_ = other.end_->prev_ = nullptr;
  size_ = other.size_ = 0;

  swap(new_list);
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  if (empty()) {
    swap(other);
    return;
  }
  pos.node_->prev_->next_ = other.end_->next_;
  other.end_->next_->prev_ = pos.node_->prev_;
  pos.node_->prev_ = other.end_->prev_;
  other.end_->prev_->next_ = pos.node_;

  size_ += other.size_;

  other.end_->next_ = other.end_->prev_ = nullptr;
  other.size_ = 0;
}

template <typename T>
void list<T>::reverse() {
  if (empty()) return;
  list<T>::iterator iter = begin();
  for (; iter != end(); ++iter) {
    std::swap(iter.node_->prev_->next_, iter.node_->prev_->prev_);
  }
  std::swap(iter.node_->next_->prev_, iter.node_->next_->next_);
}

template <typename T>
void list<T>::unique() {
  if (empty()) return;
  list<T>::iterator iter_prev = begin();
  list<T>::iterator iter_next = begin();
  ++iter_next;
  for (; iter_next != end(); ++iter_next) {
    if (*iter_prev == *iter_next) {
      erase(iter_next);
      iter_next = iter_prev;
    } else {
      ++iter_prev;
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (size_ <= 1) return;
  list<T> list_1;
  list<T> list_2;
  SplitList(list_1, list_2);
  if (list_1.size_ > 1) list_1.sort();
  if (list_2.size_ > 1) list_2.sort();
  list_1.merge(list_2);
  swap(list_1);
}

template <typename T>
void list<T>::SplitList(list &list_1, list &list_2) {
  if (this->size_ <= 1) return;

  list<T>::iterator iter = begin();
  for (size_type i = 0; i < size_ / 2; ++i) ++iter;

  list_1.size_ = list_2.size_ = size_ / 2;

  list_1.end_->next_ = end_->next_;
  list_1.end_->prev_ = iter.node_->prev_;

  list_2.end_->next_ = iter.node_;
  list_2.end_->prev_ = end_->prev_;

  iter.node_->prev_->next_ = list_1.end_;
  iter.node_->prev_ = list_2.end_;

  end_->prev_->next_ = list_2.end_;
  if (this->size_ % 2 > 0) ++list_2.size_;

  end_->next_ = end_->prev_ = nullptr;
  size_ = 0;
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  std::initializer_list<value_type> init_list =
      std::initializer_list<value_type>{args...};

  const value_type *ptr_list = init_list.begin();

  list<T>::iterator iter;
  for (size_t i = 0; i < init_list.size(); ++i, ++ptr_list) {
    iter = insert(pos, *ptr_list);
  }

  return iter;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  if (empty())
    insert_many(end(), args...);
  else
    insert_many(const_iterator(end_->next_), args...);
}

}  // namespace stlb
