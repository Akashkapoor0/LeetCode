class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 0;
        int s1 = 0, s2 = 0;
        for (int x : nums) {
            if (s1 > 0 && c1 == x) {
                s1++;
            }
            else if (s2 > 0 && c2 == x) {
                s2++;
            }
            else if (s1 == 0) {
                c1 = x;
                s1 = 1;
            }
            else if (s2 == 0) {
                c2 = x;
                s2 = 1;
            }
            else {
                s1--;
                s2--;
            }
        }
        s1 = 0;
        s2 = 0;
        for (int x : nums) {
            if (x == c1) s1++;
            else if (x == c2) s2++;
        }
        vector<int> v;
        int n = nums.size() / 3;
        if (s1 > n) v.push_back(c1);
        if (s2 > n) v.push_back(c2);
        return v;
    }
};