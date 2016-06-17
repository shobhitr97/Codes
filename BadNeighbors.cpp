#include<iostream>
#include<stdio>
#include<stdlib>
#include<string>
#include<vector>

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
		int sz=amt.size();
		vector <int> a(sz);
		vector <int> b(sz);
		a[0]=0;
		a[1]=amt[1];
		b[0]=amt[0];
		b[1]=amt[1];
		for(i=2;i<=sz-1;i++){
			a[i]=max((a[i-2]+amt[i]),(a[i-1]+amt[i]-amt[i-1]));
			if(i<sz-1)
				b[i]=max((b[i-2]+amt[i]),(b[i-1]+amt[i]-amt[i-1]));
		}
		return max(a[sz-1],b[sz-2]);
	}
};

int main(){
	int input;
	vector <int> donations;
	while(cin>>input){
		donations.push_back(input);
	}
	BadNeighbors obj;
	cout<<obj.maxDonations(donations)<<"\n";
	return 0;
}

