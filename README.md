### Copyright (C) 2015 Łukasz Czerwiński

# CxxDojo
Solutions to selected programming puzzles.  
  
## Website
https://github.com/wo3kie/cxxdojo

## Requirements
C++20  
boost  
gsl  
  
## How to build it?
mkdir build  
cd build  
cmake ..  
cmake --build .  

## How to clean it?
rm -rf build

## List of puzzles
  
### aho_corasick.cpp  
Implement the Aho-Corasick algorithm.
  
From [Wikipedia](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm), the Aho-Corasick algorithm can be used to locate elements of a finite set of strings (the "dictionary") within an input text.
  
```
$ ./aho_corasick aho_corasick.dct aho_corasick.cpp
--------------------------------------------------------------------------------
>     auto const print = []( size_t const pos, std::string const & word ){
>     auto
>          const
>                  int
>                                   const
>                                                          const
>                                                                   or
--------------------------------------------------------------------------------
```
  
### allocator.cpp  
Implement a simple allocator. Follow `std::allocator` as an example.
  
### apply.cpp  
Demonstrates usage of a custom `apply` function. From [cppreference](https://en.cppreference.com/w/cpp/utility/apply.html) `std::apply` function invokes a callable object `f` with the elements of the tuple `t` expanded to it as parameters.
  
```{r, engine='cpp'}
void f(int, float, char){ /* ... */ }
auto t = std::make_tuple(1, 2.2, '3');
apply(f, t);
```
  
### assert.cpp  
Implement an improved `assert` utility that accepts a simple conditional expression (`==`, `!=`, `<=`, `<`, `>=`, `>`) and, upon failure, prints both the _actual_ and _expected_ values.
  
```{r, engine='bash'}
$ cat assert.cpp
#include "./assert.hpp"
int main() {
  int a = 1;
  int b = 2;
  Assert(a == b);
}

$ make assert

$ ./bin/assert 
cxxDojo/assert.cpp:5 Assertion failed 1 == 2
```
  
### async.cpp  
Demonstrates parallel computation using `std::async` to find the minimum and maximum elements in a range.
  
```{r, engine='cpp'}
assert(min_max({1, 2, 3, 4, 5}) == {1, 5});
```
  
### base64.cpp  
Implement a program to do _base64_ encoding/decoding. From [Wikipedia](https://en.wikipedia.org/wiki/Base64) _base64_ is encoding scheme that transforms binary data into a sequence of printable characters, limited to a set of 64 unique characters.
  
```{r, engine='bash'}
$ ./base64.encode "Hello World"
SGVsbG8gV29ybGQ
  
$ ./base64.decode SGVsbG8gV29ybGQ
Hello World
```
  
### bayes.cpp  
Implement a simple program for _ham_/_spam_ messages classification. Use the naive Bayes approach.
  
From [Wikipedia](https://en.wikipedia.org/wiki/Naive_Bayes_classifier), naive Bayes classifiers are a family of simple probabilistic classifiers based on applying Bayes theorem with strong (naive) independence assumptions between the features.
  
### bellman_ford.cpp  
Implement the Bellman-Ford algorithm.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm), the Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph.  
  
### black_scholes.cpp  
Calculate an option price for a given time and underlying stock price using _Black-Scholes_ method for it.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Black%E2%80%93Scholes_model), the Black–Scholes model is a mathematical model for the dynamics of a financial market containing derivative investment instruments.  
  
### bloom_filter.cpp  
Implement a Bloom filter.

From [Wikipedia](https://en.wikipedia.org/wiki/Bloom_filter), a Bloom filter is a space-efficient probabilistic data structure with false positive matches possible but false negatives not.
  
### box_muller.cpp  
Implement the Box-Muller algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform), the Box-Muller algorithm can transform uniformly distributed random numbers into standard, normally distributed N(0, 1) (expected value 0, standard deviation 1) random numbers.
  
### circular_buffer.cpp  
Implement a circular buffer.
  
### concurent_queue.cpp  
Design and implement a thread-safe queue with bounded capacity. The queue should support concurrent access from multiple threads. If a thread attempts to enqueue an item when the queue is full, it must be blocked until space becomes available. Similarly, if a thread tries to dequeue an item from an empty queue, it should be blocked until an item is available.
  
### concat_view.cpp  
Implement a simple version of `std::concat_view`. From [cppreference](https://en.cppreference.com/w/cpp/ranges/concat_view.html) the `concat_view` takes an arbitrary number of ranges as an argument list, and provides a view that starts at the first element of the first range, ends at the last element of the last range, with all range elements sequenced in between respectively in the order given in the arguments, effectively concatenating, or chaining together the argument ranges. 
  
### concepts.cpp  
Implement some C++ `std`-like concepts examples demonstrating some different syntax. 
  
### convert_base.cpp  
Implement a function that converts a number from one numeric base to another.
  
```
assert(convertBase("101010", 2, 8) == "52");
assert(convertBase("52", 8, 10) == "42");
assert(convertBase("42", 10, 16) == "2A");
assert(convertBase("2A", 16, 2) == "101010");
```
  
### copy_vs_move.cpp  
Compare function calls passing arguments by value, by reference, and by ref ref.
  
### correlation.cpp  
Implement a function to calculate the correlation between two collections using.
  
### covariance.cpp  
Implement a function to calculate the covariance between two collections.
  
### count_bits.cpp  
Implement a program to count the number of `1` bits in a given integer.  
Can you use `constexpr` to achieve this?  
Can you use `preprocessor` to achieve this?  
  
### crtp.cpp  
Implement the CRTP pattern example.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) the Curiously Recurring Template Pattern is a C++ idiom to express static polymorphism. More formally is it known as F-bound polymorphism.
  
### ctad.cpp  
Implement some examples showing class template argument deduction (CTAD) usage.  
  
### dijkstra.cpp  
Implement Dijkstra algorithm.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) the Dijkstra algorithm is a procedure for finding the shortest paths between nodes in a weighted graph.
  
### entropy.cpp  
Write a program to compute the entropy of a given sequence.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Entropy_(information_theory)) the entropy of a random variable quantifies the average level of uncertainty or information associated with the variable's potential states or possible outcomes.
  
### enumerate_view.cpp  
Implement a simple version of `std::enumerate_view`. From [cppreference](https://en.cppreference.com/w/cpp/ranges/enumerate_view.html) the `enumerate_view` is a range adaptor that takes a view and produces a view of tuples which holds: the value which is a zero-based index of the element of underlying sequence, and the reference to the underlying element.  
  
### exec.cpp  
Implement a function to run shell commands and capture their output, including support for long-running processes.
  
### exponential_smoothing.cpp  
Implement a function to perform exponential smoothing average (EMA) on a given sequence using a specified alpha parameter. From [Wikipedia](https://en.wikipedia.org/wiki/Exponential_smoothing) the EMA is a technique for smoothing time series data using the exponential window function, where exponential functions are used to assign exponentially decreasing weights over time.
  
### fdm.cpp  
Implement a program demonstrating a Finite Difference Method to calculate differential equation.
  
### filter_view.cpp  
Implement a simple version of `std::filter_view`. From [cppreference](https://en.cppreference.com/w/cpp/ranges/filter_view.html) the `filter_view` is a range adaptor that represents view of an underlying sequence with only the elements that satisfy the predicate. 
  
```{r, engine='cpp'}
// pseudocode
assert(filter_view({1, 2, 3, 4, 5}, isEven) == {2, 4});
```
  
### feq.cpp  
Create a function to compare two floating-point values within a given tolerance.
  
```{r, engine='cpp'}
assert(feq(0.1f + 0.2f, 0.3f));
assert(feq(0.1 + 0.2, 0.3));
assert(feq(0.1l + 0.2l, 0.3l));

assert(0.1f + 0.2f == approx(0.3f));
assert(0.1 + 0.2 == approx(0.3));
assert(0.1l + 0.2l == approx(0.3l));
```
  
### find_union.cpp  
Implement a find-union algorithm.  
  
### find.root.cpp  
Implement a program to find the root of a function using the bisection and Newton's methods.
  
### float_formatter.cpp  
Implement a function that formats a floating-point number to fit within a fixed number of characters.
  
```{r, engine='cpp'}
assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");
```
  
### floyd_warshall.cpp  
Implement Floyd-Warshall algorithm. From [Wikipedia](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) the Floyd–Warshall algorithm is a procedure for finding shortest paths in a directed weighted graph with positive or negative edge weights but with no negative cycles.
  
### fold_expression.cpp  
Implement simple examples that demonstrate how to use C++17 fold expressions.  
  
### functional.cpp  
Implement higher-order functions such as `fold`, `reduce`, and `filter`.
  
### gcd.cpp  
Implement a function to calculate the greatest common divisor.
  
### gram_schmidt.cpp  
Implement the Gram-Schmidt process function. From [Wikipedia](https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process) the Gram-Schmidt algorithm is a way of finding a set of two or more vectors that are perpendicular to each other.
  
### group_by.cpp  
Implement a `group_by` function, for aggregating data into a dictionary by a given key.

### gsl/correlation.cpp  
Implement a function to calculate the correlation between two collections using gsl library.

### gsl/covariance.cpp  
Implement a function to calculate the covariance between two collections using gsl library.
  
### gsl/interpolation.cpp  
Implement a program to interpolate a set of points with a polynomial function. Can you use boost::ublas for it? Can you use GNU Scientific Library for it?

### gsl/mean.cpp  
Implement a function to calculate a mean value from a collection.

### gsl/page_rank.cpp  
Implement the Page Rank algorithm using eigenvalues and eigenvectors. 
  
### gsl/pca.cpp  
Implement Principal Component Analysis using gsl library. From [Wikipedia](https://en.wikipedia.org/wiki/Principal_component_analysis) principal component analysis is a procedure to transform a given data set _X_ of dimension _p_ to an alternative data set _Y_ of smaller dimension _p'_.
  
### gsl/variance.cpp  
Implement a function to calculate a variance. From [Wikipedia](https://en.wikipedia.org/wiki/Variance) variance is a measure how far a values are spread out.
  
### gzip.cpp  
Implement a function to compress and decompress text using the _gzip_ algorithm.
  
### hanoi.cpp  
Implement a program to solve the Tower of Hanoi problem.

```{r, engine='bash'}
$ ./hanoi 3
Move from 1 to 2
Move from 1 to 3
Move from 2 to 3
Move from 1 to 2
Move from 3 to 1
Move from 3 to 2
Move from 1 to 2
```
  
### has_type.cpp  
Implement various methods to determine whether a given class contains a nested internal type.  
  
### heap.cpp  
Implement the heap data structure.
  
### in.cpp  
Implement _in_ operator in C++. Follow the idea of [named-operators](https://github.com/klmr/named-operator).

```{r, engine='cpp'}
assert(    1 <in> std::vector< int >{ 1 } );
assert( !( 2 <in> std::vector< int >{ 1 } ) );
```
  
### integration.cpp  
Implement a set of functions to calculate numerical integration for a function _f(x)_ in range _(a,b)_.
  
### interpolation.cpp  
Implement a function to interpolate a given set of points with a polynomial. Use Newton's divided difference method.  
  
### is_prime.cpp  
Implement a function to check whether a given number is prime using _Fermat's Little Theorem_ and _Rho-Pollard_ algorithm.
  
### jaccard_index.cpp  
Implement a function to compute the Jaccard Index for two given sets. From [Wikipedia](https://en.wikipedia.org/wiki/Jaccard_index) the Jaccard index is used for comparing the similarity and diversity of sample sets.
  
### knuth_morris_pratt.cpp  
Implement the Knuth-Morris-Pratt text searching algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm), the Knuth-Morris-Pratt algorithm searches ofr occurences od a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

```
$ ./kmp 5 3.14159265359
5 9 11
```
  
### laplace_smoothing.cpp  
Implement a function to perform _the Laplace smoothing_. From [Wikipedia](https://en.wikipedia.org/wiki/Additive_smoothing) the Laplace smoothing, also known as additive smothing (not to be confused with Laplacian smoothing) is a technique used to smooth categorical data.
  
### levenstein.cpp  
Implement the _Levenstein distance_ function.

From [Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance), the Levenstein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other.
  
### linear_regression.cpp  
Implement a function to calcuate linear regression using least squares approach.

From [Wikipedia](https://en.wikipedia.org/wiki/Linear_regression) linear regression is an approach for modelling the relationship between a scalar dependent variable _Y_ and one or more explanatory variables (or independent variables) denoted _X_.
  
### literal.cpp  
Implement used defined literal _bin_ to convert a string of zeros and ones "1010101" into a decimal integer value.

```
assert( 561 == "1000110001"_bin );
assert( 561 == 1000110001_bin );
```
  
### ls.cpp  
Implement a program to print a content of a given directory.

```{r, engine='bash'}
$ ./ls .
F "./get.request.cpp"
F "./par.cpp"
F "./barrier.cpp"
F "./ls.cpp"
F "./scope_exit.cpp"
...
```
  
### mandelbrot.cpp  
Implement a program to print ASCII art of Mandelbrot set fractal.

```
...............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....
.............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,..
............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..........................,,,,,,,,,,,,,,,,,,::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.........................,,,,,,,,,,,,,::::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.......................,,,,,,,,,,:::::::::::::::::::::::;;;;;^;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
......................,,,,,,,,::::::::::::::::::::::;;;;;;^*&.&*^^;;;;;:::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.....................,,,,,,::::::::::::::::::::::;;;;;;;^^^*& ^##.*;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,
....................,,,,,:::::::::::::::::::::;;;;;;;;;^^^^&&#.; #&*^;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,
...................,,,,:::::::::::::::::::::;;;;;;;;;^^^^*#..:. ^ @*^^^;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,
..................,,,,::::::::::::::::::::;;;;;;;;;^^^**&&@:     ;:#*^^^^^;;;;::::::,,,,,,,,,,,,,,,,,,,,,
.................,,,::::::::::::::::::::;;;;;;;;^^****&&&# ;      ,##&****^^;;;:::::::,,,,,,,,,,,,,,,,,,,
.................,,::::::::::::::::::;;;;;;;^^^^*# &^ @,;:&.    ###..@.#&&#^&^;;:::::::,,,,,,,,,,,,,,,,,,
................,,:::::::::::::::::;;;;;^^^^^^**&#.&  &              &.,:^.@.*^;;:::::::,,,,,,,,,,,,,,,,,
...............,,:::::::::::::::;;;^^^^^^^^^***&#@.*                       *#*^^;::::::::,,,,,,,,,,,,,,,,
...............,::::::::::::;;;^****^^^^^****&&  .,                       . #&*^;;::::::::,,,,,,,,,,,,,,,
...............::::::::;;;;;;^^*#;#&&&#@#&&&&##.^                          *;,&^;;;::::::::,,,,,,,,,,,,,,
..............,::::;;;;;;;^^^^**#;,^,.,#:# @@@ &                             .&^;;;::::::::,,,,,,,,,,,,,,
..............::;;;;;;;;^^^^^*&&#@*  @    &^,,;                             &,*^;;;:::::::::,,,,,,,,,,,,,
..............:;;;;;;;;^^^^^*##@,^,          &@                             :#*^;;;;::::::::,,,,,,,,,,,,,
..............;;;;;;;^****&&@*,&;#            ;                             @*^^;;;;::::::::,,,,,,,,,,,,,
..............^^**&@&## ##@,,#                                             #&*^^;;;;::::::::,,,,,,,,,,,,,
..............^^**&@&## ##@,,#                                             #&*^^;;;;::::::::,,,,,,,,,,,,,
..............;;;;;;;^****&&@*,&;#            ;                             @*^^;;;;::::::::,,,,,,,,,,,,,
..............:;;;;;;;;^^^^^*##@,^,          &@                             :#*^;;;;::::::::,,,,,,,,,,,,,
..............::;;;;;;;;^^^^^*&&#@*  @    &^,,;                             &,*^;;;:::::::::,,,,,,,,,,,,,
..............,::::;;;;;;;^^^^**#;,^,.,#:# @@@ &                             .&^;;;::::::::,,,,,,,,,,,,,,
...............::::::::;;;;;;^^*#;#&&&#@#&&&&##.^                          *;,&^;;;::::::::,,,,,,,,,,,,,,
...............,::::::::::::;;;^****^^^^^****&&  .,                       . #&*^;;::::::::,,,,,,,,,,,,,,,
...............,,:::::::::::::::;;;^^^^^^^^^***&#@.*                       *#*^^;::::::::,,,,,,,,,,,,,,,,
................,,:::::::::::::::::;;;;;^^^^^^**&#.&  &              &.,:^.@.*^;;:::::::,,,,,,,,,,,,,,,,,
.................,,::::::::::::::::::;;;;;;;^^^^*# &^ @,;:&.    ###..@.#&&#^&^;;:::::::,,,,,,,,,,,,,,,,,,
.................,,,::::::::::::::::::::;;;;;;;;^^****&&&# ;      ,##&****^^;;;:::::::,,,,,,,,,,,,,,,,,,,
..................,,,,::::::::::::::::::::;;;;;;;;;^^^**&&@:     ;:#*^^^^^;;;;::::::,,,,,,,,,,,,,,,,,,,,,
...................,,,,:::::::::::::::::::::;;;;;;;;;^^^^*#..:. ^ @*^^^;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,
....................,,,,,:::::::::::::::::::::;;;;;;;;;^^^^&&#.; #&*^;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,
.....................,,,,,,::::::::::::::::::::::;;;;;;;^^^*& ^##.*;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,
......................,,,,,,,,::::::::::::::::::::::;;;;;;^*&.&*^^;;;;;:::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.......................,,,,,,,,,,:::::::::::::::::::::::;;;;;^;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.........................,,,,,,,,,,,,,::::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..........................,,,,,,,,,,,,,,,,,,::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,..
...............................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,....
```
  
### map_reduce.cpp  
Implement `map`, `reduce`, `filter` and `to` functions. Follow `std::ranges` and `std::views` patterns, that all can be composed in a pipeline expression.
  
```{r, engine='cpp'}
  // pseudocode

  list<int> list = {1, 2, 3};
  assert(list | Map(square) | Reduce(0) == 1 + 4 + 9);

  map<string, int> map{{"a", 1}, {"bb", 2}, {"ccc", 3}};
  assert(map | Map([](const auto& p) { return p.second; }) | To<std::vector>() == {1, 2, 3})
```
  
### matrix.cpp  
This task involves implementing a simple matrix class and providing essential functionality.
  
### matrix_chain_multiplication.cpp  
From [Wikipedia](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) _the matrix chain multiplication_ is an optimization problem that for given sequence of matrices, the goal is to find the most efficient way to multiply these matrices.
  
### matrix_mul_perf.cpp  
Design a performance benchmark for matrix multiplication, considering various loop nesting orders.

```
$ ./matrix.mul.perf
nmp: 743355µs
npm: 1925037µs
mnp: 721955µs
mpn: 793389µs
pnm: 1738803µs
pmn: 962802µs
```
  
### mean.cpp  
Implement a function to find the mean value of provided numbers.  
  
### mean_squared_error.cpp
Implement a function to calculate _mean squared error (MSE)_. From [Wikipedia](https://en.wikipedia.org/wiki/Mean_squared_error) the MSE is the average squared difference between the estimated values and the true value. 
  
### member_offset.cpp  
Implement a function to calculate struct/class member offert.
  
### metasort.cpp  
Implement a program that demonstrates how to sort numbers inside a `TypeList` using template metaprogramming.  
  
### modexp.cpp  
Implement a function to perform modular exponentiation.
  
### ode.cpp  
Implement a function to solve a first order ordinary differential equation numerically with Euler's and Runge-Kutta methods.
  
### output.cpp  
Implement the output stream operator (`operator<<`) for basic STL containers such as `std::array`, `std::vector`, `std::list`...
  
### overload.cpp  
Create a dispatch mechanism for `overloaded` lambda expressions.
  
### parameter_pack.cpp  
Implement operations that work with template parameter pack—like `size`, `head`, `front`, `tail`, `back`, `any`, `all`, and `none`.
  
### par.cpp  
Create a function to execute shell commands in parallel, inspired by [GNU Parallel](http://www.gnu.org/software/parallel/).

```{r, engine='bash'}
$ echo {1..10} > 1-10-file
$ sed -i 's/ /\n/g' 1-10-file
$
$ cat 1-10-file | ./par echo
140556950165248: 1
140556941772544: 2
140556950165248: 3
140556941772544: 4
140556950165248: 5
140556941772544: 6
140556950165248: 7
140556941772544: 8
140556941772544: 10
140556950165248: 9
```
  
### partition.cpp  
Implement `partition` and `stable_partition` algorithms. 
  
### qr.cpp  
Implement a function to do a QR decomposition of a matrix. From [Wikipedia](https://en.wikipedia.org/wiki/QR_decomposition) QR decomposition is a decomposition of a matrix _A_ into a product _A_=_QR_ of an orthogonal matrix _Q_ and an upper triangular matrix _R_.  
  
### quick_sort.cpp  
Write a `quicksort` implementation. Can any STL utilities be used to simplify the task?
  
### reverse_words.cpp  
Implement a program that reverses the words in a given sentence.
  
### rotate_matrix.cpp  
Implement a program to rotate inplace matrix to right by 90 degrees

```{r, engine='bash'}
1 2 3    7 4 1
4 5 6 -> 8 5 2
7 8 9    9 6 3
```
  
### rotate.cpp  
Implement a function to rotate the contents of a container around a pivot element.  
  
```{r, engine='bash'}
  rotate_left([1 2'3 4 5 6 7]) == [3 4 5 6 7 2 1]
  rotate_right([1 2'3 4 5 6 7]) == [6 7 1 2 3 4 5]
```
  
### scaling.cpp  
Implement the functions for _mean scaling_ and _standard scaling_. From [Wikipedia](https://en.wikipedia.org/wiki/Feature_scaling) scaling is a method used to standardize the range of independent variables of features of data.
  
### set_utils.cpp  
Implement `std::set` and `std::unordered_set` utility functions like _union_, _difference_, _intersection_ and _symmetric difference_.  
  
### scope_exit.cpp  
Implement a scope quard class.

From [open-std](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4189.pdf), a *scope_exit* is a generic RAII wrapper class which ties zero or one resource to a clean-up/completion routine which is bound by scope, ensuring execution at scope exit.

```{r, engine='cpp'}
{
  FILE * file = open("filename.txt", "r");
  auto fileGuard = make_scope_exit(
    [&file](){ close(file); }
  );
  ...
}
```
  
### std_dev.cpp  
Implement a function to calculate the standard deviation of a given container of numbers.  
  
### timer.cpp  
Implement a function to measure an execution time of a some piece of code.

```{r, engine='bash'}
$ ./timer
0
1
2
3
4
5
6
7
8
9
702µs
```
  
### tree_classification.cpp  
Check if a tree is a full tree or a complete tree. A full tree is a tree in which every node other than the leaves has two children. A complete tree is a tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
  
### trie.cpp  
Implement TRIE data structure.  
  
### tuple.cpp  
Implement simple example of a `tuple` class using either composition or inheritance. Next, add some `std::tuple` utilities like `head`, `tail`, `merge`, `foldl`, `foldr`, `hash`, `print`...
  
### type.cpp  
Implement _named type_ utility. The _named type_ is strongly-typed wrappers around existing types to improve code clarity, safety, and maintainability.  
  
```{r, engine='cpp'}
  typedef Type<int> Int;
  typedef Type<int> Age;

  static_assert(std::is_assignable<Int, Age>::value == false);
```
  
### type_erasure_*.cpp  
Implement a program representing the type erasure idiom.

From [Wikibooks](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Erasure) type erasure is a mechanism to provide a type-neutral container that interfaces a variety of concrete types. An example can be an implementation of [boost::any](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html) and also a way how does arbitrary deleter type can be used in [std::shared_ptr](http://en.cppreference.com/w/cpp/memory/shared_ptr).
  
### union_cast.cpp  
Implement union_cast.
  
### variance.cpp
Implement the `variance` function.
  
### virtual_range.cpp  
Implement a program that demonstrates how to integrate C++20 `std::ranges` concepts with _virtual functions_. Since `std::ranges` concepts operate at compile time, while _virtual functions_ enable runtime polymorphism, a direct combination is not possible. To bridge this gap, apply _type erasure_ as a technique for enabling runtime dispatch over range-based constructs.  
  
### visitor.cpp  
Implement an example of the visitor design pattern.
  
From [Wikipedia](https://en.wikipedia.org/wiki/Visitor_pattern) the visitor design pattern is a way of separating an algorithm from an object structure on which it operates.
  
### void_t.cpp  
What is a `void_t` and how it can be useful?
  
### zip_view.cpp  
Implement a simple version of `std::zip_view`. From [cppreference](https://en.cppreference.com/w/cpp/ranges/zip_view.html) the `zip_view` is a range adaptor that takes one or more views, and produces a view whose *i*th element is a tuple-like value consisting of the *i*th elements of all views. All ranges have to be equal size.
  
```{r, engine='cpp'}
  // pseudocode

  list<int> lst = {1, 2, 3};
  deque<int> deq = {4, 5, 6};
  vector<int> vec = {7, 8, 9};
  assert(zip_view{lst, deq, vec} == {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}});
```
  