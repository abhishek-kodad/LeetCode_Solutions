class Solution {
public:
    int jump(vector<int>& nums) {
        int pos=0,des=0,jump=0;
        for(int i=0;i<nums.size()-1;i++){
            des=max(des,nums[i]+i);
            if(pos==i){
                pos=des;
                jump++;
            }
        }
        if(pos>=nums.size()-1){
            return jump;
        }
        else
        return -1;
    }
};