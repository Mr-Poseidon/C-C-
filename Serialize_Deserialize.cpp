#include<iostream>
#include<fstream>
using namespace std;

class Point{
	private:
		
	public:
		int x,y;
		void show()
		{
			cout<<"data : "<<x<<" "<<y<<endl;
		}
}point;

int main()
{
	//һ��
	
	 
	//���л� 
	ofstream fout;
	fout.open("Serialize_and_Deserialize.txt",ios::binary);
	 
	Point p;
	p.x=10;
	p.y=35;
	fout.write((char*)&p.x,sizeof(p.x));
	fout.write((char*)&p.y,sizeof(p.y));
	fout.close();
	
	ifstream fin;
	fin.open("Serialize_and_Deserialize.txt",ios::binary);
	
//	char* temp=new char[sizeof(Point)];
//	
//	while(fin.read(temp,sizeof(Point)))
//	{
//		Point pp=*(Point*)(temp);
//		pp.show();
//	}
	
	//�����л� 
	//�˶δ���Ϊ�ϲ�ע�ʹ������д 
	Point pp;	
	while(fin.read((char*)&pp,sizeof(Point)))
		pp.show();
	fin.close();
	 
	
	return 0;
} 
