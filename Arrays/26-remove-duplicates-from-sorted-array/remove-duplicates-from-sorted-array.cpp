#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<N;i++){
            if(umap.find(nums[i])!= umap.end()){
                umap[nums[i]]++;
            }
            else{
                umap.insert(make_pair(nums[i],1));
            }
        }
        vector<int> result;
        for(auto i:umap){
            result.push_back(i.first);
        }
        nums.clear();
        nums = result;
        sort(nums.begin(),nums.end());
       return nums.size();
    }
};