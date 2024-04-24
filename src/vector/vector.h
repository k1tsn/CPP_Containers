#ifndef CONTAINERS_VECTOR_VECTOR_H_
#define CONTAINERS_VECTOR_VECTOR_H_

#include <initializer_list>

namespace stlb {

template <typename T>
class vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &other);
  vector(vector &&other);
  ~vector();
  vector &operator=(const vector &other);
  vector &operator=(vector &&other);

  reference at(size_type pos);
  const_reference at(size_type pos) const;

  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;

  reference front();
  const_reference front() const;

  reference back();
  const_reference back() const;

  T *data();

  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear();
  iterator insert(const_iterator pos, const_reference value);
  iterator erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);

  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  void CopyVector(const vector &other);
  void MoveVector(vector &&other);
  void Resize(size_type size);

  value_type *ptr_;
  size_type size_;
  size_type capacity_;
};

}  // namespace stlb

#include "vector.inc"

#endif  // CONTAINERS_VECTOR_VECTOR_H_
