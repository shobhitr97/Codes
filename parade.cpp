#include<iostream>
#include<cmath>

using namespace std;

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
	int n,l[100005],r[100005],maxm,sum,i,l_sum,r_sum,val,index;
	cin>>n;
	l_sum=0;
	r_sum=0;
	for(i=0;i<n;i++){
		cin>>l[i]>>r[i];
		l_sum+=l[i];
		r_sum+=r[i];
	}
	maxm=abs(l_sum-r_sum);
	index=0;
	for(i=0;i<n;i++){
	    val=abs( l_sum - r_sum + 2*( r[i]-l[i]) );
		if(val>maxm){
		    index=i+1;
		    maxm=val;
		}
	}
	cout<<index<<"\n";
	return 0;
}