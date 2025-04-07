#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int mod=1e9+7;
    int n,x;
    cin>>n>>x;
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c,c+n);
    int dp[n][x+1];
    for(int i=0;i<x+1;i++){
        if(i%c[0]==0){
            dp[0][i]=1;
        }else{
            dp[0][i]=0;
        }
    }
    for(int i=1;i<n;i++){
        dp[i][0]=1;
        for(int j=1;j<x+1;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<c[i];j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=c[i];j<x+1;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-c[i]])%mod;
        }
    }
    cout<<dp[n-1][x];

}