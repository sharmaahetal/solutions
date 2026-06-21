class Solution {
public:
    void validStr(int n, int open, int close, vector<string>& str, string s){
        if(open == n && close == n){
            str.push_back(s);
            return;
        }
        if(open<n){
            validStr(n, open+1, close, str, s +'(');
        }
        if(close<open){
            validStr(n, open, close+1, str, s +')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> str;
        int open = 0;
        int close = 0;

        validStr(n, open, close, str, "");
        return str;
    }
};
