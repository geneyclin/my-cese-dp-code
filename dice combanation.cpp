#include<iostream>
using namespace std;
const int MOD = 1000000007;
int main(){
    long long a[6]={32,1,2,4,8,16};
    long long n;
 
    long long total=32;
    cin>>n;
    if(n<6){
        cout<<a[n];
    }else{
        long long i=7;
        long long j=1;
        long long k;
        while(i<=n){
            if((i%6-1)>=0){
                k=i%6-1;
            }else{
                k=5;
            }
            total=total;
            total+=a[k]%MOD;
            total-=j;
            j=a[i%6];
            a[i%6]=total%MOD;
            
            i=i+1;
        }
        cout<<total%MOD;
    }
}