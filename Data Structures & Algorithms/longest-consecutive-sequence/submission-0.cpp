class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if (nums.empty())
        {
            return 0;
        }

        sort(nums.begin(), nums.end());

        int largestCount = 1;
        int count = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1] == nums[i])
            {
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                count++;
                largestCount = max(largestCount, count);
            }
            else
            {
                count = 1;
            }
        }
        largestCount = max(largestCount, count);
        return largestCount;
    }
};
