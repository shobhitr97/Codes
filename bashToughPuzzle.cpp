#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef set<int> si;

#define pb push_back
#define mp make_pair
#define fori(a, b) for(int i=a ; i<b ; i++ )
#define forn(i, a, b) for(int i=a ; i<b ; i++ )
#define forin(a, b) for(int i=a ; i>=b ; i-- )
#define fornn(i, a, b) for(int i=a ; i>=b ; i-- )
#define fi first
#define se second
#define INF 1000000007
#define NUM 500005

int binTree[3*NUM], a[NUM], pos[NUM];
int n;

int gcd(int x, int y){
	int temp;
	if(x > y){
		temp = x;
		x = y;
		y = temp;
	}
	if(x == 0)	return y;
	return gcd(y%x, x);
}

void fillBinTree(int index, int l, int r){
	if( l == r ){
		binTree[index] = a[l];
		pos[l] = index;
		return;
	}
	int mid = (l+r)/2;
	fillBinTree(2*index+1, l, mid);
	fillBinTree(2*index+2, mid+1, r);
	binTree[index] = gcd(binTree[2*index+1], binTree[2*index+2]);
}

int check(int index, int left, int right, int l, int r, int x){
		if(r < left || l > right)	return 1;

		if(binTree[index]%x == 0)	return 1;
		if(left == right)	return 0;

		int leftChild, rightChild, mid;

		mid = (left+right)/2;
		leftChild = 2*index+1;
		rightChild = 2*index+2;

		if(left >= l && right <= r){
			if(binTree[leftChild]%x > 0 && binTree[rightChild]%x > 0)	return -1;

			if(binTree[leftChild]%x > 0)	return check(leftChild, left, mid, l, r, x);
			else	return check(rightChild, mid+1, right, l, r, x);
		}
		else{
			int k1 = 1, k2 = 1;
			if(!(r < left || l > mid))	k1 = check(leftChild, left, mid, l, r, x);
			if(!(r < (mid+1) || l > right))	k2 = check(rightChild, mid+1, right, l, r, x);

			if(k1 == (-1) || k2 == (-1))	return -1;
			if(k1 == 1 && k2 == 1)	return 1;
			if(k1 + k2 == 1)	return 0;
			if(k1 == 0 && k2 == 0)	return -1;
		}
}

void setVal(int position, int val){
	int newVal, index;

	index = pos[position];

	a[position] = val;
	binTree[index] = val;

	index = (index-1)/2;
	while(index >= 0){
		newVal = gcd(binTree[2*index+1], binTree[2*index+2]);
		if(newVal == binTree[index])	break;
		binTree[index] = newVal;
		index = (index-1)/2;
	}
}

int main(){

	int q, t, l, r, x;

	cin>>n;
	fori(0, n)	scanf("%d", &a[i]);
	cin>>q;

	fillBinTree(0, 0, n-1);
	
	fori(0, q){
		scanf("%d", &t);
		switch(t){
			case 1:	scanf("%d %d %d", &l, &r, &x);	
					if(check(0, 0, n-1, l-1, r-1, x) >= 0)	printf("YES\n");
					else	printf("NO\n");
					break;
			case 2:	scanf("%d %d", &l, &x);		
					setVal(l-1, x);
					break;
		}
	}

	return 0;
}