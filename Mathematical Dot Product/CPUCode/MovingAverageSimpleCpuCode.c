/**
 * Document: Vector Dot Product
 * MaxFile name: MovingAverageSimple
 * Summary:
 *   CPU code for the Dot Product Computation.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Maxfiles.h" 			// Includes .max files
#include <MaxSLiCInterface.h>	// Simple Live CPU interface

#define n 4
int a[n], b[n], result[n];

void dotProduct(int expected, int result)
{
	printf(" Input1     Input2\n");
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf(" . ");
	for (int i = 0; i < n; ++i)
		printf("%d ", b[i]);
	printf("\nDot Product Expected Result = %d \n", expected);
    printf("Dot product Calculation is completed \n");
	printf("Dot product Actual Result = %d \n", result);
}

void verifyResult(int expected, int actual) 
{
	if (expected != actual)
	{
		printf("Dot Product Expected Result of %d doesnt match with Actual Result of %d\n",
				expected, actual);
	}
	else
	printf("Dot Product Expected Result of %d matches with Actual Result of %d\n",
				expected, actual);
}

int main()
{
	int expected = 0;
	int actual = 0;
	
	for(int i = 0; i < n; ++i) {
		a[i] = 1;
		b[i] = 2;
		expected = expected +(a[i] * b[i]);
	}

	printf("Dot product Program running on Maxeler DFE\n");
	MovingAverageSimple(n, a, b, result);

	for (int i = 0 ; i < n; ++i)
	{
		actual = actual + result[i];
	}

	dotProduct(expected, actual);
	
	verifyResult(expected, actual);
	
	return 0;

}