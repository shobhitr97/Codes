#include<iostream>

using namespace std;

typedef long long int ll;

ll min(ll a,ll b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	ll a,b,c,n;
	cin>>n>>a>>b>>c;
	switch(n%4){
		case 0:cout<<"0\n";break;
		case 1:cout<<min(min(c,b+a),3*a)<<"\n";break;
		case 2:cout<<min(min(2*a,b),2*c)<<"\n";break;
		case 3:cout<<min(min(a,b+c),3*c)<<"\n";break;
		default:break;
	}
	return 0;
}