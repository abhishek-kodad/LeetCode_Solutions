class Solution {
public:
    int findMin(vector<int>& nums) {
     int small = 0;
     int large = nums.size() - 1;
      int mid = small + ( large - small)/2;
     while(small < large)
     {
      if( nums[mid] > nums[large] )
      {
          small = mid + 1;
      }
      else if ( nums[mid] < nums[large])
     {
         large = mid;
     }
    
     else if(nums[large] == nums[large - 1])
     {
         large --;
     }
     else{
         small++;
     }
     mid = small + (large - small)/2;
     }
     return nums[small];
        
    }
};
