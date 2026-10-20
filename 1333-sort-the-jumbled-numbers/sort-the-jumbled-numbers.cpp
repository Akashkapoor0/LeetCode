class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int val = 0;
            int digits = 0;
            if (a == 0)
                val = mapping[0];
            while (a) {
                int last = a % 10;
                a /= 10;
                val = mapping[last] * pow(10, digits++) + val;
            }
            arr.push_back({val, nums[i]});
        }
        stable_sort(arr.begin(), arr.end(),
                    [](auto& a, auto& b) { return a.first < b.first; });
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = arr[i].second;
        }
        return nums;
    }
};