/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <limits>
#include <string>
#include <vector>

#include "./output.hpp"

struct Node {
    int rows = 0;
    int columns = 0;
    int score = std::numeric_limits<int>::max();
    std::string solution;
};

std::ostream& operator<<(std::ostream& out, const Node& n) {
    return out << "{" << n.rows << ", " << n.columns << ", " << n.score << ", " << n.solution << "}";
}

Node matrix_chain_multiplication(const std::vector<std::pair<int,int>>& m) {
    const int n = m.size();
    std::vector<std::vector<Node>> dp(n, std::vector<Node>(n));

    for(int i = 0; i < n; ++i) {
        dp[i][i].rows = m[i].first;
        dp[i][i].columns = m[i].second;
        dp[i][i].score = 0;
        dp[i][i].solution = std::to_string(i);
    }

    for(int len = 2; len <= n; ++len) {
        for(int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;

            for(int k = i; k < j; ++k) {
                const Node& left = dp[i][k];
                const Node& right = dp[k+1][j];

                const int cost = left.score + right.score + left.rows * left.columns * right.columns;

                if(cost < dp[i][j].score) {
                    dp[i][j].score = cost;
                    dp[i][j].rows = left.rows;
                    dp[i][j].columns = right.columns;
                    dp[i][j].solution = "(" + left.solution + ")*(" + right.solution + ")";
                }
            }
        }
    }

    return dp[0][n-1];
}


/*
 * main
 */

int main() {
  {
    /*
        * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
        */

    std::vector<std::pair<int, int>> matrices{
        {50, 20}, //
        {20, 1},
        {1, 10},
        {10, 100}};

    std::cout << matrix_chain_multiplication(matrices) << std::endl;
  }

  {
    /*
         * T. H. Cormen, Ch. E. Leiserson, R. L. Rivest,
         *  Introduction to Algorithms
         */

    std::vector<std::pair<int, int>> matrices{
        {30, 35}, //
        {35, 15},
        {15, 5},
        {5, 10},
        {10, 20},
        {20, 25}};

    std::cout << matrix_chain_multiplication(matrices) << std::endl;
  }
}
