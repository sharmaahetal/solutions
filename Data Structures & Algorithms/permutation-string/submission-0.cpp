class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1freq(26,0);
        vector<int> s2freq(26,0);

        if(s1.size() > s2.size()){
            return false;
        }
        for(char c : s1){
            s1freq[c - 'a']++;
        }
        for(int i=0 ; i<s1.size() ; i++){
            s2freq[s2[i] - 'a']++;
        }
        if(s1freq == s2freq){
            return true;
        }
        for(int right=s1.size() ; right<s2.size() ; right++){
            s2freq[s2[right] - 'a']++;
            s2freq[s2[right-s1.size()] - 'a']--;

            if(s1freq == s2freq){
                return true;
            }
        }
        return false;
    }
};
