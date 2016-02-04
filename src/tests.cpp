#include <tuple>
#include <gtest/gtest.h>

#include "point.hpp"
#
typedef std::tuple<int, int, int> Pos;
TEST(subtract, PositiveNos){
  Point a(0,0,0);
  Point b(1, 2, 3);
  Vector c = a-b;
  Vector d(-1, -2, -3);
  ASSERT_EQ(1,1);
}

/*
int main(int argc, char**argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/
