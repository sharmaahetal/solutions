class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxwater = 0;
        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            int l = min(heights[left], heights[right]);
            int b = right - left;

            int currwater = l*b;

            maxwater = max(maxwater, currwater);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxwater;
    }
};
