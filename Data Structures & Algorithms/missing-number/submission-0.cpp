class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all = 0;

        for(int i=0; i<=nums.size(); i++){
            all = all ^ i;
        }
        for(int x : nums){
            all = all ^ x;
        }
        return all;
    }
};
