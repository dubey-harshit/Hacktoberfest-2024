#include<iostream>
using namespace std;
int main()
{
    int i,s,k,n;
    cout<<"Enter the value of n \n";
    cin>>n;
    for(i=1,k=0;i<=n;i++,k=0)
    {
      for(s=1;s<=(n-i);s++)
      {
          cout<<" ";
      }
      while(k!=(2*i)-1)
      {
          cout<<"*";
          k++;
      }
      cout<<"\n";
    }
    for(i=n-1,k=0;i>=1;i--,k=0)
    {
      for(s=1;s<=(n-i);s++)
      {
          cout<<" ";
      }
      while(k!=(2*i)-1)
      {
          cout<<"*";
          k++;
      }
      cout<<"\n";
    }

    return 0;
}
