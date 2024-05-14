#include <limits>
#include <stdexcept>
#include <utility>

#include "vector.h"

namespace stlb {

template <typename T>
vector<T>::vector() {
  capacity_ = size_ = 0;
  ptr_ = nullptr;
}

template <typename T>
vector<T>::vector(size_type n) {
  capacity_ = size_ = n;
  if (size_ == 0) return;
  ptr_ = static_cast<value_type *>(operator new[](sizeof(value_type) *
                                                  (size_ + 1)));
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items) {
  capacity_ = size_ = items.size();
  if (size_ == 0) return;

  const value_type *list_ptr = items.begin();
  ptr_ = static_cast<value_type *>(operator new[](sizeof(value_type) *
                                                  (size_ + 1)));

  for (size_type i = 0; i < size_; ++i) {
    new (&ptr_[i]) T(list_ptr[i]);
  }
}

template <typename T>
vector<T>::vector(const vector &other) {
  CopyVector(other);
}

template <typename T>
vector<T>::vector(vector &&other) {
  MoveVector(std::move(other));
}

template <typename T>
vector<T>::~vector() {
  if (ptr_) {
    for (size_type i = 0; i < size_; ++i) {
      ptr_[i].~T();
    }
    operator delete[](ptr_);
  };
}

template <typename T>
vector<T> &vector<T>::operator=(const vector &other) {
  if (ptr_ == other.ptr_) return *this;
  if (ptr_) operator delete[](ptr_);
  CopyVector(other);
  return *this;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&other) {
  if (ptr_ == other.ptr_) return *this;
  if (ptr_) operator delete[](ptr_);
  MoveVector(std::move(other));
  return *this;
}

template <typename T>
void vector<T>::CopyVector(const vector &other) {
  capacity_ = other.capacity_;
  size_ = other.size_;

  ptr_ = static_cast<value_type *>(operator new[](sizeof(value_type) *
                                                  (size_ + 1)));
  for (size_type i = 0; i < size_; ++i) {
    new (&ptr_[i]) T(other.ptr_[i]);
  }
}

template <typename T>
void vector<T>::MoveVector(vector &&other) {
  capacity_ = std::exchange(other.capacity_, 0);
  size_ = std::exchange(other.size_, 0);
  ptr_ = std::exchange(other.ptr_, nullptr);
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= size_) throw std::out_of_range("pos out of range");
  return *(ptr_ + pos);
}

template <typename T>
typename vector<T>::const_reference vector<T>::at(size_type pos) const {
  if (pos >= size_) throw std::out_of_range("pos out of range");
  return *(ptr_ + pos);
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return *(ptr_ + pos);
}

template <typename T>
typename vector<T>::const_reference vector<T>::operator[](size_type pos) const {
  return *(ptr_ + pos);
}

template <typename T>
typename vector<T>::reference vector<T>::front() {
  return *ptr_;
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() const {
  return *ptr_;
}

template <typename T>
typename vector<T>::reference vector<T>::back() {
  return *(ptr_ + size_ - 1);
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() const {
  return *(ptr_ + size_ - 1);
}

template <typename T>
T *vector<T>::data() {
  return ptr_;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return iterator(ptr_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::begin() const {
  return const_iterator(ptr_);
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return iterator(ptr_ + size_);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::end() const {
  return const_iterator(ptr_ + size_);
}

template <typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
typename vector<T>::size_type vector<T>::size() const {
  return size_;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<value_type>::max();
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (capacity_ >= size) return;
  Resize(size);
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (capacity_ == size_) return;
  Resize(size_);
}

template <typename T>
void vector<T>::Resize(size_type size) {
  capacity_ = size;
  value_type *new_ptr = ptr_ = static_cast<value_type *>(operator new[](
      sizeof(value_type) * (size + 1)));
  for (size_type i = 0; i < size_; ++i) {
    new (&new_ptr[i]) T(ptr_[i]);
  }
  operator delete[](ptr_);
  ptr_ = std::exchange(new_ptr, nullptr);
}

template <typename T>
void vector<T>::clear() {
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(const_iterator pos,
                                               const_reference value) {
  if (empty()) {
    size_ = 1;
    capacity_ = capacity_ > size_ ? capacity_ : size_;
    if (ptr_ == nullptr)
      ptr_ = static_cast<value_type *>(operator new[](sizeof(value_type) *
                                                      (size_ + 1)));
    *ptr_ = value;
    return iterator(ptr_);
  }

  size_type new_size = size_ * 2;
  size_type insert_pos = pos - ptr_;
  if (capacity_ < new_size) Resize(new_size);
  for (size_type i = size_; i > insert_pos; --i) {
    ptr_[i] = ptr_[i - 1];
  }
  ptr_[insert_pos] = value;
  ++size_;

  return iterator(ptr_ + insert_pos);
}

template <typename T>
typename vector<T>::iterator vector<T>::erase(iterator pos) {
  size_type erase_pos = pos - ptr_;
  for (size_type i = erase_pos; i < size_ - 1; ++i) {
    ptr_[i] = ptr_[i + 1];
  }
  --size_;
  return iterator(ptr_ + erase_pos);
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  insert(iterator(ptr_ + size_), value);
}

template <typename T>
void vector<T>::pop_back() {
  erase(iterator(ptr_ + size_ - 1));
}

template <typename T>
void vector<T>::swap(vector &other) {
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
  std::swap(ptr_, other.ptr_);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  std::initializer_list<value_type> init_list =
      std::initializer_list<value_type>{args...};

  vector<T>::iterator iter;

  const value_type *ptr_to_list = init_list.begin();

  size_type pos_to_insert = pos - ptr_;

  for (size_t i = 0; i < init_list.size(); ++i, ++ptr_to_list) {
    const_iterator iter_to_insert = ptr_ + pos_to_insert;
    iter = insert(iter_to_insert, *ptr_to_list);
    ++pos_to_insert;
  }

  return iter;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  insert_many(end(), args...);
}

}  // namespace stlb
