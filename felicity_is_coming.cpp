#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

#define num 1000000007
#define num1 1299827	
#define num3 1000679
#define num2 1016027

typedef long long int ll;
typedef vector< long long int > vl;
typedef vector<int> vi;

ll fact[num2+2];

void fill(){

	ll i=2;

	fact[1] = 1;
	fact[0] = 1;

	while(i<=num2){

		fact[i] = ( fact[i-1] * i )%num ;
		i++;
	
	}

}

ll poww(int a,int b ){
	ll x,y;
	y=a;
	x=1;
	while(b){
		if(b%2==1){
			x = (x*y)%num;
		}
		y = (y*y)%num;
		b/=2;
	}
	return x;
}

int main(){

	int n,m,i,g,j,k,sec,x;
	ll ans;

	fill();
	// for(i=0;i<=10;i++){
	// 	cout<<i<<" : "<<fact[i]<<"\n";
	// }

	vl a1;
	vl a2;
	vl a3;
	// vi pp;
	vl ff;

	cin>>n>>m;

	// pp.resize(m+2);
	ff.resize(m+2);
	a2.resize(m+2);
	a1.resize(m+2);
	a3.resize(m+2);
	//vi g;

	//g.resize(n+1);

	for(i=0;i<m;i++){
		ff[i]=0;
		a1[i]=0;
		a2[i]=0;
		a3[i]=0;
	}

	for( i=0 ; i < n ; i++ ){
		
		cin>>g;

		for( j=0 ; j < g ; j++ ){
			cin>>k;
			ff[k-1]+= 1;
			// x = poww(num1,i)%num;
			// cout<<x<<"\n";
			a1[k-1] = ( a1[k-1]+ ( ( poww(num1,i) )%num ) )%num; //poww will calculated multiple times
			a2[k-1] = ( a2[k-1]+ ( ( poww(num2,i) )%num ) )%num;
			a3[k-1] = ( a3[k-1]+ ( ( poww(num3,i) )%num ) )%num;
		}

	}

	// for(i=0;i<m;i++){
	// 	cout<<a1[i]<<" ";
	// }
	// cout<<"\n";

	// for(i=0;i<m;i++){
	// 	cout<<a2[i]<<" ";
	// }
	// cout<<"\n";	

	sort(a1.begin(),a1.begin()+m);
	sort(a2.begin(),a2.begin()+m);
	sort(a3.begin(),a3.begin()+m);

	// for(i=0;i<m;i++){
	// 	cout<<a1[i]<<" ";
	// }
	// cout<<"\n";

	// for(i=0;i<m;i++){
	// 	cout<<a2[i]<<" ";
	// }
	// cout<<"\n";

	sec=1;
	i=1;
	ans=1;

	while(i!=m){
		if( ff[i] && a1[i]==a1[i-1] &&  a2[i]==a2[i-1] && a3[i]==a3[i-1] ){
			sec++;
		}
		else{
			// cout<<sec<<":"<<fact[sec]<<"\n";
			ans = ( ans*fact[sec] )%num;
			sec=1;
		}
		i++;
	}
	ans = ( ans*fact[sec] )%num;     // for the end 

	cout<<ans<<"\n";

	return 0;
}