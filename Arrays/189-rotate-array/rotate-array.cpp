class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
//Temp vector is taken for storing new index
        vector<int>ans(n);
        for(int i=0;i<n;i++){
//calculating new index for current index after shifting by k step
            int newindex=(i+k)%(nums.size());
            ans[newindex]=nums[i];
             
        }
//nums == ans which means nums is equal to the ans vector
        nums=ans;
    }
};