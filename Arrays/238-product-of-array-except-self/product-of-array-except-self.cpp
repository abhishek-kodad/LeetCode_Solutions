class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int count = 0;
        int zeroIndex = -1;
        long long int product = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
                zeroIndex = i;
            }
            if(nums[i] != 0)
            {
                product*=nums[i];
            }
        }

        vector<int>output(nums.size(),0);

        if(count > 1) return output;

        if(count == 1) {
            output[zeroIndex] = product;
            return output;
        }

        for(int i=0;i<nums.size();i++)
        {
            output[i] = product/nums[i];
        }

        return output;

    }
};