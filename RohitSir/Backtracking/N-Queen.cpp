class Solution {
public:
    bool issafe(vector<string> &temp,int row,int col,int n){
        for(int i=0;i<=row;i++){
            if(temp[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(temp[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0&&j<n;i--,j++){
            if(temp[i][j]=='Q'){
                return false;
            }
        }

        return true;
    }
    void helper(vector<vector<string>> &ans,int n,vector<string> &temp,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(temp,row,i,n)){
                temp[row][i]='Q';
                helper(ans,n,temp,row+1);
                temp[row][i] = '.';
            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string p="";
        for(int i=0;i<n;i++){
            p.push_back('.');
        }
        vector<string>temp (n,p);
        vector<vector<string>> ans;
        helper(ans,n,temp,0);

        return ans;
    }
};