#include<iostream>
#include<iomanip>
#include <cstdlib>
#include<time.h>
using namespace std;
int *x;
int n;
int no_of_sol=0;
//k row--i col
bool Place(int k,int i)
{
    for(int j=1;j<=k-1;j++){
        if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
        {return false;}
    }
    return true;
}
void write(){
    no_of_sol++;
    cout<<"Solution "<<no_of_sol<<": ";
    for(int i=1;i<=n;i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<endl<<"In matrix representation:\n";
    for(int i=1;i<=n;i++){
        cout<<"|";
        for(int j=1;j<=n;j++)
        {   
            if(j==x[i])
            cout<<"Q |";
           else cout<<"  |";
        }
        cout<<endl;
    }
    cout<<"-------------------------------------"<<endl;
    cout<<endl;

}

void nqueens(int k,int n)
{
    for(int i=1;i<=n;i++ ){
        if (Place(k, i)){
            x[k] = i;
            if(k == n)
            {write ();}
            else nqueens(k+1,n);
    }
}
}


int main()
{  
    cout<<"Enter the size of nxn chessboard: ";
    cin>>n;
    x=new int[n+1];
    x[0]=0;
    cout<<"\nAll the solutions of "<<n<<" queen's problem are:\n";
    clock_t beg=clock();
    nqueens(1,n);
    clock_t end=clock();
    double exec_time=(double)(end-beg)/CLOCKS_PER_SEC;
    cout<<"Time spent: "<<exec_time;
    cout<<endl<<"Total no. of solutions are: "<<no_of_sol;
    return 0;
}