#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define pn        printf("\n")
#define SZ(x)  (int)((x).size())
vector< int>tmp;
int check(int num,int k)
{
 int i,j,prev=tmp[0]+num;
k--;
 for(i=1;i<tmp.size();i++)
 {
   if(prev+num>=tmp[i])
    continue;
   if(k==0)
    return 0;
   prev=tmp[i]+num;
   k--;
 }
 return 1;
}
int main()
{
  int n,i,j,k;
  cin>>n>>k;
  tmp.resize(n);
  rep(i,n)
  cin>>tmp[i];
  sort(tmp.begin(),tmp.end());
  
   int l=0,h=0,mid,p=-1;
    h=100000000;
  while(h>=l)
  {
      mid=(l+h)/2; 
      int vv=check(mid,k);
   cout<<l<<" "<<h<<" "<<mid<<" "<<vv<<"\n";
    if( check(mid,k) && check(mid-1,k)==0)break;
      if(vv==0)
        {
          p=mid;
          l=mid+1;
        }
      else
      h=mid-1;
  }
  cout<<mid<<"\n";
  return 0;
}
