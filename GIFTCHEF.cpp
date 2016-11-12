#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

#define mod1 173357
#define mod2 281033
typedef long long int ll;

int ab(int a,int b,int mod){
	ll x=1,y=a;
	while(b!=0){
		if(b%2==1){
			x=(x*y)%mod;
			// cout<<x<<" -> ";
		}
		y=(y*y)%mod;
		b=b/2;
	}
	// cout<<"<-\n";
	return x;
}

int main(){
	string ss;
	char s[300005],f[300005];
	int i,str[300005],h1[300005],t[300005];
	scanf("%s %s\n",s,f);

	i=0,val1=0,val2=0;
	while(f[i]!='\0'){
		val1 = ( ( val1 * 26 )%mod1 + ( f[i]-'a') )%mod1;
		val2 = ( ( val2 * 26 )%mod2 + ( f[i]-'a') )%mod2;
		i++;  
	}
 	mlen=i;

	i=0;
	while(s[i]!='\0'){
		str[i]=s[i]-'a';
		i++;
	}
	length = i;
	
	h1[0]=0;
	k=mlen-1;
	for(i=0;i<mlen;i++){
		h1[0]= ( ( h1[0]*26 )%mod1 + str[i] )%mod1;
		k--;
	}

	while(i>=0&&i<length-mlen+1){
		h1[i] = ( ( ( h1[i-1] -  ( str[i-1] * pow(26,mlen-1,mod1) )%mod1 )*26 )%mod1 + str[i+mlen-1] )%mod1;
		i++;
	}

	h2[0]=0;
	k=mlen-1;
	for(i=0;i<mlen;i++){
		h2[0]= ( ( h2[0]*26 )%mod2 + str[i] )%mod2;
		k--;
	}

	while(i>=0&&i<length-mlen+1){
		h2[i] = ( ( ( h2[i-1] -  ( str[i-1] * pow(26,mlen-1,mod2) )%mod2 )*26 )%mod2 + str[i+mlen-1] )%mod2;
		i++;
	}
	 
	for(i=0;i<length;i++){
		check[i] = (i+mlen<length+1) && (h1[i]==val1) && (h2[i]==val2) ;
	}

	







	return 0;
}