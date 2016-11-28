#include<iostream>

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int l[300005],n,i,r[300005],a[300005],maxm,m,d,l1,r1;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	cin>>m;
	while(m--){
		cin>>l1>>r1>>d;
		for(i=l1-1;i<r1;i++){
			a[i]+=d;
		}
	}


	l[0]=0;
	for(i=1;i<n;i++){
		if(a[i]>a[i-1]){
			l[i]=l[i-1]+1;
		}
		else{
			l[i]=0;
		}
	}

	r[n-1]=0;
	for(i=n-2;i>=0;i--){
		if(a[i]>a[i+1]){
			r[i]=r[i-1]+1;
		}
		else{
			r[i]=0;
		}
	}
	for(i=0;i<n;i++){
		maxm=max(maxm,l[i]+r[i]+1);
	}
	return 0;
}