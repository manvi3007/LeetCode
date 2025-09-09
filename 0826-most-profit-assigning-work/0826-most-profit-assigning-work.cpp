class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>>jobs(n);
        int profitt = 0;
        int j = 0;
        int total = 0;

        for (int i = 0; i < n ; i++){
            jobs[i]={difficulty[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());

        for ( int i = 0 ; i< worker.size();i++){
            int ability = worker[i];
            while (j < n && ability >= jobs[j].first) {
                profitt = max(profitt,jobs[j].second );
                j++;
            }
            total += profitt;
            
        }
        return total;
    }

};