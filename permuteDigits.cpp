#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <functional>

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

int main(){
	string a, b;
	int alen, blen, digita[10], digitb[10], ans[19], used[10];
	vi aa;
	
	cin>>a>>b;

	alen = a.length();
	blen = b.length();

	if(alen < blen){
		fori(0, alen){
			aa.pb(a[i]-'0');
		}
		sort(aa.begin(), aa.end());
		forin(alen-1, 0){
			cout<<aa[i];
		}
		cout<<"\n";
	}
	else{
		// The answer always exists

		fori(0, 10){
			digita[i]=0;
			digitb[i]=0;
			used[i]=0;
		}

		fori(0, alen){
			digita[a[i]-'0']++;
			digitb[b[i]-'0']++;
		}

		// fori(0, 10)	cout<<digita[i]<<" ";
		// cout<<"\n";

		bool flag = true;
		fori(0, blen){
			if(digita[b[i]-'0'])
			{
				// cout<<"--"<<i<<":"<<(b[i]-'0')<<"\n";
				ans[i] = (b[i]-'0');
				digita[b[i]-'0']--;
				// used[b[i]-'0']++;
			}
			else
			{
				bool isThere = false;

				int val = 0;

				while(i>=0)
				{
					fornn(j, b[i]-'0'-1, 0)
					{
						if( digita[j] > 0 /*&& digita[j] != used[j] */)
						{
							isThere = true;
							val = j;
							break;
						}
					}
					if(isThere == false)
					{
						// cout<<"->"<<i<<"\n";
						i--;
						digita[b[i]-'0']++;
					}
					else
					{
						break;
					}

				}

				// cout<<":="<<val<<"\n";

				ans[i] = val;
				digita[val]--;

				forn(j, 0, 10){
					forn(k, 0, digita[j])	aa.pb(j);
				}

				sort(aa.begin(), aa.end());

				fornn(j, aa.size()-1, 0){
					ans[++i] = aa[j]; 
				}

				// break;

			}
		}

		fori(0, alen)	cout<<ans[i];
		cout<<"\n";

	}

	return 0;
}