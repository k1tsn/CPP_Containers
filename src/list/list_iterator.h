#ifndef CONTAINERS_LIST_LIST_ITERATOR_H_
#define CONTAINERS_LIST_LIST_ITERATOR_H_

#include "list.h"

namespace stlb {

template <typename T>
class list;

template <typename T>
struct ListNode;

template <typename T>
class ListConstIterator;

template <typename T>
class ListIterator {
 public:
  using value_type = T;
  using reference = T&;
  friend class list<T>;

  ListIterator();
  ListIterator(ListNode<T>* node);
  ListIterator(const ListIterator& other);
  ListIterator(ListIterator&& other);
  ~ListIterator();

  reference operator*();
  ListIterator<T>& operator=(const ListIterator& other);
  ListIterator<T>& operator=(ListIterator&& other);
  ListIterator<T>& operator++();
  ListIterator<T> operator++(int);
  ListIterator<T>& operator--();
  ListIterator<T> operator--(int);
  bool operator==(ListIterator&& other) const;
  bool operator!=(ListIterator&& other) const;

  operator ListConstIterator<T>() { return ListConstIterator(node_); }

 private:
  ListNode<T>* node_;
};

template <typename T>
class ListConstIterator {
 public:
  using value_type = T;
  using const_reference = const T&;
  friend class list<T>;

  ListConstIterator();
  ListConstIterator(ListNode<T>* node);
  ListConstIterator(const ListConstIterator& other);
  ListConstIterator(ListConstIterator&& other);
  ~ListConstIterator();

  const_reference operator*();
  ListConstIterator<T>& operator=(const ListConstIterator& other);
  ListConstIterator<T>& operator=(ListConstIterator&& other);
  ListConstIterator<T>& operator++();
  ListConstIterator<T> operator++(int);
  ListConstIterator<T>& operator--();
  ListConstIterator<T> operator--(int);
  bool operator==(ListConstIterator&& other) const;
  bool operator!=(ListConstIterator&& other) const;

 private:
  ListNode<T>* node_;
};

}  // namespace stlb

#include "list_iterator.inc"

#endif  // CONTAINERS_LIST_LIST_ITERATOR_H_
