﻿#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void task1(int *arr, int *row, int *col, int *vecColMax, int *vecRowMax)
{
	/* Формируем массив из элементов столбцов */
	int *vectCol = GetMemoryVect(col);

	/* Формируем массив из элементов строк */
	int *vectRow = GetMemoryVect(row);

	int stub = 1; // stub - заглушка

				  /* ищем максимальный элемент в столбце */
	for (int j = 0; j < *col; j++)
	{
		int k = 0;
		for (int i = 0; i < *row; i++)
		{
			*(vectCol + k) = *(arr + j + i * *row);
			k++;
		}

		*(vecColMax + j) = maxArray(vectCol, col); // записываем наибольший элемент
	}
	printf("Массив наибольших элементов в столбце:\n");
	printArray(vecColMax, &stub, col);

	/* ищем максимальный элемент в строке */
	for (int i = 0; i < *row; i++)
	{
		//int l = 0;
		for (int j = 0; j < *col; j++)
		{
			*(vectRow + j) = *(arr + i * *row + j);
			//l++;
		}
		//printArray(vectRow, &stub, col);

		*(vecRowMax + i) = maxArray(vectRow, col); // записываем наибольший элемент
	}
	printf("Массив наибольших элементов в строке:\n");
	printArray(vecRowMax, &stub, row);

}

void task2(int *arr, int *row, int *col, int *vecColFirstEven, int *vecRowLastEven)
{
	/* Формируем массив из элементов столбцов */
	int *vectCol = GetMemoryVect(col);

	/* Формируем массив из элементов строк */
	int *vectRow = GetMemoryVect(row);

	int stub = 1; // stub - заглушка

				  /* ищем четный элемент в столбце */
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
				*(vecColFirstEven + j) = *(vectCol + i); // записываем первый четный элемент
				flag = 1;
				break;
			}

		}
		if (!flag)
			*(vecColFirstEven + j) = 0;
	}
	printf("Массив первых четных элементов столбца:\n");
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
				*(vecRowLastEven + j) = *(vectRow + i); // записываем последний четный элемент
				flag = 1;
				break;
			}

		}
		if (!flag)
			*(vecRowLastEven + j) = 0;
	}
	printf("Массив последних четных элементов строки:\n");
	printArray(vecRowLastEven, &stub, row);
}