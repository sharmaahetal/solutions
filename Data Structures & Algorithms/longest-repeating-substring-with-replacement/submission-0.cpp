class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int left = 0;
        int maxfreq = 0;
        int result = 0;

        for(int right = 0 ; right < s.size() ; right++){
            count[s[right]]++;
            maxfreq = max(maxfreq , count[s[right]]);

            while((right - left + 1) - maxfreq > k){
                count[s[left]]--;
                left++;
            }
            result = max(result,right-left+1);
        }
        return result;
    }
};
