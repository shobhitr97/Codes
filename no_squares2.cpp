#include<bits/stdc++.h>
int d;
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
/*
int check1(int num){
    int test=0;
	while(num){
    	if(num%10==d){
    		test=1;
    		break;
    	}
    	num/=10;
    }
    return test;
}*/
int main(){
	int **val,*val1,i,*list,numb,num;
	val=(int**)malloc(10*sizeof(int*));
	val1=(int*)calloc(100001,sizeof(int));
	for(i=0;i<10;i++){
		val[i]=(int*)calloc(100001,sizeof(int));
	}
	list=prime(100000);
	i=1;
	while(list[i]<=316){
		num=list[i]*list[i];
		numb=num;
		while(numb<=100000){
			val1[numb]=1;
			numb+=num;
		}
		i++;
	}
	i=1;
	while(i<100001){
		if(!val1[i]){
			while(num){
				val[num%10][i]=1;
				num/=10;
			}
		}
		i++;
	}

	int a,b,t,count=0;
	std::cin>>t;
	while(t--){
		std::cin>>a>>b>>d;
		for(i=a;i<=b;i++){
			if(val[d][i]){
				count++;
			}
		}
		std::cout<<count<<"\n";
		count=0;
	}
	return 0;
}