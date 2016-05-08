#include<bits/stdc++.h>

int r_digit(float n){
	int i=0;
	float p;
	p=n-floor(n);
	n=p;
	while(n){
		i++;
		n*=10;
		p=n-floor(n);
		n=p;
	}
	return i;
}

	int self_gcd(int a,int b){
	int temp;
	if (a<b){
		temp=a;
		a=b;
		b=temp;
	}
	if(a%b==0){
		return b;
	}
	else{
		return self_gcd(b,a%b);
	}
}

int main(){
	int power1,t,k;
	float n,f;
	std::cin>>t;
	while(t--){
		std::cin>>n;
		n=floor(n*10000)/10000;
		power1=r_digit(n);
		if (!power1){
			std::cout<<"1"<<"\n";
			continue;
		}
		else{
			k=pow(10,power1);
			n*=k;
			std::cout<<(k/self_gcd(k,n))<<"\n";
		}
	}
	return 0;
}