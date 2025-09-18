## Copyright (C) 2015 Łukasz Czerwiński

# Dojo
Implementation of some programmic puzzles

## Website
https://github.com/wo3kie/cxxdojo

## Requirements
C++11
boost
xml2
openssl
lua
gsl

## How to build it?
make

## List of puzzles

**aho_corasick.cpp**  
Implement the Aho-Corasick algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm), the Aho-Corasick algorithm can be used to locate elements of a finite set of strings (the "dictionary") within an input text.

```
$ ./ahoCorasick ahoCorasick.dct ahoCorasick.cpp
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

**allocator.cpp**  
Implement a simple allocator. Follow std::allocator as an example.

**apply.cpp**  
Implement a simple version of `std::apply` function. From [cppreference](https://en.cppreference.com/w/cpp/utility/apply.html) `std::apply` function invokes a callable object `f` with the elements of the tuple `t` expanded to it as parameters.

```{r, engine='cpp'}
void f(int, float, char){ /* ... */ }
auto t = std::make_tuple(1, 2.2, '3');
apply(f, t);
```

**async.cpp**  
Implement a recursive `min_max` function that leverages `std::async` to concurrently compute the minimum and maximum values within a given range.

  
```{r, engine='cpp'}
assert(min_max({1, 2, 3, 4, 5}) == {1, 5});
```

**base64.cpp**  
Implement a program to do _base64_ encoding/decoding. From [Wikipedia](https://en.wikipedia.org/wiki/Base64) _base64_ is encoding scheme that transforms binary data into a sequence of printable characters, limited to a set of 64 unique characters.
  
```{r, engine='bash'}
$ ./base64.encode "Hello World"
SGVsbG8gV29ybGQ

$ ./base64.decode SGVsbG8gV29ybGQ
Hello World
```

**bayes.cpp**  
Implement a simple program for _ham_/_spam_ messages classification. Use the naive Bayes approach.

From [Wikipedia](https://en.wikipedia.org/wiki/Naive_Bayes_classifier), naive Bayes classifiers are a family of simple probabilistic classifiers based on applying Bayes theorem with strong (naive) independence assumptions between the features.

**bellman_ford.cpp**  
Implement the Bellman-Ford algorithm.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm), the Bellman–Ford algorithm is an algorithm that computes shortest paths from a single source vertex to all of the other vertices in a weighted digraph.  
  
**black_scholes.cpp**  
Calculate an option price for a given time and underlying stock price using _Black-Scholes_ method for it.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Black%E2%80%93Scholes_model), the Black–Scholes model is a mathematical model for the dynamics of a financial market containing derivative investment instruments.  
  
**bloom_filter.cpp**  
Implement a Bloom filter.

From [Wikipedia](https://en.wikipedia.org/wiki/Bloom_filter), a Bloom filter is a space-efficient probabilistic data structure with false positive matches possible but false negatives not.
  
**box_muller.cpp**  
Implement the Box-Muller algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform), the Box-Muller algorithm can transform uniformly distributed random numbers into standard, normally distributed N(0, 1) (expected value 0, standard deviation 1) random numbers.
  
**concurent_queue.cpp**  
Design and implement a thread-safe queue with bounded capacity. The queue should support concurrent access from multiple threads. If a thread attempts to enqueue an item when the queue is full, it must be blocked until space becomes available. Similarly, if a thread tries to dequeue an item from an empty queue, it should be blocked until an item is available.
  
**concepts.cpp**  
Implement some C++ `std`-like concepts examples demonstrating some different syntax. 
  
**convert_base.cpp**  
Implement a function that converts a number from one numeric base to another.

```
assert(convertBase("101010", 2, 8) == "52");
assert(convertBase("52", 8, 10) == "42");
assert(convertBase("42", 10, 16) == "2A");
assert(convertBase("2A", 16, 2) == "101010");
```
  
**copy_vs_move.cpp**  
Compare function calls passing arguments by value, by reference, and by ref ref.
  
**correlation.cpp**  
Implement a function to calculate the correlation between two collections using.
  
**covariance.cpp**  
Implement a function to calculate the covariance between two collections.
  
**countBits.cpp**  
Implement a program to count the number of `1` bits in a given integer.  
Can you use `constexpr` to achieve this?  
Can you use `preprocessor` to achieve this?  
  
**crtp.cpp**  
Implement a CRTP pattern example.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) the Curiously Recurring Template Pattern is a C++ idiom to express static polymorphism. More formally is it known as F-bound polymorphism.
  
**ctad.cpp**  
Implement some examples showing class template argument deduction (CTAD) usage.  
  
**dijkstra.cpp**  
Implement Dijkstra algorithm.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) the Dijkstra algorithm is a procedure for finding the shortest paths between nodes in a weighted graph.
  
**entropy.cpp**  
Write a program to compute the entropy of a given sequence.  
  
From [Wikipedia](https://en.wikipedia.org/wiki/Entropy_(information_theory)) the entropy of a random variable quantifies the average level of uncertainty or information associated with the variable's potential states or possible outcomes.
  
**enumerate.cpp**  
Implement a simple version of `std::enumerate_view` [cppreference](https://en.cppreference.com/w/cpp/ranges/enumerate_view.html). The `enumerate_view` is a range adaptor that takes a view and produces a view of tuples which holds: the value which is a zero-based index of the element of underlying sequence, and the reference to the underlying element.  
  
**exec.cpp**  
Implement a function to run shell commands and capture their output, including support for long-running processes.
  
**exponential_smoothing.cpp**  
Implement a function to perform exponential smoothing average (EMA) on a given sequence using a specified alpha parameter. From [Wikipedia](https://en.wikipedia.org/wiki/Exponential_smoothing) the EMA is a technique for smoothing time series data using the exponential window function, where exponential functions are used to assign exponentially decreasing weights over time.
  
**fdm.cpp**  
Implement a program demonstrating a Finite Difference Method to calculate differential equation.
  
**find_union.cpp**  
Implement a find-union algorithm.  
  
**find.root.cpp**  
Implement a program to find the root of a function using the bisection and Newton's methods.
  
**floatFormatter.cpp**  
Implement a function that formats a floating-point number to fit within a fixed number of characters.
  
```{r, engine='cpp'}
assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");
```
  
**floyd_warshall.cpp**  
Implement Floyd-Warshall algorithm. From [Wikipedia](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) the Floyd–Warshall algorithm is a procedure for finding shortest paths in a directed weighted graph with positive or negative edge weights but with no negative cycles.
  
**fold_expression.cpp**  
Implement simple examples that demonstrate how to use C++17 fold expressions.  
  
**functional.cpp**  
Implement higher-order functions such as `fold`, `reduce`, and `filter`.
  
**gcd.cpp**  
Implement a function to calculate the greatest common divisor.
  
**gramSchmidt.cpp**  
Implement the Gram-Schmidt process function. From [Wikipedia](https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process) the Gram-Schmidt algorithm is a way of finding a set of two or more vectors that are perpendicular to each other.
  
**gzip.cpp**  
Implement a function to compress and decompress text using the _gzip_ algorithm.
    
**hanoi.cpp**  
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
  
**has_type.cpp**  
Implement various methods to determine whether a given class contains a nested internal type.  
  
**heap**  
Implement the heap data structure.
  
**in.cpp**  
Implement _in_ operator in C++. Follow the idea of [named-operators](https://github.com/klmr/named-operator).

```{r, engine='cpp'}
assert(    1 <in> std::vector< int >{ 1 } );
assert( !( 2 <in> std::vector< int >{ 1 } ) );
```
  
**integration.cpp**  
Implement a set of functions to calculate numerical integration for a function _f(x)_ in range _(a,b)_.
  
**interpolation.cpp**  
Implement a function to interpolate a given set of points with a polynomial. Use Newton's divided difference method.  
  
**is_prime.cpp**  
Implement a function to check whether a given number is prime using _Fermat's Little Theorem_ and _Rho-Pollard_ algorithm.
  
**jaccard_index.cpp**  
Implement a function to compute the Jaccard Index for two given sets. From [Wikipedia](https://en.wikipedia.org/wiki/Jaccard_index) the Jaccard index is used for comparing the similarity and diversity of sample sets.
  
**kmp.cpp**  
Implement the Knuth-Morris-Pratt text searching algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm), the Knuth-Morris-Pratt algorithm searches ofr occurences od a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

```
$ ./kmp 5 3.14159265359
5 9 11
```
  
**laplace_smoothing.cpp**  
Implement a function to perform _the Laplace smoothing_. From [Wikipedia](https://en.wikipedia.org/wiki/Additive_smoothing) the Laplace smoothing, also known as additive smothing (not to be confused with Laplacian smoothing) is a technique used to smooth categorical data.
  
**levenstein.cpp**  
Implement the _Levenstein distance_ function.

From [Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance), the Levenstein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other.
  
**linear.regression.cpp**  
Implement a function to calcuate linear regression using least squares approach.

From [Wikipedia](https://en.wikipedia.org/wiki/Linear_regression) linear regression is an approach for modelling the relationship between a scalar dependent variable _Y_ and one or more explanatory variables (or independent variables) denoted _X_.
  
**literal.cpp**  
Implement used defined literal _bin_ to convert a string of zeros and ones "1010101" into a decimal integer value.

```
assert( 561 == "1000110001"_bin );
assert( 561 == 1000110001_bin );
```
  
**ls.cpp**  
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
  
**mandelbrot.cpp**  
Implement a program to print ASCII art of Mandelbrot set fractal.

```
.....................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.....
...................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,...
.................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.
................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..............................,,,,,,,,,,,,,,,,,,,::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.............................,,,,,,,,,,,,,,::::::::::::::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
...........................,,,,,,,,,,,,:::::::::::::::::::::::::::;;;;;;^^^;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..........................,,,,,,,,,,::::::::::::::::::::::::::;;;;;;;^^*@ *^^^;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.........................,,,,,,,,::::::::::::::::::::::::::;;;;;;;;^^^^*## #&&&^;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
........................,,,,,,,:::::::::::::::::::::::::;;;;;;;;;;^^^^*&#@:;# &*^;;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.......................,,,,,,:::::::::::::::::::::::::;;;;;;;;;;^^^^^*&#@,;,,@&**^^;;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,
......................,,,,,::::::::::::::::::::::::;;;;;;;;;;;;^^^^**,*#^#  &.::*^^^^^;;;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,
.....................,,,,::::::::::::::::::::::::;;;;;;;;;;;^^^****&#@,       # &&*^^^^^;;;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,,
.....................,,,:::::::::::::::::::::::;;;;;;;;;;^^^****&&&## ::      * #&&*****^^^;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,
....................,,,::::::::::::::::::::::;;;;;;;;^^^^*&: .^@@@:^.,:&     @;,. : #&&&& .*;;;::::::::,,,,,,,,,,,,,,,,,,,,,,
...................,,::::::::::::::::::::::;;;;;;^^^^^^***&;&*;@:;;              ^  . *&.;.,^^;;:::::::::,,,,,,,,,,,,,,,,,,,,
...................,::::::::::::::::::::;;;;^^^^^^^^^^***&#@:                       &&   #,#*^;;::::::::::,,,,,,,,,,,,,,,,,,,
..................,,:::::::::::::::::;;;^^^^^^^^^^^*****#@:.*                           & #&*^^;;:::::::::,,,,,,,,,,,,,,,,,,,
..................,::::::::::::::;;;;^#******^^^*****&&#                                ,^#&&*^;;;:::::::::,,,,,,,,,,,,,,,,,,
.................,:::::::::;;;;;;;^^**#.#&&&&#^#&&&&&##@,*@                               ^..&^;;;::::::::::,,,,,,,,,,,,,,,,,
.................,:::::;;;;;;;;^^^^^**#^;:*  .@; . @@@@.*                                   :&^;;;;:::::::::,,,,,,,,,,,,,,,,,
.................:::;;;;;;;;;^^^^^^**&#@.*  & ^ ^&@^...;&                                   #*^;;;;::::::::::,,,,,,,,,,,,,,,,
................,:;;;;;;;;;;^^^^^^*&&& .:&;          ^;                                    ; *^;;;;::::::::::,,,,,,,,,,,,,,,,
................:;;;;;;;;;^^^^^**#^@@@.*                                                   *&^^;;;;;::::::::::,,,,,,,,,,,,,,,
................:;;;;;;;^*****&&&@ #  &#                                                  ;&*^^;;;;;::::::::::,,,,,,,,,,,,,,,
................^^^**&&&###@@#@ :.&:                                                    *@&**^^;;;;;::::::::::,,,,,,,,,,,,,,,
................^^^**&&&###@@#@ :.&:                                                    *@&**^^;;;;;::::::::::,,,,,,,,,,,,,,,
................:;;;;;;;^*****&&&@ #  &#                                                  ;&*^^;;;;;::::::::::,,,,,,,,,,,,,,,
................:;;;;;;;;;^^^^^**#^@@@.*                                                   *&^^;;;;;::::::::::,,,,,,,,,,,,,,,
................,:;;;;;;;;;;^^^^^^*&&& .:&;          ^;                                    ; *^;;;;::::::::::,,,,,,,,,,,,,,,,
.................:::;;;;;;;;;^^^^^^**&#@.*  & ^ ^&@^...;&                                   #*^;;;;::::::::::,,,,,,,,,,,,,,,,
.................,:::::;;;;;;;;^^^^^**#^;:*  .@; . @@@@.*                                   :&^;;;;:::::::::,,,,,,,,,,,,,,,,,
.................,:::::::::;;;;;;;^^**#.#&&&&#^#&&&&&##@,*@                               ^..&^;;;::::::::::,,,,,,,,,,,,,,,,,
..................,::::::::::::::;;;;^#******^^^*****&&#                                ,^#&&*^;;;:::::::::,,,,,,,,,,,,,,,,,,
..................,,:::::::::::::::::;;;^^^^^^^^^^^*****#@:.*                           & #&*^^;;:::::::::,,,,,,,,,,,,,,,,,,,
...................,::::::::::::::::::::;;;;^^^^^^^^^^***&#@:                       &&   #,#*^;;::::::::::,,,,,,,,,,,,,,,,,,,
...................,,::::::::::::::::::::::;;;;;;^^^^^^***&;&*;@:;;              ^  . *&.;.,^^;;:::::::::,,,,,,,,,,,,,,,,,,,,
....................,,,::::::::::::::::::::::;;;;;;;;^^^^*&: .^@@@:^.,:&     @;,. : #&&&& .*;;;::::::::,,,,,,,,,,,,,,,,,,,,,,
.....................,,,:::::::::::::::::::::::;;;;;;;;;;^^^****&&&## ::      * #&&*****^^^;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,
.....................,,,,::::::::::::::::::::::::;;;;;;;;;;;^^^****&#@,       # &&*^^^^^;;;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,,
......................,,,,,::::::::::::::::::::::::;;;;;;;;;;;;^^^^**,*#^#  &.::*^^^^^;;;;;::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,
.......................,,,,,,:::::::::::::::::::::::::;;;;;;;;;;^^^^^*&#@,;,,@&**^^;;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,
........................,,,,,,,:::::::::::::::::::::::::;;;;;;;;;;^^^^*&#@:;# &*^;;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.........................,,,,,,,,::::::::::::::::::::::::::;;;;;;;;^^^^*## #&&&^;;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..........................,,,,,,,,,,::::::::::::::::::::::::::;;;;;;;^^*@ *^^^;;;;;;::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
...........................,,,,,,,,,,,,:::::::::::::::::::::::::::;;;;;;^^^;;;;;:::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.............................,,,,,,,,,,,,,,::::::::::::::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
..............................,,,,,,,,,,,,,,,,,,,::::::::::::::::::::::::::::,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
.................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,.
...................................,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,...```
```

**matrix.cpp**  
This task involves implementing a simple matrix class and providing essential functionality.
  
**matrix_chain_multiplication.cpp**  
From [Wikipedia](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) _the matrix chain multiplication_ is an optimization problem that for given sequence of matrices, the goal is to find the most efficient way to multiply these matrices.
  
**matrix.mul.perf.cpp**  
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
  
**mean.cpp**  
Implement a function to find the mean value of provided numbers.  
  
**mean_squared_error.cpp**
Implement a function to calculate _mean squared error (MSE)_. From [Wikipedia](https://en.wikipedia.org/wiki/Mean_squared_error) the MSE is the average squared difference between the estimated values and the true value. 
  
**member_offset.cpp**  
Implement a function to calculate struct/class member offert.
  
**modexp.cpp**  
Implement a function to perform modular exponentiation.
    
**output.cpp**  
Implement the output stream operator (`operator<<`) for basic STL containers such as `std::array`, `std::vector`, `std::list`...
    
**parameter_pack.cpp**  
"Implement operations that work with template parameter pack—like `size`, `head`, `front`, `tail`, `back`, `any`, `all`, and `none`.
  
**par.cpp**  
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
  
**partition.cpp**  
Implement `partition` and `stable_partition` algorithms. 
  
**qr.cpp**  
Implement a function to do a QR decomposition of a matrix. From [Wikipedia](https://en.wikipedia.org/wiki/QR_decomposition) QR decomposition is a decomposition of a matrix _A_ into a product _A_=_QR_ of an orthogonal matrix _Q_ and an upper triangular matrix _R_.  
  
**quick_sort.cpp**  
Write a `quicksort` implementation. Can any STL utilities be used to simplify the task?
  
**reverse_words.cpp**  
Implement a program that reverses the words in a given sentence.
  
**xml/xpath.cpp**  
Implement a program to print nodes from xml matching a given XPath.
```{r, engine='bash'}
$ ./xpath xpath.xml "/doc/name/@first"
David
Shane
Joseph
Stephen
```

**feq.cpp**  
Create a function to compare two floating-point values within a given tolerance.
    
**ssl/sign.verify.cpp**  
Write a program to sign/verify a message with a RSA key.

```{r, engine='bash'}
$ openssl genrsa -des3 -out private.key 1024

$ openssl rsa -in private.key -pubout > key.pub

$ echo "C++" | openssl dgst -sha1 -sign private.key -out signature

$ echo "C++" | openssl dgst -sha1 -verify key.pub -signature signature
Verified OK

$ echo "C--" | openssl dgst -sha1 -verify key.pub -signature signature
Verification Failure
```

**scope_exit.cpp**  
Implement a scope quard class.

From [open-std](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2014/n4189.pdf), a *scope_exit* is a generic RAII wrapper class which ties zero or one resource to a clean-up/completion routine which is bound by scope, ensuring execution at scope exit.

```{r, engine='cpp'}
{
  FILE * file = open( "filename.txt", "r" );
  auto fileGuard = make_scope_exit(
    [ & file ](){ close( file ); }
  );
  ...
}
```
    
**timer.cpp**  
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
  
**union_cast.cpp**  
Implement union_cast.
  
**visitor.cpp**  
Implement an example of the visitor design pattern.

From [Wikipedia](https://en.wikipedia.org/wiki/Visitor_pattern) the visitor design pattern is a way of separating an algorithm from an object structure on which it operates.
    
**xml/xml.cpp**  
Implement a program to parse an xml document. Can you use only boost for it?
  
**rotate.cpp**  
Implement 'rotate' function.

From [cppreference](http://en.cppreference.com/w/cpp/algorithm/rotate) std::rotate performs a left rotation on a range of elements.

**void_t.cpp**  
What is a void_t and how it can be useful?
 
From [Wikipedia](https://en.wikipedia.org/wiki/Monte_Carlo_method) Monte-Carlo method is a computational algorithm that relies on repeated random sampling to obtain numerical results.
  
**get_container_type.cpp**  
Can you get a container type from its iterator?

```{r, engine='cpp'}
{
    std::vector< int >::iterator vectorIterator;

    static_assert(
        std::is_same<
            decltype( getContainerType( vectorIterator ) ) ),
            std::vector< int >
        >::value
    );
}
```
    
**gsl/interpolation.cpp**  
Implement a program to interpolate a set of points with a polynomial function. Can you use boost::ublas for it? Can you use GNU Scientific Library for it?

**gsl/mean.cpp**  
Implement a function to calculate a mean value from a collection.

**gsl/variance.cpp**  
Implement a function to calculate a variance. From [Wikipedia](https://en.wikipedia.org/wiki/Variance) variance is a measure how far a values are spread out.

**standardDeviation.cpp**  
Implement a function to calculate a standard deviation. From [Wikipedia](https://en.wikipedia.org/wiki/Standard_deviation), standard deviation indicates how the data values tend to be close to the mean.

**gsl/correlation.cpp**  
Implement a function to calculate the correlation between two collections using gsl library.

**gsl/covariance.cpp**  
Implement a function to calculate the covariance between two collections using gsl library.
  
**lu.cpp**  
Implement a function to make a LU decomposition of a matrix. From [Wikipedia](https://en.wikipedia.org/wiki/LU_decomposition) LU decomposition factors a matrix _A_ into a product _A_=_LU_ of a lower triangular matrix _L_ and an upper trianguar matrix _U_.

**ode.cpp**  
Implement a function to solve a first order ordinary differential equation numerically with Euler's and Runge-Kutta methods.
    
**ssl/https.cpp**  
Implement a function to make secure connection with https server. Use can use Bing Web Search API as a use case.
  
**rotate_matrix.cpp**  
Implement a program to rotate inplace matrix to right by 90 degrees

```{r, engine='bash'}
1 2 3    7 4 1
4 5 6 -> 8 5 2
7 8 9    9 6 3
```
  
**typeErasure.*.cpp**  
Implement a program representing the type erasure idiom.

From [Wikibooks](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Erasure) type erasure is a mechanism to provide a type-neutral container that interfaces a variety of concrete types. An example can be an implementation of [boost::any](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html) and also a way how does arbitrary deleter type can be used in [std::shared_ptr](http://en.cppreference.com/w/cpp/memory/shared_ptr).

**tree_classification.cpp**  
Check if a tree is a full tree or a complete tree. A full tree is a tree in which every node other than the leaves has two children. A complete tree is a tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

**circular_buffer.cpp**  
Implement a circular buffer.
  
**layout.cpp**  
Find struct/class layout for the most common cases.
  
**tuple.cpp**  
Implement simple examples of a `tuple` class using either composition or inheritance.
    
**rho_pollard.cpp**  
Implement the Pollard's rho algorithm. From [Wikipedia](https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm) Pollard's rho algorithm is a integer factorization algorithm.
  
**scaling.cpp**  
Implement functions for mean scaling and standard scaling. From [Wikipedia](https://en.wikipedia.org/wiki/Feature_scaling) scaling is a method used to standardize the range of independent variables of features of data.

**gsl/pca.cpp**  
Implement Principal Component Analysis using gsl library. From [Wikipedia](https://en.wikipedia.org/wiki/Principal_component_analysis) principal component analysis is a procedure to transform a given data set _X_ of dimension _p_ to an alternative data set _Y_ of smaller dimension _p'_.
  
**gsl/page_rank.cpp**  
Implement the Page Rank algorithm using eigenvalues and eigenvectors. 
      
**trie.cpp**  
Implement TRIE data structure.  
    
**tuple_utils.cpp**  
Implement simple `std::tuple` utilities, working on values like `head`, `tail`, `merge`, `foldl`, `foldr` `hash`, and working on types like `All`, `Any`, `None`, `Foldl`.  
      
**concat_view.cpp**  
Implement a simple version of `std::concat_view` [cppreference](https://en.cppreference.com/w/cpp/ranges/concat_view.html). The `concat_view` takes an arbitrary number of ranges as an argument list, and provides a view that starts at the first element of the first range, ends at the last element of the last range, with all range elements sequenced in between respectively in the order given in the arguments, effectively concatenating, or chaining together the argument ranges.  
 
  