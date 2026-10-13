class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = nums[0];
        int lowIndex = 0;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                if (nums[l] < low) {
                    low = nums[l];
                    lowIndex = l;
                }            
                break;
            }
            int m = l + (r - l) / 2;
            if (nums[m] < low) {
                low = nums[m];
                lowIndex = m;
            }      

            if (nums[m] >= nums[l]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        if (target >= nums[lowIndex] && target <= nums[r]) {
            l = lowIndex;
        } else {
            r = lowIndex - 1;
        }
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > target) {
                r = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return -1;
    }
    
};
