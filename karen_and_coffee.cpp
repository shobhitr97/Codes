#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 1000005

int n, k, q;
int arr[num];

void fill(int index, int l, int r, int x, int y){
	if(x>y)	return;
	if(x==l&&y==r){
		arr[index]++;
		return;
	}
	int mid=(l+r)/2;
	if(x>=l&&x<=r&&y>=l&&y<=r){
		if(x>mid)	fill(2*index+1, mid+1, r, x, y);
		else{
			if(y<=mid)	fill(2*index, l, mid, x, y);
			else{
				fill(2*index, l, mid, x, mid);
				fill(2*index+1, mid+1, r, mid+1, y);
			}
		}
	}
}

int process(int index, int l, int r, int qs){
	int temp=arr[index], mid=(l+r)/2;
	if(l==r)	return temp;
	if(qs>mid)	temp+=process(2*index+1, mid+1, r, qs);
	else	temp+=process(2*index, l, mid, qs);
	return temp;
}

int main(){
	int l, r, pre[200005];
	cin>>n>>k>>q;
	vi output;
	fori(0, num)	arr[i]=0;
	fori(0, n){
		cin>>l>>r;
		fill(1, 1, 200000, l, r);
	}
	pre[0]=0;
	fori(1, 200001){
		int temp=process(1, 1, 200000, i);
		// cout<<temp<<"\n";
		pre[i]=pre[i-1]+1*(temp>=k);
	}
	fori(0, q){
		cin>>l>>r;
		output.pb(pre[r]-pre[l-1]);
	}
	fori(0, q)	cout<<output[i]<<"\n";
	return 0;
}