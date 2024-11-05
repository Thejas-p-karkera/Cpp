#include<iostream>
using namespace std;

void main()
{
	int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(j>i)
			{
				cout<<"0 ";
			}
			else
			{
				cout<<matrix[i][j]<<" ";
			}			
		}
		cout<<endl;
	}

}