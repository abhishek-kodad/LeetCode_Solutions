class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), element;
        if(n==1){
            return;
        }
        int index=-1;
        priority_queue<int> pq;
        for(int i=n-1; i>=0; i--){
            pq.push(nums[i]);
            if(pq.top()!= nums[i]){
                index = i;
                break;
            }
        }

        if(index == -1){
            sort(nums.begin(), nums.end());
            return;
        }

        int check, k = n-1;
        bool flag = true;
        element = nums[index];
        while (!pq.empty()) {
            if(pq.top() == element && flag){
                check = k+1;
                flag = false;
            }
            nums[k] = pq.top();
            pq.pop();
            k--;
        }
        
        reverse(nums.begin() + index, nums.begin() + check);
        reverse(nums.begin() + index, nums.begin() + check+1);

    }
};