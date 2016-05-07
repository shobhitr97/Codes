//ups and downs

#include<iostream>
#include<stdlib.h>

int min(int a,int b){
	if (a<b){
		return a;
	}
	return b;
}
int max(int a,int b){
	if (b>a){
		return b;
	}
	return a;
}
void printd(int a){
	std::cout<<a<<"\n";
}
int main(){
	int t,i,n,n1,n2,*a;
	std::cin>>t;
	while(t--){
		i=0;
		std::cin>>n;
		//std::cout<<"n:";printd(n);
		a=(int*)malloc((n+1)*sizeof(int));
		std::cin>>n1;
		//std::cout<<"n1:";printd(n1);
		while(i<n){
			if ((i+1)<n){
				std::cin>>n2;
				//std::cout<<"n2:";printd(n2);
				a[i]=min(n1,n2);
				n1=max(n1,n2);
				if (i+2<n){
					std::cin>>n2;
					//std::cout<<"n2:";printd(n2);
					a[i+1]=max(n1,n2);
					n1=min(n1,n2);
					i+=2;	
					//print(i);
				}
				else{
					a[i+1]=n1;
					break;
				}	
			}
			else{
				a[i]=n1;
				break;
			}
		}
		for(i=0;i<n;i++){
			std::cout<<a[i]<<" ";
		}
		std::cout<<"\n";
		free(a);
	}
	return 0;
}