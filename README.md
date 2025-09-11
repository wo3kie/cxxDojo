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

**echo.server/echo.client**  
Implement simple echo server and text line based client to work with server.
```{r, engine='bash'}
[console 1] $ ./echo.server

[console 2] $ ./echo.client test
[console 2] $ server echo: test
```

**xml/xpath.cpp**  
Implement a program to print nodes from xml matching a given XPath.
```{r, engine='bash'}
$ ./xpath xpath.xml "/doc/name/@first"
David
Shane
Joseph
Stephen
```

**get.request.cpp**  
Implement a program to download a website content. Use _get_ request to perform it.
Take care about at least a simple authorization on a proxy server.
```{r, engine='bash'}
$ ./get.request http://www.boost.org LICENSE_1_0.txt proxy_server proxy_port \
  $(echo -n "my_login:my_password" | base64)
```

**base64.encode.cpp**  
Implement a program to do _base64_ encoding.
```{r, engine='bash'}
$ ./base64.encode "Hello World"
SGVsbG8gV29ybGQ
```

**base64.decode.cpp**  
Implement a program to do _base64_ decoding.
```{r, engine='bash'}
$ ./base64.decode SGVsbG8gV29ybGQ
Hello World
```

**bind.cpp**  
What is _boost::apply_? What is _boost::protect_? Write a short program to demonstrate usage of each of them.

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

**barrier.cpp**  
Implement a barrier synchronization method.

From [Wikipedia](https://en.wikipedia.org/wiki/Barrier_(computer_science)), a *barrier* for a group of threads or processes in the source code is a point where any thread/process must stop and cannot proceed until all other threads/processes reach this point.

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

**buffer.cpp**  
Implement a thread safe queue with a limited capacity. A thread trying to put an item to the full queue should be blocked and as well as a thread trying to get an item from the empty queue.

**exec.cpp**  
Implement a function to execute a shell command and capture its output. Consider a case of long running process.

**bloom.cpp**  
Implement a Bloom filter.

From [Wikipedia](https://en.wikipedia.org/wiki/Bloom_filter), a Bloom filter is a space-efficient probabilistic data structure with false positive matches possible but false negatives not.

**bond.cpp**  
Implement a function to calculate a price for a bond.

```{r, engine='bash'}
$ ./bond 2015/12/31 100 0.08 0.08 2014/12/31
  PV( F ): 92.5926
  PV( Coupon ): 7.40741
P: 100
```

  **par.cpp**  
Implement a function to execute shell commands in parallel. As an example follow [GNU parallel](http://www.gnu.org/software/parallel/).

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

**grep.cpp**  
Implement a program to find a text matching a regular expression in a standard input.

```{r, engine='bash'}
$ cat grep.cpp | ./grep ".*line.*"
    std::string line;
        while( std::getline( std::cin, line ) )
            if( std::regex_match( line, std::regex( argv[1] ) ) )
                std::cout << line << std::endl;
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

**output.cpp**  
Implement an output operator (operator<<) for basic containers like std::array, std::vector, std::list...

**union_cast.cpp**  
Implement union_cast.

**literal.cpp**  
Implement used defined literal _bin_ to convert a string of zeros and ones "1010101" into a decimal integer value.

```
assert( 561 == "1000110001"_bin );
assert( 561 == 1000110001_bin );
```


**matrix.mul.perf.cpp**  
Implement a performance test for matrix multiplication. Consider all possibilities with loop nesting.

```
$ ./matrix.mul.perf
nmp: 743355µs
npm: 1925037µs
mnp: 721955µs
mpn: 793389µs
pnm: 1738803µs
pmn: 962802µs
```

**visitor.cpp**  
Implement an example of the visitor design pattern.

From [Wikipedia](https://en.wikipedia.org/wiki/Visitor_pattern) the visitor design pattern is a way of separating an algorithm from an object structure on which it operates.

**ahoCorasick.cpp**  
Implement the Aho-Corasick algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm), the Aho-Corasick algorithm can be used to locate elements of a finite set of strings (the "dictionary") within an input text.

```
$ ./ahoCorasick ahoCorasick.dct ahoCorasick.cpp
...
--------------------------------------------------------------------------------
>     auto const print = []( size_t const pos, std::string const & word ){
>     auto
>          const
>                  int
>                                   const
>                                                          const
>                                                                   or
--------------------------------------------------------------------------------
...
```

**gzip.cpp**  
Implement a function to pack/unpack text using compression algorithm.

**levenstein.cpp**  
Implement a Levenstein distance function.

From [Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance), the Levenstein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other.

**convertBase.cpp**  
Implement a function to convert number between different numeric bases.

```
assert( convertBase( "101010", 2, 8 ) == "52" );
assert( convertBase( "52", 8, 10 ) == "42" );
assert( convertBase( "42", 10, 16 ) == "2A" );
assert( convertBase( "2A", 16, 2 ) == "101010" );
```

**kmp.cpp**  
Implement a Knuth-Morris-Pratt text searching algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm), the Knuth-Morris-Pratt algorithm searches ofr occurences od a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

```
$ ./kmp 5 3.14159265359
5 9 11
```

**xml/xml.cpp**  
Implement a program to parse an xml document. Can you use only boost for it?

**json.cpp**  
Implement a program to parse a json document. Can you use only boost for it?

**rotate.cpp**  
Implement 'rotate' function.

From [cppreference](http://en.cppreference.com/w/cpp/algorithm/rotate) std::rotate performs a left rotation on a range of elements.

**allocator.cpp**  
Implement a simple allocator. Follow std::allocator as an example.

**const_expr.cpp**  
Can you calculate trigonometric functions like 'sin', 'cos'... during a compilation time?

**void_t.cpp**  
What is a void_t and how it can be useful?

**pi.cpp**  
Estimate PI number using Monte-Carlo method.

From [Wikipedia](https://en.wikipedia.org/wiki/Monte_Carlo_method) Monte-Carlo method is a computational algorithm that relies on repeated random sampling to obtain numerical results.

**linear.regression.cpp**  
Implement a function to calcuate linear regression using least squares approach.

From [Wikipedia](https://en.wikipedia.org/wiki/Linear_regression) linear regression is an approach for modelling the relationship between a scalar dependent variable _Y_ and one or more explanatory variables (or independent variables) denoted _X_.

**getContainerType.cpp**  
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

**getCounters.cpp**  
Implement a function to count a distrubution of data.

**bayes.cpp**  
Implement a simple program for ham/spam messages classification. Use naive Bayes approach.

From [Wikipedia](https://en.wikipedia.org/wiki/Naive_Bayes_classifier), naive Bayes classifiers are a family of simple probabilistic classifiers based on applying Bayes theorem with strong (naive) independence assumptions between the features.

**mandelbrot.cpp**  
Implement a program to print ASCII art of Mandelbrot set fractal.

```
####################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#################&&&&&&&&&&&&&&&&&&&&&&&*********************************&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
################&&&&&&&&&&&&&&&&&************************************************&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
##############&&&&&&&&&&&&&********************************^^^^^^^;::;;;;^^^^^********&&&&&&&&&&&&&&&&&&&&&&&&&&&&
############&&&&&&&&&&&*******************************^^^^^^^^^;;;:,  ,:::;;^^^^^^^*******&&&&&&&&&&&&&&&&&&&&&&&&
###########&&&&&&&&&******************************^^^^^^^^^^^;;;;;:,.@.  @^@:;^^^^^^^^********&&&&&&&&&&&&&&&&&&&&
#########&&&&&&&&******************************^^^^^^^^^^^^;;;;;::,..@&*&@.,::;;^^^^^^^^*********&&&&&&&&&&&&&&&&&
########&&&&&&*****************************^^^^^^^^^^^^^^;;;;;::. @&*@@@^*@ ,:;;;;;^^^^^^^**********&&&&&&&&&&&&&&
#######&&&&&****************************^^^^^^^^^^^^^^;;;:::::,. #.@@@@@@@@.#.,:;;;;;;;^^^^^**********&&&&&&&&&&&&
######&&&&****************************^^^^^^^^^^^^;;;:::::,,,,. @&#@@@@@@@@;@..,,::::::;;;^^^^**********&&&&&&&&&&
#####&&&***************************^^^^^^^^^;;;;;::.*^.@#   &#:*@;:@@@@@@^,;*&#&@..,,,,.@,:;^^^***********&&&&&&&&
####&&*************************^^^^^^^;;;;;;;;;:::,.@*@@@@:.:@@@@@@@@@@@@@@@@@@@@: #&@,;;.;,;;^^***********&&&&&&&
###&&***********************^^^^;;;;;;;;;;;;:::::,. @&:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:@.:;;;^^***********&&&&&&
###&*******************^^^^;;:;;;;;;;;;;;:::::,, ^;  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*^@.,::;;^^^***********&&&&&
##&*************^^^^^^^;;:, ;.,,,,,,,,,,,,,,,,..@&;.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.#  ::;^^^^***********&&&&
##*******^^^^^^^^^^;;;;;::, ;&&#*  @^^#   ...  @^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;:;;^^^^***********&&&
#&***^^^^^^^^^^^^;;;;;;::,,. #*^@@,^&@@**@^&###*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* ,:;;^^^^************&&
#**^^^^^^^^^^^;;;;;;;;:,,,.&#*.,@@@@@@@@@@@@;;;,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:,:;;^^^^^***********&&
#*^^^^^^^^^^;;;:::::,.^@@ ##;,@@@@@@@@@@@@@@@@^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^,:;;;^^^^^************&
#^;;;;;;:,,:::::,,,,  #;@,@.,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,::;;;^^^^^************&
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@**@.,,::;;;^^^^^************&
#^;;;;;;:,,:::::,,,,  #;@,@.,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ,::;;;^^^^^************&
#*^^^^^^^^^^;;;:::::,.^@@ ##;,@@@@@@@@@@@@@@@@^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@^,:;;;^^^^^************&
#**^^^^^^^^^^^;;;;;;;;:,,,.&#*.,@@@@@@@@@@@@;;;,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#:,:;;^^^^^***********&&
#&***^^^^^^^^^^^^;;;;;;::,,. #*^@@,^&@@**@^&###*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@* ,:;;^^^^************&&
##*******^^^^^^^^^^;;;;;::, ;&&#*  @^^#   ...  @^@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;:;;^^^^***********&&&
##&*************^^^^^^^;;:, ;.,,,,,,,,,,,,,,,,..@&;.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.#  ::;^^^^***********&&&&
###&*******************^^^^;;:;;;;;;;;;;;:::::,, ^;  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*^@.,::;;^^^***********&&&&&
###&&***********************^^^^;;;;;;;;;;;;:::::,. @&:@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:@.:;;;^^***********&&&&&&
####&&*************************^^^^^^^;;;;;;;;;:::,.@*@@@@:.:@@@@@@@@@@@@@@@@@@@@: #&@,;;.;,;;^^***********&&&&&&&
#####&&&***************************^^^^^^^^^;;;;;::.*^.@#   &#:*@;:@@@@@@^,;*&#&@..,,,,.@,:;^^^***********&&&&&&&&
######&&&&****************************^^^^^^^^^^^^;;;:::::,,,,. @&#@@@@@@@@;@..,,::::::;;;^^^^**********&&&&&&&&&&
#######&&&&&****************************^^^^^^^^^^^^^^;;;:::::,. #.@@@@@@@@.#.,:;;;;;;;^^^^^**********&&&&&&&&&&&&
########&&&&&&*****************************^^^^^^^^^^^^^^;;;;;::. @&*@@@^*@ ,:;;;;;^^^^^^^**********&&&&&&&&&&&&&&
#########&&&&&&&&******************************^^^^^^^^^^^^;;;;;::,..@&*&@.,::;;^^^^^^^^*********&&&&&&&&&&&&&&&&&
###########&&&&&&&&&******************************^^^^^^^^^^^;;;;;:,.@.  @^@:;^^^^^^^^********&&&&&&&&&&&&&&&&&&&&
############&&&&&&&&&&&*******************************^^^^^^^^^;;;:,  ,:::;;^^^^^^^*******&&&&&&&&&&&&&&&&&&&&&&&&
##############&&&&&&&&&&&&&********************************^^^^^^^;::;;;;^^^^^********&&&&&&&&&&&&&&&&&&&&&&&&&&&&
################&&&&&&&&&&&&&&&&&************************************************&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
#################&&&&&&&&&&&&&&&&&&&&&&&*********************************&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
####################&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
```

**quickSort.cpp**  
Implement the quick sort algorithm. Can you use any standard library function to do it?

**in.cpp**  
Implement _in_ operator in C++. Follow the idea of [named-operators](https://github.com/klmr/named-operator).

```{r, engine='cpp'}
assert(    1 <in> std::vector< int >{ 1 } );
assert( !( 2 <in> std::vector< int >{ 1 } ) );
```

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

**gsl/interpolation.cpp**  
Implement a program to interpolate a set of points with a polynomial function. Can you use boost::ublas for it? Can you use GNU Scientific Library for it?

**gsl/mean.cpp**  
Implement a function to calculate a mean value from a collection.

**gsl/variance.cpp**  
Implement a function to calculate a variance. From [Wikipedia](https://en.wikipedia.org/wiki/Variance) variance is a measure how far a values are spread out.

**standardDeviation.cpp**  
Implement a function to calculate a standard deviation. From [Wikipedia](https://en.wikipedia.org/wiki/Standard_deviation), standard deviation indicates how the data values tend to be close to the mean.

**gsl/correlation.cpp**  
Implement a function to calculate a correlation between two collections.

**exponentialSmoothing.cpp**  
Implement a function to do exponential smoothing. Use Brown's simple exponential smoothing.

**integration.cpp**  
Implement a set of functions to calculate numerical integration for a function _f(x)_ in range _(a,b)_.

**lu.cpp**  
Implement a function to make a LU decomposition of a matrix. From [Wikipedia](https://en.wikipedia.org/wiki/LU_decomposition) LU decomposition factors a matrix _A_ into a product _A_=_LU_ of a lower triangular matrix _L_ and an upper trianguar matrix _U_.

**ode.cpp**  
Implement a function to solve a first order ordinary differential equation numerically with Euler's and Runge-Kutta methods.

**gsl/covariance.cpp**  
Implement a function to calculate a covariance between two collections.

**matrix.cpp**  
Implement a simple matrix class. Provide a basic functionality for it.

**blackScholes.cpp**  
Calculate an option price for a given time and underlying stock price. Use Black-Scholes method for it.

**boxMuller.cpp**  
Implement the Box-Muller algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform), the Box-Muller algorithm can transform uniformly distributed random numbers into standard, normally distributed N(0, 1) (expected value 0, standard deviation 1) random numbers.

**logNormal.cpp**  
Implement a program to demonstrate a log normal distribution.

**floatFormatter.cpp**  
Implement a function to display a float number in a fixed number of characters.

```{r, engine='cpp'}
assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");
```

**brownianMotion.cpp**  
Implement a program to calculate simple Brownian motion, Brownian motion with drift, and geometric Brownian motion.

**ssl/https.cpp**  
Implement a function to make secure connection with https server. Use can use Bing Web Search API as a use case.

**countBits.cpp**  
Implement a program to count 1 bits in a number. Can you use constexpr to do it?

**reverseWords.cpp**  
Implement a program to reverse words in a given sentence.

**rotateMatrix.cpp**  
Implement a program to rotate inplace matrix to right by 90 degrees

```{r, engine='bash'}
1 2 3    7 4 1
4 5 6 -> 8 5 2
7 8 9    9 6 3
```

**generateAllSubsets.cpp**  
For a given set of numbers generate all possible subsets.

**parenthesis.cpp**  
Implement a program to generate all strings correctly matched _n_ pairs of parenthesis, eg.:

```{r, engine='bash'}
3: , , (), ()(), ()()(), ()(()), (()), (())(), (()()), ((()))
```

**longestIncreasingSubsequence.cpp**  
Implement a program to find a longest increasing subsequence in  a given sequence, eg.:

```{r, engine='bash'}
lis( {1, 9, 2, 8, 3, 7, 4} ) == { 1, 2, 3, 4 } )
```

**typeErasure.*.cpp**  
Implement a program representing the type erasure idiom.

From [Wikibooks](https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Type_Erasure) type erasure is a mechanism to provide a type-neutral container that interfaces a variety of concrete types. An example can be an implementation of [boost::any](http://www.boost.org/doc/libs/1_61_0/doc/html/any.html) and also a way how does arbitrary deleter type can be used in [std::shared_ptr](http://en.cppreference.com/w/cpp/memory/shared_ptr).

**dijkstra.cpp**  
Implement Dijkstra algorithm.

**bellmanFord.cpp**  
Implement Bellman-Ford algorithm.

**floydWarshall.cpp**  
Implement Floyd-Warshall algorithm.

**treeClassification.cpp**  
Check if a tree is a full tree or a complete tree. A full tree is a tree in which every node other than the leaves has two children. A complete tree is a tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

**matrixChainMultiplication.cpp**  
From [Wikipedia](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) matrix chain multiplication is an optimization problem that for given sequence of matrices, the goal is to find the most efficient way to multiply these matrices.

**circular_buffer.cpp**  
Implement a circular buffer.

**print_tuple.cpp**  
Implement a function to print a tuple content.

**layout.cpp**  
Find struct/class layout for the most common cases.

**member_offset.cpp**  
Implement a function to calculate struct/class member offert.

**tuple.cpp**  
Implement a simple _tuple_ class. Provide _get_ operator.

**crtp.cpp**  
Implement a CRTP pattern example. From [Wikipedia](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern) the Curiously Recurring Template Pattern is a C++ idiom to express static polymorphism. More formally is it known as F-bound polymorphism.

**apply.cpp**  
Implement a utility funtion to call another function with a tuple exploded to it as parameters.

```{r, engine='cpp'}
void f(int, float, char){ /* ... */ }
apply(f, std::make_tuple(1, 2.2, '3'));
```

**heap**  
Implement a heap data structure.

**gcd.cpp**  
Implement a function to calculate the greatest common divisor.

**modexp.cpp**  
Implement a function to calculate quickly exponential function with modulo operation.

**isPrime.cpp**  
Implement a function to verify using Fermat theorem if a given number is a prime number.

**rhoPollard.cpp**  
Implement the Pollard's rho algorithm. From [Wikipedia](https://en.wikipedia.org/wiki/Pollard%27s_rho_algorithm) Pollard's rho algorithm is a integer factorization algorithm.

**laplaceSmoothing.cpp**  
Implement a function to perform Laplace smoothing. From [Wikipedia](https://en.wikipedia.org/wiki/Additive_smoothing) Laplace smoothing, also known as additive smothing (not to be confused with Laplacian smoothing) is a technique used to smooth categorical data.

**rSquared.cpp**  
Implement a function to calculate r squared score. From [Wikipedia](https://en.wikipedia.org/wiki/Coefficient_of_determination) R squared, also known as coefficient of determination is the proportion of the varince in the dependent variable that is predictable from the independent variable(s).

**jaccardIndex.cpp**  
From [Wikipedia](https://en.wikipedia.org/wiki/Jaccard_index) Jaccard index is used for comparing the similarity and diversity of sample sets.

**scaling.cpp**  
Implement functions for mean scaling and standard scaling. From [Wikipedia](https://en.wikipedia.org/wiki/Feature_scaling) scaling is a method used to standardize the range of independent variables of features of data.

**find.root.cpp**  
Implement a program to find the root of a function. Use bisection and Netwon's methods.

**gsl/pca.cpp**  
Implement Principal Component Analysis using gsl library. From [Wikipedia](https://en.wikipedia.org/wiki/Principal_component_analysis) principal component analysis is a procedure to transform a given data set _X_ of dimension _p_ to an alternative data set _Y_ of smaller dimension _p'_.

**entropy.cpp**  
Implement a program to calculate a sequence's entropy.

**fold.cpp**  
Implement the _fold_ function using variadic templates.

**gsl/page_rank.cpp**  
Implement the Page Rank algorithm using eigenvalues and eigenvectors.

**differentiation.cpp**  
Implement functions to calcutate a differentiate of a function.

**fdm.cpp**  
Implement a program demonstrating a Finite Difference Method to calculate differential equation.  

**cholesky.cpp**  
Implement Cholesky matrix decomposition. From [Wikipedia](https://en.wikipedia.org/wiki/Cholesky_decomposition) Cholesky decomposition of positive-definte matrix into the product of a lower triangular matrix _L_ and its conjugate transpose _L'_ _A_=_LL'_.  
  
**gramSchmidt.cpp**  
Implement a function to orthonormalise a set of vectors. Use [Gram-Schmidt](https://en.wikipedia.org/wiki/Gram%E2%80%93Schmidt_process) algorithm to do it.  
  
**qr.cpp**  
Implement a function to do a QR decomposition of a matrix. From [Wikipedia](https://en.wikipedia.org/wiki/QR_decomposition) QR decomposition is a decomposition of a matrix _A_ into a product _A_=_QR_ of an orthogonal matrix _Q_ and an upper triangular matrix _R_.  
  
**interpolation.cpp**  
Implement a function to interpolate a given set of points with a polynomial. Use Newton's divided difference method.  
  
**find_union.cpp**  
Implement a find-union algorithm.  
  
**functional.cpp**  
Implement higher-order functions like fold, map, reduce, filter...  
    
**copy_move.cpp**  
Compare calling function with by value, by ref, by ref ref argument passing and returning.  
  
**async.cpp**  
Implement a min max function using std:async.  
  
**mapUtils.cpp**  
Implement a collection of function to work with std::map like: groupBy, keys, values...  
  
**trie.cpp**  
Implement TRIE data structure.  
  
**isDuplicate.cpp**  
Implement a function to check if there is a duplicate in a container of strings.  
  

```{r, engine='bash'}
$ ./isDuplicate 
605µs
313µs
4684µs
91218µs
35834µs
2454739µs
```
  
**co_await.cpp, co_iter.cpp, co_transform.cpp, co_yield.cpp**  
Implement short examples presenting coroutine usages.  
  
**partition.cpp**  
Implement partition and stable_partition algorithms.  
  
**tupleUtils.cpp**  
Implement simple `std::tuple` utilities, working on values like `head`, `tail`, `merge`, `foldl`, `foldr` `hash`, and working on types like `All`, `Any`, `None`, `Foldl`.  
  
**fold_expression.cpp**  
Implement simple examples showing how to use C++17 fold expressions.  
  
**has_type.cpp**  
Implement various methods to determine whether a given class contains a nested internal type.  
  
**concepts.cpp**  
Implement some concepts examples.  
  
**ctad.cpp**  
Implement some examples showing class template argument deduction (CTAD) usage.  
  
**dotdotdot.cpp**  
Implement functional list operation like head, front, tail, back on template/function parameter pack.  
  
**concat_view.cpp**  
Implement a simple version of `std::concat_view` [cppreference](https://en.cppreference.com/w/cpp/ranges/concat_view.html). The `concat_view` takes an arbitrary number of ranges as an argument list, and provides a view that starts at the first element of the first range, ends at the last element of the last range, with all range elements sequenced in between respectively in the order given in the arguments, effectively concatenating, or chaining together the argument ranges.  
  
**enumerate.cpp**  
Implement a simple version of `std::enumerate_view` [cppreference](https://en.cppreference.com/w/cpp/ranges/enumerate_view.html). The `enumerate_view` is a range adaptor that takes a view and produces a view of tuples which holds: the value which is a zero-based index of the element of underlying sequence, and the reference to the underlying element.  
  
  