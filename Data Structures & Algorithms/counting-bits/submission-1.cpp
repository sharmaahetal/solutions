class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        if(n == 0)  return res;     //number is 0
        res[0] = 0;     //binary represn of number is 0 


        //traverse from 0 to n
        for(int i=0; i<=n; i++){
            //even --> res[i/2]
            if(i%2 == 0){
                res[i] = res[i/2];
            }
            else{
                //odd --> res[i/2] + 1
                res[i] = res[i/2] + 1;
            }
        }
        return res;
    }
};
