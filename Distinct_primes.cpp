#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

#define num 7000

int* prime(int b){
	int num,i,count,limit;
	//limit=(int)sqrt(b);
	int *sieve=(int*)calloc((b+1),sizeof(int));
	int *list=(int*)calloc((b+1),sizeof(int));
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

int main(){
	int a[num+1],*list,i,j,b[1000];
	list=prime(num);
	memset(a,1,num+1);
	for(i=0;list[i];i++){
		for(j=1;list[i]*list[j]<=num;j++){
			a[list[i]*list[j]]=0;
		}
	}
	
}