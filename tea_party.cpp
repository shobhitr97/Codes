#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define fori(a, b) for(int i=a ; i<b ; i++ )
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int main(){

	int a[105], hold[105], n, half, w, j, temp;

	cin>>n>>w;

	fori(0, n){
		cin>>a[i];
	}

	half=0;
	fori(0, n){
		half+=(a[i]/2);
		if(a[i]%2>0)	half++;
	}

	if( w<half ){
		cout<<"-1\n";
		return 0;
	}

	vii pour;
	fori(0, n){
		pour.pb(mp(a[i],i) );
	}
	sort(pour.begin(), pour.end() );

	fori(0, n){
		hold[i] = a[i]/2;
		if(a[i]%2)	hold[i]++;
	}
	w=w-half;
	j=n-1;
	while(w){
		temp=min(w,pour[j].fi); 
		w-=(temp-hold[pour[j].se]);
		hold[pour[j].se]=temp;
		j--;
	}

	fori(0, n){
		cout<<hold[i]<<" ";
	}
	cout<<"\n";

	return 0;
}