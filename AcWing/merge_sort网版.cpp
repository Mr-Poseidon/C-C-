#include<iostream>
using namespace std;
int ans=0;

static void merge(int a[], int low, int mid, int high)
{
	// 分配额外的数组，low 到 high需要的空间大小
    int *temp = new int[high - low + 1];
    // 左边从low开始指的指针，会一直到mid
    int i = low;
    // 右边从mid+1开始，一直到high，因为我们需要对两个分组进行比较，排序
    int j = mid + 1;
    // 额外分组的指针
    int k = 0;
    // 2个分组都没到头就说明还是可以继续比较
    while (i <= mid && j <= high) {
    	// 比较，小的在temp的前面
    	// =可以解决数据相同的问题 
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else { 
        	ans+=mid-i+1;/*此处可以计算逆序数对*/
            temp[k++] = a[j++];
        }
    }
    // 如果左边还没有结束，则继续进行分配
    while (i <= mid) {    
        temp[k++] = a[i++];
    }
    // 右边也是这样
    while (j <= high) {
        temp[k++] = a[j++];
    }
    // 将重新排序好的temp 覆盖到a数组上面去
    for (int x = 0; x < high - low + 1/*temp.length()*/; x++) {
        a[low + x] = temp[x];
    }
}

// a为需要排序的数组，low是低位，high是高位
static void sort(int a[], int low, int high)
{
	// 如果低位比高位低的话，就是还可以别分割，直到 low==high
	// 例如：上图的 4 8，low=0，high=1
	// 继续分割则是 4:low=0，high=0， 8:low=1，high=1
    if (low < high) {
    	// low=0，high=1 ，mid = 0
        int mid = (low + high) / 2;
        // 从这里可以体现 4:low=0，high=0
        // 不能再分割后就返回了
        sort(a, low, mid);
        // 8:low=1，high=1
        sort(a, mid + 1, high);
        // 所以第一次meger是这里，low=0，mid=0，high=1
        merge(a, low, mid, high);
    }
}

int main()
{
	int a[13]={12,11,10,9,8,7,6,5,4,3,2,1,0};
	int b[6]={2,3,4,5,6,1};
	int c[4]={2,4,3,1};
	
	ans=0;
	sort(a,0,12);
	for(int i=0;i<13;i++)
		cout<<a[i]<<" ";
	cout<<endl<<ans<<endl;
	
	ans=0;
	sort(b,0,5);
	for(int i=0;i<6;i++)
		cout<<b[i]<<" ";
	cout<<endl<<ans<<endl;
	
	ans=0;
	sort(c,0,3);
	for(int i=0;i<4;i++)
		cout<<c[i]<<" ";
	cout<<endl<<ans<<endl;
	return 0;
}
