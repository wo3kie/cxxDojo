/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_FIND_UNION_HPP__
#define __CXX_DOJO_FIND_UNION_HPP__

#include <vector>

class FindUnion {
public:
    FindUnion(int size)
        : data_(size)
    {
        for(int i = 0; i < size; ++i){
            data_[i] = i;
        }
    }

    int cfind(int i) const {
        while(data_[i] != i){
            i = data_[i];
        }

        return i;
    }

    int find(int i) {
        if(data_[i] == i){
            return i;
        }

        int const root = find(data_[i]);

        data_[i] = root;
        return i;
    }

    void merge(int i, int j){
        int const i_pos = cfind(i);
        int const j_pos = cfind(j);

        data_[i_pos] = j_pos;
    }

    unsigned size() const {
        return data_.size();
    }

    std::vector<int> getData() const {
        return data_;
    }

private:
    std::vector<int> data_;
};

#endif

