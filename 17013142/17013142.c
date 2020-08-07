#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "my_struct.h"
#include "my_define.h"
#include "my_func.h" 



// �⸻ ������Ʈ �ǽ� 4

int main()
{
	TEL **tel_list = NULL;
	char tt[101], tt2[101], tt3[101];
	int n, Max_num, k = 0;
	FILE *fp1, *fp2;

	// ������ �Է¹ް� ����ü �����Ҵ�
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
		// �޴� ���
		printf("*****Menu*****\n");
		printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.RegFromFile><6.Exit>\n");
		printf("Enter_the_menu_number:");
		scanf("%d", &n);
		getchar();

		if (n == 1)
		{
			// �޸� �ʰ��� ��Ʈ ��� �� �޴���
			if (k >= Max_num)
			{
				printf("OVERFLOW\n");
				continue;
			}
			// ���� �Լ� ȣ��
			insert(tel_list, k);
			k++;
		}
		else if (n == 2)
		{
			// ��ü���� �Լ� ȣ��
			print_all(tel_list, k);
		}
		else if (n == 3)
		{
			// ��ϵ� ����� ���� ��� ��Ʈ ��� �� �޴���
			if (k == 0)
			{
				printf("NO MEMBER\n");
				continue;
			}

			// ã�� ��� �Է� �� �����Լ� ȣ��
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
			// ã�� ���� �Է� �� �� ã�� �Լ� ȣ��
			printf("Birth:");
			gets(tt);

			find_by_birth(tel_list, tt, k);
		}
		else if (n == 5)
		{
			// �ҷ��� ������ ������ �ҷ����� ������ �޴���
			fp1 = fopen("PHONE_BOOK.txt", "r");
			if (fp1 == NULL) continue;

			while(!feof(fp1))
			{
				// ���پ� ��������
				fscanf(fp1, "%s %s %s\n", tt, tt2, tt3);


				// �޸� �ʰ��� ��Ʈ ��� �� �޴���
				if (k >= Max_num)
				{
					printf("OVERFLOW\n");
					break;
				}
				
				// �����Ҵ� �޾� ���� �����ϱ�
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
				// �̸������� ����
				sort(tel_list, k);
			}
			// ���� ����
			fclose(fp1);
		}
		else
		{
			// ó���� ���� �޸��忡 �����Ű��
			fp2 = fopen("PHONE_BOOK.txt", "w");
			for (int i = 0; i < k; i++)
			{
				fprintf(fp2, "%s %s %s\n", tel_list[i]->name, tel_list[i]->phone, tel_list[i]->birth);
			}
			// ���� ����
			fclose(fp2);
			break;
		}
	}

	// �����Ҵ� ����
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