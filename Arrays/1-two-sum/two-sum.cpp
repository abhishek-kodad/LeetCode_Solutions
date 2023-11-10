class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            int num=target-nums[i];
            if(map.find(num)==map.end()){
                map.insert({nums[i],i});
            }
            else{
                return {i,map[target-nums[i]]};
            }
        }
        return {0,0};
        
    }
};