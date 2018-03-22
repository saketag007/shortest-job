#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int find_min_priority(int A[],double P[],int k)
{
	double max=0;int max2=0,pos,flag=0;
	for(int i=1;i<k;i++)
	{
		if((max<P[i])&&(P[i]!=-1))
		{
			max=P[i];
			pos=i;
			max2=A[i];
			flag=1;
		}
		else if(max==P[i])
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
		return pos;
	}
	else
	{
		return -1;
	}
}
void update_data(int k,int A[],double P[],int p)
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
	printf("Enter the burst time or running time of each process \n");
	for(int i=1;i<n;i++)
	{
		scanf("%d",&A[i]);
		P[i]=1;
	}
	printf("Your initial table looks something like this\n");
	printf("Process      Burst Time      Priority \n");
	for(int i=1;i<n;i++)
	{
		printf("%d               %d             %lf \n",i,A[i],P[i]);
	}
	printf("\n\n\n");
	Sleep(2000);
	printf("The priority of each process will be 1 at the begining \n\n\n\n");
	Sleep(3000);
	while(1)
	{
		int k;
		k=find_min_priority(A,P,n);
		if(k!=-1)
		{
			update_data(k,A,P,n);
		}
		else
		{
			printf("\n\n");
			printf("      All the processes are over. Have a nice day \n");
			break;
		}
	}
}
