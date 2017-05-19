#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<stdio.h>
#include<set>
#include<map>
#include<cmath>

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

	int n;
	ll a[100005];
	ll sum, total_sum;
	set<ll> diff;
	map<ll, 	 int> diffIndex;
	bool flag;

	cin>>n;
	total_sum=0;
	fori(0, n){
		cin>>a[i];
		total_sum+=a[i];
	}

	if(total_sum&1){
		cout<<"NO\n";
		return 0;
	}

	flag=false;
	// sum=a[0];
	fori(0, n){
		if(2*sum==total_sum){
			flag=true;
			break;
		}
		diff.insert(total_sum-2*sum);
		diffIndex.insert(mp(total_sum-2*sum, i));
		sum+=a[i];
	}

	if( flag==false ){
		fori(0, n){
			if(diff.find(2*a[i])!=diff.end() ){
				if(i>=diffIndex[ 2*a[i] ]){
					flag=true;
					break;
				}
			}
			if(diff.find((-2)*a[i])!=diff.end() ){
				if(i<diffIndex[(-2)*a[i] ]){
					flag=true;
					break;
				}
			}
		}
	}

	if(flag==true)	cout<<"YES\n";
	else	cout<<"NO\n";

	return 0;
}