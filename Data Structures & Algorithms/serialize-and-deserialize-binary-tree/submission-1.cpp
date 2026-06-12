/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) 
            return "N";

        string res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node) {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
                res += "N,";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "N") 
            return nullptr;

        vector<string> nodes;
        string curr;

        for(char c : data){
            if(c == ','){
                nodes.push_back(curr);
                curr.clear();
            }
            else{
                curr += c;
            }
        }
        TreeNode* root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i =1;

        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();

            if(nodes[i] != "N"){
                parent->left = new TreeNode(stoi(nodes[i]));
                q.push(parent->left);
            }
            i++;

            if(nodes[i] != "N"){
                parent->right = new TreeNode(stoi(nodes[i]));
                q.push(parent->right);
            }
            i++;
        }
        return root;
    }
};
