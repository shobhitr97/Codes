#include<iostream>
#include<string>

using namespace std;

typedef long long int ll;

#define num 100005
#define fori(a, b) for( int i=a ; i<b ; i++ )

int max(int a, int b ){
	if( a>b ){
		return a;
	}
	return b;
}

int min(int a, int b ){
	if( a<b ){
		return a;
	}
	return b;
}

int main(){

	int n, k, p, x1, max1, x2, max2, a[num], j, temp, x, vis[num];
	string s;

	cin>>n>>k>>p;

	fori(0, n){
		cin>>a[i];
		vis[i] = 0;
	}

	max1 = 0;
	max2 = 0;

	j = 0;

	while( j<n ){

		if( vis[j] == 1 ){
			break;
		}

		vis[j] = 1;

		if( a[j] == 0 ){
			j++;
			continue;
		}

		x = j;
		temp = 0;
		while( a[j] == 1 ){
			temp++;
			j = (j+1)%n;
		}

		if( temp > max1 ){
			x2 = x1;
			max2 = max1;
			x1 = x;
			max1 = temp;
		}
		else{
			if( temp > max2 ){
				x2 = x;
				max2 = temp;
			}
		}

	}

	cin>>s;

	j=0;
	fori(0, p){
		if( s[i] == '!' ){
			x1 = (x1+1)%n;
			x2 = (x2+1)%n;
		}
		else{
			if( x1 + max1 > n ){
				if( max1 == n ){
					cout<<min(k, n)<<"\n";
				}
				else{
					cout<<min( k, max(max2,max(max1-(n-x1),n-x1)) )<<"\n";
				}
			}
			else{
				cout<<min(k, max1)<<"\n";
			}
		}
	}


	return 0;
}