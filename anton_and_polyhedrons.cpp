#include<iostream>
#include<map>
#include<stdio.h>
#include<utility>
#include<string>

using namespace std;

int main(){
	string x,y;
	int i,n;
	map <string,int> mp;
	
	mp.insert(make_pair("Tetrahedron",4));
	mp.insert(make_pair("Cube",6));
	mp.insert(make_pair("Dodecahedron",12));
	mp.insert(make_pair("Octahedron",8));
	mp.insert(make_pair("Icosahedron",20));

	cin>>n;
	i=0;
	while(n--){
		cin>>x;
		i += mp[x];
	}
	cout<<i<<"\n";
	return 0;
}