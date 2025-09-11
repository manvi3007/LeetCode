class Solution {
public:
    void merge(vector<int>& arr, int low, int mid , int high){
        int left = low;
        int right = mid+1;
        vector<int>temp;

        while(left <= mid && right<= high){
            if (arr[left] < arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }

        }
        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = low ; i <= high; i++){
            arr[i]=temp[i-low];
        }
  
    }
    int count(vector<int>& arr, int low, int mid, int high){
        int right = mid+1;
        int cnt = 0;
        for (int i = low; i <= mid; i++ ){
            while(right <= high && (long long )arr[i]> (2LL  * arr[right])){
                right++;
            }
            cnt += (right-(mid+1));


        }
        return cnt;
    }
    int ms (vector<int>& arr, int low,int high){
         int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low+high)/2;
      

        cnt+=ms(arr,low,mid);
        cnt+=ms(arr,mid+1,high);
        cnt+=count(arr,low,mid,high);
        merge(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        return ms(nums,0,n-1);
    }
};