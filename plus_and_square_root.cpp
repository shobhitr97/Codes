#include<math.h>
#include<iostream>
typedef long long int ll;
using namespace std;

int main(){
	double m,c,n,t,k0,k,i;
	cin>>n;
	i=1;
	p=2;
	c=2;
	while(i<=n){
		m=i;
		k0=p/m;
		c=ceil(sqrt((k0+m-((ll)k0%(ll)m))/m));
		p=(m+1)*c;
		t=(p*p-k0)/m;
		cout<<t<<"\n";
		i++;
	}
	return 0;
}