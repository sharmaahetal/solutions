class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;

        while(i <= j){
            //move until i points to alphanumeric char 
            if(!isalnum(s[i])){
                i++;
            }
            //move until j points to alphanumeric char 
            else if(!isalnum(s[j])){
                j--;
            }
            //compare the lowercase chars at i and j
            else if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
