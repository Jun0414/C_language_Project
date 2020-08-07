#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 



// 기말 프로젝트 실습 4

int main()
{
	TEL **tel_list = NULL;
	char tt[101], tt2[101], tt3[101];
	int n, Max_num, k = 0;
	FILE *fp1, *fp2;

	// 정보량 입력받고 구조체 동적할당
	printf("Max_num:");
	scanf("%d", &Max_num);
	tel_list = (TEL**)malloc(sizeof(TEL*)*Max_num);

	if (tel_list == NULL)
	{
		printf("Not Enough Memory");
		return -1;
	}

	while (1)
	{
		// 메뉴 출력
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &n);
		getchar();

		if (n == 1)
		{
			// 메모리 초과시 멘트 출력 후 메뉴로
			if (k >= Max_num)
			{
				printf("OVERFLOW\n");
				continue;
			}
			// 저장 함수 호출
			insert(tel_list, k);
			k++;
		}
		else if (n == 2)
		{
			// 전체보기 함수 호출
			print_all(tel_list, k);
		}
		else if (n == 3)
		{
			// 등록된 사람이 없는 경우 멘트 출력 후 메뉴로
			if (k == 0)
			{
				printf("NO MEMBER\n");
				continue;
			}

			// 찾을 사람 입력 후 삭제함수 호출
			printf("Name:");
			gets(tt);

			for (int i = 0; i < k; i++)
			{
				if (strcmp(tel_list[i]->name, tt) == 0)
				{
					delete_tel(tel_list, tt, k);
					k--;
				}
			}
		}
		else if (n == 4)
		{
			// 찾을 달을 입력 후 달 찾기 함수 호출
			printf("Birth:");
			gets(tt);

			find_by_birth(tel_list, tt, k);
		}
		else if (n == 5)
		{
			// 불러올 내용이 있으면 불러오고 없으면 메뉴로
			fp1 = fopen("PHONE_BOOK.txt", "r");
			if (fp1 == NULL) continue;

			while(!feof(fp1))
			{
				// 한줄씩 가져오기
				fscanf(fp1, "%s %s %s\n", tt, tt2, tt3);


				// 메모리 초과시 멘트 출력 후 메뉴로
				if (k >= Max_num)
				{
					printf("OVERFLOW\n");
					break;
				}
				
				// 동적할당 받아 내용 저장하기
				tel_list[k] = (TEL*)malloc(sizeof(TEL));
				if (tel_list[k] == NULL)
				{
					printf("not Enough Memory");
					return -1;
				}

				tel_list[k]->name = (char*)malloc(sizeof(char)*(strlen(tt) + 1));
				if (tel_list[k]->name == NULL)
				{
					printf("not Enough Memory");
					return -1;
				}
				strcpy(tel_list[k]->name, tt);

				tel_list[k]->phone = (char*)malloc(sizeof(char)*(strlen(tt2) + 1));
				if (tel_list[k]->phone == NULL)
				{
					printf("not Enough Memory");
					return -1;
				}
				strcpy(tel_list[k]->phone, tt2);

				tel_list[k]->birth = (char*)malloc(sizeof(char)*(strlen(tt3) + 1));
				if (tel_list[k]->birth == NULL)
				{
					printf("not Enough Memory");
					return -1;
				}
				strcpy(tel_list[k]->birth, tt3);

				k++;
				// 이름순으로 정렬
				sort(tel_list, k);
			}
			// 파일 해제
			fclose(fp1);
		}
		else
		{
			// 처리한 내용 메모장에 저장시키기
			fp2 = fopen("PHONE_BOOK.txt", "w");
			for (int i = 0; i < k; i++)
			{
				fprintf(fp2, "%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
			}
			// 파일 해제
			fclose(fp2);
			break;
		}
	}

	// 동적할당 해제
	for (int i = 0; i < k; i++)
	{
		free(tel_list[i]->name);
		free(tel_list[i]->phone);
		free(tel_list[i]->birth);
		free(tel_list[i]);
	}
	free(tel_list);

	return 0;
}