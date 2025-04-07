#include<iostream>
#include<vector>
#include<cmath>
long long power(long long x,long long y){
    long long ans=1;
    for(int i=0;i<y;i++){
        ans*=x;
    }
    return ans;
}
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    vector<long long> n;
    int test=0;
    long long totala=0;
    if(a/10!=0){
        a=a-1;
        while(a!=0){
            n.push_back(a%10);
            a/=10;
        }
        
        totala+=n[n.size()-1]*power(9,n.size()-1);
        for(long long i=0;i<n.size()-1;i++){
            totala+=power(9,i);
        } 
    }else{
        totala=a-1;
    }
    
 
    if(n.size()>=2){
        for(long long i=n.size()-2;i>=0;i--){
            if(n[i+1]<n[i]){
                totala+=(n[i]-1)*power(9,i);
            }else if(n[i+1]==n[i]){
                totala+=(n[i])*power(9,i);
                test=1;
                break;
            }else{
                totala+=n[i]*power(9,i);
            }   
        }  
    }
    if(test==0){
        totala+=1;
    }
    n.clear();
 
    long long totalb=0;
    if(b/10!=0){
        while(b!=0){
            n.push_back(b%10);
            b/=10;
        }    
        totalb+=(n[n.size()-1]-1)*power(9,n.size()-1);
        for(long long i=0;i<n.size();i++){
            totalb+=power(9,i);

        }  
    }else{
        totalb=b;
    }
    
    test=0;
    if(n.size()>=2){
        for(long long i=n.size()-2;i>=0;i--){
            if(n[i+1]<n[i]){
                totalb+=(n[i]-1)*power(9,i);
            }else if(n[i+1]==n[i]){
                totalb+=(n[i])*power(9,i);
                test=1;
                break;
            }else{
                totalb+=n[i]*power(9,i);
            }   
        }
        
    }
    if(test==0){
        totalb+=1;
    }
    cout<<totalb-totala<<endl;

 
    
}
