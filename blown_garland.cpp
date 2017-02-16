#include<iostream>
#include<stdio.h>

using namespace std;

int vv(char ch){
	switch(ch){
		case 'R':return 0;break;
		case 'B':return 1;break;
		case 'Y':return 2;break;
		case 'G':return 3;break;
	}
}

int main(){
	char a[105],p[4],kk,total;
	int i,ch,length,val[4],pos[4],j;
	bool vis[4];
	for(i=0;i<4;i++){
		vis[i]=0;
		val[i]=0;
	}
	// vis[0]=vis[1]=vis[2]=vis[3]=0;
	
	p[0]='R',p[1]='B',p[2]='Y',p[3]='G';

	ch=getchar();
	i=0;
	total=0;
	while(ch!=' '&&ch!='\n'&&ch!=EOF){
		a[i]=ch;
		if(a[i]=='!'){
			total++;
		}
		ch=getchar();
		i++;
	}
	length=i;
	int value,sum;
	sum=0;
	for(i=0;i<length;i++){
			
		if(a[i]!='!'){

			j=vv(a[i]);

			if(vis[j]){
				continue;
			}
			vis[j]=1;
			pos[j]=(i%4);
			value=0;
			j=(i%4);
			while(j<length){
				if(a[j]=='!'){
					value++;
				}
				j+=4;
			}
			j=vv(a[i]);
			val[j]=value;
			sum+=value;

		}

	}

	value=0;
	for(i=0;i<4;i++){
		if(!vis[i]){
			val[i]=(total-sum);
			vis[i]=1;
		}
	}

	for(i=0;i<4;i++){
		cout<<val[i]<<" ";
	}
	cout<<"\n";

	return 0;

}