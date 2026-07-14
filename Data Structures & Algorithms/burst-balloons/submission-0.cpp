class Solution {
public:
    vector<vector<int>> dp;
    int solve(int left, int right, vector<int> &arr){
        if(left > right){
            return 0;
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = 0;

        for(int k=left; k<=right ; k++){
            int leftcoins = solve(left, k-1, arr);
            int rightcoins = solve(k+1, right, arr);
            int curr = arr[left-1] * arr[k] * arr[right+1];

            ans = max(ans, leftcoins + curr + rightcoins);
        }
        return dp[left][right] = ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);

        for(int x : nums){
            arr.push_back(x);
        }
        arr.push_back(1);

        dp.assign(n+2, vector<int>(n+2, -1));
        return solve(1, n, arr);
    }
};
