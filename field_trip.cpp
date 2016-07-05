#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

int a[1001][169],*list;

void prime(int b){
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
	//return list;
}
void factorize(){
	int i,j,num,temp;
	// have not covered the remaining cases where there is no need to calculate nCr or the limit is not the same
	// for nCr


	for(i=0;i<=1000;i++){
		for(j=0;j<=168;j++){
			a[i][j]=0;
		}
	}

	for(i=2;i<=1000;i++){
		for(j=1;j<=168;j++){
			num=list[j];
			temp=i/num;
			while(temp){
				a[i][j]+=temp;
				num*=list[j];
				temp=i/num;
			}
		}
	}
}

double comb(int *x){
	double p=1;
	int power,i;
	for(i=1;i<169&&list[i]<=x[4];i++){
		power=0;
		power+=(a[x[0]][i]+a[x[2]][i]+a[x[5]][i]+a[x[4]-x[5]][i]);
		power-=(a[x[1]][i]+a[x[0]-x[1]][i]+a[x[3]][i]+a[x[2]-x[3]][i]+a[x[4]][i]);
		p*=pow(list[i],power);
	}
	return p;
}


int main(){
	prime(1000);
	factorize();
	/*
	for(i=0;i<=1000;i++){
		for(j=0;j<=168;j++){
			cout<<list[j]<<":"<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	int t,s,n,m,k,x[6];
	double p;
	cin>>t;
	while(t--){
		cin>>s>>n>>m>>k;
		p=0;
		if(k>(n-1)){
			p=0;
			printf("%.6f\n",p);
			continue;
		}
		if(m==s||n==s){
			p=1;
			printf("%.6f\n",p);
			continue;
		}
		x[0]=m-1;
		x[2]=s-m;
		x[4]=s-1;
		x[5]=n-1;
		i=k;
		while(m-1-i>=0&&n-1-i>=0){
			x[1]=i;
			x[3]=n-1-i;
			p+=comb(x);
			i++;
		}
		printf("%.7f\n",p);

	}
	return 0;
}