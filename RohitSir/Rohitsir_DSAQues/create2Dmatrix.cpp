#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        int ind1 = 0;
        int mini1 = INT_MAX;

        for(int i=0;i<n;i++){
            if(rowSum[i]<mini1){
                mini1 = rowSum[i];
                ind1=i;
            }
        }

        int ind2 = 0 ;
        int mini2 = INT_MAX;

        for(int i=0;i<m;i++){
            if(colSum[i]<mini2){
                mini2 = colSum[i];
                ind2=i;
            }
        }
        vector<vector<int>>v(n,vector<int>(m,0));
        if(mini1<mini2){
           v[ind1][0]=mini1;
           rowSum[ind1]-=mini1;
           colSum[0]-=mini1;
        }
        else{
            v[0][ind2]=mini2;
            rowSum[0]-=mini2;
            colSum[ind2]-=mini2;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==0){
                    int mini = min(rowSum[i],colSum[j]);
                    v[i][j]=mini;
                    rowSum[i]-=mini;
                    colSum[j]-=mini;
                }
            }
        }

        return v;

    }