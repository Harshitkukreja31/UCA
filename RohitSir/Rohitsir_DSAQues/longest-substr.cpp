#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) 
{
       int l=0;
        map<char,int>mp;
        int i=0;
        int j;
        for(j=0;j<s.size();j++)
        {
            if(mp.find(s[j])!=mp.end())
            {
                l=max(l,j-i);
                mp[s[j]]++;
                while(s[i]!=s[j])
                {
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
                mp[s[i]]--;
                i++;
            }
            else
                mp[s[j]]++;
        }
        l=max(l,j-i);
        return l;
}


int main()
{
    string str="pwwkew";
    int ans=lengthOfLongestSubstring(str);
    cout<<"Length :"<<ans<<endl;
    
    return 0;
}