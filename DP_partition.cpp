#include<iostream>
#include<stdio.h>

using namespace std; 



bool partition(int arr[],int n){

	int sum = 0 ;
	int i,j;
	for(i=0 ; i<n ; i++)
		sum += arr[i] ;
	if(sum % 2)
		return false;
	bool part[sum/2+1][n+1] ;
	for(i=0 ; i<=n ; i++)
		part[0][i] = true ;
	for(i=1  ; i<=sum/2 ; i++)
		part[i][0] = 0;
	for(i=1 ; i<=sum/2 ; i++){
		for(j=1 ; j<=n; j++){
			if(arr[j-1] > i)
				part[i][j] = part[i][j-1];
			else
				part[i][j] = part[i][j-1] || part[i-arr[j-1]][j-1];
		
		}
	}
	 for (i = 0; i <= sum/2; i++)  
     {
       for (j = 0; j <= n; j++)  
          printf ("%4d", part[i][j]);
       printf("\n");
     } 
	return part[sum/2][n];
}
int main(){

	int arr[] = {3, 1, 1, 2, 2, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<partition(arr,n);

}
