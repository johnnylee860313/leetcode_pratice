class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        int maxscore = 0;
        int left = 0,right = tokens.size()-1;

        sort(tokens.begin(),tokens.end());
        while(left <= right){
            if(power >= tokens[left]){//greedy to pick the face up
                power -= tokens[left++];
                score++;
                maxscore = maxscore>score?maxscore:score;
            }else if(score > 0){//if power is not enough but score is greater than 0, do the face down but not update the score
                power += tokens[right--];
                score--;
            }else{//no score and power left but still remain numbers in tokens
                break;
            }
        }
        
        return maxscore;
    }
};