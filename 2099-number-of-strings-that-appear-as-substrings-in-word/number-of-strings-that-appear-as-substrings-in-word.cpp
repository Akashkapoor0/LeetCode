class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count=0;
        for(string subString : patterns){
            if(word.contains(subString)){
                count++;
            }
        }
        return count;
    }
};