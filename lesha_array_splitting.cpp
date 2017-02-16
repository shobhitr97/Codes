#include<iostream>

using namespace std;

int main(){

	int n,k,a[105],l[105],r[105],sum,sump,beg,i;

	cin>>n;

	sum=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}

	l[0]=1;
	i=1;
	while(a[i]==0&&i<=n){
		i++;
	}

	if(sum==0&&i==(n+1)){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	// beg=i;
	sump=0;
	k=0;
	while(i<=n){
		sump+=a[i];
		if(a[i]!=0&&sump==0){
			r[k]=i-1;
			k++;
			l[k]=i;
			sump=0;
		}
		i++;
	}
	r[k]=n;

	cout<<k+1<<"\n";

	for(i=0;i<=k;i++){
		cout<<l[i]<<" "<<r[i]<<"\n";
	}

	return 0;
}