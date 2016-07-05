#include<bits/stdc++.h>
int main(){

	int num,i,count,limit,b;
	
	std::cin>>b;
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
			//std::cout<<i;
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
	//std::cout<<"the count is:"<<count<<"\n";
	i=0;
	while (i<count){
		std::cout<<list[i]<<"\n";
		i++;
	}
	std::cout<<count<<"\n";

	return 0;
}