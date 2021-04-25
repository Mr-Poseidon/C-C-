#include<iostream>
using namespace std;
int rnp=0;//逆序数对-Reverse number pairs

 
void merge(int a[],int low,int mid,int high)
{
	int *temp=new int[high-low+1];
	int i=low,j=mid+1,k=0;
	
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])//=可以解决相同数据的问题 
		{
			temp[k++]=a[i++];
		}
		else
		{
			rnp+=mid-i+1;//计算逆序数对 
			//cout<<ans<<" : "<<a[i]<<" "<<a[j]<<endl;//逆序对示例
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=high)
		temp[k++]=a[j++];
	
	for(int x=0;x<high-low+1;x++)
		a[low+x]=temp[x];
	delete[] temp;
}
void sort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		sort(a,low,mid);
		sort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	int a[5]={2,3,4,5,1};
	sort(a,0,5-1);
	for(int i=0;i<5;i++)
		cout<<a[i]<<" ";
	cout<<endl<<rnp<<endl;
	return 0;
} 
