// -- ---------------------------------------------------------------------- --
//           Tests for clear, insert, push_back, swap (List | Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>

#include "../../src/containers.h"

template <typename T>
class ListVectorModifiersTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static std::initializer_list<T> init_list_other_;
  static T val_;
};

template <>
std::initializer_list<int> ListVectorModifiersTest<int>::init_list_{10, 33, 56,
                                                                    -1};

template <>
std::initializer_list<char> ListVectorModifiersTest<char>::init_list_{'l', 'i',
                                                                      's', 't'};

template <>
std::initializer_list<std::string>
    ListVectorModifiersTest<std::string>::init_list_{"list", "aboba", "miu"};

template <>
std::initializer_list<int> ListVectorModifiersTest<int>::init_list_other_{
    3, 6, 10, 8, 2, -19, -5};

template <>
std::initializer_list<char> ListVectorModifiersTest<char>::init_list_other_{
    'k', 'o', 's', 'h', 'k', 'a'};

template <>
std::initializer_list<std::string>
    ListVectorModifiersTest<std::string>::init_list_other_{
        "AoaoaoaoOAAAO", "KoSHka", "potra", "cheno"};

template <>
int ListVectorModifiersTest<int>::val_{10};

template <>
char ListVectorModifiersTest<char>::val_{'y'};

template <>
std::string ListVectorModifiersTest<std::string>::val_{"hru"};

using MyTypes = ::testing::Types<
    std::pair<stlb::list<char>, std::list<char>>,
    std::pair<stlb::list<int>, std::list<int>>,
    std::pair<stlb::list<std::string>, std::list<std::string>>,
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;
TYPED_TEST_SUITE(ListVectorModifiersTest, MyTypes);

TYPED_TEST(ListVectorModifiersTest, clear) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  a.clear();
  b.clear();

  EXPECT_EQ(a.size(), b.size());

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert(iter_a, (typename stlb_list_vector::value_type){});
  b.insert(iter_b, (typename std_list_vector::value_type){});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, insert_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert(
      iter_a,
      ListVectorModifiersTest<typename stlb_list_vector::value_type>::val_);
  b.insert(iter_b,
           ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, insert_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  ++iter_a;
  ++iter_b;

  a.insert(
      iter_a,
      ListVectorModifiersTest<typename stlb_list_vector::value_type>::val_);
  b.insert(iter_b,
           ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, insert_3) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  a.insert(
      iter_a,
      ListVectorModifiersTest<typename stlb_list_vector::value_type>::val_);
  b.insert(iter_b,
           ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, insert_4) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  --iter_a;
  --iter_b;

  a.insert(
      iter_a,
      ListVectorModifiersTest<typename stlb_list_vector::value_type>::val_);
  b.insert(iter_b,
           ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, insert_5) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a;

  std_list_vector b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert(
      iter_a,
      ListVectorModifiersTest<typename stlb_list_vector::value_type>::val_);
  b.insert(iter_b,
           ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, erase_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.erase(iter_a);
  b.erase(iter_b);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, erase_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  ++iter_a;
  ++iter_b;

  a.erase(iter_a);
  b.erase(iter_b);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, erase_3) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  --iter_a;
  --iter_b;

  a.erase(iter_a);
  b.erase(iter_b);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, erase_4) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a = ListVectorModifiersTest<
      typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  --iter_a;
  --iter_b;

  a.erase(iter_a);
  b.erase(iter_b);

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, push_back_1) {
  using s21_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  s21_list_vector a =
      ListVectorModifiersTest<typename s21_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename s21_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.push_back(
      ListVectorModifiersTest<typename s21_list_vector::value_type>::val_);
  b.push_back(
      ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, push_back_2) {
  using s21_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  s21_list_vector a;
  std_list_vector b;

  typename s21_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.push_back(
      ListVectorModifiersTest<typename s21_list_vector::value_type>::val_);
  b.push_back(
      ListVectorModifiersTest<typename std_list_vector::value_type>::val_);

  iter_a = a.begin();
  iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, pop_back) {
  using s21_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  s21_list_vector a =
      ListVectorModifiersTest<typename s21_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename s21_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.pop_back();
  b.pop_back();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, swap_1) {
  using s21_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  s21_list_vector a =
      ListVectorModifiersTest<typename s21_list_vector::value_type>::init_list_;
  s21_list_vector c;
  a.swap(c);

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;
  std_list_vector d;
  b.swap(d);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename s21_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorModifiersTest, swap_2) {
  using s21_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  s21_list_vector a =
      ListVectorModifiersTest<typename s21_list_vector::value_type>::init_list_;
  s21_list_vector c = ListVectorModifiersTest<
      typename s21_list_vector::value_type>::init_list_other_;
  a.swap(c);

  std_list_vector b =
      ListVectorModifiersTest<typename std_list_vector::value_type>::init_list_;
  std_list_vector d = ListVectorModifiersTest<
      typename std_list_vector::value_type>::init_list_other_;
  b.swap(d);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename s21_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}
