#include<iostream>
#include<math.h.

using namespace std;

typedef long long int ll;

ll m2;

ll val(ll m){
	ll c;
	c=floor(pow(m,(double)1/(double)3));
	return c;
}

ll my_pow(ll x){
	return x*x*x;
}

ll calc(ll m){
	if(m<=7){
		return m;
	}
	ll a;
	a=val(m);
	return 1+max(m-my_pow(a),my_pow(a)-1-my_pow(a-1));
}