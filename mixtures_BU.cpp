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

int main(){
     int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp.clear();
    dp.resize(1005,vector<int>(1000,0));

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+color_mix(i,k,arr)*color_mix(k+1,j,arr));
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    // cout<<f(0,n-1,arr)<<endl;
}