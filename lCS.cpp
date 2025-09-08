#include<iostream>
#include<vector>
#include<cstring>
#include<climits>
#define ll long long int
using namespace std;
int dp[1005][1005];
int solve(string &text1,string &text2,int i,int j){
     int m=text1.length();
    int n=text2.length();
    if(i>=m||j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j]) return dp[i][j]=1+solve(text1,text2,i+1,j+1);
    int a=solve(text1,text2,i+1,j);
    int b=solve(text1,text2,i,j+1);
    return dp[i][j]=max(a,b);
}
int main(){
    string text1,text2;
    cin>>text1>>text2;
   memset(dp,-1,sizeof(dp));
   int ans=solve(text1,text2,0,0);
   cout<<ans<<endl;

}