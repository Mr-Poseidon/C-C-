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
		 
		time_t t;//声明一个 time_t 变量 
		time(&t);//获得当前时间 
		printf("%s\n",ctime(&t));
		
		
		struct tm *p;//tm结构体指针 
		
		p=gmtime(&t);//返回世界统一时间(格林尼治时间)的 tm结构体 形式 
		printf("格林尼治时间:\n"); 
		printf("%4d-%02d-%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday);//年份+1900，月份+1 
		printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);//时分秒
		
		printf("\n\n"); 
		
		p=localtime(&t);//返回本地时间的 tm结构体 形式 
		printf("北京时间:\n");
		printf("%4d-%02d-%02d\n",p->tm_year+1900,p->tm_mon+1,p->tm_mday);//年份+1900，月份+1 
		printf("%02d:%02d:%02d\n",p->tm_hour,p->tm_min,p->tm_sec);//时分秒 
		
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
	
	printf("%lf\n",difftime(t2,t1));//diff(t2,t1) 返回t2比t1多的秒数,精确到 1s 
	
	return 0;
}









