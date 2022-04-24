
#include <cassert>
#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>

#include "./functional.hpp"

template<typename T_>
class NVector
{
public:
    typedef T_ value_type;

public:
    NVector(std::vector<std::size_t> const & sizes)
    {
        sizes_.assign(sizes.begin(), sizes.end());
        offsets_ = get_offsets_(sizes_);
        data_.resize(dojo::product(sizes_));
    }

    value_type & operator[](std::vector<std::size_t> const & indices){
        std::size_t index = 0;

        for(unsigned i = 0; i < indices.size(); ++i){
            index += indices[i] * offsets_[i];
        }

        return data_[index];
    }

    std::size_t size() const {
        return data_.size();
    }

private:

    static std::vector<std::size_t> get_offsets_(std::vector<std::size_t> const & sizes) {
        std::vector<std::size_t> result(sizes.size(), 1);

        for(int i = result.size() - 2; i >= 0; --i){
            result[i] = result[i+1] * sizes[i+1];
        }

        return result;
    }

private:
    std::vector<std::size_t> sizes_;
    std::vector<std::size_t> offsets_;
    std::vector<T_> data_;
};

int main(){
    NVector<float> nVector({2, 4, 8});
    assert(2 * 4 * 8 == nVector.size());

    for(unsigned x = 0; x < 2; ++x){
        for(unsigned y = 0; y < 4; ++y){
            for(unsigned z = 0; z < 8; ++z){
                nVector[{x, y, z}] = 100 * x + 10 * y + z;
            }
        }
    }

    for(unsigned x = 0; x < 2; ++x){
        for(unsigned y = 0; y < 4; ++y){
            for(unsigned z = 0; z < 8; ++z){
                assert(( nVector[{x, y, z}] == 100 * x + 10 * y + z ));
            }
        }
    }
}