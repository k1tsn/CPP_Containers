#ifndef CONTAINERS_LIST_LIST_H_
#define CONTAINERS_LIST_LIST_H_

#include "list_iterator.h"

namespace stlb {

template <typename T>
struct ListNode {
  T value_;
  ListNode<T> *next_;
  ListNode<T> *prev_;
};

template <typename T>
class list {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using size_type = size_t;

  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &other);
  list(list &&other);
  ~list();
  list &operator=(const list &other);
  list &operator=(list &&other);

  reference front();
  const_reference front() const;

  reference back();
  const_reference back() const;

  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  void clear();
  iterator insert(const_iterator pos, const_reference value);
  void erase(iterator pos);

  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);

  void splice(const_iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args>
  void insert_many_back(Args &&...args);

  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  void InitEndNode();
  void CopyList(const list &other);
  void MoveList(list &&other);
  void SplitList(list &list_1, list &list_2);
  size_type size_;
  ListNode<T> *end_;
};

}  // namespace stlb

#include "list.inc"

#endif
