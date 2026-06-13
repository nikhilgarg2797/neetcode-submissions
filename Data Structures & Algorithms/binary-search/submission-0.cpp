class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l = 0;
        int mid = 0;
        while(l<=r)
        {
            mid = (r+l)/2;
            if(nums[mid] > target)
            {
                r = mid -1;
            }
            else if(nums[mid] < target)
            {
                l = mid + 1;
            }
            else    return mid;
        }
        return -1;
    }
};
