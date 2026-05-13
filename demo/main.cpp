#include <lab07_solver/quadratic.hpp>

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

namespace {

double read_arg(char const* value)
{
  std::size_t processed = 0;
  const std::string text{value};
  const double result = std::stod(text, &processed);

  if (processed != text.size())
  {
    throw std::invalid_argument("argument is not a number");
  }

  return result;
}

} // namespace

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "usage: demo <a> <b> <c>" << std::endl;
    return 1;
  }

  try
  {
    const auto roots = lab07_solver::solve_quadratic(
      read_arg(argv[1]),
      read_arg(argv[2]),
      read_arg(argv[3])
    );

    std::cout << std::fixed << std::setprecision(6);
    if (roots.empty())
    {
      std::cout << "no real roots" << std::endl;
      return 0;
    }

    for (const auto root : roots)
    {
      std::cout << root << std::endl;
    }
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what() << std::endl;
    return 2;
  }
}
