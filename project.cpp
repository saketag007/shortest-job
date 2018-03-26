#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int clock=0,max_clock=0;
int find_min_priority(int A[],double P[],int k,char status[])
{
	double max=0;int max2=0,pos,flag=0;
	for(int i=1;i<k;i++)
	{
		if((max<P[i])&&(P[i]!=-1)&&(status[i]=='A'))
		{
			max=P[i];
			pos=i;
			max2=A[i];
			flag=1;
		}
		else if((max==P[i])&&(status[i]=='A'))
		{
			if(max2>A[i])
			{
				max2=A[i];
				max=P[i];
				pos=i;
			}
		}
	}
	if(flag==1)
	{
		clock+=A[pos];
		return pos;
	}
	else
	{
		return -1;
	}
}
void update_data(int k,int A[],double P[],int p,char status[])
{
	double b;
	b=A[k];
	A[k]=0;P[k]=-1;
	printf("Process %d is running for %lf seconds...... \n\n\n",k,b);
	Sleep(b*1000);
	printf("Please wait while we update your table....\n\n\n");
	Sleep(5000);
	for(int i=1;i<p;i++)
	{
		if((i!=k)&&(P[i]!=-1))
		{
		P[i]=1+(b/A[i]);
		}
	}
	printf("Your updated table looks something like this \n\n");
	printf("Process      Burst Time      Priority \n");
	for(int i=1;i<p;i++)
		{
			printf("%d               %d             %lf \n",i,A[i],P[i]);
		}
}
void arrival(char status[],int Arr[],int n)
{
	int flag=0;
	while(1)
	{
		flag=0;
		for(int i=0;i<n;i++)
		{
			if((Arr[i]<=clock)&&(status[i]=='P'))
			{
				status[i]='A';
				flag=1;
			}
		}
		if((flag==0)&&(clock<max_clock))
		{
			printf("Waiting for process \n");
			clock++;
			Sleep(1000);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	printf("                       Welcome to the scheduling algorithm calculator\n\n\n");
	Sleep(3000);
	printf("Enter the number of processes you want to load into the memory \n");
	int n;
	scanf("%d",&n);
	n+=1;
	int A[n];
	double  P[n];
	int Arr[n];
	char status[n];
	printf("Enter the burst time or running time and the arrival time of each process \n");
	for(int i=1;i<n;i++)
	{
		printf("Enter details of P%d process\n",i);
		printf("Burst Time - ");
		scanf("%d",&A[i]);
		P[i]=1;
		printf("Arrival Time - ");
		scanf("%d",&Arr[i]);
		status[i]='P';
		max_clock+=A[i];
	}
	printf("Your initial table looks something like this\n");
	printf("Process      Burst Time     Arrival Time  Priority \n");
	for(int i=1;i<n;i++)
	{
		printf("%d               %d             %d           %lf \n",i,A[i],Arr[i],P[i]);
	}
	printf("\n\n\n");
	Sleep(2000);
	printf("The priority of each process will be 1 at the begining \n\n\n\n");
	Sleep(3000);
	while(1)
	{
		int k,flag=0;
		arrival(status,Arr,n);
		k=find_min_priority(A,P,n,status);
		if(k!=-1)
		{
			update_data(k,A,P,n,status);
		}
		else
		{
			for(int i=1;i<n;i++)
			{
				if(P[i]!=-1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("\n\n");
				printf("      All the processes are over. Have a nice day \n");
				break;
			}
			else
			continue;
		}
	}
}
