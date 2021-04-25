//		struct tm
//		{
//		  int tm_sec;                   /* Seconds.     [0-60] (1 leap second) */
//		  int tm_min;                   /* Minutes.     [0-59] */
//		  int tm_hour;                  /* Hours.       [0-23] */
//		  int tm_mday;                  /* Day.         [1-31] */
//		  int tm_mon;                   /* Month.       [0-11] */
//		  int tm_year;                  /* Year - 1900.  */
//		  int tm_wday;                  /* Day of week. [0-6] */
//		  int tm_yday;                  /* Days in year.[0-365] */
//		  int tm_isdst;                 /* DST.         [-1/0/1]*/		
//		};

#include<stdio.h>
#include<time.h>
#include<windows.h>

void show_clock()
{
//	Sleep(5000);
	while(1)
	{
		 
		time_t t;//����һ�� time_t ���� 
		time(&t);//��õ�ǰʱ�� 
		printf("%s\n",ctime(&t));
		
		
		struct tm *p;//tm�ṹ��ָ�� 
		
		p=gmtime(&t);//��������ͳһʱ��(��������ʱ��)�� tm�ṹ�� ��ʽ 
		printf("��������ʱ��:\n"); 
		printf("%4d-%02d-%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday);//���+1900���·�+1 
		printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);//ʱ����
		
		printf("\n\n"); 
		
		p=localtime(&t);//���ر���ʱ��� tm�ṹ�� ��ʽ 
		printf("����ʱ��:\n");
		printf("%4d-%02d-%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday);//���+1900���·�+1 
		printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);//ʱ���� 
		
		printf("\n\n"); 
		
		printf("weekday:%d\n",p->tm_wday);
		printf("yearday:%d\n",p->tm_yday);
		 	
				
//		system("pause");
		system("cls");
				
	}
} 

int main()
{
	time_t t1,t2;
	time(&t1);
	Sleep(12345.6789);
	time(&t2);
	
	printf("%s\n",ctime(&t1));
	printf("%s\n",ctime(&t2));
	
	printf("%lf\n",difftime(t2,t1));//diff(t2,t1) ����t2��t1�������,��ȷ�� 1s 
	
	return 0;
}









