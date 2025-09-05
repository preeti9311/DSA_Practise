#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<vector<int>>dp;
int color_mix(int i,int j,vector<int>&color){
    int sum=0;
     for(int k=i;k<=j;k++){
       sum+=color[k];
     }
     return sum %100;
}
int f(int i,vector<int>&color,int j){
    if(i==j)return 0;
    if(i+1==j)return color[i]*color[j];
    if(dp[i][j]!=0)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
    ans=min(ans,f(i,color,k)+f(k+1,color,j)+(color_mix(i,k,color)*color_mix(k+1,j,color)));
    }
    return dp[i][j]=ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>color(n);
    for(int i=0;i<n;i++){
        cin>>color[i];
    }
    dp.clear();
    dp.resize(1005,vector<int>(1000,0));
    cout<<f(0,color,n-1)<<endl;

}