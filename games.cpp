#include<bits/stdc++.h>


int check(float f){
	if (f*100<1){
		return 1;
	}
	return 0;
}

int main(){
	int i,p,num[10],den[10],temp,t;
	float f,n;
	std::cin>>t;
	while(t--){
		i=-1;
		std::cin>>n;
		f=n-floor(n);
		p=check(f);
		if(p){
			std::cout<<floor(n)<<"\n";
			continue;
		}
		while(!p&&i<10){
			i++;
			n=1/f;
			num[i]=floor(n);
			den[i]=1;
			f=n-floor(n);
			p=check(f);
			
		}
		temp=num[i];
		num[i]=den[i];
		den[i]=temp;
		i--;
		while(i>=0){
			num[i]=num[i]*den[i+1] +num[i+1];
			den[i]=den[i+1];
			temp=num[i];
			num[i]=den[i];
			den[i]=temp;
			i--;
		}
		std::cout<<den[0]<<"\n";
	}
	return 0;
}