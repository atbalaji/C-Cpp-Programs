#include<iostream>
#include<vector>
#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<map>
#include<algorithm>


#define ll long long
#define p(a) printf("%d\n",a)
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sll(a) scanf("%ld",&a)
#define FOR(a,b) for(int i=a ; i<=b ; ++i)

using namespace std ;

int main() 
{
	while(true){
	int n ;
	s(n);
	if(n==0)
		break;
	int from = n/2 + 1;
	int c = 0;
	long long int sum = 0;
	while(n--){
		int val;
		s(val);
		c++;
		if(c>=from)
			sum += val;
	}
	printf("%lld\n",sum);
	}
	return 0 ;
}
