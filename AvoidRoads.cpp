#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;
 

class AvoidRoads{
	long long int a[105][105];
	bool b[105][105];
public:
	    AvoidRoads(int w=103,int h=103){
		for(int i=0;i<h;i++){
			for(int j=0;i<w;j++){
				a[i][j]=0;
				b[i][j]=true;			
			}
		}
	}

	long long int give_val(int i,int j,bool val){
		if(i>=0&&j>=0){
			if(b[i][j]||val){
				return a[i][j];
			}
			//return (b[i][j]||val)*a[i][j];
		}
		
		return 0;
	} 

	long long int numWays(int width,int height,int** bad,int n ){
		int i,j;
		for(i=0;i<n;i++){
		    for(j=0;j<4;j++){
		        cout<<bad[i][j]<<" ";
		    }
		    cout<<"\n";
		}
		for(i=0;i<n;i++){
			b[bad[i][1]][bad[i][0]]=false;
			b[bad[i][3]][bad[i][2]]=false;
		}
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				cout<<b[i][j]<<" ";
			}
			cout<<"\n";
		}
		for(i=0;i<height;i++){
			for(j=0;j<width;j++){
				a[i][j]=give_val(i-1,j,b[i][j])+give_val(i,j-1,b[i][j]);
				if((!i)&&(!j)){
				    a[i][j]=1;
				}
				cout<<a[i][j]<<"\n";
			}
		}
		return a[height-1][width-1];
	}
};

int main(){
    int n;
    int i,h,w,j;
    long long int ans;
    cin>>n;
	int **bd;
	bd=(int**)malloc(101*sizeof(int));
	for(i=0;i<4;i++){
		bd[i]=(int*)malloc(5*sizeof(int));
	}
	
	
	cin>>w>>h;
	
	for(i=0;i<n;i++){
		for(j=0;j<4;j++){
		    cin>>bd[i][j];
		}
	}
	
    
	AvoidRoads obj=AvoidRoads();
	ans=obj.numWays(w,h,bd,n);
	cout<<"\n";

	return 0;
}