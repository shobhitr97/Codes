#include<iostream>

using namespace std;

#define l -1000001
#define r 1000001
#define forn(a,b) for(int i=a ; i<b ; i++)
#define num 2000005

typedef long long int ll;

ll arr[num];
int c[r], n;

void create_tree(){

	int index, temp = n, j;

	index = n + (n%2);
	forn(index,index+n){
		arr[i] = c[i];
	}

	while( temp != 1 ){

		for( j = index ; j < index+temp ; j+=2 ){
			arr[(j>>1) - ((j>>1)%2)] = (arr[j] + arr[j+1]);
		}
		if( temp%2){
			arr[ j/2 - 1 ] += arr[index+temp-1];
		}

		index = index/2 - (index%2);
		temp = temp/2;
	}

}

int main(){
	
	cin>>n;

	int w, x, y, z;

	forn(0,2*n+3){
		arr[i] = 0;
	}

	forn(0,n){
		cin>>c[i];
	}

	create_tree();

	cin>>q;

	forn(0,q){
		cin>>w>>x>>y>>z;
		cout<<find_sum(w, x)<<"\n";
	}

	return 0;
}