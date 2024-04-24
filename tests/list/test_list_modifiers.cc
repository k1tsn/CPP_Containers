// -- ---------------------------------------------------------------------- --
//           Tests for push_front, pop_front, merge, splice,
//           reverse, unique, sort, insert_many_front (List)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>

#include "../../src/containers.h"

template <typename T>
class ListModifiersTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static std::initializer_list<T> init_list_other_;
  static std::initializer_list<T> init_list_uniq_1_;
  static std::initializer_list<T> init_list_uniq_2_;
  static std::initializer_list<T> init_list_uniq_3_;
  static std::initializer_list<T> init_list_sort_1_;
  static std::initializer_list<T> init_list_sort_2_;
  static T val_;
  static T val_1_;
  static T val_2_;
  static T val_3_;
};

// ________________________________init_list___________________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_{10, 33, 56, -1};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_{'l', 'i', 's',
                                                                't'};

template <>
std::initializer_list<std::string> ListModifiersTest<std::string>::init_list_{
    "list", "aboba", "miu"};

// ____________________________________________________________________________

// _____________________________init_list_other________________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_other_{
    3, 6, 10, 8, 2, -19, -5};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_other_{
    'k', 'o', 's', 'h', 'k', 'a'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_other_{"AoaoaoaoOAAAO", "KoSHka",
                                                     "potra", "cheno"};

// ____________________________________________________________________________

// __________________________________val_______________________________________

template <>
int ListModifiersTest<int>::val_{19};
template <>
char ListModifiersTest<char>::val_{'u'};
template <>
std::string ListModifiersTest<std::string>::val_{"lIsT"};

template <>
int ListModifiersTest<int>::val_1_{10};

template <>
char ListModifiersTest<char>::val_1_{'y'};

template <>
std::string ListModifiersTest<std::string>::val_1_{"hru"};

template <>
int ListModifiersTest<int>::val_2_{67};

template <>
char ListModifiersTest<char>::val_2_{'h'};

template <>
std::string ListModifiersTest<std::string>::val_2_{"red"};

template <>
int ListModifiersTest<int>::val_3_{-12};

template <>
char ListModifiersTest<char>::val_3_{'s'};

template <>
std::string ListModifiersTest<std::string>::val_3_{"black"};

// ____________________________________________________________________________

// ______________________________init_list_uniq_1______________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_uniq_1_{1, 2, 2, 3,
                                                                     3, 3, 4};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_uniq_1_{
    'a', 'b', 'b', 'c', 'c', 'c', 'd'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_uniq_1_{
        "list", "miu", "miu", "hru", "hru", "hru", "rabbit"};

// ____________________________________________________________________________

// ______________________________init_list_uniq_2______________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_uniq_2_{
    1, 2, 2, 3, 3, 2, 1, 1, 2};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_uniq_2_{
    'a', 'b', 'b', 'c', 'c', 'b', 'a', 'a', 'b'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_uniq_2_{
        "list", "miu", "miu", "hru", "hru", "miu", "list", "list", "miu"};
// ____________________________________________________________________________

// ______________________________init_list_uniq_3______________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_uniq_3_{
    1, 2, 12, 23, 3, 2, 51, 1, 2, 2};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_uniq_3_{
    'a', 'b', 'y', 'f', 'c', 'b', 'z', 'a', 'b', 'b'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_uniq_3_{
        "list", "miu",  "rabbit", "Carrot", "hru",
        "miu",  "town", "list",   "miu",    "miu"};

// ____________________________________________________________________________

// ______________________________init_list_sort_1______________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_sort_1_{1};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_sort_1_{'f'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_sort_1_{"list"};

// ____________________________________________________________________________

// ______________________________init_list_sort_2______________________________

template <>
std::initializer_list<int> ListModifiersTest<int>::init_list_sort_2_{1, -10};

template <>
std::initializer_list<char> ListModifiersTest<char>::init_list_sort_2_{'f',
                                                                       'A'};

template <>
std::initializer_list<std::string>
    ListModifiersTest<std::string>::init_list_sort_2_{"list", "high"};

// ____________________________________________________________________________

using MyTypes = ::testing::Types<
    std::pair<stlb::list<char>, std::list<char>>,
    std::pair<stlb::list<int>, std::list<int>>,
    std::pair<stlb::list<std::string>, std::list<std::string>>>;
TYPED_TEST_SUITE(ListModifiersTest, MyTypes);

TYPED_TEST(ListModifiersTest, push_front_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  std_list b = ListModifiersTest<std_list_type>::init_list_;

  a.push_front(ListModifiersTest<stlb_list_type>::val_);
  b.push_front(ListModifiersTest<std_list_type>::val_);

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, push_front_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a;
  std_list b;

  a.push_front(ListModifiersTest<stlb_list_type>::val_);
  b.push_front(ListModifiersTest<std_list_type>::val_);

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, pop_front) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  std_list b = ListModifiersTest<std_list_type>::init_list_;

  a.pop_front();
  b.pop_front();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, merge_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  a.merge(c);
  b.merge(d);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, merge_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_other_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_;

  std_list b = ListModifiersTest<std_list_type>::init_list_other_;
  std_list d = ListModifiersTest<std_list_type>::init_list_;

  a.merge(c);
  b.merge(d);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, merge_3) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  c.merge(a);
  d.merge(b);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_c = c.begin();
  typename std_list::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, merge_4) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  c.merge(a);
  d.merge(b);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_c = c.begin();
  typename std_list::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, merge_5) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d;

  c.merge(a);
  d.merge(b);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_c = c.begin();
  typename std_list::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, merge_6) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_;

  std_list b;
  std_list d = ListModifiersTest<std_list_type>::init_list_;

  c.merge(a);
  d.merge(b);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_c = c.begin();
  typename std_list::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, merge_7) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_;

  std_list d = ListModifiersTest<std_list_type>::init_list_;

  c.merge(c);
  d.merge(d);

  EXPECT_EQ(c.size(), d.size());

  typename stlb_list::iterator iter_c = c.begin();
  typename std_list::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, splice_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_a = a.begin();

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_b = b.begin();

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, splice_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_c = c.begin();

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_d = d.begin();

  c.splice(iter_c, a);
  d.splice(iter_d, b);

  iter_c = c.begin();
  iter_d = d.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, splice_3) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_a = a.begin();
  ++iter_a;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_b = b.begin();
  ++iter_b;

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, splice_4) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_c = c.begin();
  ++iter_c;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_d = d.begin();
  ++iter_d;

  c.splice(iter_c, a);
  d.splice(iter_d, b);

  iter_c = c.begin();
  iter_d = d.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, splice_5) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_a = a.end();
  --iter_a;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_b = b.end();
  --iter_b;

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, splice_6) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_c = c.end();
  --iter_c;

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_d = d.end();
  --iter_d;

  c.splice(iter_c, a);
  d.splice(iter_d, b);

  iter_c = c.begin();
  iter_d = d.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, splice_7) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_a = a.end();

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_b = b.end();

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, splice_8) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_other_;

  typename stlb_list::iterator iter_c = c.end();

  std_list b = ListModifiersTest<std_list_type>::init_list_;
  std_list d = ListModifiersTest<std_list_type>::init_list_other_;

  typename std_list::iterator iter_d = d.end();

  c.splice(iter_c, a);
  d.splice(iter_d, b);

  iter_c = c.begin();
  iter_d = d.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }
}

TYPED_TEST(ListModifiersTest, splice_9) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a;
  stlb_list c = ListModifiersTest<stlb_list_type>::init_list_;

  typename stlb_list::iterator iter_a = a.begin();

  std_list b;
  std_list d = ListModifiersTest<std_list_type>::init_list_;

  typename std_list::iterator iter_b = b.begin();

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, splice_10) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  stlb_list a;
  stlb_list c;

  typename stlb_list::iterator iter_a = a.begin();

  std_list b;
  std_list d;

  typename std_list::iterator iter_b = b.begin();

  a.splice(iter_a, c);
  b.splice(iter_b, d);

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(c.size(), d.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, reverse_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  std_list b = ListModifiersTest<std_list_type>::init_list_;

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  a.reverse();
  b.reverse();

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, reverse_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_other_;
  std_list b = ListModifiersTest<std_list_type>::init_list_other_;

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  a.reverse();
  b.reverse();

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, reverse_3) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  stlb_list a;
  std_list b;

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  a.reverse();
  b.reverse();

  iter_a = a.begin();
  iter_b = b.begin();

  EXPECT_EQ(a.size(), b.size());

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, unique_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_1_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_1_;

  a.unique();
  b.unique();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, unique_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_2_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_2_;

  a.unique();
  b.unique();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, unique_3) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_3_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_3_;

  a.unique();
  b.unique();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, unique_4) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  stlb_list a;
  std_list b;

  a.unique();
  b.unique();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_1) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_1_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_1_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_2) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_2_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_2_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_3) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_uniq_3_;
  std_list b = ListModifiersTest<std_list_type>::init_list_uniq_3_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_4) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_sort_1_;
  std_list b = ListModifiersTest<std_list_type>::init_list_sort_1_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_5) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_sort_2_;
  std_list b = ListModifiersTest<std_list_type>::init_list_sort_2_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_6) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  stlb_list a;
  std_list b;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_7) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_;
  std_list b = ListModifiersTest<std_list_type>::init_list_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, sort_8) {
  using stlb_list = typename TypeParam::first_type;
  using std_list = typename TypeParam::second_type;

  using stlb_list_type = typename stlb_list::value_type;
  using std_list_type = typename std_list::value_type;

  stlb_list a = ListModifiersTest<stlb_list_type>::init_list_other_;
  std_list b = ListModifiersTest<std_list_type>::init_list_other_;

  a.sort();
  b.sort();

  typename stlb_list::iterator iter_a = a.begin();
  typename std_list::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, insert_many_front_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a =
      ListModifiersTest<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListModifiersTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert_many_front(ListModifiersTest<stlb_type>::val_1_,
                      ListModifiersTest<stlb_type>::val_2_,
                      ListModifiersTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListModifiersTest<std_type>::val_1_,
                    ListModifiersTest<std_type>::val_2_,
                    ListModifiersTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListModifiersTest, insert_many_front_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a;
  std_list_vector b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert_many_front(ListModifiersTest<stlb_type>::val_1_,
                      ListModifiersTest<stlb_type>::val_2_,
                      ListModifiersTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListModifiersTest<std_type>::val_1_,
                    ListModifiersTest<std_type>::val_2_,
                    ListModifiersTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}
