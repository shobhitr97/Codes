#include<iostream>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

typedef set<int> seti;
typedef long long int ll;

int main(){

	int i, n, m, k, y, j	;
	bool flag, iscancel;


	cin>>n>>m;
	
	iscancel = 0;

	seti num;

	for( i=0 ; i<m ; i++ ){

		cin>>k;

		flag = 1;

		for( j=0 ; j<k ; j++ ){
	
			cin>>y;
	
			if( num.find(-y) != num.end() ){
				flag = 0;
			}
	
			num.insert(y);
	
		}
	
		iscancel = iscancel|flag;
		
		num.clear();

	}
	if( iscancel ){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	return 0;

}

