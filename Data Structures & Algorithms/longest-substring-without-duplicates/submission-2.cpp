class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int left = 0;
        int maxlen = 0;

        //traverse from right to left
        for(int right=0; right<s.size(); right++){
            //While the current character is already present
            while(st.count(s[right])){
                //shrink the window
                st.erase(s[left]);
                //update the pointer
                left++;
            }
            //window valid --> put right in set
            st.insert(s[right]);
            maxlen = max(maxlen , right-left+1);
        }
        return maxlen;
    }
};
