## Copyright (C) 2015 Łukasz Czerwiński

# Dojo  
Implementation of some programmic puzzles  

## Website  
https://github.com/wo3kie/dojo

## Requirements  
C++11  
boost  
xml2  
openssl  

## How to build it?  
make  

## List of puzzles  

**1. echo.server/echo.client**  
Implement simple echo server and text line based client to work with server.  
```{r, engine='bash'}
[console 1] $ ./echo.server  

[console 2] $ ./echo.client test  
[console 2] $ server echo: test  
```

**2. xpath.cpp/xpath.xml**  
Implement a program to print nodes from xml matching a given XPath.  
```{r, engine='bash'}
$ ./xpath xpath.xml "/doc/name/@first"  
David  
Shane  
Joseph  
Stephen  
```

**3. get.request.cpp**  
Implement a program to download a website content. Use _get_ request to perform it.  
Take care about at least a simple authorization on a proxy server.  
```{r, engine='bash'}
$ ./get.request http://www.boost.org LICENSE_1_0.txt proxy_server proxy_port \
  $(echo -n "my_login:my_password" | base64)  
```

**4. base64.encode.cpp**  
Implement a program to do _base64_ encoding.  
```{r, engine='bash'}
$ ./base64.encode "Hello World"  
SGVsbG8gV29ybGQ  
```

**5. base64.decode.cpp**  
Implement a program to do _base64_ decoding.  
```{r, engine='bash'}
$ ./base64.decode SGVsbG8gV29ybGQ  
Hello World  
```

**6. bind.cpp**  
What is _boost::apply_? What is _boost::protect_? Write a short program to demonstrate usage of each of them.  

**7. sign.verify.cpp**  
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

**8. barrier.cpp**  
Implement a barrier synchronization method.  

From [Wikipedia](https://en.wikipedia.org/wiki/Barrier_(computer_science)), a *barrier* for a group of threads or processes in the source code is a point where any thread/process must stop and cannot proceed until all other threads/processes reach this point.  

**9. scope_exit.cpp**  
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

**10. buffer.cpp**  
Implement a thread safe queue with a limited capacity. A thread trying to put an item to the full queue should be blocked and as well as a thread trying to get an item from the empty queue.  

**11. exec.cpp**  
Implement a function to execute a shell command and capture its output. Consider a case of long running process.  

**12. bloom.cpp**  
Implement a Bloom filter.  

From [Wikipedia](https://en.wikipedia.org/wiki/Bloom_filter), a Bloom filter is a space-efficient probabilistic data structure with false positive matches possible but false negatives not.  

**13. bond.cpp**  
Implement a function to calculate a price for a bond.  

```{r, engine='bash'}
$ ./bond 2015/12/31 100 0.08 0.08 2014/12/31
  PV( F ): 92.5926
  PV( Coupon ): 7.40741
P: 100
```  

  **14. par.cpp**  
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

**15. ls.cpp**  
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

**16. grep.cpp**  
Implement a program to find a text matching a regular expression in a standard input.  

```{r, engine='bash'}
$ cat grep.cpp | ./grep ".*line.*"
    std::string line;
        while( std::getline( std::cin, line ) )
            if( std::regex_match( line, std::regex( argv[1] ) ) )
                std::cout << line << std::endl;
```

**17. timer.cpp**  
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

**18. output.cpp**  
Implement an output operator (operator<<) for basic containers like std::array, std::vector, std::list...  

**19. union_cast.cpp**  
Implement union_cast.

**20. literal.cpp**  
Implement used defined literal _bin_ to convert a string of zeros and ones "1010101" into a decimal integer value.  

```
assert( 561 == "1000110001"_bin );
assert( 561 == 1000110001_bin );
```


**21. matrix.mul.perf.cpp**  
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

**22. visitor.cpp**  
Implement an example of the visitor design pattern.  

From [Wikipedia](https://en.wikipedia.org/wiki/Visitor_pattern) the visitor design pattern is a way of separating an algorithm from an object structure on which it operates.  

**23. ahoCorasick.cpp**  
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

**24. gzip.cpp**  
Implement a function to pack/unpack text using compression algorithm.  

**25. levenstein.cpp**  
Implement a Levenstein distance function.  

From [Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance), the Levenstein distance is a string metric for measuring the difference between two sequences. Informally, the Levenshtein distance between two words is the minimum number of single-character edits (i.e. insertions, deletions or substitutions) required to change one word into the other.  

**26. shared**  
Implement a shared (.so) library.  

**27. convertBase.cpp**  
Implement a function to convert number between different numeric bases.

```
assert( convertBase( "101010", 2, 8 ) == "52" );
assert( convertBase( "52", 8, 10 ) == "42" );
assert( convertBase( "42", 10, 16 ) == "2A" );
assert( convertBase( "2A", 16, 2 ) == "101010" );
```

**28. kmp.cpp**  
Implement a Knuth-Morris-Pratt text searching algorithm.

From [Wikipedia](https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm), the Knuth-Morris-Pratt algorithm searches ofr occurences od a "word" W within a main "text string" S by employing the observation that when a mismatch occurs, the word itself embodies sufficient information to determine where the next match could begin, thus bypassing re-examination of previously matched characters.

```
$ ./kmp 5 3.14159265359
5 9 11
```

**29. jni**  
Implement a simple Java class and then call its code from C++ application. Use JNI for it.  

From [Wikipedia](https://en.wikipedia.org/wiki/Java_Native_Interface) Java Native Interface (JNI) is a programming framework that enables Java code running in a Java Virtual Machine to call and be called by native applications and libraries written in other languages such as C, C++ and assembly.

**30. xml.cpp**  
Implement a program to parse an xml document. Can you use only boost for it?  

**31. json.cpp**  
Implement a program to parse a json document. Can you use only boost for it?  

**32. rotate.cpp**  
Implement 'rotate' function.  

From [cppreference](http://en.cppreference.com/w/cpp/algorithm/rotate) std::rotate performs a left rotation on a range of elements.

**33. allocator.cpp**  
Implement a simple allocator. Follow std::allocator as an example.  

**34. const_expr.cpp**  
Can you calculate trigonometric functions like 'sin', 'cos'... during a compilation time?  

**35. void_t.cpp**  
What is a void_t and how it can be useful?  

**36. pi.cpp**  
Estimate PI number using Monte-Carlo method.  

From [Wikipedia](https://en.wikipedia.org/wiki/Monte_Carlo_method) Monte-Carlo method is a computational algorithm that relies on repeated random sampling to obtain numerical results.  

**37. lua**  
Implement a simple Lua function and then call it from C++ code.  

**38. linear.regression.cpp**  
Implement a function to calcuate linear regression using least squares approach.  

From [Wikipedia](https://en.wikipedia.org/wiki/Linear_regression) linear regression is an approach for modelling the relationship between a scalar dependent variable _Y_ and one or more explanatory variables (or independent variables) denoted _X_.

**39. getContainerType.cpp**  
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

**40. getCounters.cpp**  
Implement a function to count a distrubution of data.

**41. bayes.cpp**  
Implement a simple program for ham/spam messages classification. Use naive Bayes approach.  

From [Wikipedia](https://en.wikipedia.org/wiki/Naive_Bayes_classifier), naive Bayes classifiers are a family of simple probabilistic classifiers based on applying Bayes theorem with strong (naive) independence assumptions between the features.  

**42. mandelbrot.cpp**  
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

**43. quickSort.cpp**  
Implement the quick sort algorithm. Can you use any standard library function to do it?  

**44. in.cpp**  
Implement _in_ operator in C++. Follow the idea of [named-operators](https://github.com/klmr/named-operator).

```{r, engine='cpp'}  
assert(    1 <in> std::vector< int >{ 1 } );
assert( !( 2 <in> std::vector< int >{ 1 } ) );
```  

**45. hanoi.cpp**  
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

**46. interpolation.cpp**  
Implement a program to interpolate a set of points with a polynomial function. Can you use boost::ublas for it? Can you use GNU Scientific Library for it?  

**47. mean.cpp**  
Implement a function to calculate a mean value from a collection.  

**48. variance.cpp**  
Implement a function to calculate a variance. From [Wikipedia](https://en.wikipedia.org/wiki/Variance) variance is a measure how far a values are spread out.

**49. standardDeviation.cpp**  
Implement a function to calculate a standard deviation. From [Wikipedia](https://en.wikipedia.org/wiki/Standard_deviation), standard deviation indicates how the data values tend to be close to the mean.

**50. correlation.cpp**  
Implement a function to calculate a correlation between two collections.  

**51. exponentialSmoothing.cpp**  
Implement a function to do exponential smoothing. Use Brown's simple exponential smoothing.  

**52. integration.cpp**  
Implement a set of functions to calculate numerical integration for a function _f(x)_ in range _(a,b)_.  

**53. lu.cpp**  
Implement a function to make a LU decomposition of a matrix.  

**54. ode.cpp**  
Implement a function to solve a first order ordinary differential equation numerically with Euler's and Runge-Kutta methods.  

**55. covariance.cpp**  
Implement a function to calculate a covariance between two collections.  

**56. matrix.cpp**  
Implement a simple matrix class. Provide a basic functionality for it.  

**57. blackScholes.cpp**  
Calculate an option price for a given time and underlying stock price. Use Black-Scholes method for it.  

**58. boxMuller.cpp**  
Implement the Box-Muller algorithm.  

From [Wikipedia](https://en.wikipedia.org/wiki/Box%E2%80%93Muller_transform), the Box-Muller algorithm can transform uniformly distributed random numbers into standard, normally distributed N(0, 1) (expected value 0, standard deviation 1) random numbers.  

**58. logNormal.cpp**  
Implement a program to demonstrate a log normal distribution.  

**59. floatFormatter.cpp**  
Implement a function to display a float number in a fixed number of characters.  

```{r, engine='cpp'}  
assert(FloatFormatter(0.0000001234, 6).toString() == " 1e-07");
assert(FloatFormatter(0.0000001234, 7).toString() == "1.2e-07");
assert(FloatFormatter(0.0000001234, 8).toString() == "1.23e-07");
assert(FloatFormatter(0.0000001234, 9).toString() == "0.0000001");
```  

**60. brownianMotion.cpp**  
Implement a program to calculate simple Brownian motion, Brownian motion with drift, and geometric Brownian motion.  
