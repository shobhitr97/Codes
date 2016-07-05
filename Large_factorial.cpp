#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>


int main(){
	int a[3][200],div,i,j,carry,num,n,temp,index,k,t;
	std::cin>>t;
	while(t--){
		std::cin>>n;
		if(n==1||n==2){
			std::cout<<n<<"\n";
			continue;
		}
		for(i=0;i<200;i++){
			a[0][i]=0;
		}
		
		num=n;
		i=0;

		while(n){
			a[0][i]=n%10;
			i++;
			n/=10;
			
		}
		index=i-1;
		n=num-1;
		while(n>=2){
		    //std::cout<<"number:"<<n<<"\n";
		    for(i=0;i<200;i++){
		    //    std::cout<<a[0][i]<<" ";
	    		for(j=1;j<3;j++){
	    			a[j][i]=0;
	    		}
		    }
		    //std::cout<<"\n"; 
			num=n;
			i=0;
			while(num){
				div=num%10;
			//	std::cout<<"digit:"<<div<<"\n";
				j=0;
				carry=0;
				//a=multiply_(div,i,a);
				while(j<=index){

					temp=a[0][j]*div+carry;
					a[i+1][j+i]=temp%10;
			//		std::cout<<a[i+1][j+i]<<" ";
					carry=temp/10;
					j++;
				}
				while(carry){
					a[i+1][j+i]=carry%10;
			//		std::cout<<a[i+1][j+i]<<" ";
					carry/=10;
					j++;
				}
				index=j+i-1;
			//	std::cout<<"\n";
				num/=10;
				i++;
			}
			--i;
			j=0;
			//a[0][0]=a[1][0];
			carry=0;
			while(j<=index){
				temp=carry;
				for(k=0;k<=i;k++){
					temp+=a[1+k][j];
				}
				a[0][j]=temp%10;
		//		std::cout<<a[0][j]<<" ";
				carry=temp/10;
				j++;
			}
			while(carry){
				a[0][j]=carry%10;
		//		std::cout<<a[0][j]<<" ";
				carry/=10;
				j++;
			}
		//	std::cout<<"\n";
			
			n--;
		}
		--j;
		while(j>=0){
			std::cout<<a[0][j];
			for(k=-1;k<=i;k++){
				a[1+k][j]=0;
			}
			j--;
		}
		std::cout<<"\n";
	}
	return 0;
}