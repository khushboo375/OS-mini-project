#include<stdio.h>
//accept no of process and its size
typedef struct
{
	int id;
	int size;
	int cmplt;
}Process;


typedef struct
{
	int id;
	int size;
	int cmplt;
	int P_id;
	int rem_size;
}Memory;

void acceptP(Process arr[],int n)
{
	int i=0;
	while(i<n)
	{
		printf("Enter id and size:");
		scanf("%d %d",&arr[i].id, &arr[i].size);
		arr[i].cmplt=0;
		i++;
	}
}

void acceptM(Memory arr[],int n)
{
	int i=0;
	while(i<n)
	{
		printf("Enter id and size:");
		scanf("%d %d",&arr[i].id, &arr[i].size);
		arr[i].cmplt=0;
		i++;
	}
}
void firstfit(Process p[],Memory m[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i].size<=m[j].size && p[i].cmplt==0 && m[j].cmplt==0)
			{
				p[i].cmplt=1;
				m[j].cmplt=1;
				m[j].P_id=p[i].id;
				m[j].rem_size=m[j].size-p[i].size;	
			}	
		}
	}
	printf("Firstfit\n");
	i=0;
	while(i<n)
	{
		if(m[i].cmplt==1)
		{
			printf("P%d block is allocated in M%d block with remaining %d size\n",m[i].P_id,m[i].id,m[i].rem_size);
		}
		i++;
	}	
	i=0;
	while(i<n)
	{
		if(p[i].cmplt==0)
		{
			printf("\nP%d block is not allocated",p[i].id);
		}
		i++;
	}	
}

void bestfit(Process p[],Memory m[],int n)
{
	int i,j;
	int l_size;
	int pos;
	for(i=0;i<n;i++)
	{
		l_size=1e9;
		pos=-1;
		for(j=0;j<n;j++)
		{
			if(p[i].size<=m[j].size && p[i].cmplt==0 && m[j].cmplt==0)
			{
				if((m[j].size-p[i].size)<l_size)
				{
					l_size=m[j].size-p[i].size;
					pos=j;
				}
			}
					
		}
		if(pos!=-1)
			{
				p[i].cmplt=1;
				m[pos].cmplt=1;
				m[pos].P_id=p[i].id;
				m[pos].rem_size=m[pos].size-p[i].size;
			}
			
	}
	printf("Bestfit\n");
	i=0;
	while(i<n)
	{
		if(m[i].cmplt==1)
		{
			printf("P%d block is allocated in M%d block with remaining %d size\n",m[i].P_id,m[i].id,m[i].rem_size);
		}
		i++;
	}	
	i=0;
	while(i<n)
	{
		if(p[i].cmplt==0)
		{
			printf("\nP%d block is not allocated",p[i].id);
		}
		i++;
	}	
}


void worstfit(Process p[],Memory m[],int n)
{
	int i,j;
	int l_size;
	int pos;
	for(i=0;i<n;i++)
	{
		l_size=0;
		pos=-1;
		for(j=0;j<n;j++)
		{
			if(p[i].size<=m[j].size && p[i].cmplt==0 && m[j].cmplt==0)
			{
				if((m[j].size-p[i].size)>l_size)
				{
					l_size=m[j].size-p[i].size;
					pos=j;
				}
			}
					
		}
		if(pos!=-1)
			{
				p[i].cmplt=1;
				m[pos].cmplt=1;
				m[pos].P_id=p[i].id;
				m[pos].rem_size=m[pos].size-p[i].size;
			}
			
	}
	printf("Worstfit\n");
	i=0;
	while(i<n)
	{
		if(m[i].cmplt==1)
		{
			printf("P%d block is allocated in M%d block with remaining %d size\n",m[i].P_id,m[i].id,m[i].rem_size);
		}
		i++;
	}	
	i=0;
	while(i<n)
	{
		if(p[i].cmplt==0)
		{
			printf("\nP%d block is not allocated",p[i].id);
		}
		i++;
	}	
}

int main()
{
	int n,ch;
	Process pro[10];
	Memory mem[10];
	printf("\nEnter no. of processes: ");
	scanf("%d",&n);
	acceptP(pro,n);
	printf("\nNo. of memory block: %d\n",n);
	acceptM(mem,n);
	printf("\nEnter choice:\n1.First Fit\n2.Best Fit\n3.Worst Fit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:firstfit(pro ,mem,n);
				break;
		case 2:bestfit(pro ,mem,n);
				break;
		case 3:worstfit(pro ,mem,n);
				break;
	}
	return 0;
}
