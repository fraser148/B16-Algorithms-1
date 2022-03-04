#include <assert.h>
#include "utils.hpp"

template <typename T>
void array_delete(std::vector<T>& A, const std::size_t index) {
    assert(index <= A.size());
    int end = (A.size()-1);
    for (int i = index; i != end; i++) {
        A[i] = A[i + 1];
    }
    
    A.pop_back();
}