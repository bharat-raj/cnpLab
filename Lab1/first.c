#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	double loop_time;
	int windowSize=3,min,max,i;
	int dataFrame[]={0,1,2,3,4,5,6,7,8,9,10};
	loop_time=10/3.0;
	//printf("%lf",loop_time);
	min=0;
	max=2;
	while(loop_time>0)
	{
		for(i=min;i<=max;i++)
		{
			printf("dataFrame %d sent\n",dataFrame[i] );
			sleep(0.25);
		}
		int ack=0;
		while(ack!=max)
		{
			if(max==min)
			{
				ack=max;
				printf("ack %drecive\n",dataFrame[ack] );
				break;	
			}
			ack=min+rand()%(max-min)+1;
			printf("ack %drecive\n",dataFrame[ack] );
			sleep(0.25);
		}
		loop_time--;
		min=max+1;
		max=max+3;
		if(max>=10)
			max=10;
	}
	
}