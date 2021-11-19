/* To implement Multi programming with variable number of tasks*/
#include<stdio.h>
int main(void) {
	int mm, np, ps[100], rm[100], am = 0, flag = 0, i ,j;
	printf("Enter memory size: ");
	scanf("%d", &mm);
	printf("Enter number of processes: ");
	scanf("%d", &np);
	for(i = 0; (i < np) && (am<mm); i++) {
		printf("Enter size of p[%d]: ", i + 1);
		scanf("%d", &ps[i]);
		am = am + ps[i];
		if(am >= mm) {
			flag = 1;
			break;
		}
		rm[i] = mm - am;
	}
	j = i;
	printf("Process\tSize\tRM\n");
	for(i = 0; i < j; i++)
	printf("%d\t%d\t%d\n", i + 1, ps[i], rm[i]);
	if(flag == 1)
	printf("Memory is unavailable\n");
}

Output1:
Enter memory size: 100
Enter number of processes: 5
Enter size of p[1]: 10
Enter size of p[2]: 20
Enter size of p[3]: 15
Enter size of p[4]: 5
Enter size of p[5]: 25
Process Size    RM
1       10      90
2       20      70
3       15      55
4       5       50
5       25      25

--------------------------------
Process exited after 23.7 seconds with return value 5
Press any key to continue . . .

Output2:
Enter memory size: 150
Enter number of processes: 3
Enter size of p[1]: 60
Enter size of p[2]: 25
Enter size of p[3]: 54
Process Size    RM
1       60      90
2       25      65
3       54      11

--------------------------------
Process exited after 34.22 seconds with return value 3
Press any key to continue . . .
