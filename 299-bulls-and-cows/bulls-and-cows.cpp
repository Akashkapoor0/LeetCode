class Solution {
public:
    string getHint(string s, string g) {
        vector<int>freq(10);
        int a = 0,b = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == g[i]) a++;
            else freq[s[i]-'0']++;
        }
        for(int i=0;i<g.size();i++){
            if(s[i] == g[i]) continue;
            else if(freq[g[i]-'0']>0){
                b++;
                freq[g[i]-'0']--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};