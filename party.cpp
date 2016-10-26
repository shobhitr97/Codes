#include<iostream>

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int n,a[2005],i,num,j,up,vis[2005];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		vis[i]=0;
		if(a[i]!=-1)
		    a[i]--;
	}
	up=0;
	for(i=0;i<n;i++){
		if(vis[i]){
			// cout<<"Skipped:"<<i<<"\n";
			continue;
		}
		// vis[i]=1;
		num=0;
		j=i;
		while(j!=-1){
			vis[j]=1;
			j=a[j];
			num++;
		}
		up=max(up,num);
	}
	cout<<up<<"\n";
	return 0;
}