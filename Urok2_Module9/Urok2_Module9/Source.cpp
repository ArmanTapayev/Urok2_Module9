#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include "Header.h"

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int n;
	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);

		switch (n)
		{
			case 1:
			{
				/*1. Ввести вещественные числа. Создать массив из этих чисел, пока не встретится число 10.
				Вычислить сумму отрицательных элементов массива */
				int stub = 1, N = 0;
				float *arr = NULL;
				arr = (float*)calloc(1, sizeof(float));

				printf("Для формирования массива введите произвольное число целых чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");

				do
				{
					printf("Введите число: ");
					if ((scanf("%f", (arr + N)) == true) && (*(arr + N) != 10))
					{
						N++;
						arr = (float*)realloc(arr, sizeof(float)*(N + 1));
					}
					else
						break;

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);

				float sum = 0;
				for (int i = 0; i < N; i++)
				{
					if (*(arr + i) < 0)
						sum += *(arr + i);
				}

				printf("Сумму отрицательных элементов массива: %3.2f\n", sum);
				free(arr);

				system("pause");
				system("cls");
			}
			break;

			case 2:
			{
				/*2. Ввести в StringGrid массив из 10 целых чисел. Создать два новых массива – из положительных 
				и отрицательных элементов исходного массива. Определить суммы элементов каждого массива. */

				int N=10, stub = 1;
				int minElem = -20, maxElem = 50;

				printf("Формируем массив из %d целых чисел.\n", N);
				int *arr = GetMemoryVect(&N); // подготавливаем одномерный массив из N элементов
				fillArray(arr, &stub, &N, &minElem, &maxElem);
				printArray(arr, &stub, &N);

				int *vecPos = NULL;
				vecPos = GetMemoryVect(&N); // положительные элементы

				int *vecNeg = NULL;
				vecNeg = GetMemoryVect(&N); // отрицательные элементы

				task2(arr, &N, vecPos, vecNeg);

				free(arr);
				free(vecPos);
				free(vecNeg);

				system("pause");
				system("cls");
			}
			break;

			case 3:
			{
				/*3. Ввести массив из 9 вещественных чисел. Создать новый массив из элементов исходного,
				которые по модулю больше 10. Вычислить среднее арифметическое элементов нового массива */
				int N = 9, stub = 1;
				float minElem = -20, maxElem = 50;

				printf("Формируем массив из %d вещественных чисел.\n", N);
				float *arr = GetMemoryVectF(&N); // подготавливаем одномерный массив из N элементов
				fillArray(arr, &stub, &N, &minElem, &maxElem);
				printArray(arr, &stub, &N);

				float *vec = NULL;
				vec = GetMemoryVectF(&N); 

				task3(arr, &N, vec);

				free(arr);
				free(vec);
		
				system("pause");
				system("cls");
			}
			break;

			case 4:
			{
		    	/*4. Ввести вещественные числа. Создать массив из положительных чисел. Определить, 
				является ли массив упорядоченным по возрастанию.*/

				int stub = 1, N = 0;
				float *arr = NULL;
				arr = (float*)calloc(1, sizeof(float));

				printf("Для формирования массива введите произвольное число вещественных чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");

				do
				{
					printf("Введите число: ");
					if (scanf("%f", (arr + N)) == true)
					{
						N++;
						arr = (float*)realloc(arr, sizeof(float)*(N + 1));
					}
					else
						break;					

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);
				
				if (ascArr(arr, &N))
					printf("Массив возрастающий.\n");
				else
					printf("Массив не возрастающий.\n");

				free(arr);
				
				system("pause");
				system("cls");
			}
			break;

			case 5:
			{
				/*5. Ввести целые числа. Создать массив из этих чисел до первого отрицательного числа. 
				Определить, является ли массив упорядоченным по убыванию.*/

				int stub = 1, N = 0;
				int *arr = NULL;
				arr = (int*)calloc(1, sizeof(int));

				printf("Для формирования массива введите произвольное число целых чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");

				do
				{
					printf("Введите число: ");
					if (scanf("%d", (arr + N)) == true && *(arr + N)>0)
					{
						N++;
						arr = (int*)realloc(arr, sizeof(int)*(N + 1));
					}
					else
						break;

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);

				if (descArr(arr, &N))
					printf("Массив убывающий.\n");
				else
					printf("Массив не убывающий.\n");

				free(arr);

				system("pause");
				system("cls");
			}
			break;

			case 6:
			{
				/*6. Ввести массив из 15 вещественных чисел. Создать новый массив из элементов исходного, 
				в который не включать элементы, попадающие в промежуток (-3,7). Определить произведение
				отрицательных элементов нового массива */

				int N = 15, stub = 1;
				float minElem = -15, maxElem = 20;

				printf("Формируем массив из %d вещественных чисел.\n", N);
				float *arr = GetMemoryVectF(&N); // подготавливаем одномерный массив из N элементов
				fillArray(arr, &stub, &N, &minElem, &maxElem);
				printArray(arr, &stub, &N);

				task6(arr, &N);

				free(arr);

				system("pause");
				system("cls");
			}
			break;

			case 7:
			{
				/*7. Ввести целые числа. Создать массив из чисел, которые не делятся на 5. 
				Определить минимальный элемент массива. */

				int stub = 1, N = 0;
				int *arr = NULL;
				arr = (int*)calloc(1, sizeof(int));

				printf("Для формирования массива введите произвольное число целых чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");

				do
				{
					int num=0;
					printf("Введите число: ");
					if (scanf("%d", &num))
					{
						if (num % 5 != 0 || num==0)
						{
							*(arr + N) = num;
							N++;
							arr = (int*)realloc(arr, sizeof(int)*(N + 1));
						}					
					}
					else
						break;

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);

				printf("Минимальный элемент массива: %d\n", minArray(arr, &N));

				free(arr);
		
				system("pause");
				system("cls");
			}
			break;

			case 8:
			{
				/*8. Ввести вещественные числа. Создать массив из этих чисел, пока не встретится число 33. 
				Определить максимальный элемент массива*/
	
				int stub = 1, N = 0;
				float *arr = NULL;
				arr = (float*)calloc(1, sizeof(float));

				printf("Для формирования массива введите произвольное число целых чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");
				
				do
				{
					printf("Введите число: ");
					if ((scanf("%f", (arr + N)) == true ) && (*(arr + N)!=33))
					{
						N++;
						arr = (float*)realloc(arr, sizeof(float)*(N + 1));
					}
					else
						break;

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);

				printf("Максимальный элемент массива: %3.2f\n", maxArray(arr, &N));

				free(arr);

				system("pause");
				system("cls");
			}
			break;

			case 9:
			{
				/*9. Ввести массив из 9 вещественных чисел. Создать новый массив из элементов исходного, 
				которые по модулю не больше 12. Поменять местами минимальный и максимальный элементы нового массива*/

				int N = 9, stub = 1;
				float minElem = -20, maxElem = 20;

				printf("Формируем массив из %d вещественных чисел.\n", N);
				float *arr = GetMemoryVectF(&N); // подготавливаем одномерный массив из N элементов
				fillArray(arr, &stub, &N, &minElem, &maxElem);
				printArray(arr, &stub, &N);

				task9(arr, &N);

				free(arr);

				system("pause");
				system("cls");
			}
			break;

			case 10:
			{
				/*10. Ввести вещественные числа. Создать массив из чисел, которые попадают в интервал [2,13]. 
				Определить, есть ли в массиве числа, большие 10.*/

				int stub = 1, N = 0;
				float *arr = NULL;
				arr = (float*)calloc(1, sizeof(float));

				printf("Для формирования массива введите произвольное число целых чисел.\n");
				printf("Для завершения ввода наберите \'+\'\n");

				do
				{
					float num = 0;
					printf("Введите число: ");
					if (scanf("%f", &num))
					{
						if (num >= 2 && num <= 13)
						{
							*(arr + N) = num;
							N++;
							arr = (float*)realloc(arr, sizeof(float)*(N + 1));
						}
					}
					else
						break;

				} while (true);

				printf("\nСформированный массив:\n");
				printArray(arr, &stub, &N);

				int count = 0;
				for (int i = 0; i < N; i++)
				{
					if (*(arr + i) > 10)
						count++;
				}

				printf("В массиве %d чисел больше 10.\n", count);

				free(arr);

				system("pause");
				system("cls");			
			}
			break;
		}

	} while (n != 0);

}
