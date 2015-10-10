# dojo  
Implementation of some programmic puzzles  

## license  
For license please refer to LICENSE file  

## requirements  
C++11  
g++/clang++  
boost  
xml2  
openssl  
python  

## how to build it  
make  

## list of puzzles  

**1. echo.server/echo.client**  
Implement simple echo server and text line based client.  
`[console 1] $ ./echo.server`  
`[console 2] $ ./echo.client test`  
`[console 2] $ server echo: test`  

**2. xpath.cpp/xpath.xml**  
Implement a program to print nodes from xml matching a given XPath.  
`$ ./xpath xpath.xml "/doc/name/@first"`  
`David`  
`Shane`  
`Joseph`  
`Stephen`  

**3. get.request.cpp**  
Implement a program to download a website content. Use 'get' request to do it.  
Take care about at least a simple authorization on a proxy server.  
``$ ./get.request http://www.boost.org LICENSE_1_0.txt proxy_server proxy_port `echo -n "my_login:my_password" | base64```  

**4. base64.encode.cpp**  
Implement a program to do base64 encoding.  
`$ ./base64.encode "Hello World"`  
`SGVsbG8gV29ybGQ`  

**5. base64.decode.cpp**  
Implement a program to do base64 decoding.  
`$ ./base64.decode SGVsbG8gV29ybGQ`  
`Hello World`  

**6. bind.cpp**  
What is boost::apply? What is boost::protect? Write a short program to demonstrate usage of each of them  
  
**7. sign.verify.cpp**
Write a program to sign/verify a message with a RSA key

```{r, engine='bash'}
$ openssl genrsa -des3 -out private.key 1024  
  
$ openssl rsa -in private.key -pubout > key.pub  
  
$ echo "C++" | openssl dgst -sha1 -sign private.key -out signature  
  
$ echo "C++" | openssl dgst -sha1 -verify key.pub -signature signature   
Verified OK  
  
$ echo "C--" | openssl dgst -sha1 -verify key.pub -signature signature   
Verification Failure  
```

