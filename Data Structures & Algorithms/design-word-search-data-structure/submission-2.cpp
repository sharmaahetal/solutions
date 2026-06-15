class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;

        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for(char c : word){
            int idx = c - 'a';

            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(TrieNode* node, string& word, int idx){
        if(node == nullptr){
            return false;
        }

        if(idx == word.size()){
            return node->isEnd;
        }

        char ch = word[idx];

        if(ch != '.'){
            return dfs(node->children[ch - 'a'], word, idx + 1);
        }

        for(int i = 0; i < 26; i++){
            if(node->children[i] != nullptr){
                if(dfs(node->children[i], word, idx + 1)){
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
