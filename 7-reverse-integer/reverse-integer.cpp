class Solution {
public:
    int reverse(int x) {
        int sign=1;
        int temp=x;
        long long answer=0;
        if(x<0) sign=-1;
        while(temp){
            if(INT_MAX<sign*answer*10) return 0;
            if(INT_MIN>sign*answer*10) return 0;
            answer=(answer*10)+(temp%10);
            temp/=10;
        }
        answer*=sign;
        return answer*sign;
    }
};