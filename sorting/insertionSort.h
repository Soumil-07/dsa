#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_

#include <utility>
#include <vector>

void insertionSort(std::vector<int> &vec)
{
    int i = 1;
    while (i < vec.size())
    {
        int j = i;
        while (j > 0 && vec[j-1] > vec[j])
        {
            std::swap(vec[j-1], vec[j]);
            j--;
        }
        i++;
    }
}

#endif // _INSERTION_SORT_H_
