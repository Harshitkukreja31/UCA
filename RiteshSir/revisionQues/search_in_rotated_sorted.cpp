class Solution {
public:
    int search(vector<int>& arr, int target) {
        int s=0;
        int e=arr.size()-1;
        int mid=0;
  
        while(s<=e){
            mid=s+(e-s)/2;
            if(target==arr[mid]){
                return mid;
            }
            if(arr[s]<=arr[mid]){
                if(target>=arr[s] && target<arr[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else{
                if(target>arr[mid] && target<=arr[e]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};