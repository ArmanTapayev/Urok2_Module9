#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void task2(int *arr, int *len, int *vecPos, int *vecNeg)
{
	int stub = 1, pos=0, neg=0; // stub - заглушка

		for (int i = 0; i < *len; i++)
		{
			if (*(arr + i) >= 0)
			{
				*(vecPos + pos) = *(arr + i); // записываем положительные элементы
				pos++;
			}				
			else
			{
				*(vecNeg + neg) = *(arr + i); // записываем положительные элементы
				neg++;
			}
				
		}

	printf("Массив положительных элементов массива:\n");
	printArray(vecPos, &stub, &pos);

	printf("Массив отрицательных элементов массива:\n");
	printArray(vecNeg, &stub, &neg);

	printf("Сумма положительных элементов: %d\n", arrSum(vecPos, &pos));
	printf("Сумма отрицательных элементов: %d\n", arrSum(vecNeg, &neg));

}

void task3(float *arr, int *len, float *vec)
{
	int stub = 1, k = 0; // stub - заглушка

	for (int i = 0; i < *len; i++)
	{
		if (abs(*(arr + i)) > 10)
		{
			*(vec + k) = abs(*(arr + i)); // записываем элементы по модулю большие 10
			k++;
		}
	}

	printf("Массив элементов по модулю больших 10:\n");
	printArray(vec, &stub, &k);

	printf("Среднее арифметическое элементов массива: %3.2f\n", averArray(vec, &k));

}


void task6(float *arr, int *len)
{
	int stub = 1, k = 0; // stub - заглушка

	float *vec = NULL;
	vec = GetMemoryVectF(len);

	for (int i = 0; i < *len; i++)
	{
		if (!((*(arr + i) > -3) && (*(arr + i) < 7)))
		{
			*(vec + k) = *(arr + i); // записываем элементы, не входящие в (-3,7)
			k++;
		}
	}

	printf("Массив элементов не входящих в (-3,7):\n");
	printArray(vec, &stub, &k);

	float mult = 1;

		for (int i = 0; i < k; i++)
		{
			if (*(vec + i)<0)
				mult *= *(vec + i); 
		}

	printf("Произведение отрицательных элементов нового массива: %3.2f\n", mult);
}


void task9(float *arr, int *len)
{
	int stub = 1, k = 0; // stub - заглушка

	float *vec = NULL, min, max;
	vec = GetMemoryVectF(len);

	for (int i = 0; i < *len; i++)
	{
		if (abs(*(arr + i))<12)
		{
			*(vec + k) = abs(*(arr + i)); // записываем элементы по модулю не большие 12
			k++;
		}
	}

	printf("Массив элементов по модулю не больших 12:\n");
	printArray(vec, &stub, &k);

	min = minArray(vec, &k);
	max = maxArray(vec, &k);

	printf("Минимальный элемент нового массива: %3.2f\n", min);
	printf("Максимальный элемент нового массива: %3.2f\n", max);

	printf("Массив с переставленными min и max элементами:\n");
	vec = swapNum(vec, &k, &min, &max);
	printArray(vec, &stub, &k);

}

