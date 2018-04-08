#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void task1(int *arr, int *row, int *col, int *vecColMax, int *vecRowMax)
{
	/* ��������� ������ �� ��������� �������� */
	int *vectCol = GetMemoryVect(col);

	/* ��������� ������ �� ��������� ����� */
	int *vectRow = GetMemoryVect(row);

	int stub = 1; // stub - ��������

				  /* ���� ������������ ������� � ������� */
	for (int j = 0; j < *col; j++)
	{
		int k = 0;
		for (int i = 0; i < *row; i++)
		{
			*(vectCol + k) = *(arr + j + i * *row);
			k++;
		}

		*(vecColMax + j) = maxArray(vectCol, col); // ���������� ���������� �������
	}
	printf("������ ���������� ��������� � �������:\n");
	printArray(vecColMax, &stub, col);

	/* ���� ������������ ������� � ������ */
	for (int i = 0; i < *row; i++)
	{
		//int l = 0;
		for (int j = 0; j < *col; j++)
		{
			*(vectRow + j) = *(arr + i * *row + j);
			//l++;
		}
		//printArray(vectRow, &stub, col);

		*(vecRowMax + i) = maxArray(vectRow, col); // ���������� ���������� �������
	}
	printf("������ ���������� ��������� � ������:\n");
	printArray(vecRowMax, &stub, row);

}

void task2(int *arr, int *row, int *col, int *vecColFirstEven, int *vecRowLastEven)
{
	/* ��������� ������ �� ��������� �������� */
	int *vectCol = GetMemoryVect(col);

	/* ��������� ������ �� ��������� ����� */
	int *vectRow = GetMemoryVect(row);

	int stub = 1; // stub - ��������

				  /* ���� ������ ������� � ������� */
	for (int j = 0; j < *col; j++)
	{
		int k = 0;
		for (int i = 0; i < *row; i++)
		{
			*(vectCol + k) = *(arr + j + i * *row);
			k++;
		}

		int flag = 0;
		for (int i = 0; i < *col; i++)
		{
			if (*(vectCol + i) % 2 == 0)
			{
				*(vecColFirstEven + j) = *(vectCol + i); // ���������� ������ ������ �������
				flag = 1;
				break;
			}

		}
		if (!flag)
			*(vecColFirstEven + j) = 0;
	}
	printf("������ ������ ������ ��������� �������:\n");
	printArray(vecColFirstEven, &stub, col);

	for (int j = 0; j < *row; j++)
	{
		int k = 0;
		for (int i = 0; i < *col; i++)
		{
			*(vectRow + k) = *(arr + j * *row + i);
			k++;
		}

		int flag = 0;
		for (int i = *col - 1; i >= 0; i--)
		{
			if (*(vectRow + i) % 2 == 0)
			{
				*(vecRowLastEven + j) = *(vectRow + i); // ���������� ��������� ������ �������
				flag = 1;
				break;
			}

		}
		if (!flag)
			*(vecRowLastEven + j) = 0;
	}
	printf("������ ��������� ������ ��������� ������:\n");
	printArray(vecRowLastEven, &stub, row);
}