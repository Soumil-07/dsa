#ifndef _STOOGE_SORT_H_
#define _STOOGE_SORT_H_

#include <vector>

void _stoogeSort(std::vector<int>& vec, int lo, int hi)
{
    if (lo >= hi) return;

    if (vec[lo] > vec[hi]) {
        std::swap(vec[lo], vec[hi]);
    }

    int len = hi - lo + 1;
    if (len > 2) {
        int t = len / 3;  // size of one third
        // sort first 2/3
        _stoogeSort(vec, lo, hi - t);
        // sort last 2/3
        _stoogeSort(vec, lo + t, hi);
        // sort first 2/3 again
        _stoogeSort(vec, lo, hi - t);
    }
}

void stoogeSort(std::vector<int>& vec)
{
    _stoogeSort(vec, 0, static_cast<int>(vec.size()) - 1);
}

#endif // _STOOGE_SORT_H_

