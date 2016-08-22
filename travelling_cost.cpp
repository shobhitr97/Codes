#include <iostream>
#include<tuple>
#include<stack>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    // city number(i),cost including the road to city i,total length of the roads traversed till city i
    tuple<int,int,int> tup;
    stack<tup> cit;
    tuple<int,int,int> temp;
    while(t--){
    	cin>>n;
    	//cost[n][n] and length[n][n]
    	for(i=0;i<m;i++){
    		cin>>u>>v>>c>>l;
    		cost[u][v]=c;
    		length[u][v]=l;
    	}
    	get<0>(tup)=1;
    	get<1>(tup)=0;
    	get<2>(tup)=0;
		cit.push(tup);
		tcity=get<0>(temp);
		tcost=get<1>(temp);
		tlength=get<2>(temp);
		while(!cit.empty()){	
			temp=cit.top();
			cit.pop();
			//visiting condition if the cost until now is already greater then the cost inthe matrix then there is no meaning in visiting it again
			for(i=0;i<n;i++){
				if(cost[tcity][i]!=-1){
					c=cost[tcity][i]+tcost;
					l=length[tcost][i]+tlength;
					if(c<=y){
						if(b[i][c]==-1){
							b[i][c]=l;
						}
						else{
							b[i][c]=min(l,b[i][c]);
						}
					}
					else{
						continue;
					}
				}
			}
		}
    }
    return 0;
}
