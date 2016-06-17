#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class BadNeighbors{
	public:
	int max(int a,int b){
		if(a>b){
			return a;
		}
		return b;
	}
	int maxDonations(vector <int> amt){
		vector <int> a(don.size());
		a[0]=amt[0];
		a[1]=amt[1]+amt[amt.size()-1];
		for(i=2;i<amt.size()-2;i++){
			a[i]=max((a[i-2]+amt[i]),(a[i-1]+amt[i]-amt[i-1]));
		}
	}//need to be edited
}
