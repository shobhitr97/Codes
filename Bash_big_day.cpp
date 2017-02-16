#include<iostream>
#include<vector>

using namespace std;

int sieve[100005],prime[100005],count;


void gen(){
	count=0;
	int i,j,k;
	sieve[0]=0;
	sieve[1]=0;
	i=2;
	k=0;
	while(i<=100000){
		if(sieve[i]==0){
			i++;
			continue;
		}
		prime[k]=i;
		k++;
		j=2*i;
		while(j<=100000){
			sieve[j]=0;
			j+=i;
		}
		i++;
	}
	count=k;
}

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

void printt(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		// if(!arr[i]){
		// 	continue;
		// }
		cout<<i<<" "<<arr[i]<<"\n";
	}
}

int main(){
	int n,arr[100005],i,b[100005],k,maxm,pppp;

	for(i=0;i<=100000;i++){
		sieve[i]=1;
		arr[i]=0;

	}

	gen();

	cin>>n;



	pppp=0;
	for(i=0;i<n;i++){
		cin>>b[i];
		pppp=max(pppp,b[i]);
	}

	if(n==1){
		cout<<"1\n";
		return 0;
	}

	for(i=0;i<n;i++){



		if(sieve[ b[i] ]){
			arr[ b[i] ]++;
			continue;
		}
		k=0;
		while(prime[k]<=b[i]){
			if(b[i]%prime[k]==0){
				arr[prime[k]]++;
				b[i]/=prime[k];
				
			}
			k++;
		}

	}

	// printt(sieve,100000);
	// printt(arr,4);

	maxm=1;
	for(i=0;i<count;i++){
		if(!arr[ prime[i] ]){
			continue;
		}
		maxm=max(maxm,arr[ prime[i] ]);
	}

	cout<<maxm<<"\n";

	return 0;
}