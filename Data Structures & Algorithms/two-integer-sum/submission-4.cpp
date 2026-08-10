class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //hashmap --> stores val,index
        unordered_map<int, int> mp;

        int sum = 0;
        
        for(int i=0; i<nums.size(); i++){
            int compliment = target - nums[i];
            if(mp.count(compliment)){
                return {mp[compliment], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
