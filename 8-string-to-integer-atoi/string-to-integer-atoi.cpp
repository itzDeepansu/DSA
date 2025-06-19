class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int i=0;
        long answer=0;
        while(i<s.size() && s[i]==' ') i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }else if(s[i]=='+') i++;
        if(s[i]=='0') i++;
        while(i<s.size() && isdigit(s[i])){
            answer=answer*10+(s[i]-'0');
            i++;
            if(sign*answer>=INT_MAX ) return INT_MAX;
            if(sign*answer<= INT_MIN) return INT_MIN;
        }
        return sign*answer;
    }
};