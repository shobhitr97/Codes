#include<iostream>

using namespace std;

int calc(int a,int b,int c){
	x=0;
	y=b%c;
	while(a>=1){
		if(a%2==0){
			x=(x+y)%c;
		}
		y=(2*y)%c;
		a/=2;
	}
	return x;
}