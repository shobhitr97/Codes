#include<iostream>
#include<vector>

using namespace std;

int main(){

	int n, a[105], sum, i, c, d, count;
	vector<int>  l, r;

	cin>>n;

	for( i=0 ; i<n ; i++ ){
		cin>>a[i];
	}

	sum = 0;
	c = 0;
	d = 0;
	while( a[d] == 0 && d < n){
		d++;
	}

	if( d == n ){
		cout<<"NO\n";
		return 0;
	}

	count = 0;
	for( i=d ; i<n ; i++ ){

		if( sum + a[i] == 0 ){
			l.push_back(c+1);
			r.push_back(d+1);
			sum = a[i];
			c = i;
			d = i;
			count++;
		}
		else{
			sum += a[i];
			d = i;
		}

	}
	l.push_back(c+1);
	r.push_back(d+1);
	count++;

	cout<<"YES\n";
	cout<<count<<"\n";	
	for( i=0 ; i<count ; i++ ){
		cout<<l[i]<<" "<<r[i]<<"\n";
	}
	
	return 0;
}