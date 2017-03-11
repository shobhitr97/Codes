#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef vector< string > vecs;
typedef vector<int> vec;

int min(int a, int b ){
	if(a<b){
		return a;
	}
	return b;
}

int main(){
	int n,i,j,l,x;
	vecs hashtags;
	vec strlength;

	cin>>n;
	hashtags.resize(n+1);

	for( i=0 ; i<n ; i++ ){
		cin>>hashtags[i];
	}

	strlength.resize(n+1);
	strlength[n-1] = hashtags[n-1].length();  

	for( i=n-2 ; i>=0 ; i-- ){
		l = hashtags[i].length();
		x = min(l,strlength[i+1]);
		j=1;
		while( j<x && hashtags[i][j] == hashtags[i+1][j] ){
			j++;
		}
		if(j!=x){
			if(hashtags[i][j]-'a' < hashtags[i+1][j]-'a'){
				j=l;
			}
		}

		strlength[i] = j;
	}

	for( i=0 ; i<n ; i++ ){
		for( j=0 ; j<strlength[i] ; j++ ){
			cout<<hashtags[i][j];
		}
		cout<<"\n";
	}
	return 0;
}