#include<bits/stdc++.h>
int d,count=0,*list1,a,b,*val,*check;
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
void fn(int t,int n,int len,int *arr){
	if (n==10){
		return ;
	}
	if(len==5){
		if(t){
			int i,num=0,limit,power;
			for(i=0;i<5;i++){
				num += (pow(10,i)*arr[i]);
			}
			if(num<a||num>b){
				return ;
			}
			std::cout<<num<<"\n";
			int ch=1;
			limit=sqrt(num);
			for(i=1;list1[i]<=limit;i++){
				power=0;
				while(num%list1[i]==0){
					power++;
				}
				if(power!=0&&power%2==0){
					ch=0;
					break;
				}
			}
			if(ch){
				count++;
			}
		}
	}
	arr[len]=n;
	if(n==d){
		fn(1,n+1,len+1,arr);
	}
	else{
		fn(t,n+1,len+1,arr);
	}
}
*/
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
}
void fn(int num){
	int i,limit,power,p=num,test=0;
	if(num>b){
		return ;
	}
	if(!check1(num)){
	    fn(num+1);
	    return ;
	}
	if(check[num]){
	    count+=val[num];
		fn(num+1);
		return;
	}
	check[num]=1;
	int ch=1;
	limit=sqrt(num);
	for(i=1;list1[i]<=limit;i++){
		power=0;
		while(num%list1[i]==0&&num){
			power++;
			num/=list1[i];
		}
		if(power>=2){
			ch=0;
			break;
		}
	}
	if(ch){
	    val[p]=1;
		count++;
		//std::cout<<p<<"\n";
	}
	fn(p+1);
}
int main(){
	list1=prime(100000);
	val=(int*)calloc(100001,sizeof(int));
	check=(int*)calloc(100001,sizeof(int));
	int arr[5],t;
	std::cin>>t;
	while(t--){
		std::cin>>a>>b>>d;
		//fn(0,0,0,arr);
		fn(a);
		std::cout<<count<<"\n";
		count=0;
	}
	return 0;
}