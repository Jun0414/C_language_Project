#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 

void find_by_birth(TEL **p, char tt[], int k)
{
	int j;

	// �޿� �ش��ϴ� �ε��� 2���� ��ġ�ϴ� ���� �ִ��� Ȯ�� �� ���
	for (int i = 0; i < k; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (strlen(tt) == 1 && tt[j] == p[i]->birth[j + 5])
			{
				printf("%s %s %s\n", p[i]->name, p[i]->phone, p[i]->birth);
				break;
			}
			if (p[i]->birth[j + 4] != tt[j]) break;
		}
		if (j == 2) printf("%s %s %s\n", p[i]->name, p[i]->phone, p[i]->birth);
	}
}