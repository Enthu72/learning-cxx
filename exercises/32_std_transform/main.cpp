﻿#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>
std::string To_string(int i) {
    if (i == 0) {
        return "0";
    }
    i = i*2;
    
    std::string str = "";
    while (i != 0) {
        str += (i % 10 + '0');  // Convert digit to character
        i /= 10;
    }
    
    // Reverse the string to get the correct number order
    std::reverse(str.begin(), str.end());
    return str;
}

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    // TODO: 调用 `std::transform`，将 `v` 中的每个元素乘以 2，并转换为字符串，存入 `ans`
    // std::vector<std::string> ans
    std::vector<std::string> ans(val.size());
    std::transform(val.begin(),val.end(),ans.begin(),To_string);
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");
    return 0;
}
