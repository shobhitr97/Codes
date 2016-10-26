#include<iostream>
#include<tuple>

using namespace std;
typedef tuple<int,int,int> tup;
int main(){
	int i;
	int a,b,c;
	cin>>a>>b>>c;
	tup P=make_tuple(a,b,c);
	cout<<get<1>(P)<<get<2>(P)<<get<3>(P);
	return 0;
}