class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        vector<int> result;
        for(int i=0;i<N;i++){
            if(nums[i] != val){
                result.push_back(nums[i]);
            }
        }
        nums.clear();
        nums = result;
        return nums.size();
    }
};