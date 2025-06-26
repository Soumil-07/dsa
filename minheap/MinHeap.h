#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <optional>
#include <utility>
#include <vector>

template <class T>
class MinHeap 
{
public:
    MinHeap()
    {

    }

    ~MinHeap()
    {

    }

    void insert(const T &item)
    {
        _data.push_back(item);
        _heapify();
    }

    std::optional<T> top() const
    {
        return _data.empty() ? std::nullopt : std::make_optional(_data.front());
    }

    void pop()
    {
        if (_data.empty()) return;

        std::swap(_data.front(), _data.back());
        _data.pop_back();

        int idx = 0;
        while (true)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;

            if (left < _data.size() && _data[left] < _data[smallest])
                smallest = left;
            if (right < _data.size() && _data[right] < _data[smallest])
                smallest = right;

            if (smallest == idx) break;

            std::swap(_data[idx], _data[smallest]);
            idx = smallest;
        }
    }

    bool empty() const
    {
        return _data.empty();
    }

private:
    std::vector<T> _data;

    // change the ordering of the array to ensure every node is lower than its leaves
    void _heapify()
    {
        int idx = _data.size() - 1;
        while (idx > 0 && _data[idx] < _data[(idx - 1) / 2])
        {
            std::swap(_data[idx], _data[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
};

#endif // _MIN_HEAP_H_
