#include<bits/stdc++.h>

double r_digit(double n){
	/*
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
	*/
	int power=0;
	long long int k;
	k=n*10*10*10*10;
	while(!(k%10)){
		k/=10;
		power++;
	}
	return 4-power;
}

int self_gcd(long long int a,long long int b){
	long int temp;
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
	int t,r;
	double k,power1;
	float n;
	std::cin>>t;
	while(t--){
		scanf("%f ",&n);
		power1=r_digit(n);
		if (!power1){
			std::cout<<"1"<<"\n";
			continue;
		}
		else{
			k=pow(10,power1);
			printf("%.4f ",n);
			r=n*k;
			std::cout<<r<<" "<<k<<" "<<n<<"\n";
			std::cout<<(k/self_gcd(k,r))<<"\n";
		}
	}
	return 0;
}