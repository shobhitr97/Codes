#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<set>

using namespace std;

typedef long long int ll;
typedef vector<string> svec;
typedef set<string> sets;

#define pb push_back
#define is insert
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define num 200005

sets block;
svec sites, filters;
int N, blockStat[num];

int max(int a, int b){
	if(a > b){
		return a;
	}
	return b;
}

int main(){

	cin>>N;
	
	int x, j, start, end, len1, len2, len, ans;
	char ch;
	string s, ss, se, filter;

	fori(0, N){
	
		cin>>ch;
		cin>>s;

		sites.pb(s);

		if( ch == '-' ){
			block.is(s);
		}

	}				

	sort(sites.begin(), sites.end() );

	fori(0, N){
		if( block.find( sites[i] ) == block.end() ){
			blockStat[i] = 0;
		}
		else{
			blockStat[i] = 1;
		}
	}

	// fori(0, N){
	// 	cout<<sites[i]<<" "<<blockStat[i]<<"\n";
	// }

	j = 0;
	ans = 0;
	// start = -1;
	end = -1;
	while( j < N ){
		
		ss.assign("");
		se.assign("");

		start = end;
		while( blockStat[start+1] == 0 ){
			start++;
		}
		// cout<<start<<"\n";
		if( start != -1 ){
			ss = sites[start];
		}

		end = start+1;
		while( blockStat[end] == 1 ){
			end++;
		}
		// cout<<end<<"\n";
		if( end != N ){
			se = sites[end];
		}

		// no use except for end cases
		if( end - start == 1 ){
			j = end+1;
			continue;
		}
		// cout<<ss<<" "<<se<<"\n";

		j=start+1;

		while( j < end ){
			len1 = 0;
			while( len1 < ss.length() && len1 < sites[j].length() && ss[len1] == sites[j][len1] ){
				len1++;
			}
			// cout<<len1<<"\n";	
			// if everything matches with the preceding unblocked site
			if( len1 == sites[j].length() ){
				cout<<"-1\n";
				return 0;
			}

			len2 = 0;
			while( len2 < se.length() && len2 < sites[j].length() && se[len2] == sites[j][len2] ){
				len2++;
			}
			// cout<<len2<<"\n";		
			// if everything matches with the preceding unblocked site
			if( len2 == sites[j].length() ){
				cout<<"-1\n";
				return 0;
			}

			len = max(len1, len2);
			// cout<<len<<"\n";
			filter.assign(sites[j],0,len+1);

			// cout<<filter<<"\n";
			filters.pb(filter);
			ans++;

			j++;
			while( j<end ){
				if( sites[j].length() < len+1 ){
					break;
				}
				if( sites[j].compare(0, len+1, filter ) != 0 ){
					// cout<<"YYYBREAK\n";
					break;
				}
				// cout<<"comp: "<<sites[j].compare(0, len+1, filter )<<"\n";
				j++;
			}
		}
		j = end+1;
	}

	svec::iterator it;

	for( it = filters.begin() ; it != filters.end() ; it++ ){
		cout<<(*it)<<"\n";
	}

	return 0;
}