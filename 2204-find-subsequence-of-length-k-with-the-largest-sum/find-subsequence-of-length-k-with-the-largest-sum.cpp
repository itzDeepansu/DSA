class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> answer;
        priority_queue<int> largest;
        for(auto el:nums) largest.push(el);
        unordered_map<int,int> freq;
        int tempK = k;
        while(tempK){
            freq[largest.top()]++;
            largest.pop();
            tempK--;
        }
        for(auto el:nums){
            if(answer.size() == k) return answer;
            if(freq[el]){
                answer.push_back(el);
                freq[el]--;
            }
        }
        return answer;
    }
};