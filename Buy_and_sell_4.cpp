#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int dp[1005][1005][2];
int solve(vector<int>& prices,int k,int i,bool on){
    if(i==prices.size())return 0;
    if(dp[i][k][on]!=-1)return dp[i][k][on];
    int ans=INT_MIN;
    ans=solve(prices,k,i+1,on);//avoid
    if(on){
        ans=max(ans,solve(prices,k-1,i+1,false)+prices[i]);//sell
    }
    else{
        if(k>0){
             ans=max(ans,solve(prices,k,i+1,true)-prices[i]); 
        }
    }
    return dp[i][k][on]=ans;
}
    int maxProfit(int k, vector<int>& prices) {
       memset(dp,-1,sizeof(dp));
       int ans=solve(prices,k,0,false);
       return ans; 
    }
};