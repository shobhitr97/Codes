#include<bits/stdc++.h>
char **city;
struct cit{
	char dir;
	struct cit* next;
	struct cit *prev;
};
struct cit* head=NULL;

struct cit *lsearch(char dirn){
	struct cit *ptr=head;
	while(ptr->dir!=dirn){
		ptr=ptr->next;
	}
	return ptr;
}
/*
char chan(char X,int dir){
	struct cit *a;
	a=lsearch(X);
	if(dir==0){
		a=a->next;
	}
	else{
		a=a->prev;
	}
	
	city[i][j]= a->dir;
}
*/
void change(int x1,int y1,int x2,int y2,int dir){
	int i,j;
	for(i=x1;i<=x2;i++){
		for(j=y1;j<=y2;j++){
	
			struct cit *a;
			a=lsearch(city[i][j]);
			if(dir==0){
				a=a->next;
			}
			else{
				a=a->prev;
			}
			
			city[i][j]= a->dir;
		}
	}
}
struct cit *alloca(){
	struct cit *ptr,*ptr2,*ptr3,*ptr1;
	ptr=(struct cit*)malloc(sizeof(struct cit));
	ptr->dir ='N';
	ptr->next =NULL;
	ptr->prev=NULL;
	ptr1=(struct cit*)malloc(sizeof(struct cit));
	ptr1->dir ='E';
	ptr1->next =NULL;
	ptr->prev=NULL;
	ptr2=(struct cit*)malloc(sizeof(struct cit));
	ptr2->dir ='S';
	ptr2->next =NULL;
	ptr->prev=NULL;
	ptr3=(struct cit*)malloc(sizeof(struct cit));
	ptr3->dir ='W';
	ptr3->next =NULL;
	ptr->prev=NULL;
	ptr3->next=ptr;
	ptr->prev=ptr3;
	ptr->next=ptr1;
	ptr1->prev=ptr;
	ptr1->next=ptr2;
	ptr2->prev=ptr1;
	ptr2->next=ptr3;
	ptr3->prev=ptr2;

	return ptr;
}
int main(){
	int m,n,i,j,t;
	char k;
	std::cin>>m>>n;
	head=alloca();
	city=(char**)malloc(m*sizeof(char*));
	for(i=0;i<n;i++){
		city[i]=(char*)malloc(n*sizeof(char));
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			std::cin>>city[i][j];
		}
	}
	
	std::cin>>t;
	for(i=1;i<=t;i++){
		std::cin>>k;
		switch(k){
			case 'D':   int x,y;
						std::cin>>x>>y;
						std::cout<<city[x-1][y-1]<<"\n";
						break;
			case 'C':	int x1,y1,x2,y2,dirnn;
						std::cin>>x1>>y1>>x2>>y2>>dirnn;
						change(x1-1,y1-1,x2-1,y2-1,dirnn);
						break;
		}
	}




	

	return 0;
}