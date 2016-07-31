/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 matrixChainMultiplication.cpp \
 *          -o matrixChainMultiplication
 *
 * Usage:
 *      $ ./matrixChainMultiplication
 */


#include <limits>
#include <string>
#include <vector>

#include "./output.hpp"

struct Node {
    int rows = 0;
    int columns = 0;
    int score = 99999;
    std::string solution;
};

std::ostream & operator<<(std::ostream & out, Node const & node){
    return out << "{" << node.rows << ", " << node.columns << ", " 
        << node.score << ", " << node.solution << "}";
}

Node matrixChainMultiplication(std::vector<std::pair<int, int>> matrices){
    int const n = matrices.size();

    std::vector<std::vector<Node>> C(
        n,
        std::vector<Node>(n)
    );
    
    for(int i = 0; i != n; ++i){
        C[0][i].rows = matrices[i].first;
        C[0][i].columns = matrices[i].second;
        C[0][i].score = 0;
        C[0][i].solution = std::to_string(i);
    }

    for(int i = 1; i != n; ++i){
        for(int j = i; j != n; ++j){
            int from = j - i;
            int to = j;

            for(int k = from; k < to; ++k){
                Node const & first = C[k - from][k];
                Node const & second = C[to - k - 1][to];

                int const score 
                    = first.score
                    + second.score
                    + first.rows 
                    * first.columns
                    * second.columns;


                if(C[i][j].score > score){
                    C[i][j].score = score;
                    C[i][j].rows = first.rows;
                    C[i][j].columns = second.columns;
                    
                    C[i][j].solution 
                        = "(" + first.solution + ")"
                        + "*(" + second.solution + ")";
                } 
            }
        }
    }

    return C.back().back();
}

int main(){
    {
        /*
        * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
        */

        std::vector<std::pair<int, int>> matrices{
            { 50, 20 },
            { 20, 1 },
            { 1, 10 },
            { 10, 100 }
        };

        std::cout << matrixChainMultiplication(matrices) << std::endl;
    }

    {
        /*
         * T. H. Cormen, Ch. E. Leiserson, R. L. Rivest,
         *  Introduction to Algorithms
         */

        std::vector<std::pair<int, int>> matrices{
            { 30, 35 },
            { 35, 15 },
            { 15,  5 },
            {  5, 10 },
            { 10, 20 },
            { 20, 25 }
        };

        std::cout << matrixChainMultiplication(matrices) << std::endl;
    }
}

