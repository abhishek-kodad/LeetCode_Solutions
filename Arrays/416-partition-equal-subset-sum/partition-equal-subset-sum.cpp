class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        /*
            If Sum is odd, it is clear that we cannot have 
            subset of any length which have equal sum. Since
            Odd Sum can be obtained by adding even sum + odd Sum
            For ex: 23 = 11 (odd) + 12 (even).
            Therefore, directly return FALSE;
        */
        if(sum%2 !=0 ) return false;

        /*
            However if the sum is even, then it can be obtained by 
            adding odd sum + odd sum or even sum + even sum
            For ex: 6 = 3 (odd sum) + 3 (odd sum)
            For ex: 8 = 4 (even sum) + 4 (even sum)
        */
        int n = nums.size();
        sum = sum/2;
        bool possible[n+1][sum+1];
        for(int i=1; i<=sum; i++) possible[0][i] = false;
        for(int i=0; i<=n; i++) possible[i][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(nums[i-1] > j) possible[i][j] = possible[i-1][j];
                else possible[i][j] = possible[i-1][j-nums[i-1]] || possible[i-1][j];
            }
        }
        return possible[n][sum];
    }
};