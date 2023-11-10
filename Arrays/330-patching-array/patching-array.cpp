/*
i E to [1,n]
reach at ith day if nums[j]<=i+1 than add nums[j] into i  else add i+1 in to ith day
*/
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long sum = 0, cnt = 0, i = 0;
        while(sum<n){
            if(i<nums.size()&&nums[i]<=sum+1){
                sum += nums[i++];
            }else{
                cnt++;
                sum += sum+1;
            }
        }
        return cnt;
    }
};