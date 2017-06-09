#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<stdio.h>
#include<utility>
#include<algorithm>

using namespace std;

typedef vector<string> vecs;
typedef vector< vector<string> > vvecs;
typedef map<string,string> maps;

vecs var_name;
maps vars0, vars1;

#define num 1005
#define mp make_pair

int n, m, neededz[num], neededo[num];
string a, b;

int check(string var){

	int len = var.length();
	int i=0 ;

	if( var[i] != '0' && var[i] != '1' ){
		return 0;
	}

	return 1;

}

// int func_op( int op, int val){
// 	int ans;
	
// 	ans = -1;

// 	switch(op){
// 		case 0: if(!val){
// 			    	ans = 1;
// 				}break;
// 		case 1: if(val){
// 					ans = 1;
// 				}break;
// 		case 2: if(val){
// 					ans = 0;
// 				}
// 				else{
// 					ans = 1;
// 				}break;
// 	}
// 	return ans;
// }

int fun( int var1, int oprt, int var2){
	switch( oprt ){
		case 0:return (var1|var2);
		case 1:return (var1&var2);
		case 2:return (var1^var2);
	}
}

// OR  = 0, AND = 1, XOR = 2
void operations( string name, string var1, string op, string var2 ){
	int x, y, i, z, oprt, a1, a2;
	string p, q, r, s, cons1, cons2, zero, one;

	x = var1.compare("?");
	y = var2.compare("?");

	zero.assign("0");
	one.assign("1");

	// cout<<x<<" "<<y<<"\n";

	if( op.compare("OR") == 0 ){
		oprt = 0;
	}
	else{
		if( op.compare("AND") == 0 ){
			oprt = 1;
		}
		else{
			oprt = 2;
		}
	}
	// cout<<oprt<<"\n";

	if( x == 0 || y == 0 ){
		
		if( x==0 && y!=0 ){
			p = a;
			q = vars0[var2];
			r = b;
			s = vars1[var2];
		}
		else{
			if( x!=0 && y==0 ){
				p = vars0[var1];
				q = a;
				r = vars1[var1];
				s = b;
			}
			else{
				 p = a;
				 q = a;
				 r = b;
				 s = b;
			}
		}

	
	}

	if( x != 0 && y != 0 ){
		p = vars0[var1];
		q = vars0[var2];
		r = vars1[var1];
		s = vars1[var2];
	}
	
	// cout<<p<<" "<<q<<"\n";
	// cout<<r<<" "<<s<<"\n";

	i=0;
	a1 =  fun( p[i]=='1', oprt, q[i]=='1' ) ;
	a2 =  fun( r[i]=='1', oprt, s[i]=='1' ) ;
	if( a1 == 0){
		cons1 = zero;
	}
	else{
		cons1 = one;
	}

	if( a2 == 0){
		cons2 = zero;
	}
	else{
		cons2 = one;
	}
	// cout<<cons1<<"\n"<<cons2<<"\n";
	for( i=1 ; i<m ; i++ ){
		a1 =  fun( p[i]=='1', oprt, q[i]=='1' ) ;
		a2 =  fun( r[i]=='1', oprt, s[i]=='1' ) ;
		if( a1 == 0){
			cons1.append(zero);
		}
		else{
			cons1.append(one);
		}
		if( a2 == 0){
			cons2.append(zero);
		}
		else{
			cons2.append(one);
		}
	}

	// cout<<cons1<<"\n";
	// cout<<cons2<<"\n";

	for( i=0 ; i<m ; i++ ){
		if( cons1[i] == '1' ){
			neededz[i]++;
		}

		if( cons2[i] == '1' ){
			neededo[i]++;
		}
	}

	vars0.insert(mp(name, cons1));
	vars1.insert(mp(name, cons2));
	
}

int main(){
	
	int t, i, dir;
	string x, var1, op, var2;

	cin >> n >> m;

	for( i=0 ; i<m ; i++ ){
		neededz[i] = 0;
		neededo[i] = 0;
	}

	var1.assign("0");
	var2.assign("1");

	a = var1, b = var2;
	for( i=1 ; i<m ; i++ ){
		a = a + var1;
		b = b + var2;
	}

	// cout<<a<<"\n";
	// cout<<b<<"\n";

	t = n;

	while(t--){	

		cin >> x;   // variable name
		cin >> var1; // for :=
		cin >> var1; // variable

		dir = check(var1);
		if( !dir ){
			cin >> op;
			cin >> var2;
		}
	
		switch( dir ){
			case 1: var_name.push_back(x);
					vars0.insert( mp(x, var1) );
					vars1.insert( mp(x, var1) );
					break;
			case 0: var_name.push_back(x);
					operations( x, var1, op, var2);
					break;

		}

	}
	
	for( i=0 ; i<m ; i++ ){
		if( neededz[i] <= neededo[i] ){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	cout<<"\n";

	for( i=0 ; i<m ; i++ ){
		if( neededz[i] >= neededo[i] ){
			cout<<"0";
		}
		else{
			cout<<"1";
		}
	}
	cout<<"\n";
	return 0;
}