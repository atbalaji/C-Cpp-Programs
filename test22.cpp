#include<iostream>

using namespace std ;

int main()
{
	int n = 17*17 ;
	for(int i=1 ; i<=n ; i++)
		if(n % i == 0)
			cout<<i<<endl;
}
