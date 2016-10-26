#include<iostream>
using namespace std;


int main(){
	int n,c,i,pp,p,sum;
	cin>>n>>c;
	sum=0;
	for(i=0;i<n;i++){
		cin>>p;
		if(!i){
			pp=p;
		}
		sum+=1;
		if(p-pp>c){
			sum=1;
		}
		pp=p;
	}
	cout<<sum<<"\n";
	return 0;
}