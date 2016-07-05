#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define number 2000000000
#define F(i,a,b) for(int i=(int)a;i<(int)b;i++)
using namespace std;

int* prime(int b){
	int num,i,count,limit;
	//limit=(int)sqrt(b);
	int *sieve=(int*)calloc((b+1),sizeof(int));
	int *list=(int*)malloc((b+1)*sizeof(int));
	i=1;
	count =1;
	list[0]=1;
	while(i!=b){
		++i;
		if(sieve[i]==0){
			count++;
			list[count-1]=i;
			num=i;
			while(num<=b){
			sieve[num]=1;
			num+=i;
			}
		}
		else{
			continue;
		}
	}
	free(sieve);
	return list;
}
int power(int a,int b,int n){
	int num,t;
	if(b==1){
		return a%n;
	}
	if(b%2){
		num=power(a,b/2,n);
		t=(num*num)%n;
		return (t*(a%n))%n;
	}
	num=power(a,b/2,n);
	return (num*num)%n;
}

int main(){

	int t;
	long long int n,p,b,a,i;
	list=prime(number);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;list[i]<=n;i++){
			while()
		}
	}
	return 0;
}

int main(){
	long long int n;
	cin>>n;
	limit=sqrt(n);
	m=n;
	num=2;
	power=0;
	while(n/num){
		power+=(n/num);
		num*=2;
	}
	for(i=3;i<=sqrt(n);i+=2){

		if(m%i==0){
			power=0;
			while(m%i==0){
				m/=i;
			}
			while()
		}

	}
	return 0;
}