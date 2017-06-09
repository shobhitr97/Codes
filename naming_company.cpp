#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>
#include<string>

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
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

int main(){
	vector<char> oleg, igor;
	string a, b, name;

	cin>>a;
	cin>>b;

	int n;
	n = a.length();

	fori(0, n){
		oleg.pb(a[i]);
		igor.pb(b[i]);
	}

	name = a;
	sort(oleg.begin(), oleg.end() );
	sort(igor.begin(), igor.end() );
	reverse(igor.begin(), igor.end() );

	int front, end, j1, j2, k1, k2, i;

	fori(0, n){
		name[i] = '*';
	}

	// fori(0, n){
	// 	cout<<oleg[i];				
	// }
	// cout<<"\n";

	// fori(0, n){
	// 	cout<<igor[i];				
	// }
	// cout<<"\n";

	j1 = 0;
	k1 = 0;
	j2 = (n%2==0)?(n/2-1):n/2;
	k2 = n/2-1;
	i = 0;
	front = 0;
	end = n-1;

	while( front < n && end >= 0 && front <= end ){
		if( i%2 == 0 ){
			if( oleg[j1] >= igor[k1] ){
				name[end--] = oleg[j2--];
			}
			else{
				name[front++] = oleg[j1++];
			}
		}
		else{
			if( igor[k1] <= oleg[j1] ){
				name[end--] = igor[k2--];
			}
			else{
				name[front++] = igor[k1++];
			}
		}
		i++;
	}

	cout<<name<<"\n";

	return 0;
}