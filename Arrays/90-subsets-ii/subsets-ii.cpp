class Solution {
public:    
    void subsetHelper(int idx, vector<int>& nums, int n, vector<int> &temp, vector<vector<int>>& ans) {
        ans.push_back(temp);
        for (int i = idx; i < n; i++) {
            if (i != idx && nums[i] == nums[i-1])
                continue;
            temp.push_back(nums[i]);
            subsetHelper(i+1, nums, n, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        subsetHelper(0, nums, n, temp, ans);
        return ans;
    } 
};