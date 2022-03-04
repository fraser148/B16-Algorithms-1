#include <iostream>
#include <list>
#include <math.h>
#include "utils.hpp"

// Strong assistance from https://www.tutorialspoint.com/cplusplus-program-to-implement-radix-sort#:~:text=Radix%20sort%20is%20non%2Dcomparative,base%20of%20a%20number%20system.

void radix_sort(const std::vector<int>::iterator begin, const std::vector<int>::iterator end) {
    int temp;
    int m;
    int p;
    int index;
    std::list<int> pocket[10];
    for (auto i = 0; i < 2 ; i++)
    {
        m = pow(10, i+1);
        p = pow(10, i);
        for (auto j = begin; j != end; j++) {
            temp = *j%m;
            index = temp/p;
            pocket[index].push_back(*j);
        }
        auto count = begin;
        for(auto j = 0; j<10; j++) {
         //delete from linked lists and store to array
            while(!pocket[j].empty()) {
                *count = *(pocket[j].begin());
                pocket[j].erase(pocket[j].begin());
                count++;
            }
        }
    }
}