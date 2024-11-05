#include<iostream>
using namespace std;

void main()
{
	for(int i = 0; i <= 5; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			cout<<"*";
		}

		cout<<endl;
	}
}