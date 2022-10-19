#include <iostream>
#include <conio.h>
#include <vector>
#include <graphics.h>
using namespace std;

void TriAngle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

vector<vector<float>> mul(vector<vector<float>> ar1,vector<vector<float>> ar2){
    if(ar1[0].size()!=ar2.size()){
        cout<<"multiplication not possible..\n";
        exit;
    }
    vector<vector<float>> mult={{0,0,0},{0,0,0},{0,0,0}};
     for(int i = 0; i<ar1.size();i++)
        for(int j = 0; j <ar2[0].size(); j++)
            for(int k = 0; k <ar1[0].size();k++)
            {
                mult[i][j]+= ar1[i][k]*ar2[k][j];
            }
    return mult;
}

void Scaling(vector<vector<float>> vert_mat)
{   
    float sx,sy;
    cout<<"Enter the value for sx and sy: ";
    cin>>sx>>sy;
    vector<vector<float>> scal_mat;
    scal_mat.push_back({sx,0,0});
    scal_mat.push_back({0,sy,0});
    scal_mat.push_back({0,0,1});
    vector<vector<float>> transl_mat;
    transl_mat.push_back({1,0,-vert_mat[0][0]});
    transl_mat.push_back({0,1,-vert_mat[1][0]});
    transl_mat.push_back({0,0,1});
    vector<vector<float>> transl_mat2;
    transl_mat2.push_back({1,0,vert_mat[0][0]});
    transl_mat2.push_back({0,1,vert_mat[1][0]});
    transl_mat2.push_back({0,0,1});
    vector<vector<float>> trans1=mul(scal_mat,transl_mat);
    vector<vector<float>> trans2=mul(transl_mat2,trans1);
    vector<vector<float>> transformed=mul(trans2,vert_mat);
    cout<<"Scaled:\n";
    for(int i=0;i<transformed.size();i++){
        for(int j=0;j<transformed[0].size();j++){
            cout<<transformed[i][j]<<" ";
        }
        cout<<endl;
    }
    TriAngle(transformed[0][0],transformed[1][0],transformed[0][1],transformed[1][1],transformed[0][2],transformed[1][2]);
}


int main()
{
    float x1, y1, x2, y2, x3, y3, x4, y4;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    cleardevice();
    cout<<"Enter the first coordinates of triangle: ";
    cin>>x1>>y1;
    cout<<"Enter the second coordinates of triangle: ";
    cin>>x2>>y2;
    cout<<"Enter the third coordinates of triangle: ";
    cin>>x3>>y3;
    vector<vector<float>> vert_mat;
    vert_mat.push_back({x1,x2,x3});
    vert_mat.push_back({y1,y2,y3});
    vert_mat.push_back({1,1,1});
    TriAngle(x1, y1, x2, y2, x3, y3);
    setcolor(RED);
    Scaling(vert_mat);
    getch();
    return 0;
}
