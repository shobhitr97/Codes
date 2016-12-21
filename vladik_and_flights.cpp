#include<iostream>
#include<stdio.h>

using namespace std;

#define num 100005

int min(int a,int b){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	int i,a,b,n,af,ab,am,bm,bf,bb;
	char ch;
	bool air[num];
	cin>>n>>a>>b;

	for(i=1;i<=n;i++){
		cin>>ch;
		// cout<<ch<<" ";
		if(ch-'0'==0){
			air[i]=0;
		}		
		else{
			air[i]=1;
		}
	}
	// cout<<"\n";
	// for(i=1;i<=n;i++){
	// 	cout<<air[i]<<" ";
	// }
	// cout<<"\n";
	if(air[a]==air[b]){
		cout<<"0\n";
	}
	else{
		cout<<"1\n";
	}
	// af=-1;
	// for(i=a;i<=n;i++){
	// 	if(air[i]!=air[a]){
			
	// 		af=i;
	// 		break;
	// 	}
	// }
	// cout<<af<<"\n";

	// ab=-1;
	// for(i=a;i>=1;i--){
	// 	if(air[i]!=air[a]){
			
	// 		ab=i;
	// 		break;
	// 	}
	// }
	// cout<<ab<<"\n";

	// if(ab==-1||af==-1){
	// 	am=(a-ab)*(ab!=-1)+(af-a)*(af!=-1);
	// }
	// else{
	// 	am=min(a-ab,af-a);
	// }

	// bf=-1;
	// for(i=b;i<=n;i++){
	// 	if(air[i]!=air[b]){
			
	// 		bf=i;
	// 		break;
	// 	}
	// }
	// cout<<bf<<"\n";

	// bb=-1;
	// for(i=b;i>=1;i--){
	// 	if(air[i]!=air[b]){
			
	// 		bb=i;
	// 		break;
	// 	}
	// }
	// cout<<bb<<"\n";

	// if(bb==-1||bf==-1){
	// 	bm=(b-bb)*(bb!=-1)+(bf-b)*(bf!=-1);
	// }
	// else{
	// 	bm=min(b-bb,bf-b);
	// }
	// cout<< min(am,bm) <<"\n";
	return 0;
}