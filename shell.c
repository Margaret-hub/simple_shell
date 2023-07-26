#include <stdio.h>
#include <string.h>

/**
* main - includes all codes
* Return: always return 0
*/

int main(void)
{
	char ans[10];
	int i = 0;

	do {
		i++;

		printf("iteration #%d \n", i);
		printf("Do You Want To continue?[enter NO to quit]\n");
		scanf("%9s", ans);
	} while (strcmp(ans, "NO") != 0);
	return (0);
}
