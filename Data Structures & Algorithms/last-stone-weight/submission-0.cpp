class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap 
        priority_queue<int> pq;
        //traverse
        for(int stone : stones){
            pq.push(stone);
        }
        //at most one stone remains
        while(pq.size() > 1){
            //largest
            int y = pq.top();
            pq.pop();

            //second largest
            int x = pq.top();
            pq.pop();

            //if not equal push their difference in queue
            if(x != y){
                pq.push(y-x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
