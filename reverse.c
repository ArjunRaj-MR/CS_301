#include <stdio.h>
int main()
{
	char a[50],b[50];
	int s,e,count=0;
	printf("Enter the string\n");
	gets(a);
	while(a[count]!='\0')
	count++;
	e=count-1;
	for(s=0;s<count;s++)
	{
		b[s]=a[e];
		e--;
	}
	b[s]='\0';
	printf("The reverse of the string is : %s\n",b);
	return 0;
}
