// #include<iostream>
// #include<cmath>

// using namespace std;

// int gcd(int a, int b){
// 	if( a%b == 0){
// 		return b;
// 	}

// 	return gcd(b, a%b);
// }

// int x[2][2], g;

// int find_gcd(int a, int b){

// 	int r,r1,r2,t,p,q;
//  	int temp;
//     r=1;

//     if(a<b){
//     	temp=a;
//     	a=b;
//     	b=temp;
//     }   
//     p=a;
//     q=b;
//     x[0][0]=1;
//     x[0][1]=0;
//     x[1][0]=0;
//     x[1][1]=1;
//     while(r!=0){
//       r1=x[0][0]-(p/q)*x[1][0];
//       r2=x[0][1]-(p/q)*x[1][1];
//       r=r1*a+r2*b;
//       x[0][0]=x[1][0];
//       x[0][1]=x[1][1];
//       x[1][0]=r1;
//       x[1][1]=r2;
//       p=q;
//       q=r;
//     }  

//     return p;
	
// }

// int main(){

// 	int a, b ,c, d, g, u, v, i, aa, cc;

// 	cin>>a>>b>>c>>d;

// 	// if( a > b ){
// 	// 	g = findgcd(a,b);
// 	// }
// 	// else{
// 	// 	g = gcd(b,a);
// 	// }
// 	g = find_gcd(a, c);

// 	if( a > c){
// 		u = x[0][0];
// 		v = x[0][1];
// 	}
// 	else{
// 		v = x[0][0];
// 		u = x[0][1];
// 	}

// 	// cout<<u<<" "<<v<<" "<<g<<"\n";

// 	i = (int)abs(b-d);
// 	i = i%g;
// 	if( i != 0 ){
// 		cout<<"-1\n";
// 		return 0;
// 	}

// 	i = (int)abs(b-d)/g;
// 	// cout<<i<<"\n";
// 	aa = (c/g) + u*i;
// 	cc = (a/g) - v*i;

// 	int lcma, lcm;
// 	lcm = (a*c)/g;
// 	lcma = lcm/a;
// 	int k = abs(aa/lcma) ;
// 	aa = aa + k*lcma;
// 	while(aa < 0){
// 		k++;
// 		aa +=lcma;
// 	}
// 	cc = cc + k*(lcm/c);

// 	cout<<(b + a*(aa))<<"\n";

// 	return 0;
// }

#include<iostream>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef vector<int> vec;
typedef set<int> si;

int main(){
	int a, b, c, d, i, j, x, y;

	si aa;
	vec cc;

	cin>>a>>b>>c>>d;

	for( i=0 ; i<=100 ; i++ ){
		aa.insert(b + (i*a));
		cc.push_back(d + (i*c));
	}

	for( i=0 ; i<=100 ; i++ ){
		if( aa.find(cc[i]) != aa.end() ){
			break;
		}
	}

	if( i>100 ){
		cout<<"-1\n";
	}
	else{
		cout<<cc[i]<<"\n";
	}

	return 0;

}