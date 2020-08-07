#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 

void insert(TEL **p, int k)
{
	char tt[101];

	// 이중 포인터 안에 다시 할당
	p[k] = (TEL*)malloc(sizeof(TEL));

	if (p[k] == NULL)
	{
		printf("not Enough Memory");
		return -1;
	}

	// 자료길이에 따라 동적할당 받아 정보 입력 받기
	printf("Name:");
	gets(tt);
	p[k]->name = (char*)malloc(sizeof(char)*(strlen(tt) + 1));

	if (p[k]->name == NULL)
	{
		printf("not Enough Memory");
		return -1;
	}
	strcpy(p[k]->name, tt);

	printf("Phone_number:");
	gets(tt);
	p[k]->phone = (char*)malloc(sizeof(char)*(strlen(tt) + 1));

	if (p[k]->phone == NULL)
	{
		printf("not Enough Memory");
		return -1;
	}
	strcpy(p[k]->phone, tt);

	printf("Birth:");
	gets(tt);
	p[k]->birth = (char*)malloc(sizeof(char)*(strlen(tt) + 1));

	if (p[k]->birth == NULL)
	{
		printf("not Enough Memory");
		return -1;
	}
	strcpy(p[k]->birth, tt);

	k++;
	// 소팅함수 호출
	sort(p, k);

	// 몇 명 등록되었는지 출력
	printf("<<%d>>\n", k);
}