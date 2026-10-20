class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        r = nums.size() - 1;
        if (target > nums[r]) {
            r = l - 1;
            l = 0;
        }

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            }
            else if (nums[m] < target) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};
