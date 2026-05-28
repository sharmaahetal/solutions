class Solution {
public:
    int maxArea(vector<int>& heights) {
        int right = heights.size()-1 ;
        int left = 0;

        int maxarea = 0;

        while(left<right){
            int wt = right-left;
            int ht = min(heights[left],heights[right]);
            int area = ht*wt;
            maxarea = max(maxarea,area);

            if(heights[left]<heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxarea;
    }
};
