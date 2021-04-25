#include<iostream>
using namespace std;

int n;
int a[305][5];

bool compare(int x[5],int y[5])
{
	if(x[3]>y[3])return true;
	else if(x[3]<y[3])return false;
	else if(x[3]==y[3])
	{
		if(x[0]>y[0])return true;
		else if(x[0]<y[0])return false;
		else if(x[0]==y[0])
		{
			if(x[4]<y[4])return true;
			else if(x[4]>y[4])return false;
		}
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
    {
    	cin>>a[i][0]>>a[i][1]>>a[i][2];
    	a[i][3]=a[i][0]+a[i][1]+a[i][2];
    	a[i][4]=i+1;
    }
    for(int i=0;i<5;i++)
    {
    	for(int j=i+1;j<n;j++)
    	{
    		if(!compare(a[i],a[j]))
    		{
    			for(int k=0;k<5;k++)
    			{
    				int t;
    				t=a[i][k];
    				a[i][k]=a[j][k];
    				a[j][k]=t;
    			}	
    		}
    	}
    	cout<<a[i][4]<<" "<<a[i][3]<<endl;
    }
    return 0;
}
