//O(n)
class Solution {
public:
    string pushDominoes(string dominoes) {
        //find every sub interval and determine which way they will fall

        string res = "";
        dominoes = "L" + dominoes + "R";//it won't affect the result but let us skip finding the first force step
        for(int left = 0,right = 1;right < dominoes.size();++right){
            if(dominoes[right] == '.')continue;//find the right edge of the first sub interval
            
            int mid = right-left-1;//count the number between left and right in the sub interval
            if(left > 0)res += dominoes[left];
    
            if(dominoes[left] == dominoes[right])res += string(mid,dominoes[left]);//ex L..L or R..R
            else if(dominoes[left]== 'L' && dominoes[right] == 'R') res += string(mid,'.');
            else res += string(mid / 2, 'R') + string(mid % 2, '.') + string(mid / 2, 'L');

            left = right;
        }
        return res;
    }
};