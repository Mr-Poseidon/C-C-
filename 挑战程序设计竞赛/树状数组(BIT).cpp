//��״�����ģ��

 
#include<vector>
using namespace std;

vector<int> bit;
vector<int> ori;// ��¼ԭʼ���飬�Ӷ��ܹ���update��ʱ������λ��i����ֵ�ı仯��
                // bit�Ǹ�����ķ�Ӧ

int low_bit(int x){
    return x & (-x);
}

// ����ԭ�����б߽��±�ֵ������ǰ׺�� 
int prefixSum(int i)
{
	//ע����״�����±��� 1 ��ʼ,0���� 
    i+=1;
    int sum=0;
    while(i>0){
        sum+= bit[i];
        i-=low_bit(i);
    }
    return sum;
}
    
void init(vector<int>& nums)//��ʼ�� 
{
    ori.push_back(0);
    ori.insert(ori.end(), nums.begin(), nums.end());

    bit.push_back(0);
    bit.insert(bit.end(), nums.begin(), nums.end());

    // ��ʼ��bit,���Ӷ�O(n),���ε�����¸��Ӷ�O(nlogn),�Ż���logn 
    // �����ݸ���i�����������ܰ�����i���ұ߽�
    for (int i = 1; i < bit.size(); i++)
	{
        int j = i + low_bit(i);
        if (j < bit.size())
			bit[j] += bit[i];
    }
}

// ע��˴��ǽ�i�±��ֵ����Ϊval����������ԭ����������val
// ����ԭ����һ���ģ��������仯ֵ
void update(int i, int val) {
    i += 1;
    int dec = val - ori[i];  // ע��bit�м�¼��������ͣ�ori��¼�Ĳ���bit��Ӧ��ԭʼ����
    ori[i] = val;

    while(i < bit.size()){
        bit[i] += dec;
        i += low_bit(i);
    }
}

// ��ԭ���������[i,j]�ĺ�
int sumRange(int i, int j){
    return prefixSum(j) - prefixSum(i-1);
}

int main()
{
	return 0;
}
