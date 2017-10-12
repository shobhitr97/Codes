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
#define base 7
#define num 290

int main(){

	int dp1[num], dp2[num], t, N, lim, pw[3], arr[3][13];
	vi output;
	int *a1, *a2, *temp;

	cin>>t;
	forn(T, 0, t){
		a1=dp1, a2=dp2;
		pw[0]=1;
		pw[1]=7;
		pw[2]=49;

		cin>>N;
		forn(i, 0, 3){
			forn(j, 0, N)	cin>>arr[i][j];
		}

		lim=N/2+1*(N%2);

		// If maximum number of problems solved by an individual is less than or equal to ceil(N/2)
		fori(0, num)	a1[i]=INF;
		a1[0]=0;
		forn(j, 0, N){
			fori(0, num)	a2[i]=a1[i];
			fori(0, num){
				if(a1[i]<INF){
					// cout<<"("<<(i%pw[1])<<","<<((i%pw[2])/pw[1])<<","<<(i/pw[2])<<") ";
					if(i%pw[1]<lim && a1[i]+arr[0][j]<=280){
						a2[i+pw[0]]=min(a2[i+pw[0]], a1[i]+arr[0][j]);
					}
					if(((i%pw[2])/pw[1])<lim && a1[i]+arr[1][j]<=280){
						a2[i+pw[1]]=min(a2[i+pw[1]], a1[i]+arr[1][j]);
					}
					if((i/pw[2])<lim && a1[i]+arr[2][j]<=280){
						a2[i+pw[2]]=min(a2[i+pw[2]], a1[i]+arr[2][j]);
					}
				}
			}
			// cout<<"\n";
			temp=a1;
			a1=a2;
			a2=temp;
		}

		int maxm=0;
		forn(i, 0, num){
			if(a1[i]<=280){
				int tt=i%pw[1]+(i%pw[2])/pw[1]+i/pw[2];
				int limit=tt/2+1*(tt%2);
				if(i%pw[1]<=limit&&(i%pw[2])/pw[1]<=limit&&i/pw[2]<=limit)	maxm=max(maxm, tt);
			}
		}
		output.pb(maxm);
	}

	forn(T, 0, t)	cout<<output[T]<<"\n";

	return 0;
}