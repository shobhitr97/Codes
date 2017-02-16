#include<iostream>
using namespace std;

int main(){
	int a,b,c;
	
	cin>>a>>b;

	if(!a && !b){
		cout<<"NO\n";
		return 0;
	}

	c = a-b;

	if( c <= 1 && c >= -1 ){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}

	return 0;
}