class Solution {
public:
    string intToRoman(int num) {
        string answer = "";
        unordered_map<int, string> romans;
        romans[1] = "I";
        romans[5] = "V";
        romans[10] = "X";
        romans[50] = "L";
        romans[100] = "C";
        romans[500] = "D";
        romans[1000] = "M";

        int freq = 0;
        for (int i = 1000; i >= 1; i /= 10) {
            freq = num / i;
            num = num % i;
            if (freq <= 3) {
                while (freq != 0) {
                    answer += romans[i];
                    freq--;
                }
            } 
            else if(freq==4) {
                answer+=romans[i];
                answer+=romans[i*5];
            }
            else if( freq ==9){
                answer+=romans[i];
                answer+=romans[i*10];
            }
            else{
                answer+=romans[i*5];
                freq-=5;
                while(freq!=0){
                    answer+=romans[i];
                    freq--;
                }
            }
        }

        return answer;
    }
};