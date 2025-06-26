#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <vector>

void _quickSort(std::vector<int>& vec, int lo, int hi)
{
    if (lo >= hi) return;

    int pivot = vec[hi];
    int ptrFromLeft = lo;
    int ptrFromRight = hi - 1;

    while (ptrFromRight >= ptrFromLeft)
    {
        if (vec[ptrFromLeft] > pivot && vec[ptrFromRight] < pivot)
        {
            std::swap(vec[ptrFromLeft], vec[ptrFromRight]);
        }
        ++ptrFromLeft;
        --ptrFromRight;
    }

    std::swap(vec[ptrFromLeft], vec[hi]);

    _quickSort(vec, lo, ptrFromLeft-1);
    _quickSort(vec, ptrFromLeft+1, hi);
}

void quickSort(std::vector<int>& vec)
{
    if (vec.size() < 2) return;
    _quickSort(vec, 0, vec.size() - 1);
}

#endif // _QUICK_SORT_H_
