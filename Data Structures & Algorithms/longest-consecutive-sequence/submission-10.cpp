class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        for(auto &x : st){
            if(!st.count(x-1)){
                int length = 1;

                while(st.count(x + length)){
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};
