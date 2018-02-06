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

int main(){
	int a[3][2][8], b[3][2][2], c[3][2][2];

	a[0][0][0]=13; 
	a[0][0][1]=14;
	a[0][0][2]=5;
	a[0][0][3]=6;
	a[0][0][4]=17;
	a[0][0][5]=18;
	a[0][0][6]=21;
	a[0][0][7]=22;
	a[0][1][0]=15;
	a[0][1][1]=16;
	a[0][1][2]=7;
	a[0][1][3]=8;
	a[0][1][4]=19;
	a[0][1][5]=20;
	a[0][1][6]=23;
	a[0][1][7]=24;

	b[0][0][0]=1;
	b[0][0][1]=2;
	b[0][1][0]=3;
	b[0][1][1]=4;

	c[0][0][0]=9;
	c[0][0][1]=10;
	c[0][1][0]=11;
	c[0][1][1]=12;

	a[1][0][0]=1; 
	a[1][0][1]=3;
	a[1][0][2]=5;
	a[1][0][3]=7;
	a[1][0][4]=9;
	a[1][0][5]=11;
	a[1][0][6]=24;
	a[1][0][7]=22;
	a[1][1][0]=2;
	a[1][1][1]=4;
	a[1][1][2]=6;
	a[1][1][3]=8;
	a[1][1][4]=10;
	a[1][1][5]=12;
	a[1][1][6]=23;
	a[1][1][7]=21;

	b[1][0][0]=13;
	b[1][0][1]=14;
	b[1][1][0]=15;
	b[1][1][1]=16;

	c[1][0][0]=17;
	c[1][0][1]=18;
	c[1][1][0]=19;
	c[1][1][1]=20;

	a[2][0][0]=9; 
	a[2][0][1]=10;
	a[2][0][2]=19;
	a[2][0][3]=17;
	a[2][0][4]=4;
	a[2][0][5]=3;
	a[2][0][6]=14;
	a[2][0][7]=16;
	a[2][1][0]=11;
	a[2][1][1]=12;
	a[2][1][2]=20;
	a[2][1][3]=18;
	a[2][1][4]=2;
	a[2][1][5]=1;
	a[2][1][6]=13;
	a[2][1][7]=15;

	b[2][0][0]=5;
	b[2][0][1]=6;
	b[2][1][0]=7;
	b[2][1][1]=8;

	c[2][0][0]=21;
	c[2][0][1]=22;
	c[2][1][0]=23;
	c[2][1][1]=24;

	int arr[26];
	fori(1, 25)	cin>>arr[i];
	bool flag;

	forn(j, 0, 3){
		// flag=true;
		// for(int i=0;i<8;i+=2){
		// 	if(!(arr[a[j][0][i]]==arr[a[j][0][i+1]]&&arr[a[j][0][i+1]]==arr[a[j][1][i+1]]&&arr[a[j][1][i+1]]==arr[a[j][1][i]]))	flag=false;
		// }
		// cout<<flag<<"\n";
		// flag=true;
		// for(int i=0;i<8;i+=2){
		// 	if(!(arr[a[j][0][i]]==arr[a[j][0][i+1]]&&arr[a[j][0][i+1]]==arr[a[j][1][i+1]]&&arr[a[j][1][i+1]]==arr[a[j][1][i]]))	flag=false;
		// }
		// cout<<flag<<"\n";
		// if(flag==false){
			flag=true;
			for(int i=0;i<8;i+=2){
				if(!(arr[a[j][0][(i+2)%8]]==arr[a[j][0][(i+1+2)%8]]&&arr[a[j][0][(i+1+2)%8]]==arr[a[j][1][(i+1)%8]]&&arr[a[j][1][(i+1)%8]]==arr[a[j][1][(i)%8]]))	flag=false;
			}
			// cout<<flag<<"\n";
		// }
		if(flag==false){
			flag=true;
			for(int i=0;i<8;i+=2){
				if(!(arr[a[j][0][(i)%8]]==arr[a[j][0][(i+1)%8]]&&arr[a[j][0][(i+1)%8]]==arr[a[j][1][(i+1+2)%8]]&&arr[a[j][1][(i+1+2)%8]]==arr[a[j][1][(i+2)%8]]))	flag=false;
			}
			// cout<<flag<<"\n";
		}
		if(flag==false){
			flag=true;
			for(int i=0;i<8;i+=2){
				if(!(arr[a[j][0][(i)%8]]==arr[a[j][0][(i+1)%8]]&&arr[a[j][0][(i+1)%8]]==arr[a[j][1][(i+1+6)%8]]&&arr[a[j][1][(i+1+6)%8]]==arr[a[j][1][(i+6)%8]]))	flag=false;
			}
			// cout<<flag<<"\n";
		}
		if(flag==false){
			flag=true;
			for(int i=0;i<8;i+=2){
				if(!(arr[a[j][0][(i+6)%8]]==arr[a[j][0][(i+1+6)%8]]&&arr[a[j][0][(i+1+6)%8]]==arr[a[j][1][(i+1)%8]]&&arr[a[j][1][(i+1)%8]]==arr[a[j][1][(i)%8]]))	flag=false;
			}
			// cout<<flag<<"\n";
		}
		if(flag==false)	continue;
		if(!(arr[b[j][0][0]]==arr[b[j][0][1]]&&arr[b[j][0][1]]==arr[b[j][1][1]]&&arr[b[j][1][1]]==arr[b[j][1][0]]))	flag=false;
		// cout<<flag<<"\n";
		if(!(arr[c[j][0][0]]==arr[c[j][0][1]]&&arr[c[j][0][1]]==arr[c[j][1][1]]&&arr[c[j][1][1]]==arr[c[j][1][0]]))	flag=false;
		// cout<<flag<<"\n";
		if(flag==true){
			break;
		}
	}

	if(flag==true)	cout<<"YES\n";
	else	cout<<"NO\n";

	return 0;
}