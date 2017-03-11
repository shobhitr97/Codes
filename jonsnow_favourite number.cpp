#include<iostream>

using namespace std;

int main(){
	int arr1[1027],arr2[1027],a[100005],i,n,k,x,state,counter;

	cin>>n>>k>>x;

	for( i=0 ; i<=1024 ; i++ ){
		arr1[i] = 0;
		arr2[i] = 0;
	}

	for( i=0 ; i<n ; i++ ){
		cin>>a[i];
		arr1[ a[i] ]++;
	}

	state = 0;
	int pp;

	for( i=0 ; i<k ; i++ ){
		counter = 1;
		for( int j=0; j<=1024 ; j++ ){
			if(!state){
				if( arr1[j] ){
					pp = arr1[j];
					if(counter%2){
						arr2[j] += arr1[j]/2 ;
						arr2[ (j^x) ] += ( arr1[j] - (arr1[j]/2) );
						arr1[j] = 0;
					}
					else{
						arr2[j] += ( arr1[j]-(arr1[j]/2) );
						arr2[(j^x)] += arr1[j]/2;
						arr1[j] = 0;
					}
					counter += pp;
				}
			}
			else{
				if( arr2[j] ){
					pp = arr2[j];
					if(counter%2){
						arr1[j] += arr2[j]/2 ;
						arr1[ (j^x) ] += ( arr2[j] - (arr2[j]/2) );
						arr2[j] = 0;
					}
					else{
						arr1[j] += ( arr2[j]-(arr2[j]/2) );
						arr1[ (j^x) ] += arr2[j]/2;
						arr2[j]=0;
					}
					counter += pp;
				}
			}
		}
		state = (state + 1 )%2;
	}
	int min,max;
	if(state){
		for(i=0;i<=1024;i++){
			if(arr2[i]){
				min = i;
				break;
			}

		}

		for(i=1024;i>=0;i--){
			if(arr2[i]){
				max = i;
				break;
			}

		}
	}
	else{
		for(i=0;i<=1024;i++){
			if(arr1[i]){
				min = i;
				break;
			}

		}

		for(i=1024;i>=0;i--){
			if(arr1[i]){
				max = i;
				break;
			}

		}
	}

	cout<<max<<" "<<min<<"\n";

	return 0;
}