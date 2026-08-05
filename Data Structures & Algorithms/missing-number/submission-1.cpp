class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for(int x : nums){
            freq[x]++;
        }
        for(int i=0; i<=nums.size(); i++){
            if(freq[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
