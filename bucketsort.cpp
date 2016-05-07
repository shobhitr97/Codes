#include<iostream>
#include<stdlib.h>

struct node{
	float data;
	struct node*next;
};
struct node *make_node(float val){
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->data=val;
	p->next=NULL;
	return p;
}

void traversal(struct node* head){
	while(head!=NULL){
		std::cout<<head->data<<"\n";
		head=head->next;
	}
}


int main(){
	int n,i,k;
	float *a;
	std::cin>>n;
	a=(float*)malloc(n*sizeof(float));
	struct node **head,*ptr,*p,*pp;
	head=(struct node**)malloc(n*sizeof(struct node*));
	for(i=0;i<n;i++){
		std::cin>>a[i];
		head[i]=NULL;
	}

	for(i=0;i<n;i++){
		ptr=make_node(a[i]);
		k=(int)(n*a[i]);
		if(head[k]!=NULL){
			p=pp=head[k];
			if((ptr->data < p->data)||(p==NULL)){
				ptr->next=p;
				if(p==head[k]){
					p=ptr;
				}
				else{
					pp->next=ptr;
				}
			}
			else{
				pp=p;
				p=p->next;
			}
		}
		else{
			head[k]=ptr;
		}
	}
	for(i=0;i<n;i++){
		p=head[i];
		traversal(p);
	}




	return 0;
}
/*
10
0.79
0.13
0.16
0.64
0.39
0.20
0.89
0.53
0.71
0.42
*/