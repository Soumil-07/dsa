#include "bucketSort.h"
#include <algorithm>

void bucketSort(std::vector<double> &arr)
{
    if (arr.size() == 0) return;

    int numBuckets = arr.size();
    std::vector<std::vector<double>> buckets(numBuckets);

    auto maxVal = *std::max_element(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int bucketIdx = arr[i] * arr.size() / (maxVal + 1);
        buckets[bucketIdx].push_back(arr[i]);
    }

    // sort each individual bucket 
    for (auto& bucket : buckets)
    {
        std::sort(bucket.begin(), bucket.end());
    }

    int idx = 0;
    for (int i = 0; i < numBuckets; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }
}
