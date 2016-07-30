/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 bellmanFord.cpp -o bellmanFord
 *
 * Usage:
 *      $ ./bellmanFord
 */

#include <algorithm>
#include <limits>
#include <vector>

#include "./output.hpp"

/*
 * S. Dasgupta, C. Papadimitrioui U. Vazirani, Algorithms
 */

typedef std::vector<std::vector<int>> Matrix;

int const IN =  99; // infinity, 99 for readable output

bool update(
    Matrix const & graph,
    std::vector<int> & dist,
    std::vector<int> & prev,
    int u,
    int v
){
    if(dist[v] > dist[u] + graph[u][v]){
        dist[v] = dist[u] + graph[u][v];
        prev[v] = u;
    
        return true;
    }
    else{
        return false;
    }
}

std::pair<std::vector<int> /* dist */, std::vector<int> /* prev */>
bellmanFord(Matrix const & graph, int start = 0){
    int const size = graph.size();

    std::vector<int> dist(size, IN);
    std::vector<int> prev(size, -1);
    dist[start] = 0;

    for(int repetition = 0; repetition < size - 1; ++repetition){
        for(int u = 0; u < size; ++u){
            for(int v = 0; v < size; ++v){
                if(u == v){
                    continue;
                }

                if(graph[u][v] == IN){
                    continue;
                }

                update(graph, dist, prev, u, v);
            }
        }
    }

    { // one more time to detect a cycle
        for(int u = 0; u < size; ++u){
            for(int v = 0; v < size; ++v){
                if(u == v){
                    continue;
                }

                if(graph[u][v] == IN){
                    continue;
                }

                if(update(graph, dist, prev, u, v) == true){
                    return std::pair<
                        std::vector<int>, 
                        std::vector<int>
                    >();
                }
            }
        }
    }

    return std::make_pair(dist, prev);
}

std::vector<int> decodeShortestPath(
    std::vector<int> const & prev,
    int const start,
    int end
){
    std::vector<int> path(1, end);

    while(prev[end] != -1){
        path.push_back(prev[end]);
        end = prev[end];
    }

    std::reverse(path.begin(), path.end());

    return path;
}

int main(){
    Matrix matrix {
        // S   A   B   C   D   E   F   G
        {  0, 10, IN, IN, IN, IN, IN,  8 }, // S
        { IN,  0, IN, IN, IN,  2, IN, IN }, // A
        { IN,  1,  0,  1, IN, IN, IN, IN }, // B
        { IN, IN, IN,  0,  3, IN, IN, IN }, // C
        { IN, IN, IN, IN,  0, -1, IN, IN }, // D
        { IN, IN, -2, IN, IN,  0, IN, IN }, // E
        { IN, -4, IN, IN, IN, -1,  0, IN }, // F
        { IN, IN, IN, IN, IN, IN,  1,  0 }, // G
    };

    std::vector<int> dist;
    std::vector<int> prev;

    std::tie(dist, prev) = bellmanFord(matrix, 0);

    typedef std::vector<int> VI;

    assert(( dist == VI{ 0, 5, 5, 6, 9, 7, 9, 8 } ));
    assert(( decodeShortestPath(prev, 0, 0) == VI{0} ));
    assert(( decodeShortestPath(prev, 0, 1) == VI{0, 7, 6, 1} ));
    assert(( decodeShortestPath(prev, 0, 2) == VI{0, 7, 6, 1, 5, 2} ));
    assert(( decodeShortestPath(prev, 0, 3) == VI{0, 7, 6, 1, 5, 2, 3} ));
    assert(( decodeShortestPath(prev, 0, 4) == VI{0, 7, 6, 1, 5, 2, 3, 4} ));
    assert(( decodeShortestPath(prev, 0, 5) == VI{0, 7, 6, 1, 5} ));
    assert(( decodeShortestPath(prev, 0, 6) == VI{0, 7, 6} ));
    assert(( decodeShortestPath(prev, 0, 7) == VI{0, 7} ));
}

