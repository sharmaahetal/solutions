class TrieNode{
public:
    TrieNode* children[26];
    string word;
    TrieNode(){
        word = "";
        for(int i=0 ; i<26 ; i++){
            children[i] = nullptr;
        }
    }
};
class Solution {
public:

    vector<string> ans;
    TrieNode* root;

    void insert(string word){
        TrieNode* curr = root;
        for(char c : word){
            int idx = c - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word;
    }
    void dfs(vector<vector<char>>& board , int i , int j , TrieNode* node){
        char ch = board[i][j];
        if(ch == '#')
            return;

        if(node->children[ch - 'a'] == nullptr)
            return;
        node = node->children[ch - 'a'];

        if(node->word != "")
            ans.push_back(node->word);
            node->word = "";
        board[i][j] = '#';

        int dirs[4][2] = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        
        for(auto& d : dirs){
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size()){
                dfs(board , ni , nj , node);
            }
        }
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        for(string &word : words){
            insert(word);
        }
        int m = board.size();
        int n = board[0].size();

        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                dfs(board, i , j , root);
            }
        }
        return ans;
    }
};