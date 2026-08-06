class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;

        if(s.size() != t.size()){
            return false;
        }

        for(int i=0; i<s.size(); i++){
            freq1[s[i]]++;
            freq2[t[i]]++;
        }  
        if(freq1 == freq2){
            return true;
        }
        return false;
    }
};
