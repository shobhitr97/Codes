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
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define num 500005

int main(){
	int t, n, index, siz;
	ll x, y, a[num], b[num], minB, minOP, zeroCount, sumToBeAdded, numbersToBeAdded, op;
	vll prefixSum, output;
	vector<pair<ll, ll> > in;

	cin>>t;
	forn(T, 0, t){
		
		cin>>n;

		fori(1, n+1)	cin>>a[i];
		fori(1, n+1)	cin>>b[i];

		minB=INF;
		minOP=INF;
		zeroCount=0;
		op=0;
		fori(1, n+1){
			minB=min(minB, b[i]);
			if(a[i]%b[i]==0)	zeroCount++;
			else	in.pb(mp(a[i]%b[i], b[i]));
		}
		siz=in.size();

		sort(in.begin(), in.end());

		index=siz-1;
		while(in[index].fi>=minB){
			zeroCount++;
			op+=(in[index].se - in[index].fi);
			index--;
		}
		siz=index+1;

		prefixSum.resize(siz+5);
		prefixSum[0]=0;
		fori(1, siz){
			prefixSum[i]=prefixSum[i-1]+i*(in[i].fi-in[i-1].fi);
		}
		while(index>=0){
			int temp=index-1;
			sumToBeAdded=in[index].se - in[index].fi;
			numbersToBeAdded=1;
			while(temp>=0){
				if(in[temp].fi!=in[temp+1].fi)	break;
				numbersToBeAdded++;
				sumToBeAdded+=(in[temp].se - in[temp].fi);
				temp--;
			}

			minOP=min(minOP, op+zeroCount*in[index].fi + prefixSum[temp+1]);

			op+=sumToBeAdded;
			zeroCount+=numbersToBeAdded;

			index=temp;
		}

		// cout<<minOP<<"\n";
		output.pb(minOP);

		in.clear();
		prefixSum.clear();
	}
	forn(T, 0, t)	cout<<output[T]<<"\n";
	return 0;
}