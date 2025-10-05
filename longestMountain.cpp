class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int l=arr.size();
        vector<int>peaks;
        for(int i=1;i<l-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                peaks.push_back(i);
            }
        }
        int ans=0;
        if(peaks.size()==0)return 0;
        int j=0;
        int p=peaks.size();
        while(j<p){
        int left=peaks[j];
        int right=peaks[j];
            while(left>0 && arr[left]>arr[left-1]){
                left--;
            }
            while(right<l-1 && arr[right]>arr[right+1]){
                right++;
            }
            if(right==l)right--;
            if(left==-1)left=0;
            int len=right-left+1;
            ans=max(ans,len);
            j++;
        }
        return ans;
    }
};
