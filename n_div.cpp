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
	int count,i,power,j,a,b,n,num,*list;
	std::cin>>a>>b>>n;
	int *sieve=(int*)calloc((b-a+1),sizeof(int));
	list=prime(b);
	for(i=0;i<=b-a;i++){
		sieve[i]=1;
	}
	i=1;
	while(list[i]){
		//std::cout<<list[i]<<"\n";
		for(j=a;j<=b;j++){
			num=list[i];
			power=0;
			while(j%num==0){
				power++;
				num*=list[i];
			}
			sieve[j-a]*=(power+1);
		}
		i++;
	}
	count=0;
	//std::cout<<"\n";
	for(j=a;j<=b;j++){
		if(sieve[j-a]==n){
		    //printf("%d\n",j+a);
			count++;
		}
	}
	std::cout<<count<<"\n";
    //std::cout<<"\n"<<sieve[b-a]<<"\n";

	return 0;
}	