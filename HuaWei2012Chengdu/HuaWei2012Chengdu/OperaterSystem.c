#include<stdio.h>

void scheduler(int task[], int n, int system_task[], int user_task[])
{
	int i,j,k_sys=0,k_user=0;
	int index;
	for(i=0; i<n; i++)
	{
		if(0<=task[i] && task[i]<50)
		{
			system_task[k_sys++] = i;
			index = i;
			for(j=k_sys-2; j>=0&&task[i]<task[system_task[j]]; j--)
				system_task[j+1] = system_task[j];
			system_task[j+1] = index;
		}
		else if(50<=task[i] && task[i]<=255)
		{
			user_task[k_user++] = i;
			index = i;
			for(j=k_user-2; j>=0&&task[i]<task[user_task[j]]; j--)
				user_task[j+1] = user_task[j];
			user_task[j+1] = index;
		}
	}
	system_task[k_sys] = -1;
	user_task[k_user] = -1;
}

void scheduler_hash(int task[], int n, int system_task[], int user_task[])
{
	int hash[256];
	int i, k_sys=0, k_user=0;
	for(i=0; i<256; i++)
		hash[i] = -1;
	for(i=0; i<n; i++)
		hash[task[i]] = i;
	for(i=0; i<256; i++)
	{
		if(i<50 && hash[i]>=0)
			system_task[k_sys++] = hash[i];
		else if(i<256 && hash[i]>=0)
			user_task[k_user++] = hash[i];
	}
	system_task[k_sys] = -1;
	user_task[k_user] = -1;
}

void main()
{
	int task[]={0, 30, 155, 1, 80, 300, 170, 40, 99};
	int system_task[10];
	int user_task[10];
	int n=9;
	int i;
	scheduler_hash(task, n, system_task, user_task);
	for(i=0; i<n; i++)
	{
		printf("%d ", system_task[i]);
		if(system_task[i]==-1)
			break;
	}
	printf("\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", user_task[i]);
		if(user_task[i]==-1)
			break;
	}
	printf("\n");
}