#include<stdio.h>
#include<stdlib.h>

int completedphilo=0, n, i;
struct fork
{
	int taken;
}*forkavail;

struct philo
{
	int left;
	int right;
}*philostatus;

void Dinner(int philoid/*, struct fork *forkavail, struct philo *philostatus*/)
{
	//if already completed dinner
	if(philostatus[philoid].left == 10 && philostatus[philoid].right == 10)
		printf("Philosopher %d completed his dinner\n",philoid+1);
	//if just taken both forks
	else if(philostatus[philoid].left == 1 && philostatus[philoid].right == 1)
	{
		printf("Philosopher %d completed his dinner\n",philoid+1);
		//remembering that he completed his dinner
		philostatus[philoid].left = philostatus[philoid].right = 10;
		int otherfork=philoid-1;
		if(otherfork==-1)
			otherfork= (n-1);
		//releasing forks
		forkavail[philoid].taken = forkavail[otherfork].taken =0;
		printf("Philosopher %d released fork %d and fork %d\n",philoid+1,philoid+1,otherfork+1);
		completedphilo++;
	}
	//if left already taken and waiting for right
	else if(philostatus[philoid].left == 1 && philostatus[philoid].right == 0)
	{
		//for last philosopher
		if(philoid == (n-1))
		{
			if(forkavail[philoid].taken == 0)
			{
				forkavail[philoid].taken = philostatus[philoid].right = 1;
				printf("Fork %d taken by Philosopher %d\n",philoid+1, philoid+1);
			}
			else
				printf("Philosopher %d waiting for fork %d\n",philoid+1, philoid+1);
		}
		//except last philosopher case
		else
		{
			int dupphiloid = philoid;
			philoid -=1;
			if(philoid == -1)
				philoid = (n-1);
			if(forkavail[philoid].taken == 0)
			{
				forkavail[philoid].taken = philostatus[dupphiloid].right = 1;
				printf("Fork %d taken by philosopher %d\n",philoid+1, dupphiloid+1);
			}
			else
				printf("Philosopher %d waiting for fork %d\n", dupphiloid+1, philoid+1);
		}
	}
	// if nothing taken yet
	else if(philostatus[philoid].left == 0)
	{
		//for last philosopher
		if(philoid == (n-1))
		{
			if(forkavail[philoid-1].taken == 0)
			{
				forkavail[philoid-1].taken = philostatus[philoid].left = 1;
				printf("Fork %d taken by philosopher %d\n",philoid,philoid+1);
			}
			else
				printf("Philosopher %d waiting for fork %d\n",philoid+1, philoid);
		}
		//except last philosopher case
		else
		{
			if(forkavail[philoid].taken == 0)
			{
				forkavail[philoid].taken = philostatus[philoid].left = 1;
				printf("Fork %d taken by philosopher %d\n",philoid+1,philoid+1);
			}
			else
				printf("Philosopher %d waiting for fork %d\n",philoid+1, philoid+1);
		}
	}
	else{}
}
int main()
{
	printf("Enter the number of philosophers: ");
	scanf("%d",&n);
	forkavail = (struct fork *)calloc(n, sizeof(struct fork));
	philostatus = (struct philo *)calloc(n, sizeof(struct philo));
	for(i=0;i<n;i++)
		forkavail[i].taken = philostatus[i].left = philostatus[i].right = 0;
	while(completedphilo < n)
	{
		for(i=0;i<n;i++)
			Dinner(i/*, forkavail, philostatus*/);
		printf("Number of philosophers completed dining: %d\n", completedphilo);
	}
	return 0;
}
