#include <lab07_solver/quadratic.hpp>

#include <gtest/gtest.h>

#include <stdexcept>

TEST(Lab07Solver, FindsTwoRoots)
{
  const auto roots = lab07_solver::solve_quadratic(1.0, 0.0, -1.0);

  ASSERT_EQ(roots.size(), 2U);
  EXPECT_DOUBLE_EQ(roots[0], -1.0);
  EXPECT_DOUBLE_EQ(roots[1], 1.0);
}

TEST(Lab07Solver, FindsOneRoot)
{
  const auto roots = lab07_solver::solve_quadratic(1.0, 2.0, 1.0);

  ASSERT_EQ(roots.size(), 1U);
  EXPECT_DOUBLE_EQ(roots[0], -1.0);
}

TEST(Lab07Solver, ReturnsNoRealRoots)
{
  const auto roots = lab07_solver::solve_quadratic(1.0, 0.0, 1.0);

  EXPECT_TRUE(roots.empty());
}

TEST(Lab07Solver, RejectsLinearEquation)
{
  EXPECT_THROW(
    lab07_solver::solve_quadratic(0.0, 2.0, 1.0),
    std::invalid_argument
  );
}
