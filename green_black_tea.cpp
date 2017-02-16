#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n,a,b,k;

ll max(ll a,ll b){
	if(a>b){
		return a;
	}
	return b;
}

ll min(ll a,ll b){
	if(a<b){
		return a;
	}
	return b;
}

//a-green(0)    b-black(1)

int main(){
	
	cin>>n>>k>>a>>b;

	int i,j,next;
	ll x,y;
	char chx,chy;
	ll rem,nec;

	x=max(a,b);
	y=min(a,b);

	if( x > ( k*(y+1) ) ){
		cout<<"NO\n";
		return 0;
	}

	nec = ( x/(y+1) );
	rem = ( x%(y+1) );
	
	if(a>b){
		chx='G';
		chy='B';
	}
	else{
		chx='B';
		chy='G';
	}

	i=n;
	next=1;

	while(i){
		if(next){
			for(j=0;j<nec;j++){
				cout<<chx;
				i--;
			}
			if(rem){
				cout<<chx;
				rem--;
				i--;
			}
			next=0;
			continue;
		}
		else{
			cout<<chy;
			i--;
			next=1;
			continue;
		}
	}

	return 0;
}