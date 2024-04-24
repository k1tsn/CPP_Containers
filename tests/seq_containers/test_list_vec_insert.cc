// -- ---------------------------------------------------------------------- --
//                   Tests for insert_many (List | Vector)
// -- ---------------------------------------------------------------------- --

#include <gtest/gtest.h>

#include <initializer_list>
#include <list>
#include <string>

#include "../../src/containers.h"

template <typename T>
class ListVectorInsertTest : public testing::Test {
 public:
  static std::initializer_list<T> init_list_;
  static std::initializer_list<T> init_list_other_;
  static T val_1_;
  static T val_2_;
  static T val_3_;
};

template <>
std::initializer_list<int> ListVectorInsertTest<int>::init_list_{10, 33, 56,
                                                                 -1};

template <>
std::initializer_list<char> ListVectorInsertTest<char>::init_list_{'l', 'i',
                                                                   's', 't'};

template <>
std::initializer_list<std::string>
    ListVectorInsertTest<std::string>::init_list_{"list", "aboba", "miu"};

template <>
std::initializer_list<int> ListVectorInsertTest<int>::init_list_other_{
    3, 6, 10, 8, 2, -19, -5};

template <>
std::initializer_list<char> ListVectorInsertTest<char>::init_list_other_{
    'k', 'o', 's', 'h', 'k', 'a'};

template <>
std::initializer_list<std::string>
    ListVectorInsertTest<std::string>::init_list_other_{
        "AoaoaoaoOAAAO", "KoSHka", "porta", "noche"};

template <>
int ListVectorInsertTest<int>::val_1_{10};

template <>
char ListVectorInsertTest<char>::val_1_{'y'};

template <>
std::string ListVectorInsertTest<std::string>::val_1_{"hru"};

template <>
int ListVectorInsertTest<int>::val_2_{67};

template <>
char ListVectorInsertTest<char>::val_2_{'h'};

template <>
std::string ListVectorInsertTest<std::string>::val_2_{"red"};

template <>
int ListVectorInsertTest<int>::val_3_{-12};

template <>
char ListVectorInsertTest<char>::val_3_{'s'};

template <>
std::string ListVectorInsertTest<std::string>::val_3_{"black"};

using MyTypes = ::testing::Types<
    std::pair<stlb::list<char>, std::list<char>>,
    std::pair<stlb::list<int>, std::list<int>>,
    std::pair<stlb::list<std::string>, std::list<std::string>>,
    std::pair<stlb::vector<char>, std::vector<char>>,
    std::pair<stlb::vector<int>, std::vector<int>>,
    std::pair<stlb::vector<std::string>, std::vector<std::string>>>;
TYPED_TEST_SUITE(ListVectorInsertTest, MyTypes);

TYPED_TEST(ListVectorInsertTest, insert_many_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a =
      ListVectorInsertTest<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorInsertTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert_many(iter_a, ListVectorInsertTest<stlb_type>::val_1_,
                ListVectorInsertTest<stlb_type>::val_2_,
                ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorInsertTest, insert_many_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a =
      ListVectorInsertTest<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorInsertTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.end();
  typename std_list_vector::iterator iter_b = b.end();

  a.insert_many(iter_a, ListVectorInsertTest<stlb_type>::val_1_,
                ListVectorInsertTest<stlb_type>::val_2_,
                ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorInsertTest, insert_many_3) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a =
      ListVectorInsertTest<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorInsertTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  ++iter_a;
  ++iter_b;

  a.insert_many(iter_a, ListVectorInsertTest<stlb_type>::val_1_,
                ListVectorInsertTest<stlb_type>::val_2_,
                ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorInsertTest, insert_many_4) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a;
  std_list_vector b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.begin();

  a.insert_many(iter_a, ListVectorInsertTest<stlb_type>::val_1_,
                ListVectorInsertTest<stlb_type>::val_2_,
                ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorInsertTest, insert_many_back_1) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a =
      ListVectorInsertTest<typename stlb_list_vector::value_type>::init_list_;

  std_list_vector b =
      ListVectorInsertTest<typename std_list_vector::value_type>::init_list_;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.end();

  a.insert_many_back(ListVectorInsertTest<stlb_type>::val_1_,
                     ListVectorInsertTest<stlb_type>::val_2_,
                     ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}

TYPED_TEST(ListVectorInsertTest, insert_many_back_2) {
  using stlb_list_vector = typename TypeParam::first_type;
  using std_list_vector = typename TypeParam::second_type;

  using stlb_type = typename stlb_list_vector::value_type;
  using std_type = typename stlb_list_vector::value_type;

  stlb_list_vector a;
  std_list_vector b;

  typename stlb_list_vector::iterator iter_a = a.begin();
  typename std_list_vector::iterator iter_b = b.end();

  a.insert_many_back(ListVectorInsertTest<stlb_type>::val_1_,
                     ListVectorInsertTest<stlb_type>::val_2_,
                     ListVectorInsertTest<stlb_type>::val_3_);
  b.insert(iter_b, {ListVectorInsertTest<std_type>::val_1_,
                    ListVectorInsertTest<std_type>::val_2_,
                    ListVectorInsertTest<std_type>::val_3_});

  iter_a = a.begin();
  iter_b = b.begin();
  for (; iter_a != a.end(); ++iter_a, ++iter_b) {
    EXPECT_EQ(*iter_a, *iter_b);
  }
}
