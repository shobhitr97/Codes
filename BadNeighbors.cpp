#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

class BadNeighbors{
	vector <int> a;
	vector <int> b;
	public:
	int max(int a,int b){
		if(a>b){
			return a;
		}
		return b;
	}
	int maxDonations(vector <int> amt){
		int sz=amt.size(),i,max_m;
		a.resize(sz);
		b.resize(sz);
		a[0]=0;
		a[1]=amt[1];
		b[0]=amt[0];
		b[1]=amt[1];
		for(i=2;i<=sz-1;i++){
			a[i]=max((a[i-2]+amt[i]),(a[i-1]+amt[i]-amt[i-1]));
			if(i<sz-1)
				b[i]=max((b[i-2]+amt[i]),(b[i-1]+amt[i]-amt[i-1]));
		}
		max_m= max(max(a[sz-1],a[sz-2]),max(b[sz-2],b[sz-3]));
		a.clear(),b.clear();
		return max_m;
	}
};

int main(){
	int input,t;
	vector <int> donations;
	BadNeighbors obj;
	while(t--){
		while(cin>>input){
			donations.push_back(input);
		}
		
		cout<<obj.maxDonations(donations)<<"\n";
	}
	return 0;
}

