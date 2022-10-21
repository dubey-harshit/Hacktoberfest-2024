#include<iostream>
using namespace std;
int main()
{
    int i,j,n;
    cout<<"Enter the value of n \n";
    cin>>n;
    for(i=1;i<n;i++)
    {
      for(j=1;j<=i;j++)
      {
          if(j=n-i)
          {
              cout<<" ";
          }
          else
          {
              cout<<"*";
          }


      }
      cout<<"\n";
    }

    return 0;
}
