#include<stdio.h>
#include<math.h>
int main(void)
{
	int np, nb, mm, bs, i, j, ps[100], nba[100], ifm[100], sb=0, flag=0;
	float x;
	printf("Enter memory size: ");
	scanf("%d", &mm);
	printf("Enter number of blocks: ");
	scanf("%d", &nb);
	printf("Enter the no. of processes: ");
	scanf("%d", &np);
	bs = mm / nb;
	for(i = 1; i <= np && (sb < nb); i++)
	{
		printf("Enter the size of p[%d]: ", i);
		scanf("%d", &ps[i]);
		if(ps[i] <= bs)
		nba[i] = 1;
		else
		{
			x = ps[i] / (float)bs;
			nba[i] = (ceil)(x);
		}
		ifm[i] = nba[i] * bs - ps[i];
		sb = sb + nba[i];
		if(sb > nb)
		{
			i = i - 1;
			flag = 1;
		}
	}
	j = i;
	printf("process\t size\t nba\t ifm\n");
	for(i = 1; i < j; i++)
	printf("%d\t %d\t %d\t %d\n", i, ps[i], nba[i], ifm[i]);
	if(flag == 1)
	printf("memory space is unavailable");
		
}
