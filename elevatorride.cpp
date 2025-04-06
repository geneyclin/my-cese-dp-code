#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> dp(1<<n),last(1<<n);
    dp[0]=1;
    last[0]=0;
    for(int i=1;i<=(1<<n);i++){
        dp[i]=INT_MAX;
        last[i]=INT_MAX;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                int a=i-(1<<j);
                if(last[a]+v[j]<=x){
                    if(dp[a]<dp[i]||(dp[a]==dp[i]&&last[a]+v[j]<last[i])){
                        dp[i]=dp[a];
                        last[i]=last[a]+v[j];
                    }
                }else{
                    if(dp[a]+1<dp[i]||(dp[a]+1==dp[i]&&v[j]<last[i])){
                        dp[i]=dp[a]+1;
                        last[i]=v[j];
                    }

                }
            }
        }
        
    }
    cout<<dp[(1<<n)-1]<<endl;


    return 0;
}