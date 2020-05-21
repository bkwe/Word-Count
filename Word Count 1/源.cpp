#include <stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i, j;
	gets_s(str);
	for (i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] == ',' || str[i] == ' ')
		{
			if (i == 0 || i == strlen(str) - 1)
				j = j;
			else
				j++;
		}

	}
	j = j + 1;
	printf("%d", j);
	return 0;

}
