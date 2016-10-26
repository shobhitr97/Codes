#include<iostream>

#define MOD 1000000007w
typedef long long int ll;

using namespace std;

int main(){
	int n,i;
	ll a,b,c;
	cin>>n;
	if(n==2){
		cout<<"3\n";
		return 0;
	}
	a=0;
	b=3;
	for(i=3;i<=n;i++){
		c=((a*3)%MOD+(b*2)%MOD)%MOD;
		a=b;
		b=c;
	}
	cout<<c<<"\n";
	return 0;
}