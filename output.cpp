/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 output.cpp -o output
 *
 * Usage:
 *      $ ./output
 */

#include "./output.hpp"

void output_tests() {
  {
    std::ostringstream oss;
    oss << std::vector<int>();
    assert(std::string("[]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::vector<int>{1};
    assert(std::string("[1]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::vector<int>{1, 2};
    assert(std::string("[1,2]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::vector<int>{1, 2, 3};
    assert(std::string("[1,2,3]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::array<int, 0>();
    assert(std::string("[]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::array<int, 1>{1};
    assert(std::string("[1]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::array<int, 2>{1, 2};
    assert(std::string("[1,2]") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::array<int, 3>{1, 2, 3};
    assert(std::string("[1,2,3]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::list<int>();
    assert(std::string("()") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::list<int>{1};
    assert(std::string("(1)") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::list<int>{1, 2};
    assert(std::string("(1,2)") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::list<int>{1, 2, 3};
    assert(std::string("(1,2,3)") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::make_pair(1, 2);
    assert(std::string("{1,2}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::map<int, int>();
    assert(std::string("{}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}};
    assert(std::string("{{1,2}}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}, {3, 4}};
    assert(std::string("{{1,2},{3,4}}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}, {3, 4}, {5, 6}};
    assert(std::string("{{1,2},{3,4},{5,6}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::set<int>();
    assert(std::string("{}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::set<int>{1};
    assert(std::string("{1}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::set<int>{1, 2};
    assert(std::string("{1,2}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::set<int>{1, 2, 3};
    assert(std::string("{1,2,3}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_map<int, int>();
    assert(std::string("{}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::unordered_map<int, int>{{1, 2}};
    assert(std::string("{{1,2}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_set<int>();
    assert(std::string("{}") == oss.str());
  }
  {
    std::ostringstream oss;
    oss << std::unordered_set<int>{1};
    assert(std::string("{1}") == oss.str());
  }
}

int main() {
  output_tests();
}
