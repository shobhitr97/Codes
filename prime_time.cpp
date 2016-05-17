#include<bits/stdc++.h>
int* prime(int b){
	int num,i,count,limit;
	
	//std::cin>>b;
	//limit=(int)sqrt(b);
	int *sieve=(int*)calloc((b+2),sizeof(int));
	int *list=(int*)malloc((b+1)*sizeof(int));
	sieve[0]=0;
	sieve[1]=0;
	sieve[2]=0;
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
	int n,i=1,d,q,num,start=1;
	std::cin>>n;
	int *list=prime(n);
	i=1;
	while(list[i]){
		
		num=list[i];
		d=0;
		q=n/num;
		while(q){
			d+=q;
			num*=list[i];
			q=n/num;
			
		}
		if(!start){
			std::cout<<" * ";
		}
		else{ 
		    start=0;  
		}
		std::cout<<list[i]<<"^"<<d;
		i++;
	}
	return 0;
}	