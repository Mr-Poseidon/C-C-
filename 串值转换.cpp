#include<stdio.h>

//�ַ���aת������ֵ��m 
/* 
int main()
{
	char a[100]="00012345678910111213ABC";//1-13��17λ 
	long long int m;
	sscanf(a,"%lld",&m);
	printf("%lld\n\n",m);
	return 0;
}
*/ 

/* 
//��ֵ��mת�����ַ���a 
int main()
{
	char a[100];//1-13��17λ 
	long long int m=12345678910111213;
	sprintf(a,"%lld",m);
	printf("%s\n\n",a);
	return 0;
}
*/ 

/* 
int main()//�ֶδ��� 1 
{
	char a[100] = "123kkkABC";
	int buf1;
	char buf2[100],buf3[100];
    sscanf(a, "%d%[a-z]%[A-Z]", &buf1, buf2, buf3);
    printf("5.string=%s\n", a);
    printf("5.buf1=%d, buf2=%s, buf3=%s\n\n", buf1, buf2, buf3);
    return 0;
}
*/

/* 
int main()//�ֶδ��� 2 
{
	char a[100] = "123456789101112131415";
	int buf1,buf2,buf3;
    sscanf(a, "%9d%6d%6d", &buf1, &buf2, &buf3);
    printf("5.string=%s\n", a);
    printf("5.buf1=%d, buf2=%d, buf3=%d\n\n", buf1, buf2, buf3);
    return 0;
}
*/ 

int main()//�ֶδ��� 3 
{
	char a[100] = "123456789123456789123456789123456789123456789";
	char* b=a;
	int buf[100];
	int i=0;
	while(~sscanf(&a[4*i], "%4d", &buf[i]) )i++;//�ֶ����� 
	
	printf("i=%d\n\n",i);
	int j=i;
	i=0;
    while(printf("%d.string=%d\n", i+1, buf[i]))//��֤ 
    {
    	i++;j--;if(j==0)break;
    }
    return 0;
}


 
