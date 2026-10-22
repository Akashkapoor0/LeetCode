class Solution {
public:
    void merge(vector<int>&a,vector<int>&temp,int l,int m,int r){
        int i = l,k = l,j = m+1;
        while(i<=m&&j<=r){
            if(a[i]<=a[j]){
                temp[k] = a[i];
                i++;
                k++;
            }
            else{
                temp[k] = a[j];
                k++;
                j++;
            }
        }
        while(i<=m){
            temp[k] = a[i];
            k++;
            i++;
        }
        while(j<=r){
            temp[k] = a[j];
            k++;
            j++;
        }
        for(int p = l;p<=r;p++){
            a[p] = temp[p];
        }
    }
    void mergeSort(vector<int>&a,vector<int>&temp,int l,int r){
        if(l>=r) return ;
        int m = l + (r-l)/2;
        mergeSort(a,temp,l,m);
        mergeSort(a,temp,m+1,r);
        if(a[m]<=a[m+1]) return;
        merge(a,temp,l,m,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()<2) return nums;
        vector<int>temp(nums.size());
        mergeSort(nums,temp,0,nums.size()-1);
        return nums;
    }
};