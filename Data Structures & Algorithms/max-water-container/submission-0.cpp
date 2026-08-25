class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int l = 0;
        int r = heights.size() - 1;
        int distance = r;
        int maxiumWater = 0;

        while (l < r)
        {
            int lowest = min(heights[l], heights[r]);
            int maxWater = lowest * distance;
            maxiumWater = max(maxWater, maxiumWater);

            if (lowest == heights[l])
            {
                l++;
                distance--;
            }
            else
            {
                r--;
                distance--;
            }
        }
        return maxiumWater;
    }
};
