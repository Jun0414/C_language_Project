#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 

void print_all(TEL **p, int k)
{
	// 등록된 모든 정보 출력
	for (int i = 0; i < k; i++) printf("%s %s %s\n", p[i]->name, p[i]->phone, p[i]->birth);
}