class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int distance=1;
        unordered_map<string,bool> dict;
        dict[beginWord]=true;
        for(auto str : wordList) dict[str]=false;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            cout<<sz<<endl;
            for(int i=0;i<sz;i++){
                string str = q.front();
                q.pop();
                for(int j = 0;j<str.size();j++){
                    char original = str[j];
                    for(char ch='a' ; ch<='z' ;ch++){
                        if(ch == original) continue;
                        str[j]=ch;
                        if(dict.count(str) && !dict[str]){
                            cout<<str<<" ";
                            if(str==endWord) return distance+1;
                            q.push(str);
                            dict[str]=true;
                        }
                    }
                    cout<<endl;
                    str[j]=original;
                }
                cout<<endl;
            }
            distance++;
        }
        return 0;
    }
};