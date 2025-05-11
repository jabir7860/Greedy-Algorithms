#include<bits/stdc++.h>
using namespace std;
int fun(int ind,int coins[],int V) 
{
    if(ind==0)
    {
        if(V%coins[ind]==0) return V/coins[ind]; 
    }
    int np=fun(ind-1,coins,V); 
    int p=INT_MAX; 
    if(coins[ind]<=V) 
    {
        p=V/coins[ind]+fun(ind-1,coins,V-(V/coins[ind]*coins[ind])); 
    }
    return min(p,np); 
}
int main() {
  int V = 49;
  vector < int > ans;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int jabir=fun(8,coins,V);
  cout<<jabir<<endl; 
  int n = 9;
  for(int i=n-1;i>=0;i--) 
  {
      while(coins[i]<=V) 
      {
            V-=coins[i];
            ans.push_back(coins[i]); 
      }
  }
  cout<<"The minimum number of coins is "<<ans.size()<<endl;
  cout<<"The coins are "<<endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
