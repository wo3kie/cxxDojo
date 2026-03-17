/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./load_balancer.hpp"

void test_load_balancer() {
  LoadBalancer<int, 4> load_balancer;
  (void) load_balancer;
}

int main(){
  test_load_balancer();
}
