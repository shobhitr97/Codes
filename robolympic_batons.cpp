#include<iostream>

using namespace std;

int special[500005];

int main(){
	int ult,i,count,n,m,pos[500005],j;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>special[i];
	}
	for(i=0;i<m;i++){
		cin>>pos[i];
	}
	ult=0;
	for(i=0;i<n;i++){
		count=0;
		for(j=0;j<m;j++){
			if(special[pos[j]]==1){
					count++;
				
			}
			pos[j]=(pos[j]+1)%n;
			
		}
		if(count==m){
				ult++;
		}

		
	}
	cout<<ult<<"\n";
	return 0;
}