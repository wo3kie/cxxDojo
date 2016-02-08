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


**21. matrix.cpp**  
Implement a performance test for matrix multiplication. Consider all possibilities with loop nesting.  

```
$ ./matrix 
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
Implement a program to parse xml document. Can you use only boost for it?  
  
**31. json.cpp**  
Implement a program to parse json document. Can you use only boost for it?  
  
**32. rotate.cpp**
Implement a function 'rorate'.  

From [cppreference](http://en.cppreference.com/w/cpp/algorithm/rotate) std::rotate performs a left rotation on a range of elements.
