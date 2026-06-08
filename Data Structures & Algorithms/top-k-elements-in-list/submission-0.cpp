class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> freq;
    for (int num : nums) {
        freq[num]++;
    }

    // Step 2: Move data into a vector of pairs (element, frequency)
    vector<pair<int, int>> freqVec(freq.begin(), freq.end());

    // Step 3: Sort by frequency (descending)
    sort(freqVec.begin(), freqVec.end(), [](auto &a, auto &b) {
        return a.second > b.second;
    });

    // Step 4: Collect top k elements
    vector<int> result;
    for (int i = 0; i < k && i < freqVec.size(); i++) {
        result.push_back(freqVec[i].first);
    }

    return result;

    }
};
