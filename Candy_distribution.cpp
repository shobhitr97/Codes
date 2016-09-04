#include<iostream>
#include<vector>

using namespace std;

typedef long long int ll;
#define mod 1000000007
#define num 1000000

ll arr[1000005];

ll promod(ll a,ll b){
	ll x,y;
	y=a%mod;
	x=0;
	while(b>=1){
		if(b%2==1){
			x=(x+y)%mod;
		}
		y=(y+y)%mod;
		b=b/2;
	}
	return y;
}

ll powmod(ll a,ll n){
	a=a%mod;
	ll x=a;
	while(n!=1){
		x=promod(x,x);
		if(n%2==1){
			x=promod(x,a);
		}
		n/=2;
	}
	return x;
}

void construct_arr(){
	ll j,x;
	int i;
	for(i=3;i<=num;i++){
		arr[i]=1;
	}
	arr[1]=1;
	arr[2]=1;
	i=2;
	while(i*i<=num){
		if(i!=1){
			i++;
			continue;
		}
		j=i*i;
		x=arr[i];
		while(j<=num){
			if(arr[j+1]==1){
				arr[j+1]=0;
			}
			arr[j+1]+=powmod(x,j);
			j+=i;
		}
		i++;
	}
	
}

ll psi(ll n){
	if(n<=num+1){
		int a=n;
		return arr[a];
	}
	n--;
	i=2;
	ll pp,sum=0;
	while(i*i<=n){
		if(n%i!=0){
			i++;
			continue;
		}
		pp=psi(i);
		sum=(sum+powmod(pp,n/i))%mod;
		pp=psi(n/i);
		if(i!=(n/i)){
			sum=(sum+powmod(pp,i))%mod;
		}
		i++;
	}
	return sum;
}

int main(){
	ll n;
	construct_arr();
	cin>>n;
	cout<<psi(n)<<"\n";
	return 0;
}
