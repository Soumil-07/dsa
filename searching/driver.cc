#include <iostream>
#include "binarySearch.h"

int main()
{
    // generate a random haystack vector
    srand(time(0));
    std::vector<int> haystack;
    for (int i = 0; i < 100; ++i) {
        haystack.push_back(rand() % 1000);
    }
    // sort the vector
    std::sort(haystack.begin(), haystack.end());
    // find a needle
    int needle = haystack[rand() % haystack.size()];
    std::cout << "Searching for " << needle << " in the haystack." << std::endl;

    auto result = binarySearch<int>(haystack, needle);
    if (result.has_value()) {
        std::cout << "Found at index: " << result.value() << " (value: " << haystack[result.value()] << ")" << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
