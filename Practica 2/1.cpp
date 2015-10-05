#include <iostream>

using namespace std;

void productMatrix(int m1[][3],int m2[][3])
{
    int matriz3[3][3];
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            matriz3[i][j]=0;
        }
    }
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int z=0;z<3;z++)
            {
                matriz3[i][j]+=m1[i][z]*m2[z][j];
            }
        }
    }
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<matriz3[i][j]<<endl;
        }
    }
}

int main()
{
    int matriz1[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>matriz1[i][j];
        }
    }
    int matriz2[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>matriz2[i][j];
        }
    }
    productMatrix(matriz1, matriz2);
}
