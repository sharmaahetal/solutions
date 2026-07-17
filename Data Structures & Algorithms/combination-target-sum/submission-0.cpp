class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &nums, int target, vector<int> &curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        if(i == nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        solve(i, nums, target-nums[i], curr);

        curr.pop_back();

        solve(i+1, nums, target, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        solve(0, nums, target, curr);

        return ans;
    }
};
