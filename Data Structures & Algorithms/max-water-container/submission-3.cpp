class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea = 0;

        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            int l = min(heights[left], heights[right]);
            int b = right - left;

            int currarea = l * b;
            maxarea = max(maxarea, currarea);

            heights[left] < heights[right] ? left++ : right--;
        }
        return maxarea;
    }
};
