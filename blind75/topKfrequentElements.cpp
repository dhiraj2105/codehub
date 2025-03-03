#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    // Create a frequency map to store the count of each element
    unordered_map<int, int> frequencyMap;
    for (int n : nums)
    {
        frequencyMap[n]++;
    }

    // Create a bucket array where index corresponds to frequency and stores elements with that frequency
    vector<list<int>> bucket(nums.size() + 1); // Bucket size is nums.size() + 1
    for (auto &entry : frequencyMap)
    {
        int frequency = entry.second;
        bucket[frequency].push_back(entry.first);
    }

    // Now collect the top K frequent elements from the bucket
    vector<int> topK;
    for (int i = bucket.size() - 1; i >= 0 && topK.size() < k; i--)
    {
        if (!bucket[i].empty())
        {
            for (int num : bucket[i])
            {
                topK.push_back(num);
                if (topK.size() == k)
                {
                    break;
                }
            }
        }
    }

    return topK;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> result = topKFrequent(nums, k);
    for (int num : result)
    {
        cout << num << " ";
    }
    return 0;
}
