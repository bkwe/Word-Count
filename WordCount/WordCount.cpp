#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int CharCount(char file[])
{
	FILE* pf = NULL;
	int charcount = 0;
	pf = fopen("D:\\file.txt", "r");
	if (pf == NULL)
	{
		printf("寻找文件失败\n");
		exit(1);
	}
	char mychar;
	mychar = fgetc(pf);
	while (mychar != EOF)
	{
		mychar = fgetc(pf);
		charcount++;
	}
	fclose(pf);
	return charcount;
}
int WordCount(char file[])
{
	FILE* pf = NULL;
	int wordcount = 0;
	pf = fopen("D:\\file.txt", "r");
	if (pf == NULL)
	{
		printf("寻找文件失败\n");
		exit(1);
	}
	char mychar, mchar[100];
	int i = 0;
	mychar = fgetc(pf);
	while (mychar != EOF)
	{
		mychar = fgetc(pf);
		mchar[i] = mychar;
		i++;
	}
	fclose(pf);
	for (i = 0, wordcount = 0; i < strlen(mchar); i++)
	{
		if (mchar[i] == ',' || mchar[i] == ' ')
		{
			if (i == 0 || i == strlen(mchar) - 1)
				wordcount = wordcount;
			else
				wordcount++;
		}
	}
	wordcount = wordcount + 1;
	return wordcount;
}
int main()
{
	char input[50], file[100], com1[50] = "-c", com2[50] = "-w";
	gets_s(input);
	while (1)
	{
		if (strcmp(input, com1) == 0)
		{
			gets_s(file);
			int charcount = 0;
			charcount = CharCount(file);
			printf("代码的字符数为：%d", charcount);
		}
		if (strcmp(input, com2) == 0)
		{
			gets_s(file);
			int wordcount = 0;
			wordcount = WordCount(file);
			printf("代码的单词数为：%d", wordcount);
		}
	}
	system("pause");
	return 0;

}
