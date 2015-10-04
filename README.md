# dojo  
Implementation of some programmic puzzles  

# website  
https://github.com/wo3kie/server  

# license  
For license please refer to LICENSE file  

# requirements  
C++11  
g++/clang++  
boost  
xml2  
python  

# how to build it  
make  

# list of puzzles  

1. Implement simple echo server and text line based client.  
`[console 1] $ ./echo.server`  
`[console 2] $ ./echo.client test`  
`[console 2] $ server echo: test`  

2. Implement a program to print nodes from xml matching a given XPath  
`$ ./xpath xpath.xml "/doc/name/@first"`  
`Davi`d  
`Shane`  
`Joseph`  
`Stephen`  

3. Implement a program to download a website content. Use 'get' request to do it.  
Take care about at least a simple authorization on a proxy server.  
`$ ./get.request http://www.boost.org LICENSE_1_0.txt \`  
`  proxy_server proxy_port \`echo -n "my_login:my_password" | base64\``

