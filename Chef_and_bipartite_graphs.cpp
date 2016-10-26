#include<iostream>

using namespace std;

int main(){
	int a[105][105],k,i,degg,m,n,d,rem,edg,,D,j,t;
	while(t--) {
		cin >> n >> m >> d >> D;
		// for(i=0;i<n;i++){
		// 	for(j=0;j<n;j++){
		// 		a[i][j]=0;
		// 	}
		// }
		if(m<n*d||m>n*D){
			cout<<"-1\n";
			continue;
		}

		for(i=0;i<n;i++){
			degg=0;
			while(degg!=d){
				// a[i][(i+degg)%n]=1;
				cout<<i<<" "<<((i+degg)%n)<<"\n";
				degg++;
			}
		}
		rem=m-n*d;



		// p=d;
		k=d;
		// rem=0;
		edg=0;
		while(edg!=rem){
			i=0;
			while(i<n&&edg!=rem){
				// a[i][k]=1;
				//i++;
				cout<<i<<" "<<k<<"\n";
				k=(k+1)%n;
				edg++;
				i++;
			}
			k = (k+1)%n;
		}

	}
	return 0;
}