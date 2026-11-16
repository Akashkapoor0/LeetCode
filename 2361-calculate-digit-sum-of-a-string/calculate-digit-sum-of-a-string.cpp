
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string si = "";
            int sum = 0;
            int count = 0;

            for(int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';
                count++;

                if(count == k) {
                    si += to_string(sum);
                    sum = 0;
                    count = 0;
                }
            }

            if(count > 0) {
                si += to_string(sum);
            }

            s = si;
        }

        return s;
    }
};
