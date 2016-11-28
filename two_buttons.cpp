#include<iostream>

using namespace std;

int main(){
	int n,m,a,b,ans,i,j;
	cin>>n>>m;
	if(n>m){
		cout<<n-m<<"\n";
		return 0;
	}
	j=n;
	i=0;
	while(j<m){
		j*=2;
		i++;
	}
	a=j-m;
	b=i;
	ans=0;

	while(a!=1&&b){
		if(a%2){
			ans+=2;
		}
		else{
			ans+=1;
		}
		b--;
		a/=2;
	}
	ans=ans+a+b;
	cout<<ans<<"\n";
	return 0;
}