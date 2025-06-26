class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right = nums.size();
        while(left<right){
            int comp = nums[(left+right)/2];
            if(comp==target){
                return ((left+right)/2);
            }else if(comp>target){
                right=(left+right)/2-1;
            }else{
                left=(left+right)/2+1;
            }
        }
        if(left<nums.size() ){
            if( nums[left]>=target) return left;
            else return left+1;
        }else return left;
    }
};