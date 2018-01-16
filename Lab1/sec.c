#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	float loop_time,n;
	float windowSize;
	int dataFrame[100],max,min;
	//printf("%lf",loop_time);
	scanf("%f",&n);
	scanf("%f",&windowSize);
	loop_time=n/windowSize;
	for(int i=0;i<n;i++)
		dataFrame[i]=i;
	min=0;
	max=windowSize-1;
	while(loop_time>0)
	{
		for(int i=min;i<=max;i++)
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
		max=max+windowSize;
		if(max>=n)
			max=n-1;
	}
	
}