#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 

void delete_tel(TEL **p, char tt[], int k)
{
	int cnt = 0;
	int i;

	// 동일한 이름이 있으면 동적할당 해제 후 뒤에서 부터 덮어씌우기
	for (i = 0; i < k - 1; i++)
	{
		if (strcmp(p[i]->name, tt) == 0) cnt = 1;
		if (cnt == 1)
		{
			free(p[i]->name);
			free(p[i]->phone);
			free(p[i]->birth);
			free(p[i]);
			p[i] = (TEL*)malloc(sizeof(TEL));
			p[i]->name = (char*)malloc(sizeof(char)*(strlen(p[i + 1]->name) + 1));
			strcpy(p[i]->name, p[i + 1]->name);
			p[i]->phone = (char*)malloc(sizeof(char)*(strlen(p[i + 1]->phone) + 1));
			strcpy(p[i]->phone, p[i + 1]->phone);
			p[i]->birth = (char*)malloc(sizeof(char)*(strlen(p[i + 1]->birth) + 1));
			strcpy(p[i]->birth, p[i + 1]->birth);
		}
	}
}