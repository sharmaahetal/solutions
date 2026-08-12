class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();

        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> freq;
        for(int i=0; i<n; i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto x : freq){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};
