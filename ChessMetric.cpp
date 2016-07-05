#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<vector>

using namespace std;

class ChessMetric{
	long p_mov[100][100][51];
	int X[100][51],Y[100][51];
	
	int size_,num,end_[2];
	public:
		ChessMetric(){
			for(int i=0;i<100;i++){
				for(int j=0;j<100;j++){
					for(int k=0;k<51;k++){
						p_mov[i][j][k]=0;
					}
				}
			}		
		}
		int *finalPos(int *ipos,int move);

		long makemoves(int moves,int del){
			
			int  pos[2],*final,i,j,k=0;
		
			if(moves==num){
				return p_mov[end_[0]][end_[1]][num];
			}

				
			for(i=0;i<del;i++){
                cout<<"{"<<X[i][moves]<<","<<Y[i][moves]<<"}"<<"\n";
				for(j=1;j<=16;j++){
					
					pos[0]=X[i][moves];
					pos[1]=Y[i][moves];
					
					final=finalPos(pos,j);
					
					if(final[0]==-1){
						continue;
					}
					X[k][moves+1]=final[0];
					Y[k][moves+1]=final[1];
					k++;
					cout<<"->{"<<final[0]<<","<<final[1]<<"}"<<"\n";
					p_mov[final[0]][final[1]][moves+1]+=p_mov[X[i][moves]][Y[i][moves]][moves];
				}
			}
			//main
			//b[final[0]][final[1]]+=a[x[i]][y[i]];
				
			
		/*	x.erase(x.begin(),x.begin()+del);
			y.erase(y.begin(),y.begin()+del);
		*/	
			return makemoves(moves+1,k);
		}
		long howMany(int size,int *start,int *end,int numMoves){
			end_[0]=end[0];
			end_[1]=end[1];
			num=numMoves;
			cout<<size<<":\n"<<"{"<<start[0]<<","<<start[1]<<"}"<<","<<"{"<<end[0]<<","<<end[1]<<"}"<<"\n"<<num<<":\n";
			
			size_=size;
			X[0][0]=start[0];
			Y[0][0]=start[1];
			p_mov[start[0]][start[1]][0]=1;
			return makemoves(0,1);
			
		}
};

int main(){
	int n,m,a[2][2];
	cin>>n;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			cin>>a[i][j];
		}
	}
	cin>>m;
	ChessMetric obj;
	cout<<obj.howMany(n,a[0],a[1],m);
	return 0;
}

int* ChessMetric::finalPos(int *ipos,int move){
	switch(move){
		case 1:ipos[0]++;break;
		case 2:ipos[0]--;break;
		case 3:ipos[1]++;break;
		case 4:ipos[1]--;break;
		case 5:ipos[0]++;ipos[1]++;break;
		case 6:ipos[0]--;ipos[1]--;break;
		case 7:ipos[0]++;ipos[1]--;break;
		case 8:ipos[0]--;ipos[1]++;break;
		case 9:ipos[0]+=2;ipos[1]++;break;
		case 10:ipos[0]-=2;ipos[1]++;break;
		case 11:ipos[0]+=2;ipos[1]--;break;
		case 12:ipos[0]-=2;ipos[1]--;break;
		case 13:ipos[1]+=2;ipos[0]++;break;
		case 14:ipos[1]-=2;ipos[0]++;break;
		case 15:ipos[1]+=2;ipos[0]--;break;
		case 16:ipos[1]-=2;ipos[0]--;break;
	}
	if(ipos[0]<0||ipos[0]>=size_||ipos[1]<0||ipos[1]>=size_){
		ipos[0]=-1;
	}
	return ipos;
}