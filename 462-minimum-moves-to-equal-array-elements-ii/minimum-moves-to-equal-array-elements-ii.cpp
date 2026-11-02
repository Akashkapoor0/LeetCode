class Solution {
public:
    int minMoves2(vector<int>& nums) {
        map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        int n = nums.size() / 2 +1;
        int val = 0;

        for (auto m : mp) {
            n -= m.second;

            if (n <= 0) {
                val = m.first;
                break;
            }
        }

        int ans = 0;

        for (int x : nums) {
            ans += abs(x - val);
        }

        return ans;
    }
};