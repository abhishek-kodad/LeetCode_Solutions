class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // creating two arrays which will stores the right max and left min values of index of the array nums  
        vector<int> a(nums.size());vector<int> b(nums.size());
        // at starting the min value is the number it self and at end the max value is also number it self 
        a[0]=nums[0];b[nums.size()-1]=nums[nums.size()-1];
        // filling up all the left minimum value using a single loop
        for(int i=1;i<nums.size();i++) a[i]=min(a[i-1],nums[i]);
        // filling up all the right max value using a single loop 
        for(int i=nums.size()-2;i>=0;i--) b[i]=max(b[i+1],nums[i]);
        // if the pair exists we return true and if not the answer will be false 
        for(int i=1;i<nums.size()-1;i++) if(nums[i]>a[i] && nums[i]<b[i]) return true;
        return false;
    }
};