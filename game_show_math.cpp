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
#define MAX 32000
#define MIN -32000
#define offset 32002

int sym[102][64005];
ll arr[32004], target, p;
int visited[103][64005];

int calc(int result, int index){
	if(index==p)	return (result==target);
	// cout<<index<<","<<result+offset<<"-------\n";
	if(visited[index][result+offset]!=-1)	return visited[index][result+offset];
	int res=0;
	if(result+arr[index]<=MAX&&result+arr[index]>=MIN){
		res|=calc(result+arr[index], index+1);
		if(res==1)	sym[index][result+offset]=0;
	}
	if(res==0&&result-arr[index]<=MAX&&result-arr[index]>=MIN){
		res|=calc(result-arr[index], index+1);
		if(res==1)	sym[index][result+offset]=1;
	}
	if(res==0&&(ll)result*arr[index]<=MAX&&(ll)result*arr[index]>=MIN){
		res|=calc(result*arr[index], index+1);
		if(res==1)	sym[index][result+offset]=2;
	}
	if(res==0&&arr[index]!=0&&result%arr[index]==0&&result/arr[index]<=MAX&&result/arr[index]>=MIN){
		res|=calc(result/arr[index], index+1);
		if(res==1)	sym[index][result+offset]=3;
	}
	// cout<<res<<"\n";
	if(res==1){
		// cout<<sym[index][result+offset]<<" "<<arr[index]<<"\n";
		visited[index][result+offset]=1;
	}
	else	visited[index][result+offset]=0;
	return res;
}

int main(){
	int n;
	cin>>n;
	forn(z, 0, n){
		cin>>p;
		fori(0, p)	cin>>arr[i];
		cin>>target;
		forn(i, 0, p){
			forn(j, 0, 64003)	visited[i][j]=-1;
		}
		if(calc(arr[0], 1)==0)	cout<<"NO EXPRESSION\n";
		else{
			// cout<<"Target: "<<target<<"\n";
			printf("%d", (int)arr[0]);
			int k, result=arr[0];
			k=1;
			while(k<p){
				switch(sym[k][result+offset]){
					case 0:	result+=arr[k];
							printf("+%d", (int)arr[k++]);
							break;
					case 1:	result-=arr[k];
							printf("-%d", (int)arr[k++]);
							break;
					case 2:	result*=arr[k];
							printf("*%d", (int)arr[k++]);
							break;
					case 3:	result/=arr[k];
							printf("/%d", (int)arr[k++]);
							break;
				}
			}
			printf("=%d\n", (int)target);
		}
	}
	return 0;
}