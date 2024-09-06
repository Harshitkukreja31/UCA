#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
        
       vector<int>v(ratings.size(),1);
 
       for(int i=0;i<ratings.size();i++){           
         if(i>0 && ratings[i]>ratings[i-1]){
             v[i] = v[i-1]+1;
         }

         if(i<ratings.size()-1 && ratings[i]>ratings[i+1]){
             if(v[i]<=v[i+1]){
                v[i] = v[i+1]+1;
             }
         }
       }

         for(int i=ratings.size()-1;i>=0;i--){
             if(i>0 && ratings[i]>ratings[i-1]){
                if(v[i-1]<=v[i]){
                  v[i] = v[i-1]+1;
                } 
             }

         if(i<ratings.size()-1 && ratings[i]>ratings[i+1]){
             if(v[i]<=v[i+1]){
                v[i] = v[i+1]+1;
             }
           }
         }
         
       int sum=0;

       for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
         sum+=v[i];
       }

       return sum;
    }