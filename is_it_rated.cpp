#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define num 4128
#define N 1003
#define fori(a, b) for( int i=a ; i<b ; i++ )
#define pb push_back

typedef vector<int> vec;

int main(){
	
	int before[num], after[num], n, x, y;
	int flag;
	vec br, ar;

	cin>>n;

	// can be skipped
	fori(0, num){
		before[i] = 0;
		after[i] = 0;
	}

	fori(0, n){
		cin>>x>>y;
		br.pb(x);
		ar.pb(y);
		before[x] = i;
		after[y] = i;
	}

	flag = 0;
	fori(0, n){
		if( br[i] != ar[i] ){
			flag = 1;
			break;
		}
	}

	if( flag == 1 ){
		cout<<"rated\n";
	}
	else{
		// sort(ar.begin(), ar.end(), greater<int>() );
		// sort(br.begin(), br.end(), greater<int>() );
		fori(1, n){
			if( br[i] > br[i-1] ){
				flag = 1;
				break;
			}
		}
		if( flag == 1 ){
			cout<<"unrated\n";
		}
		else{
			cout<<"maybe\n";
		}
	}

	return 0;
}