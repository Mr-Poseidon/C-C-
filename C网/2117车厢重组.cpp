//法一： 
//冒泡排序
#include<iostream>
#include<algorithm>
using namespace std;

int n,a[10005],ans=0;
int main() 
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    for(int i=n-1;i>=0;i--)
        for(int j=0;j<i;j++)
            if(a[j]>a[j+1])
            {
                ans++;
                swap(a[j],a[j+1]);
            }
    cout<<ans;
    return 0;
}


//法二：
//归并排序
#include<iostream>
using namespace std;

int rnp=0;//逆序数对-Reverse number pairs
int a[10005],n;
 
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
			//rnp+=j-k;
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
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,0,n-1);
	
	cout<<rnp;
	return 0;
} 
