#include<iostream>

using namespace std;

int aa[501][501];
int n,m;

int main(){
	cin>>n>>m;
	char ch;
	int i,j;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>ch;
			if(ch=='.'){
				aa[i][j]=0;
			}
			else{
				aa[i][j]=1;
			}
		}
	}
	int sum;
	for(i=1;i<=n;i++){
		sum=0;
		for(j=1;j<=m;j++){
			sum+=aa[i][j];
		}
		aa[i][0]=sum;
	}

	for(i=1;i<=m;i++){
		sum=0;
		for(j=1;j<=n;j++){
			sum+=aa[j][i];
		}
		aa[0][i]=sum;
	}

	int val;


	for(i=1;i<=n;i++){
		if(aa[i][0]==0){
			continue;
		}
		j=1;
		while(aa[i][j]==0){
			j++;
		}
		val=j;

		while( j < (val+aa[i][0]) ){
			if(aa[i][j]!=1){
				cout<<"NO\n";
				return 0;
			}
			j++;
		}
	}
	int flag=1,diff;
	diff=0;
	
	i=1;
	while(aa[i][0]==0&&i<=n){
		i++;
	}
	while(aa[i][0]==1&&i<=n){
		i++;
	}
	while(i<=n){
		if(aa[i][0]!=0){
			cout<<"NO\n";
			return 0;
		}
		i++;
	}
	
	

	i=1;
	while(aa[0][i]==0&&i<=m){
		i++;
	}
	while(aa[0][i]==1&&i<=m){
		i++;
	}
	while(i<=m){
		if(aa[0][i]!=0){
			cout<<"NO\n";
			return 0;
		}
		i++;
	}
	cout<<"YES\n";
	return 0;
}