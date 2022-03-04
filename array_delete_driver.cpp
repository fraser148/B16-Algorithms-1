#include "array.hpp"
#include "array_delete.hpp"
#include "utils.hpp"

int main(int argc, char** argv)
{
    auto A = std::vector<float>{0, 1, 2, 3, 4};
    print(A, "Initial array");
    while (!A.empty()) {
        array_delete(A, 0);
        print(A, "Array after deleting element at position 0");
    }
    return 0;
}