class Solution {
public:
    int expand(int left, int right, string &s){
        int n = s.size();
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int length = 1;

        if(s.empty()){
            return "";
        }

        for(int i=0; i<n; i++){
            int odd = expand(i, i, s);
            int even = expand(i, i+1, s);

            int currlen = max(odd, even);

            if(currlen > length){
                start = i - (currlen-1)/2;
                length = currlen;
            }
        }
        return s.substr(start,length);
    }
};
