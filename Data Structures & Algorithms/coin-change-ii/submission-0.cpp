class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, int rem, vector<int>& coins) {

        // Successfully formed the amount
        if (rem == 0)
            return 1;

        // No coins left
        if (i == coins.size())
            return 0;

        // Invalid amount
        if (rem < 0)
            return 0;

        // Already computed
        if (dp[i][rem] != -1)
            return dp[i][rem];

        // Take current coin
        int take = solve(i, rem - coins[i], coins);

        // Skip current coin
        int skip = solve(i + 1, rem, coins);

        return dp[i][rem] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        dp.assign(coins.size(), vector<int>(amount + 1, -1));

        return solve(0, amount, coins);
    }
};