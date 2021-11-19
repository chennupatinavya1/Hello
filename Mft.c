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


output1:
Enter memory size: 1000
Enter number of blocks: 10
Enter the no. of processes: 3
Enter the size of p[1]: 250
Enter the size of p[2]: 150
Enter the size of p[3]: 350
process  size    nba     ifm
1        250     3       50
2        150     2       50
3        350     4       50

--------------------------------
Process exited after 21.68 seconds with return value 0
Press any key to continue . . .

	
output2:
Enter memory size: 150
Enter number of blocks: 10
Enter the no. of processes: 5
Enter the size of p[1]: 10
Enter the size of p[2]: 15
Enter the size of p[3]: 5
Enter the size of p[4]: 20
Enter the size of p[5]: 30
process  size    nba     ifm
1        10      1       5
2        15      1       0
3        5       1       10
4        20      2       10
5        30      2       0

--------------------------------
Process exited after 48.19 seconds with return value 0
Press any key to continue . . .
