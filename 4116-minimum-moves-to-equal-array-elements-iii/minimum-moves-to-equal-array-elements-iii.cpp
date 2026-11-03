class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum =0;
        for(int x:nums){
            if(x!=maxi){
                sum+= maxi-x; 
            }
        }
        return sum;
    }
};