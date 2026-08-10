class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for(int x : nums){
            //if i cannot find this element in set --> return true
            if(st.find(x) != st.end()){
                return true;
            }
            //insert element in set
            st.insert(x);
        }
        return false;
    }
};