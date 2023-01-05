/*
 * Website:
 *      https://github.com/wo3kie/dojo
 * 
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++17 trie.cpp -o trie
 *
 * Usage:
 *      $ ./trie
 */

#ifndef __CXX_DOJO_TRIE_HPP__
#define __CXX_DOJO_TRIE_HPP__

#include <cassert>
#include <deque>
#include <string>
#include <vector>

/*
 * Vector based implementation on TRIE data structure
 */

struct Node {
    bool isEnd = false;
    int letters[10 + 26 + 1] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,

        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1,

        -1
    };
};

struct Trie {
    Trie() {
        for (size_t i = 0; i < 10 + 26 + 1; ++i) {
            nodes.push_back(Node());
        }
    }

    /*
     * Returns true if created, false otherwise
     */
    bool getOrCreate(const std::string& text) {
        bool isCreated = false;

        if (text.empty()) {
            return isCreated;
        }

        char letter = text[0];
        int letterId = letterToId(letter);
        int nodeId = letterId;
        Node *node = &nodes[nodeId];

        for (size_t i = 1; i < text.size(); ++i) {
            letter = text[i];
            letterId = letterToId(letter);
            nodeId = node->letters[letterId];

            if (nodeId == -1) {
                isCreated = true;
                nodeId = nodes.size();
                node->letters[letterId] = nodeId;
                nodes.push_back(Node());
            }

            node = &nodes[nodeId];
        }

        if (nodes[nodeId].isEnd == false) {
            nodes[nodeId].isEnd = true;
            isCreated = true;
        }

        return isCreated;
    }

    std::vector<std::string> dump() const {
        std::vector<std::string> result;

        for(size_t i = 0; i < 10 + 26 + 1; ++i){
            const std::string prefix = std::string(1, idToLetter(i));
            const std::vector<std::string> partialResult = dump(prefix, i);
            result.insert(result.end(), partialResult.begin(), partialResult.end());
        }

        return result;
    }

    std::vector<std::string> dump(const std::string& prefix, size_t nodeId) const {
        std::vector<std::string> result;

        if(nodes[nodeId].isEnd){
            result.push_back(prefix);
        }

        for(size_t i = 0; i < 10 + 26 + 1; ++i){
            if(nodes[nodeId].letters[i] == -1){
                continue;
            }

            const std::vector<std::string> partialResult = dump(
                prefix + std::string(1, idToLetter(i)),
                nodes[nodeId].letters[i]
            );

            result.insert(result.end(), partialResult.begin(), partialResult.end());
        }

        return result;
    }

private:
    char idToLetter(int id) const {
        return "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_"[id];
    }

    int letterToId(char letter) const {
        int ids[256] = {
            /*   0 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /*  16 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /*  32 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /*  48 */  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
            /*  64 */ -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
            /*  80 */ 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, 36,
            /*  96 */ -1, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
            /* 112 */ 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, -1, -1, -1, -1, -1,
            /* 128 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 144 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 160 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 176 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 192 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 208 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 224 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            /* 240 */ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
            /* 256 */
        };

        assert(ids[letter] != -1);

        return ids[letter];
    }

private:
    std::vector<Node> nodes;
};

#endif 
