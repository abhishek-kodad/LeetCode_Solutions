class Solution {
public:
    int solve(int i,int j,vector<int> &v,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int a = max(v[i]+min(solve(i+2,j,v,dp),solve(i+1,j-1,v,dp)),v[j]+min(solve(i,j-2,v,dp),solve(i+1,j-1,v,dp)));
        return dp[i][j] = a;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int a = solve(0,n-1,nums,dp);
        cout<<a<<" ";
        int s = 0;
        for(auto &i: nums)s += i;
        if(a >= s-a)return true;
        return false;
    }
};