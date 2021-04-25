#include<iostream>
using namespace std;
int ans=0;

static void merge(int a[], int low, int mid, int high)
{
	// �����������飬low �� high��Ҫ�Ŀռ��С
    int *temp = new int[high - low + 1];
    // ��ߴ�low��ʼָ��ָ�룬��һֱ��mid
    int i = low;
    // �ұߴ�mid+1��ʼ��һֱ��high����Ϊ������Ҫ������������бȽϣ�����
    int j = mid + 1;
    // ��������ָ��
    int k = 0;
    // 2�����鶼û��ͷ��˵�����ǿ��Լ����Ƚ�
    while (i <= mid && j <= high) {
    	// �Ƚϣ�С����temp��ǰ��
    	// =���Խ��������ͬ������ 
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else { 
        	ans+=mid-i+1;/*�˴����Լ�����������*/
            temp[k++] = a[j++];
        }
    }
    // �����߻�û�н�������������з���
    while (i <= mid) {    
        temp[k++] = a[i++];
    }
    // �ұ�Ҳ������
    while (j <= high) {
        temp[k++] = a[j++];
    }
    // ����������õ�temp ���ǵ�a��������ȥ
    for (int x = 0; x < high - low + 1/*temp.length()*/; x++) {
        a[low + x] = temp[x];
    }
}

// aΪ��Ҫ��������飬low�ǵ�λ��high�Ǹ�λ
static void sort(int a[], int low, int high)
{
	// �����λ�ȸ�λ�͵Ļ������ǻ����Ա�ָֱ�� low==high
	// ���磺��ͼ�� 4 8��low=0��high=1
	// �����ָ����� 4:low=0��high=0�� 8:low=1��high=1
    if (low < high) {
    	// low=0��high=1 ��mid = 0
        int mid = (low + high) / 2;
        // ������������� 4:low=0��high=0
        // �����ٷָ��ͷ�����
        sort(a, low, mid);
        // 8:low=1��high=1
        sort(a, mid + 1, high);
        // ���Ե�һ��meger�����low=0��mid=0��high=1
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
