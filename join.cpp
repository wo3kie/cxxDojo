

#include "./join.hpp"
#include "./assert.hpp"

#include <vector>

/*
 * test_join_ranges
 */

void test_join_ranges() {
  auto NonEmpty = [](std::string_view s) -> bool {
    return ! s.empty();
  };

  Assert(join(std::vector<std::string>{""}, '|') == "");
  Assert(join(std::vector<std::string>{""} | std::views::filter(NonEmpty), '|') == "");

  Assert(join(std::vector<std::string>{"", ""}, '|') == "|");
  Assert(join(std::vector<std::string>{"", ""} | std::views::filter(NonEmpty), '|') == "");

  Assert(join(std::vector<std::string>{"Hello", ""}, '|') == "Hello|");
  Assert(join(std::vector<std::string>{"Hello", ""} | std::views::filter(NonEmpty), '|') == "Hello");

  Assert(join(std::vector<std::string>{"", "World"}, '|') == "|World");
  Assert(join(std::vector<std::string>{"", "World"} | std::views::filter(NonEmpty), '|') == "World");

  Assert(join(std::vector<std::string>{"", "", ""}, '|') == "||");
  Assert(join(std::vector<std::string>{"", "", ""} | std::views::filter(NonEmpty), '|') == "");

  Assert(join(std::vector<std::string>{"Hello", "", ""}, '|') == "Hello||");
  Assert(join(std::vector<std::string>{"Hello", "", ""} | std::views::filter(NonEmpty), '|') == "Hello");

  Assert(join(std::vector<std::string>{"", "World", ""}, '|') == "|World|");
  Assert(join(std::vector<std::string>{"", "World", ""} | std::views::filter(NonEmpty), '|') == "World");

  Assert(join(std::vector<std::string>{"", "", "!"}, '|') == "||!");
  Assert(join(std::vector<std::string>{"", "", "!"} | std::views::filter(NonEmpty), '|') == "!");
}

/*
 * test_join_variadic
 */

void test_join_variadic() {
  Assert(join(/* skip_empty */ false, /* sep */ '|', "") == "");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "") == "");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "", "") == "|");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "", "") == "");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "Hello", "") == "Hello|");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "Hello", "") == "Hello");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "", "World") == "|World");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "", "World") == "World");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "", "", "") == "||");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "", "", "") == "");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "Hello", "", "") == "Hello||");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "Hello", "", "") == "Hello");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "", "World", "") == "|World|");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "", "World", "") == "World");

  Assert(join(/* skip_empty */ false, /* sep */ '|', "", "", "!") == "||!");
  Assert(join(/* skip_empty */ true, /* sep */ '|', "", "", "!") == "!");
}

/*
 * main
 */

int main() {
  test_join_ranges();
  test_join_variadic();
  return 0;
}