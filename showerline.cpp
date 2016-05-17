#include<bits/stdc++.h>
int g[5][5];
int th(int *a){
	int i=0;
	return g[a[0]][a[1]]+g[a[1]][a[0]]+g[a[1]][a[2]]+g[a[2]][a[1]]+2*(g[a[2]][a[3]]+g[a[3]][a[2]]+g[a[3]][a[4]]+g[a[4]][a[3]]);
}

int main(){
	int i,j,a,b,c,d,e,arr[5],total=0,p;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			std::cin>>g[i][j];
		}
	}
	for(a=0;a<5;a++){
		arr[0]=a;
		b=0;
		while(b<5){
			if(b!=a){
				arr[1]=b;
				c=0;
				while(c<5){
					if (c!=b&&c!=a){
						arr[2]=c;
						d=0;
						while(d<5){
							if(d!=a&&d!=b&&d!=c){
								arr[3]=d;
								e=0;
								while(e<5){
									if(e!=d&&e!=c&&e!=b&&e!=a){
										arr[4]=e;
										p=th(arr);
										if(p>total){
											total=p;
										}
									}
									e++;
								}
							}
							d++;
						}
					}
					c++;
				}
			}
			b++;
		}
	}
	std::cout<<total;
	return 0;
}
