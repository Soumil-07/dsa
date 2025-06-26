#include <iostream>
#include "bucketSort.h"
#include "insertionSort.h"
#include "stoogeSort.h"
#include "quickSort.h"

int main()
{
    std::vector<double> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.82};
    
    std::cout << "Original array: ";
    for (double num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bucketSort(arr);

    std::cout << "Sorted array: ";
    for (double num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    std::cout << "Original vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    quickSort(vec);
    std::cout << "Sorted vector: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
