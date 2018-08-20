#include <gtest/gtest.h>
#include "task3.hpp"
#include "task2.hpp"
#include <tuple>

TEST(task3, print_empty)
{
  print();
}

TEST(task3, print_variable1)
{
  print(45, 4.21, "Hello Test", -56);
}

TEST(task3, print_variable2)
{
  print("Hi", true, 'e', 34, 4.0, 100000000000000000000000000000000.988888886);
}

TEST(task3, print_new_ostream_operator)
{
  point p;
  p.x = 23.0;
  p.y = -12.0;
  print(45, "Hi", p, 34);
}
