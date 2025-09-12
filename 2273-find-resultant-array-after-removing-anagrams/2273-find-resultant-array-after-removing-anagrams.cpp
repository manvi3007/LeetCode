class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size();i++){
            string curr = words[i];
            string prev = words[i-1];
            string scurr = curr;
            string sprev = prev;

            sort(scurr.begin(),scurr.end());
            sort(sprev.begin(),sprev.end());

            if (scurr != sprev){
                ans.push_back(curr);
            }
        }
        return ans;
    }
};