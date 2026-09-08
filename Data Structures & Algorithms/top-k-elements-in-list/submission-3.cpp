class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int x : nums){
            mp[x]++;
        }
        vector<vector<int>> buckets(n+1);
        for(auto it = mp.begin(); it != mp.end(); it++){
            buckets[it->second].push_back(it->first);
        }
        vector<int> ans;
        for(int i=n; i>=0; i--){
            for(auto num : buckets[i]){
                ans.push_back(num);

                if(ans.size() == k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
