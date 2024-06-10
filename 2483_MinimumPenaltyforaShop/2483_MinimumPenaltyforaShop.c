// class Solution {
// public:
//     int bestClosingTime(string customers) {
//         /* when close at ith, the penalty will be number of N before ith + the number of Y from ith*/
//         vector<char>que(customers.size(),'X');
//         int numN = 0;
//         int numY = 0;
//         int minimum_index = customers.size();
//         for(int i = 0;i < customers.size();++i){
//             que[i] = customers[i];
//             if(customers[i] == 'N')numN++;
//         }
//         int minmum = numN;
//         for(int i = customers.size()-1;i >= 0;--i){
//             int res = 0;
//             if(que[i] == 'Y')numY++;
//             if(que[i] == 'N')numN--;
//             res = numN + numY;
//             if(minmum >= res){
//                 minmum = res;
//                 minimum_index = i;
//             }
//         }
//         return minimum_index;
//     }
// };
//O(n)
//O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int index = -1, ans = 0, total = 0;
        for(int i=0; i<customers.length(); i++){
            if(customers[i] == 'Y') 
                total++;
            else 
                total--;
            if(total > ans){
                ans = total;
                index = i;
            }
        }
        return index + 1;
    }
};