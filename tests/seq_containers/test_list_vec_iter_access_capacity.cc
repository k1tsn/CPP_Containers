// -- ---------------------------------------------------------------------- --
//              Tests for front, end, begin, end (List | Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>

#include "../../src/containers.h"

template <typename T>
class ListVectorIAC : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static T val_;
};

template <>
std::initializer_list<int> ListVectorIAC<int>::init_list_{1, 2, 3, 4};

template <>
std::initializer_list<char> ListVectorIAC<char>::init_list_{'l', 'i', 's', 't'};

template <>
std::initializer_list<std::string> ListVectorIAC<std::string>::init_list_{
    "list", "aboba", "miu"};

template <>
int ListVectorIAC<int>::val_{10};

template <>
char ListVectorIAC<char>::val_{'y'};

template <>
std::string ListVectorIAC<std::string>::val_{"hru"};

using MyTypes = ::testing::Types<
    std::pair<stlb::list<char>, std::list<char>>,
    std::pair<stlb::list<int>, std::list<int>>,
    std::pair<stlb::list<std::string>, std::list<std::string>>,
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;
TYPED_TEST_SUITE(ListVectorIAC, MyTypes);

TYPED_TEST(ListVectorIAC, front) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  a.front() = ListVectorIAC<typename stlb_list_vector::value_type>::val_;
  b.front() = ListVectorIAC<typename std_list_vector::value_type>::val_;

  EXPECT_EQ(a.front(), b.front());

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorIAC, front_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  const stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  const std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  EXPECT_EQ(a.front(), b.front());
}

TYPED_TEST(ListVectorIAC, back) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  a.back() = ListVectorIAC<typename stlb_list_vector::value_type>::val_;
  b.back() = ListVectorIAC<typename std_list_vector::value_type>::val_;

  EXPECT_EQ(a.back(), b.back());

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorIAC, back_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  const stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  const std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  EXPECT_EQ(a.back(), b.back());
}

TYPED_TEST(ListVectorIAC, begin) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  EXPECT_EQ(*iter_a, *iter_b);
}

TYPED_TEST(ListVectorIAC, end) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  --iter_a;
  --iter_b;

  EXPECT_EQ(*iter_a, *iter_b);
}

TYPED_TEST(ListVectorIAC, end_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::const_iterator iter_a = a.end();
  typename std_list_vector::const_iterator iter_b = b.end();

  --iter_a;
  --iter_b;

  EXPECT_EQ(*iter_a, *iter_b);
}

TYPED_TEST(ListVectorIAC, empty_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a;
  std_list_vector b;

  EXPECT_EQ(a.empty(), b.empty());
}

TYPED_TEST(ListVectorIAC, empty_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;
  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  EXPECT_EQ(a.empty(), b.empty());
}

TYPED_TEST(ListVectorIAC, empty_3) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a(5);
  std_list_vector b(5);

  EXPECT_EQ(a.empty(), b.empty());
}

TYPED_TEST(ListVectorIAC, empty_4) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;
  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  stlb_list_vector c = std::move(a);
  std_list_vector d = std::move(b);

  EXPECT_EQ(a.empty(), b.empty());
  EXPECT_EQ(c.empty(), d.empty());
}

TYPED_TEST(ListVectorIAC, size) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a =
      ListVectorIAC<typename stlb_list_vector::value_type>::init_list_;
  std_list_vector b =
      ListVectorIAC<typename std_list_vector::value_type>::init_list_;

  stlb_list_vector c = std::move(a);
  std_list_vector d = std::move(b);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());
}
