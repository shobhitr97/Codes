#include<iostream>
using namespace std;



typedef long long int ll;

ll d,u;
ll max(ll a,ll b){
	if(a>b){
	return a;
	}
	return b;
}

ll min(ll a,ll b){
	if(a<b){
	return a;
	}
	return b;
}

ll perm(ll t){
	if(t==0){
		return d;
	}
	
	d=(d*(u+1-t))/t;
	return d;
}

int main(){
	ll i,n,k,c1,c2,ans,c,mi,ma,j,pt,temp;		

	cin>>n>>c1>>c2;

	mi=min(c1,c2);
	ma=max(c1,c2);
	if(mi==0){
		cout<<ma*(n-1);
		return 0;
	}
	//to find number of bits
	i=0;
	c=1;
	temp=n;
	while(temp>=2){
		temp/=2;
		i++;
		c*=2;
	}
	u=i;


 	if(u){
 		ans=0;
 		d=1;
		ans+=(u*(c/2)*(c1+c2));

		k=(n-c+((n-c)%2))/2;
		j=0;
		pt=perm(j);
		while(k>pt){
			ans+=((u-j)*mi+j*ma)*pt;	
			k-=pt;
			j++;
			pt=perm(j);
			cout<<u<<":C:"<<j<<" :"<<pt<<"\n";
		}
		cout<<k;
		ans+=((u-j)*mi+j*ma)*k;

		ans+=(k*ma+k*mi);
 	}
 	else{
 		ans=mi;
 	}

	cout<<ans<<"\n";

	return 0;
}
