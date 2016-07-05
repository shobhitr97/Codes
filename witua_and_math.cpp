#include<bits/stdc++.h>
int *sieve;

int* prime(int b){
	int num,i,count,limit;
	//limit=(int)sqrt(b);
	sieve=(int*)calloc((b+1),sizeof(int));
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
	//free(sieve);
	return list;
}


int main(){
	int *list,num=INT_MAX,i,limit_n,ch;
	long long int n;
	list=prime(num);
	if(n<=num){
		i=n;
		while(sieve[i]){
			i--;
		}
		std::cout<<i<<"\n";
	}
	else{
		while(1){
			ch=1;
			i=1;
			limit_n=(int)sqrt(n);
			while(list[i]<=limit_n){
				if(n%list[i]==0){
					ch=0;
					break;
				}
				i++;
			}
			if(ch==1){
				break;
			}
			n--;
		}
		std::cout<<n<<"\n";
	}
	return 0;
}