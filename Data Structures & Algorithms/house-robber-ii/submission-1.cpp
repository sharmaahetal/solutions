class Solution {
public:
    int roblinear(vector<int>& nums){
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> dp(n);

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2 ; i<n ; i++){
            int skip = dp[i-1];
            int take = nums[i] + dp[i-2];

            dp[i] = max(skip, take);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> first(nums.begin(), nums.end() - 1);
        vector<int> second(nums.begin() + 1, nums.end());

        return max(roblinear(first), roblinear(second));
    }
};
