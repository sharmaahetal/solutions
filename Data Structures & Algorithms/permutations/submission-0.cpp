class Solution {
public:
    void backtrack(vector<int>& used, vector<int>& nums, vector<vector<int>>& res){
        if(used.size() == nums.size()){
            res.push_back(used);
            return;
        }
        for(int i : nums){
            if(find(used.begin(),used.end(),i) != used.end()){
                continue;
            }

            used.push_back(i);
            backtrack(used, nums, res);
            used.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> res;
       vector<int> used;

        backtrack(used, nums, res);
        return res;
    }
};
