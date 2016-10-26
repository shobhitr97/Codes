#include<iostream>

using namespace std;

int main(){
	int n,m,i;
	cin>>n>>m;
	i=0;
	while(n<m){
		i++;
		n*=2;
	}
	cout<<(i+(n-m))<<"\n";
	return 0;
}