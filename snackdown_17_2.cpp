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
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second

int main(){
	int t, n, cnt, prev, cntDouble, curr, row, cntTemp, new_row;
	bool flag;
	string plate[3];
	cin>>t;
	while(t--){
		flag=true;
		cin>>n;
		cin>>plate[0];
		cin>>plate[1];
		cnt=0;
		fori(0, n){
			if(plate[0][i]=='#')	cnt++;
			if(plate[1][i]=='#')	cnt++;
		}
		// cout<<"Number of Black spots: "<<cnt<<"\n";
		// cout<<plate[0]<<"\n";
		// cout<<plate[1]<<"\n";
		fori(0, n){
			if(plate[0][i]=='#'||plate[1][i]=='#'){
				curr=i;
				break;
			}	
		}
		cntTemp=0;
		if(plate[0][curr]=='#'&&plate[1][curr]=='#'){
			cntDouble=0;
			while(curr<n&&plate[0][curr]=='#'&&plate[1][curr]=='#')	cntDouble++, curr++, cntTemp+=2;
			if(curr==n||(plate[0][curr]!='#'&&plate[1][curr]!='#')){
				if(cntTemp==cnt)	cout<<"yes\n";
				else	cout<<"no\n";
				continue;
			}
			// cout<<"Number of Doubles: "<<cntDouble<<"\n";
		}
		// cout<<"Count: "<<cntTemp<<"\n";
		row=1*(plate[1][curr]=='#');
		// cout<<row<<"\n";
		while(curr<n){
			if(plate[0][curr]!='#'&&plate[1][curr]!='#')	break;	
			if(plate[0][curr]=='#'&&plate[1][curr]=='#'){
				cntDouble=0;
				while(curr<n&&plate[0][curr]=='#'&&plate[1][curr]=='#')	cntDouble++, curr++, cntTemp+=2;
				if(curr==n||(plate[0][curr]!='#'&&plate[1][curr]!='#')){
					if(cntTemp!=cnt)	flag=false;
					break;
				}
				// cout<<"Number of Doubles: "<<cntDouble<<"\n";
				new_row=1*(plate[1][curr]=='#');
				// cout<<row<<" -> "<<new_row<<"\n";
				if(row==new_row&&cntDouble%2==1){
					flag=false;
					break;
				}
				if(row!=new_row&&cntDouble%2==0){
					flag=false;
					break;
				}	
				row=new_row;
			}
			else{
				new_row=1*(plate[1][curr]=='#');
				if(row!=new_row){
					flag=false;
					break;
				}
				cntTemp+=1;
				curr++;
			}
		}
		if(flag==false){
			cout<<"no\n";
			continue;
		}
		if(cntTemp==cnt)	cout<<"yes\n";
		else	cout<<"no\n";
	}
	return 0;
}