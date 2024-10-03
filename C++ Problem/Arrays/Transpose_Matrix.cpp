#include <iostream>
using namespace std;



int main()
{
    int a[3][3]={{1,2,3},
                 {4,5,6},
                 {7,8,9}};
    int temp;
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        temp=a[i][j];
        a[i][j]=a[j][i];
        a[j][i]=temp;
      }
    }

    cout<<"Original Array \n";
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        cout<<a[i][j]<<" ";
      }
      cout<<"\n";
    }

    cout<<"Transposed Array \n";
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        cout<<a[j][i]<<" ";
      }
      cout<<"\n";
    }
    return 0;
}
