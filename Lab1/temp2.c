#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int i,k;
	time_t t = time(NULL)+2;
	i=0;
	while(1)
	{
		if(time(NULL)>=t)
			break;
		i++;
		printf("i==%d\n",i);
	}
	return 0;
}
