#include<iostream>

using namespace std;

long long int min(long long int a,long long int b){
	if(a<b){
		return a;
	}
	return b;
}

long long int max(long long int a,long long int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	long long int sub,b,d,s,mi,ma,ans;
	cin>>b>>d>>s;
	sub=min(b,min(d,s));
	ans=0;
	b-=sub;
	d-=sub;
	s-=sub;
	ma=max(b,max(d,s));
	mi=b+d+s-ma;
	if(mi==0){
		if(ma==0){
			cout<<"0\n";
			return 0;
		}
	}
	if(ma-mi==0){
		ans=ma-1;
	}		
	else{
		ans=ma-1+ma-mi-1;
	}
	cout<<ans<<"\n";
	return 0;
}