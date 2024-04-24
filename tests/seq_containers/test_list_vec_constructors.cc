// -- ---------------------------------------------------------------------- --
//        Tests for constructors and overloaded operators (List | Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>
#include <utility>

#include "../../src/containers.h"

template <typename T>
class ListVectorConstructorsTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static std::initializer_list<T> init_list_other_;
};

template <>
std::initializer_list<int> ListVectorConstructorsTest<int>::init_list_{1, 2, 3,
                                                                       4};

template <>
std::initializer_list<char> ListVectorConstructorsTest<char>::init_list_{
    'l', 'i', 's', 't'};

template <>
std::initializer_list<std::string>
    ListVectorConstructorsTest<std::string>::init_list_{"list", "aboba", "miu"};

template <>
std::initializer_list<int> ListVectorConstructorsTest<int>::init_list_other_{
    3, 6, 10, 8, 2, -19, -5};

template <>
std::initializer_list<char> ListVectorConstructorsTest<char>::init_list_other_{
    'k', 'o', 's', 'h', 'k', 'a'};

template <>
std::initializer_list<std::string>
    ListVectorConstructorsTest<std::string>::init_list_other_{
        "AoaoaoaoOAAAO", "KoSHka", "potra", "cheno"};

using MyTypes = ::testing::Types<
    std::pair<stlb::list<char>, std::list<char>>,
    std::pair<stlb::list<int>, std::list<int>>,
    std::pair<stlb::list<std::string>, std::list<std::string>>,
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;

TYPED_TEST_SUITE(ListVectorConstructorsTest, MyTypes);

TYPED_TEST(ListVectorConstructorsTest, Default_constructor) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a;
  std_list_vector b;
  EXPECT_EQ(a.size(), b.size());
}

TYPED_TEST(ListVectorConstructorsTest, Param_constructor) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  stlb_list_vector a(5);
  std_list_vector b(5);
  EXPECT_EQ(a.size(), b.size());
}

TYPED_TEST(ListVectorConstructorsTest, Copy_constructor) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  stlb_list_vector c(a);

  std_list_vector b = ListVectorConstructorsTest<std_list_vec_type>::init_list_;
  std_list_vector d(b);

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename stlb_list_vector::iterator iter_c = c.begin();

  typename std_list_vector::iterator iter_b = b.begin();
  typename std_list_vector::iterator iter_d = d.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b, ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorConstructorsTest, Init_list_constructor) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  std_list_vector b = ListVectorConstructorsTest<std_list_vec_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorConstructorsTest, Move_constructor) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  stlb_list_vector c = std::move(a);
  std_list_vector b = ListVectorConstructorsTest<std_list_vec_type>::init_list_;
  std_list_vector d = std::move(b);

  typename stlb_list_vector::iterator iter_c = c.begin();
  typename std_list_vector::iterator iter_d = d.begin();

  for (; iter_c != c.end(); ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
  }

  typename stlb_list_vector::iterator iter_a = a.begin();
  iter_a = a.insert(iter_a, (typename stlb_list_vector::value_type){});
}

TYPED_TEST(ListVectorConstructorsTest, Move_operator) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  stlb_list_vector b;
  b = std::move(a);

  std_list_vector c = ListVectorConstructorsTest<std_list_vec_type>::init_list_;
  std_list_vector d;
  d = std::move(c);

  typename stlb_list_vector::iterator iter_b = b.begin();
  typename std_list_vector::iterator iter_d = d.begin();

  for (; iter_b != b.end(); ++iter_b, ++iter_d) EXPECT_EQ(*iter_b, *iter_d);
  EXPECT_EQ(a.size(), c.size());
  EXPECT_EQ(d.size(), b.size());

  typename stlb_list_vector::iterator iter_a = a.begin();
  iter_a = a.insert(iter_a, (typename stlb_list_vector::value_type){});
}

TYPED_TEST(ListVectorConstructorsTest, Copy_operator) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  stlb_list_vector c;
  c = a;

  std_list_vector b = ListVectorConstructorsTest<std_list_vec_type>::init_list_;
  std_list_vector d;
  d = b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename stlb_list_vector::iterator iter_c = c.begin();

  typename std_list_vector::iterator iter_b = b.begin();
  typename std_list_vector::iterator iter_d = d.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b, ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorConstructorsTest, Copy_operator_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_list_vec_type = typename stlb_list_vector::value_type;
  using std_list_vec_type = typename std_list_vector::value_type;

  stlb_list_vector a =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_;
  stlb_list_vector c =
      ListVectorConstructorsTest<stlb_list_vec_type>::init_list_other_;
  c = a;

  std_list_vector b = ListVectorConstructorsTest<std_list_vec_type>::init_list_;
  std_list_vector d =
      ListVectorConstructorsTest<std_list_vec_type>::init_list_other_;
  d = b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename stlb_list_vector::iterator iter_c = c.begin();

  typename std_list_vector::iterator iter_b = b.begin();
  typename std_list_vector::iterator iter_d = d.begin();

  for (; iter_a != a.end(); ++iter_a, ++iter_b, ++iter_c, ++iter_d) {
    EXPECT_EQ(*iter_c, *iter_d);
    EXPECT_EQ(*iter_a, *iter_b);
  }
}
