#include <bits/stdc++.h>
using namespace std;

void setZeroesA(vector<vector<int>>& matrix) {
    int rowmask=0;
    int colmask=0;
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(matrix[i][j]==0){
                rowmask|=(1<<i);
                colmask|=(1<<j);
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if((rowmask & (1<<i))||colmask & (1<<j)){
                matrix[i][j]=0;
            }
        }
    }

}


    void setZeroesB(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool firstrow=false;
        bool firstcol=false;
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0){
                firstrow=true;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0){
                firstcol=true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrow){
            for(int j=0;j<n;j++){
                matrix[0][j]=0;
            }
        }
        if(firstcol){
            for(int i=0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }

void print(vector<vector<int>>& matrix,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<int>> mat={
            {1,0,0},
            {1,1,1},
            {0,1,1}
    };
    int r=mat.size();
    int c=mat[0].size();
    print(mat,r,c);
    setZeroesA(mat);

    print(mat,r,c);
}