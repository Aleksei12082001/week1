#include "perms.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

void generatePermutations(list<int>& nums, std::list<int>::size_type start, list<list<int>>& result) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }

    auto it = nums.begin();
    advance(it, start);

    for (auto i = it; i != nums.end(); ++i) {
        if (find(it, i, *i) != i) continue; 

        swap(*it, *i);
        generatePermutations(nums, start + 1, result);
        swap(*it, *i); 
    }
}

std::list<std::list<int>> perms(const std::list<int>& input) {
    list<int> nums = input; 
    list<list<int>> result;

    generatePermutations(nums, 0, result);

    return result; 
}


