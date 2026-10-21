class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            for (int j = 0; j < ans.length(); j++) {
                if (j + 1 < ans.length() && ans[j] == ans[j + 1]) {
                    count++;
                } else {
                    temp += to_string(count) + ans[j];
                    count = 1;
                }
            }
            ans = temp;
        }
        return ans;
    }
};