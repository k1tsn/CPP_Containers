// -- ---------------------------------------------------------------------- --
//            Tests for reserve, capacity, shrink_to_fit (Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>

#include "../../src/containers.h"

template <typename T>
class VectorCapacityTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static T val_;
};

// ________________________________init_list___________________________________

template <>
std::initializer_list<int> VectorCapacityTest<int>::init_list_{10, 33, 56, -1};

template <>
std::initializer_list<char> VectorCapacityTest<char>::init_list_{'l', 'i', 's',
                                                                 't'};

template <>
std::initializer_list<std::string> VectorCapacityTest<std::string>::init_list_{
    "list", "aboba", "miu"};

// ____________________________________________________________________________

template <>
int VectorCapacityTest<int>::val_{10};

template <>
char VectorCapacityTest<char>::val_{'y'};

template <>
std::string VectorCapacityTest<std::string>::val_{"hru"};

using MyTypes = ::testing::Types<
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;
TYPED_TEST_SUITE(VectorCapacityTest, MyTypes);

TYPED_TEST(VectorCapacityTest, reserve) {
  using stlb_vector = typename TypeParam::first_type;
  using std_vector = typename TypeParam::second_type;

  using stlb_vector_type = typename stlb_vector::value_type;
  using std_vector_type = typename std_vector::value_type;

  stlb_vector a = VectorCapacityTest<stlb_vector_type>::init_list_;
  std_vector b = VectorCapacityTest<std_vector_type>::init_list_;

  size_t size_a = a.size();
  size_t size_b = b.size();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  a.reserve(size_a + 10);
  b.reserve(size_b + 10);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a[i], b[i]);
}

TYPED_TEST(VectorCapacityTest, capacity_1) {
  using stlb_vector = typename TypeParam::first_type;
  using std_vector = typename TypeParam::second_type;

  using stlb_vector_type = typename stlb_vector::value_type;
  using std_vector_type = typename std_vector::value_type;

  stlb_vector a = VectorCapacityTest<stlb_vector_type>::init_list_;
  std_vector b = VectorCapacityTest<std_vector_type>::init_list_;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  typename stlb_vector::iterator iter_a = a.begin();
  typename std_vector::iterator iter_b = b.begin();
  a.insert(iter_a, VectorCapacityTest<stlb_vector_type>::val_);
  b.insert(iter_b, VectorCapacityTest<std_vector_type>::val_);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a[i], b[i]);
}

TYPED_TEST(VectorCapacityTest, capacity_2) {
  using stlb_vector = typename TypeParam::first_type;
  using std_vector = typename TypeParam::second_type;

  using stlb_vector_type = typename stlb_vector::value_type;
  using std_vector_type = typename std_vector::value_type;

  stlb_vector a;
  std_vector b;

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  typename stlb_vector::iterator iter_a = a.begin();
  typename std_vector::iterator iter_b = b.begin();

  a.insert(iter_a, VectorCapacityTest<stlb_vector_type>::val_);
  b.insert(iter_b, VectorCapacityTest<std_vector_type>::val_);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a[i], b[i]);
}

TYPED_TEST(VectorCapacityTest, shrink_to_fit) {
  using stlb_vector = typename TypeParam::first_type;
  using std_vector = typename TypeParam::second_type;

  using stlb_vector_type = typename stlb_vector::value_type;
  using std_vector_type = typename std_vector::value_type;

  stlb_vector a = VectorCapacityTest<stlb_vector_type>::init_list_;
  std_vector b = VectorCapacityTest<std_vector_type>::init_list_;

  size_t size_a = a.size();
  size_t size_b = b.size();

  a.reserve(size_a + 10);
  b.reserve(size_b + 10);

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  a.shrink_to_fit();
  b.shrink_to_fit();

  EXPECT_EQ(a.size(), b.size());
  EXPECT_EQ(a.capacity(), b.capacity());

  for (size_t i = 0; i < a.size(); ++i) EXPECT_EQ(a[i], b[i]);
}
