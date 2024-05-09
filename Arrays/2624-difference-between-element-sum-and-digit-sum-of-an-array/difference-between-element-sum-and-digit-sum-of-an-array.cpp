class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int digiSum = 0;
        int eleSum = 0;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            eleSum+=a;
            if(a>=10){
                while(a){
                    digiSum+=a%10;
                    a=a/10;
                }
            }
            else{
                digiSum+=a;
            }
        }
        if(eleSum>digiSum){return eleSum - digiSum;}
        else{
            return digiSum - eleSum;
        }
    }
};