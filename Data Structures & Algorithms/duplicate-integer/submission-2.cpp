class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int i : nums){
            freq[i]++;
            if(freq[i] >= 2){
                return true;
            }
        }
        return false;
    }
};