class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int z=nums.size();
        int c1=0;
        for(int i:nums){
            if(i>0){
                c1=c1+1;
            }
        }
        int arr1[z];
        int x=0,y=c1;
        for(int i=0;i<z;i++){
            if(nums.at(i)>0){
                arr1[x]=nums.at(i);
                x++;
            }
            else{
            arr1[y]=nums.at(i);
            y++;
            }
        }
         
        sort(arr1, arr1 + z);
        int d=1;
        for(int i=0;i<z;i++){
            if(arr1[i]==d){
                if(i!=(z-1)){
                d++;}
                if(i==(z-1)){
                    d++;
                   
                }
            }
            

        }
        return d;
    }
};