class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high, vector<int>& indexes, vector<int>& count){
        int left = low;
        int right = mid+1;
        int rightc= 0;
        vector<int> temp (high-low+1);
        int k = 0;

        while (left<= mid && right <= high){
            if (nums[indexes[left]] > nums[indexes[right]]){
                rightc++;
                temp[k++] = indexes[right++];
            }
            else{
                count[indexes[left]] += rightc;
                temp[k++] = indexes[left++];
            }

        }
        while(left <= mid){
            count[indexes[left]] += rightc;
            temp[k++] = indexes[left++];
        }
        while(right <= high){
            temp[k++] = indexes[right++];
        }

        for (int i = low; i <= high; i++){
            indexes[i] = temp[i-low];
        }
    }
    void mers(vector<int>& arr, int low, int high, vector<int>& indexes, vector<int>& count){
        if (low >= high){
            return;
        }
        int mid = (low+high)/2;

        mers(arr,low,mid,indexes,count);
        mers(arr,mid+1,high,indexes,count);
        merge(arr,low,mid,high,indexes,count);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);
        vector<int> indexes(n);
        for (int i = 0; i < n ; i++){
            indexes[i]=i;
        }
        mers(nums,0,n-1,indexes,count);
        return count;
    }
};