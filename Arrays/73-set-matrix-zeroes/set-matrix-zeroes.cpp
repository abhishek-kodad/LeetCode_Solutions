class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we will keep the rows and col of 0 value 
        set<int>r;
        set<int>c;
        int rows=matrix.size();
        int cols=matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        //now comes the part of making rows and col = 0
        //for rows
        for(auto i:r){
            for(int j=0;j<cols;j++){
                matrix[i][j]=0;
            }
        }

        // for cols
        for(auto j:c){
            for(int i=0;i<rows;i++){
                matrix[i][j]=0;
            }
        }
        
    }
};