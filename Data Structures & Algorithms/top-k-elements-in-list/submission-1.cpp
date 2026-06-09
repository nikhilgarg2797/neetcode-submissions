class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets (index = frequency)
        int n = nums.size();
        vector<vector<int>> buckets(n + 1); // max frequency can't exceed n

        for (auto& entry : freq) {
            int number = entry.first;
            int count = entry.second;
            buckets[count].push_back(number);
        }

        // Step 3: Collect top k from highest frequency bucket
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
        }
};
