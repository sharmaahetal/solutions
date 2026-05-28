class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> rwindow;
        unordered_map<char,int> cwindow;

        for(char c : t){
            rwindow[c]++;
        }
        int formed = 0;
        int required = rwindow.size();

        int minlen = INT_MAX;
        int start = 0;

        int left = 0;
        for(int right = 0 ; right<s.size() ; right++){
            char c = s[right];
            cwindow[c]++;

            if(cwindow[c] == rwindow[c]){
                formed++;
            }
            while(formed == required){
                if(right-left+1 < minlen){
                    minlen = right-left+1;
                    start = left;
                }
                char ch = s[left];
                cwindow[ch]--;

                if(cwindow[ch] < rwindow[ch])
                    formed--;

                left++;
            }
        }
        if(minlen == INT_MAX)
            return "";
        return s.substr(start,minlen);
    }
};
