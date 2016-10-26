#include<iostream>

using namespace std;

int main(){
	int k,i,m,n,d,D,j,t;
	cin>>t;
	while(t--) {
		cin >> n >> m >> d >> D;
		
		if(m<n*d||m>n*D){
			cout<<"-1\n";
			continue;
		}
		i=0;
		k=0;
		while(m--){
			cout<<(i+1)<<" "<<(k+1)<<"\n";
			k=(k+1)%n;
			if(i==n-1){
				k=(k+1)%n;
			}
			i=(i+1)%n;
		}
	}
	return 0;
}