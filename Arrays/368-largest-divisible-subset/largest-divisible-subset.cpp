class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>vec(nums.size(),1);
        vector<int> ans;

        int maxi=0;
        int maxx=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0)
                    vec[i]=max(vec[j]+1,vec[i]);
            }
            maxi=max(maxi,vec[i]);
            if(maxi==vec[i])
                maxx=i;
        }
        int k=vec[maxx];
        int i=nums.size()-1;
        int x=nums[maxx];
        while(k){
            if(vec[i]==k && x%nums[i]==0){
                ans.push_back(nums[i]);
                k--;
                x=nums[i];
            }
            i--; 
        }


        return ans;
    }
};