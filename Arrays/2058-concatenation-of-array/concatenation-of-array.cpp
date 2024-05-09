class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int size = 2*n;
        vector<int> ans;

        for(int i=0;i<size;i++){
            if(i>=size/2){ ans.push_back(nums[i-n]);}
            else{
            ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};