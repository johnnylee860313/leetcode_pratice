//O(query_row^2)
//O(query_row)
/*
if the liquid exceed the capacity of parent glass, 
each parent glass (row[i], No.i) will excess the extra liquid from 2 side 
to row[i+1](No.i and No.i+1) child glass.
Child glass will have liquid 0.5*poured from their parent glass
* Notice : this is not a tree *
*/

/*
    0
   / \
  0   1
 / \ / \
0.  1   2     

i -> i
  -> i+1
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev_row;
        prev_row.push_back(poured);

        for(int row = 1;row <= query_row;++row){
            vector<double> curr_row(row+1,0);
            for(int i = 0;i < row;++i){
                double extra = prev_row[i]-1;
                if(extra > 0){
                    curr_row[i] += extra * 0.5; 
                    curr_row[i+1] += extra * 0.5;
                }
            }
            prev_row = curr_row;
        }
        return 1 < prev_row[query_glass]?1:prev_row[query_glass];
    }
};
