#include<bits/stdc++.h>

float a[300][100],P[100];
int S;
//long long int sum1;
void printli(int row){
	int i;
	for(i=0;i<S;i++){
		std::cout<<a[row][i]<<" ";
	}
	std::cout<<"\n";
}
void printp(){
	for(int i=0;i<S;i++){
		std::cout<<P[i]<<"\n";
	}
}
void subt(int a1,int a2){
	for(int i=0;i<S;i++){
		a[a1][i]-=a[a2][i];
	}

	//printli(a1);
	//P[a1]-=P[a2];
}
void print1(float sum){
	if(sum-floor(sum)>0.5){
		std::cout<<ceil(sum)<<" ";
	}
	else{
		std::cout<<floor(sum)<<" ";
	}
}
int powre1(int a,int b){
	int i=0;
	int s=1;
	for(i=0;i<b;i++){
		s*=a;
	}
	return s;
}
int main(){
	int i,j,C,t,row;
	float sum,X[100];
	std::cin>>t;
	while(t--){
		std::cin>>S>>C;
		for(i=0;i<S;i++){
			std::cin>>P[i];
		}
		//printp();
		for(i=0;i<S+C;i++){
			for(j=0;j<S;j++){
				a[i][j]=powre1((i+1),j);
			}
		//	printli(i);
		}
		//std::cout<<"\n";
		row=1;
		while(row<=S-1){
			i=S-1;
			while(i>=row){
				subt(i,i-1);
				P[i]-=P[i-1];
				i--;
			}
		//	printp();
		//	std::cout<<"\n";
			row++;
		}
		for(i=0;i<S;i++){
			for(j=0;j<S;j++){
		//		std::cout<<a[i][j]<<" ";
			}
		//	std::cout<<"\n";
		}
		i=S-1;
		//printli(i);
		while(i>-1){
			sum=P[i];
			for(j=S-1;j>=i+1;j--){
				sum-=a[i][j]*X[j];
			}
			X[i]=sum/(float)a[i][i];
		//	std::cout<<X[i]<<"*x^"<<i<<"+";
			i--;
		}
		//std::cout<<"\n";
		for(i=0;i<C;i++){
			sum=0;
			for(j=0;j<S;j++){
				sum+=((float)a[S+i][j]*X[j]);
			}
			print1(sum);
		}
		std::cout<<"\n";
	}
	return 0;
		
}