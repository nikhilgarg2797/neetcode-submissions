class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> temp;
        int length;
        int longest = 0;
        
        for(int n : nums) temp.insert(n);
        
        for(int n:nums)
        {
            if(temp.count(n-1) == 0)
            {
                length = 0;
                while(temp.count(n+length)>0) length++;
                longest = max(length,longest);
            }
        }
        return longest;
    }
};
