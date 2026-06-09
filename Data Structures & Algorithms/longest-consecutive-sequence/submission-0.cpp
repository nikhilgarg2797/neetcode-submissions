class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        for(int n : nums) temp.insert(n);
        int longest = 0;

        for(int n:nums)
        {
            if(temp.count(n-1) == 0)
            {
                int length = 0;
                while(temp.count(n+length)>0) length = length + 1;
                longest = max(length,longest);
            }
        }
        return longest;
    }
};
