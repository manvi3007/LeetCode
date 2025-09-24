class Solution {
public:
    bool check (string s , int len , int k){
        int cT = 0;
        int cF = 0;
        int n = s.size();
        for (int i = 0; i < len; i++){
            if(s[i]=='T'){
                cT++;
            }
            else{
                cF++;
            }
        }
        if(min (len-cT, len-cF) <= k){
            return true;
        }

        for (int i = len ; i < n; i++){
            if(s[i]=='T'){
                cT++;
            }
            else{
                cF++;
            }
            if(s[i-len]=='T') cT--;
            else{
                cF--;
            }
            if(min (len-cT, len-cF)<=k){
            return true;
        }
        
        }
        return false;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int low = 1;
        int high = answerKey.size();
        int ans = 0;
        while(low<=high){
            int mid = low+(high - low)/2;
            if(check(answerKey,mid,k)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};