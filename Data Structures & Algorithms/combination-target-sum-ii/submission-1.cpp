class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &candidates, int target, vector<int> &curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        if(i == candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        solve(i+1, candidates, target-candidates[i], curr);

        curr.pop_back();

        int j = i;
        while(j+1 < candidates.size() && candidates[j] == candidates[j+1]){
            j++;
        }
        solve(j+1, candidates, target, curr);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;

        solve(0, candidates, target, curr);
        return ans;
    }
};
