#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  char color;
  cin>>color;
  int counter=0;
  char arr[n][m];
  map<char,bool>mp;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
        cin>>arr[i][j];
  }
  mp[color]=1;
  mp['.']=1;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
        if(arr[i][j]==color)
        {
            if(mp[arr[i+1][j]]!=1&&i<=n-2)
            {
                mp[arr[i+1][j]]=1;
                counter++;
               // cout<<arr[i+1][j]<<endl;
            }
            if(mp[arr[i-1][j]]!=1&&i>=1)
            {
              mp[arr[i-1][j]]=1;
              counter++;
             // cout<<'2'<<endl;
            }
               if(mp[arr[i][j+1]]!=1&&j<=m-2)
              {
                  mp[arr[i][j+1]]=1;
                  counter++;
                //  cout<<'3'<<endl;
              }
              if(mp[arr[i][j-1]]!=1&&j>=1)
              {
                  mp[arr[i][j-1]]=1;
                  counter++;
                 // cout<<'4'<<endl;
              }
        }
      }
  }
  cout<<counter;

}
