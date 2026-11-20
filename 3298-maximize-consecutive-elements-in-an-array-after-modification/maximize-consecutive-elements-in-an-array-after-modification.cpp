class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx - mn + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i] - mn]++;
        }
        vector<int> arr(freq.size() + 2, 0);
        int count = 0;
        int temp = 0;
        for (int i = 0; i < freq.size(); i++) {
            temp = freq[i];
            while (temp--) {
                arr[i + 2] = max(arr[i + 2], arr[i + 1] + 1);
                arr[i + 1] = max(arr[i + 1], arr[i] + 1);
                count = max(count, max(arr[i + 1], arr[i + 2]));
            }
        }
        return count;
    }
};