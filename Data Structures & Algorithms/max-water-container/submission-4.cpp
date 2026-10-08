class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxAmount = 0;

        while (l < r) {
            int width = r - l;
            int height = min(heights[l], heights[r]);
            maxAmount = max(maxAmount, height * width);
            if (heights[l] <= heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxAmount;
    }
};
