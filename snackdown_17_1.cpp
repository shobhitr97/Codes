#include<iostream>

using namespace std;

#define fori(a, b) for(int i=a ; i<b ; i++)

int main(){
	int t, n, m, u, v;
	cin>>t;
	while(t--){
		cin>>n>>m;
		fori(0, m){
			cin>>u>>v;
		}
		if(n&1)	cout<<"no\n";
		else	cout<<"yes\n";
	}
	return 0;
}