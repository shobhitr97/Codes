#include<iostream>

using namespace std;

typedef long long int ll;
#define num 200000 

int min(ll a,ll b){
	if(a<b){
		return a;
	}
	return b;
}

ll max(ll a,ll b){
	if(a>b){
		return a;
	}
	return b;
}

int main(){
    int n,i,ind,ind2,upper;
    ll sum,maxm,j;
    ll c[200005],a[200005],b[200005],ans[200005];
    cin>>n;
    upper=0;
    for(i=0;i<=num;i++){
    	c[i]=0;
    	ans[i]=0;
    }

    for(i=0;i<n;i++){
   		cin>>a[i];
   		upper=max(upper,a[i]);
   		c[a[i]]++;
    }
    for(i=0;i<n;i++){
    	b[c[a[i]]-1]=a[i];
    	c[a[i]]--;
    }
    for(i=1;i<=num;i++){
    	c[i]+=c[i-1];
    }
    //  	 	cout<<"upper bound:"<<upper<<"\n";
    maxm=0;
    for(i=0;i<n;i++){
    	sum=0;
   		for(j=1;j*a[i]<=upper;j++){
   			ind=min(num,a[i]*(j+1)-1);
   			ind2=a[i]*j-1;
   			sum+=((c[ind]-c[ind2])*(a[i]*j));
   		}
   		maxm=max(sum,maxm);
   	}
   	cout<<maxm<<"\n";
    return 0;
}
