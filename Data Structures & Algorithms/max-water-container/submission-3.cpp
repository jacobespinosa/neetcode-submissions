class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxVolumn = 0;

        while (l < r) {
            int width = r - l;
            int volumn = min(heights[l], heights[r]) * width;
            maxVolumn = max(maxVolumn, volumn);

            if (heights[l] < heights[r]) {
                l++;
            }
            else {
                r--;
            }
        }
        return maxVolumn;
    }
};
