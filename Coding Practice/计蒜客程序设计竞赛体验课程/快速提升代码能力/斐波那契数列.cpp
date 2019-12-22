#include<iostream>
using namespace std;
int main(){
    long long n1=1,n2=1,n3=1,n;
    cin>>n;
    for(int i=2;i<n;i++){
        n3=(n1+n2)%1000000007;
        n1=n2;
        n2=n3;
    }
    cout<<n3;
}