class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> arr(size, 1);

        for(int n = 0; n < nums.size(); n++)
        {
            for(int i = 0; i < arr.size(); i++)
            {
                if(i == n) continue;
                else arr[i] = arr[i] * nums[n];
            }
        }
        return arr;

    }
};
