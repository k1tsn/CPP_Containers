// -- ---------------------------------------------------------------------- --
//                       Tests for at, data, [] (Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <string>
#include <utility>

#include "../../src/containers.h"

template <typename T>
class VectorAccessTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static T val_;
  static T other_val_;
};

template <>
std::initializer_list<int> VectorAccessTest<int>::init_list_{1, 2, 3, 4};

template <>
std::initializer_list<char> VectorAccessTest<char>::init_list_{'l', 'i', 's',
                                                               't'};

template <>
std::initializer_list<std::string> VectorAccessTest<std::string>::init_list_{
    "list", "aboba", "miu"};

template <>
int VectorAccessTest<int>::val_{54};

template <>
char VectorAccessTest<char>::val_{'y'};

template <>
std::string VectorAccessTest<std::string>::val_{"utka"};

template <>
int VectorAccessTest<int>::other_val_{-80};

template <>
char VectorAccessTest<char>::other_val_{'p'};

template <>
std::string VectorAccessTest<std::string>::other_val_{"weapon"};

using MyTypes = ::testing::Types<
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;

TYPED_TEST_SUITE(VectorAccessTest, MyTypes);

TYPED_TEST(VectorAccessTest, at) {
  using stlb_vec = typename TypeParam::first_type;
  using std_vec = typename TypeParam::second_type;

  using stlb_vec_type = typename stlb_vec::value_type;
  using std_vec_type = typename std_vec::value_type;

  stlb_vec a = VectorAccessTest<stlb_vec_type>::init_list_;
  std_vec b = VectorAccessTest<std_vec_type>::init_list_;

  EXPECT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a.at(i), b.at(i));

  a.at(0) = VectorAccessTest<stlb_vec_type>::val_;
  b.at(0) = VectorAccessTest<std_vec_type>::val_;

  a.at(2) = VectorAccessTest<stlb_vec_type>::other_val_;
  b.at(2) = VectorAccessTest<std_vec_type>::other_val_;

  EXPECT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a.at(i), b.at(i));
}

TYPED_TEST(VectorAccessTest, at_2) {
  using stlb_vec = typename TypeParam::first_type;
  using std_vec = typename TypeParam::second_type;

  using stlb_vec_type = typename stlb_vec::value_type;
  using std_vec_type = typename std_vec::value_type;

  const stlb_vec a = VectorAccessTest<stlb_vec_type>::init_list_;
  const std_vec b = VectorAccessTest<std_vec_type>::init_list_;

  EXPECT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a.at(i), b.at(i));
}

TYPED_TEST(VectorAccessTest, subscript_operator) {
  using stlb_vec = typename TypeParam::first_type;
  using std_vec = typename TypeParam::second_type;

  using stlb_vec_type = typename TypeParam::first_type::value_type;
  using std_vec_type = typename TypeParam::second_type::value_type;

  stlb_vec a = VectorAccessTest<stlb_vec_type>::init_list_;
  std_vec b = VectorAccessTest<std_vec_type>::init_list_;

  EXPECT_EQ(a.size(), b.size());
  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a[i], b[i]);
}

TYPED_TEST(VectorAccessTest, data) {
  using stlb_vec = typename TypeParam::first_type;
  using std_vec = typename TypeParam::second_type;

  using stlb_vec_type = typename TypeParam::first_type::value_type;
  using std_vec_type = typename TypeParam::second_type::value_type;

  stlb_vec a = VectorAccessTest<stlb_vec_type>::init_list_;
  std_vec b = VectorAccessTest<std_vec_type>::init_list_;

  stlb_vec_type* stlb_ptr = a.data();
  std_vec_type* std_ptr = b.data();

  for (; stlb_ptr != a.end(); ++stlb_ptr, ++std_ptr) {
    EXPECT_EQ(*stlb_ptr, *std_ptr);
  }
}

TYPED_TEST(VectorAccessTest, const_begin_end) {
  using stlb_vec = typename TypeParam::first_type;
  using std_vec = typename TypeParam::second_type;

  using stlb_vec_type = typename TypeParam::first_type::value_type;
  using std_vec_type = typename TypeParam::second_type::value_type;

  const stlb_vec a = VectorAccessTest<stlb_vec_type>::init_list_;
  const std_vec b = VectorAccessTest<std_vec_type>::init_list_;

  typename stlb_vec::const_iterator iter_a_b = a.begin();
  typename std_vec::const_iterator iter_b_b = b.begin();

  EXPECT_EQ(*iter_a_b, *iter_b_b);

  typename stlb_vec::const_iterator iter_a_e = a.end();
  typename std_vec::const_iterator iter_b_e = b.end();
  EXPECT_EQ(*--iter_a_e, *--iter_b_e);
}
