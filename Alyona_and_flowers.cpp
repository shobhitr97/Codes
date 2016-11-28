#include<iostream>

typedef long long int ll;

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int l,n,m,r,a[105];
	int i,j,max_mood,temp;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	
	max_mood=0;
	while(m--){
		temp=0;
		cin>>l>>r;
		for(j=l;j<=r;j++){
			temp+=a[j];
		}
		max_mood=max(max_mood,max_mood+temp);
	}

	cout<<max_mood<<"\n";

	return 0;
}