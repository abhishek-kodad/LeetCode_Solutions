class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> output;

        for(int i=0;i<nums.size();i++){
            output.push_back(nums[nums[i]]);
        }
        return output;
    }
};