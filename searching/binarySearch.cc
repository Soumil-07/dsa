#include "binarySearch.h"

#include <optional>

template <class T>
std::optional<size_t> _binarySearch(const std::vector<T>& vec, size_t lo, size_t hi, T key)
{
    if (lo > hi)
        return std::nullopt;

    auto mid = lo + ((hi - lo) / 2);
    auto midElement = vec.at(mid);

    if (midElement == key)
        return std::optional(mid);
    else if (key > midElement)
        return _binarySearch(vec, mid + 1, hi, key);
    else // key < midElement
        return _binarySearch(vec, lo, mid, key);
}

template <class T>
std::optional<size_t> binarySearch(const std::vector<T>& vec, T key)
{
    if (vec.size() == 0) return std::nullopt;
    return _binarySearch(vec, 0, vec.size(), key);
}

template std::optional<size_t> binarySearch<int>(const std::vector<int>& vec, int key);

