#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define ll long long int
using namespace std;
ll dp[2005][2005][8];
ll solve(string &text1,string &text2,int i,int j,int k){
     int m=text1.length();
    int n=text2.length();
    if(i>=m||j>=n)return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    ll res=0;
    if(text1[i]==text2[j]) res=1+solve(text1,text2,i+1,j+1,k);
   else{if(k>0) res=1+solve(text1,text2,i+1,j,k-1);
    res=max(res,solve(text1,text2,i+1,j,k));
    res=max(res,solve(text1,text2,i,j+1,k));
}
return  dp[i][j][k]=res;
  
}
int main(){
    string text1,text2;
    cin>>text1>>text2;
    int k;
    cin>>k;
   memset(dp,-1,sizeof(dp));
   ll ans=solve(text1,text2,0,0,k);
   cout<<ans<<endl;

}