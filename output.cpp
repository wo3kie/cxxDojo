/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/output
 */

#include "./output.hpp"

void output_tests() {
  {
    std::ostringstream oss;
    oss << std::vector<int>();
    Assert(std::string("[]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::vector<int>{1};
    Assert(std::string("[1]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::vector<int>{1, 2};
    Assert(std::string("[1, 2]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::vector<int>{1, 2, 3};
    Assert(std::string("[1, 2, 3]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::array<int, 0>();
    Assert(std::string("[]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::array<int, 1>{1};
    Assert(std::string("[1]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::array<int, 2>{1, 2};
    Assert(std::string("[1, 2]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::array<int, 3>{1, 2, 3};
    Assert(std::string("[1, 2, 3]") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::list<int>();
    Assert(std::string("()") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::list<int>{1};
    Assert(std::string("(1)") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::list<int>{1, 2};
    Assert(std::string("(1, 2)") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::list<int>{1, 2, 3};
    Assert(std::string("(1, 2, 3)") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::make_pair(1, 2);
    Assert(std::string("{1, 2}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::map<int, int>();
    Assert(std::string("{}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}};
    Assert(std::string("{{1, 2}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}, {3, 4}};
    Assert(std::string("{{1, 2}, {3, 4}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::map<int, int>{{1, 2}, {3, 4}, {5, 6}};
    Assert(std::string("{{1, 2}, {3, 4}, {5, 6}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::set<int>();
    Assert(std::string("{}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::set<int>{1};
    Assert(std::string("{1}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::set<int>{1, 2};
    Assert(std::string("{1, 2}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::set<int>{1, 2, 3};
    Assert(std::string("{1, 2, 3}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_map<int, int>();
    Assert(std::string("{}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_map<int, int>{{1, 2}};
    Assert(std::string("{{1, 2}}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_set<int>();
    Assert(std::string("{}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::unordered_set<int>{1};
    Assert(std::string("{1}") == oss.str());
  }

  {
    std::ostringstream oss;
    oss << std::make_tuple(1, 'b', 3.3);
    Assert(std::string("(1, b, 3.3)") == oss.str());
  }
}

/*
 * main
 */

int main() {
  output_tests();
}
