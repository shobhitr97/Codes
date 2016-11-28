#include<iostream>
#include<cmath>
#include<iomanip>
#include<stdio.h>


using namespace std;

#define nn 500005
typedef long long int ll;

int main(){
	ll x[nn],y[nn],x1,y1;
	char charr[nn];
	int i,j,n,flag;
	cin>>n;
	cin>>x1>>y1;
	for(i=0;i<n;i++){
		cin>>charr[i]>>x[i]>>y[i];
	}
	// flag=1;
	for(i=0;i<n;i++){
		switch(charr[i]){
			case 'B':if( abs(x[i]-x1)==abs(y[i]-y1) ){
						cout<<"YES\n";
						return 0;
					};break;
			case 'R':if( (x[i]-x1)==0 || (y[i]-y1==0) ){
						cout<<"YES\n";
						return 0;
					};break;
			case 'Q':if( abs(x[i]-x1)==abs(y[i]-y1) || ( x[i]-x1==0||y[i]-y1==0) ){
						cout<<"YES\n";
						return 0;
					}
			default: break;
			
		}
	}
	cout<<"NO\n";
	return 0;
}