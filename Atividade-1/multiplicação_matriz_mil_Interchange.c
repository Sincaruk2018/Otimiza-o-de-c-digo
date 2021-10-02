#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void mult_matrix(int rowA, int rowB, int columnA, int columnB, int** matrixA, int** matrixB, int** matrixC)
{
	int i,j,k;
	if (rowB != columnA)
	{
		printf("Invalid multiplication!\n");
		return;
	}
	
	for (i = 0; i < rowA; i++)
	{
		for(k = 0; k < rowB; k++)
		{
			for(j = 0; j < columnB; j++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	
	
	for(i = 0; i < rowA; i++)
	{
		for(j = 0; j < columnB; j++)
		{
			printf("%d ", matrixC[i][j]);
		}
		printf("\n");
	}
	
}

int main(int argc, char **argv)
{
	int i,j;
	int columnA, columnB, rowA, rowB;
	int** matrixA;
	int** matrixB;
	int** matrixC;
	
	columnA = 1000;
	rowA = 1000;
	matrixA = (int**) malloc(rowA * sizeof(int*));
	for(i = 0; i < rowA; i++)
	{
		matrixA[i] = (int*) malloc(columnA * sizeof(int));
	}
	
	columnB = 1000;
	rowB = 1000;
	matrixB = (int**) malloc(rowB * sizeof(int*));
	for(i = 0; i < rowB; i++)
	{
		matrixB[i] = (int*) malloc(columnB * sizeof(int));
	}
	
	matrixC = (int**) malloc(rowA * sizeof(int*));
	for(i = 0; i < rowA; i++)
	{
		matrixC[i] = (int*) malloc(columnB * sizeof(int));
	}
	
	
	for(i = 0; i < rowA; i++)
	{
		for(j = 0; j < columnB; j++)
		{
			matrixC[i][j] = 0;
		}
	}
	
	for(i = 0; i < rowA; i++)
	{
		for(j = 0; j < columnA; j++)
		{
			matrixA[i][j] = rand() % 10;
		}
	}
	
	for(i = 0; i < rowB; i++)
	{
		for(j = 0; j < columnB; j++)
		{
			matrixB[i][j] = rand() % 10;
		}
	}
	
	mult_matrix(rowA,rowB,columnA,columnB,matrixA,matrixB,matrixC);
	
	return 0;
}

