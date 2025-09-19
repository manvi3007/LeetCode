/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int Peak(MountainArray &mountainArr){
         int n = mountainArr.length();
        int low = 0;
        int high = n-1;

        while(low < high){
            int mid = low +(high - low)/2;
            if (mountainArr.get(mid) < mountainArr.get(mid+1)){
                low = mid +1;
            }
            else{
                high = mid -1 ;
            }
        }
        return low;
    }

    int searchL(int target, MountainArray &mountainArr, int low , int high){
        while(low<=high){
            int mid = low + (high - low)/2;
            int val = mountainArr.get(mid);
            if (val == target){
                return mid;
            }
            else if (val < target){
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;

    }

    int searchR (int target, MountainArray &mountainArr, int low , int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = mountainArr.get(mid);
            if (val == target){
                return mid;
            }
            else if (val > target){
                low = mid +1;

            }
            else{
                high = mid -1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = Peak(mountainArr);
        int left = searchL(target,mountainArr,0,peak);
        if (left != -1) {return left;}
        return searchR(target,mountainArr,peak+1, mountainArr.length()-1);
    }
};