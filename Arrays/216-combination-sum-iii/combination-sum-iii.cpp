class Solution {
public:
    void solve(int index, vector<int>& ds, int target, int size, vector<vector<int>>& result, vector<int> arr){
        if(ds.size() == size){
            if(target == 0) result.push_back(ds);
            return;
        }
        
        if(index == 9) return;
        if(arr[index] > target) return;

        ds.push_back(arr[index]);
        solve(index + 1, ds, target - arr[index], size, result, arr);
        ds.pop_back();
        solve(index + 1, ds, target, size, result, arr);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<int> ds;
        vector<vector<int>> result;
        solve(0, ds, n, k, result, arr);
        return result; 
    }
};