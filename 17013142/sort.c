#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 

void sort(TEL **p, int k)
{
	TEL *tmp;

	// 버블정렬을 이용해 정렬하기
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - 1 - i; j++)
		{
			if (strcmp(p[j]->name, p[j + 1]->name) > 0)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
	}
}