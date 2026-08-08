class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxLen = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        for(int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right] - 'A']++;

            // Track most frequent character in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // If replacements needed > k, shrink window
            while((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Current window is valid
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
