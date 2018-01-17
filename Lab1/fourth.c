#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	float loop_time,n;
	float windowSize;
	int dataFrame[100][100],max,min;
	// time_t TIME = time(NULL)+2;
	//printf("%lf",loop_time);
	scanf("%f",&n);
	scanf("%f",&windowSize);
	loop_time=n/windowSize;
	for(int i=0;i<n;i++)
	{
		dataFrame[i][0]=i;
		dataFrame[i][1]=0;
	}
	min=0;
	max=windowSize-1;
	while(loop_time>0)
	{
		for(int i=min;i<=max;i++)
		{
			printf("dataFrame %d sent\n",dataFrame[i][0]);
			sleep(1);
		}
		int ack=0;
		time_t TIME = time(NULL)+3;
		while(1)
		{
			if(time(NULL)>=TIME)
				break;
			if(max==min)
			{
				ack=max;
				printf("ack %drecive\n",dataFrame[ack][0]);
				dataFrame[ack][1]=1;
				break;	
			}
			ack=min+rand()%(max-min)+1;
			// printf("ack %drecive\n",dataFrame[ack]);
			if(dataFrame[ack][1]==0)
			{
				printf("ack %drecive\n",dataFrame[ack][0]);
				dataFrame[ack][1]=1;
				sleep(2);
			}
			// sleep(0.25);
		}
		loop_time--;
		min=max+1;
		max=max+windowSize;
		if(max>=n)
			max=n-1;
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		if(dataFrame[i][1]==1)
			printf("ack recived dataFrame=%d\n",dataFrame[i][0]);
		else
			printf("\t\t\tack not recived dataFrame=%d\n",dataFrame[i][0]);
	}
	
}