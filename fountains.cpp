#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int, int> ii;
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define num 100005
int main(){
	int maxbc1, maxm, maxbd1, n, c, d, beauty, cost, beautyRangeCoin[num], beautyRangeDiamond[num], maxbc, maxbd, j;
	char ch;
	vector<pair<int, int> > carg, darg;
	maxbc1 = maxbd1 = maxbc = maxbd = maxm = 0;
	fori(0, num){
		beautyRangeCoin[i] = 0;
		beautyRangeDiamond[i] = 0;
	}
	cin>>n>>c>>d;
	fori(0, n){
		cin>>beauty>>cost>>ch;
		if( ch == 'C' ){
			if( cost <= c ){
				carg.pb( mp(cost, beauty) );
				maxbc1 = max(beauty, maxbc1);
			}
		}
		else{
			if( cost <= d ){
				darg.pb( mp(cost, beauty) );
				maxbd1 = max(beauty, maxbd1);
			}
		}
	}
	sort(carg.begin(), carg.end() );
	sort(darg.begin(), darg.end() );
	vector<ii>::iterator it;
	maxm = ( maxbc1 > 0 && maxbd1 > 0 )?maxbc1+maxbd1:0;
	j = 1;
	for(it = carg.begin() ; it != carg.end() ; it++ ){
		while( j <= ((*it)).first ){
			beautyRangeCoin[j] = max(beautyRangeCoin[j], beautyRangeCoin[j-1] );
			j++;
		}
		j--;
		if( beautyRangeCoin[ min(j, c - (*it).first) ] != 0 ){
			maxbc = max( maxbc, (*it).second + beautyRangeCoin[ min(j, c - (*it).first) ] );
		}
		beautyRangeCoin[j] = max((*it).second, beautyRangeCoin[j]);
	}
	j=1;
	for(it = darg.begin() ; it != darg.end() ; it++ ){
		while( j <= (*it).first ){
			beautyRangeDiamond[j] = max(beautyRangeDiamond[j], beautyRangeDiamond[j-1] );
			j++;
		}
		j--;
		if( beautyRangeDiamond[ min(j, d - (*it).first) ] != 0 ){
			maxbd = max( maxbd, (*it).second + beautyRangeDiamond[ min(j, d - (*it).first) ] );
		}
		beautyRangeDiamond[j] = max( (*it).second, beautyRangeDiamond[j]);
	}
	maxm = max( maxm, maxbc);
	maxm = max( maxm, maxbd);
	cout<<maxm<<"\n";
	return 0;
}