class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        int longestLen=0;
        int localLen=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int> freq;
            for(int j=i;j<s.size();j++){
                if(freq[s[j]]){
                    longestLen=max(longestLen,localLen);
                    break;
                }
                else{
                    freq[s[j]]++;
                    localLen++;
                }
            }
            longestLen=max(longestLen,localLen);
            localLen=0;
        }
        return longestLen;
    }
};