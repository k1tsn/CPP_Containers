#include <utility>

#include "list_iterator.h"

namespace stlb {

template <typename T>
ListIterator<T>::ListIterator() {
  node_ = nullptr;
}

template <typename T>
ListIterator<T>::ListIterator(ListNode<T>* node) {
  node_ = node;
}

template <typename T>
ListIterator<T>::ListIterator(const ListIterator& other) {
  node_ = other.node_;
}

template <typename T>
ListIterator<T>::ListIterator(ListIterator&& other) {
  node_ = std::exchange(other.node_, nullptr);
}

template <typename T>
ListIterator<T>::~ListIterator() {}

template <typename T>
typename ListIterator<T>::reference ListIterator<T>::operator*() {
  return node_->value_;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(const ListIterator& other) {
  if (node_ == other.node_) return *this;
  node_ = other.node_;
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator=(ListIterator&& other) {
  if (node_ == other.node_) return *this;
  node_ = std::exchange(other.node_, nullptr);
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator++() {
  node_ = node_->next_;
  return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator++(int) {
  node_ = node_->next_;
  return *this;
}

template <typename T>
ListIterator<T>& ListIterator<T>::operator--() {
  node_ = node_->prev_;
  return *this;
}

template <typename T>
ListIterator<T> ListIterator<T>::operator--(int) {
  node_ = node_->prev_;
  return *this;
}

template <typename T>
bool ListIterator<T>::operator==(ListIterator&& other) const {
  return node_ == other.node_;
}

template <typename T>
bool ListIterator<T>::operator!=(ListIterator&& other) const {
  return node_ != other.node_;
}

template <typename T>
ListConstIterator<T>::ListConstIterator() {
  node_ = nullptr;
}

template <typename T>
ListConstIterator<T>::ListConstIterator(ListNode<T>* node) {
  node_ = node;
}

template <typename T>
ListConstIterator<T>::ListConstIterator(const ListConstIterator& other) {
  node_ = other.node_;
}

template <typename T>
ListConstIterator<T>::ListConstIterator(ListConstIterator&& other) {
  node_ = std::exchange(other.node_, nullptr);
}

template <typename T>
ListConstIterator<T>::~ListConstIterator() {}

template <typename T>
typename ListConstIterator<T>::const_reference
ListConstIterator<T>::operator*() {
  return node_->value_;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator=(
    const ListConstIterator& other) {
  if (node_ == other.node_) return *this;
  node_ = other.node_;
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator=(
    ListConstIterator&& other) {
  if (node_ == other.node_) return *this;
  node_ = std::exchange(other.node_, nullptr);
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator++() {
  node_ = node_->next_;
  return *this;
}

template <typename T>
ListConstIterator<T> ListConstIterator<T>::operator++(int) {
  node_ = node_->next_;
  return *this;
}

template <typename T>
ListConstIterator<T>& ListConstIterator<T>::operator--() {
  node_ = node_->prev_;
  return *this;
}

template <typename T>
ListConstIterator<T> ListConstIterator<T>::operator--(int) {
  node_ = node_->prev_;
  return *this;
}

template <typename T>
bool ListConstIterator<T>::operator==(ListConstIterator&& other) const {
  return node_ == other.node_;
}

template <typename T>
bool ListConstIterator<T>::operator!=(ListConstIterator&& other) const {
  return node_ != other.node_;
}

}  // namespace stlb
