class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagramGroup;
        unordered_map<string,vector<string>> mp;
        for(auto str:strs){
            string copy = str;
            sort(copy.begin(),copy.end());
            mp[copy].push_back(str);
        }
        for(auto el:mp){
            anagramGroup.push_back(el.second);
        }
        return anagramGroup;
    }
};