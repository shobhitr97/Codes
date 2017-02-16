#include<iostream>
using namespace std;
int main(){
	long long int a,b,c,n,m,t=10;
	while(t--){
		a=0;
		b=1;
		cin>>n>>m;
		n--;
		while(n--){
			c=a+b;
			a=b;
			b=c;

		}
		cout<<c%m<<"\n";
	}
	return 0;
}