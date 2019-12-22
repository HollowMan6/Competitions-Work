#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int a,b,c,n;
    double d;
    cin>>n;
    double Max = sqrt(n);
    for(a = 0; a <= Max; a ++)
		for(b = a; b <= Max; b ++)
			for(c = b; c <= Max; c ++){
				d = sqrt(n - a*a - b*b - c*c);
				if(d == (int)d){ 
					cout<<a<<" "<<b<<" "<<c<<" "<<(int)d;
                    return 0;
				}
			}
}