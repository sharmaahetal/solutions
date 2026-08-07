class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(string s : strs){
            encoded += to_string(s.size());
            encoded += '#';
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;

        //until i is in bounds
        while(i < s.size()){
            int j = i;

            while(s[j] != '#'){
                j++;
            }
            //in case j = '#'
            int len = stoi(s.substr(i,j));
            j++;

            string word = s.substr(j, len);
            res.push_back(word);

            i = j+len;
        }
        return res;
    }
};
