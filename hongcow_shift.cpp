#include<bits/stdc++.h>

using namespace std;

#define randn1 234971
#define randn2 564366
typedef long long int ll;

ll powr1(int a,int b){
	ll x,y;
	y=a;
	x=1;
	while(b){
		if(b%2==1){
			x=(x*y)%randn1;
		}
		y=(y*y)%randn1;
		b=b/2;
	}
	return x;
}

ll powr2(int a,int b){
	ll x,y;
	y=a;
	x=1;
	while(b){
		if(b%2==1){
			x=(x*y)%randn2;
		}
		y=(y*y)%randn2;
		b=b/2;
	}
	return x;
}

ll mod1[55],mod2[55],power1[55],power2[55];
int str[55];

void fill_pow1(){
	int i;
	for(i=0;i<50;i++){
		power1[i]=powr1(26,i);
	}
}

void fill_pow2(){
	int i;
	for(i=0;i<50;i++){
		power2[i]=powr2(26,i);
	}
}

int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}

void printt(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int n;

int main(){
	
	int ch,i;
	int sample1[600000],sample2[600000];
	ll sum1,sum2,count1,count2;
	int x;

	for(i=0;i<600000;i++){
		sample1[i]=0;
		sample2[i]=0;
	}

	fill_pow1();
	fill_pow2();

	ch=getchar();
	i=0;
	
	while(ch!=' '&&ch!='\n'&&ch!=EOF){
		str[i]=ch-'a';
		ch=getchar();
		i++;
	}
	n=i;

	// printt(str,n);

	mod1[0]=0;
	for(i=0;i<n;i++){
		mod1[0]+=(str[i]*power1[i])%randn1;
		
	}
	x=mod1[0];
	sample1[x]++;

	mod2[0]=0;
	for(i=0;i<n;i++){
		mod2[0]+=(str[i]*power2[i])%randn2;
		
	}
	x=mod2[0];
	sample2[x]++;

	sum1=mod1[0];
	sum2=mod2[0];
	count1=1;
	count2=1;

	for(i=n-1;i>=1;i--){
		sum1=sum1-(power1[n-1]*str[i])%randn1;
		sum1=(sum1*26)%randn1;
		sum1+=(str[i]);
		if(sum1<0){
			sum1+=randn1;
		}
		mod1[i]=sum1;
		x=sum1;
		if(sample1[x]==0){
			sample1[x]=1;
			count1++;
		}
		
		sum2=sum2-(power2[n-1]*str[i])%randn2;
		sum2=(sum2*26)%randn2;
		sum2+=(str[i]);
		if(sum2<0){
			sum2+=randn2;
		}
		mod2[i]=sum2;
		x=sum2;
		if(sample2[x]==0){
			sample2[x]=1;
			count2++;
		}

	}

	cout<<max(count1,count2)<<"\n";
	return 0;
}