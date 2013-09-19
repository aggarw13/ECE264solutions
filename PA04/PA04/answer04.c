/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */

void partitionALLhelper(int value,int sum, int original, int * arr, int index) 
{  
  /* 
  int n;
  int n1 = sum;
  for(n = 1; n <= (value - n1); n++)
    { 
      if((sum < value) && (sum + n <=  value))
	{
	  sum = sum + n;
	  if(sum != value)
	    printf("%d + ", n);
	  else
	    printf("%d",n);
	  if(sum < value) 
	    partitionALLhelper(value,sum);
	  sum = sum - n;
	}
    }
  printf("\n= ");
  */
  int i,j;
  for(i = 1; i <= value; i++)
    { 
      
      sum = sum + i;
      arr[index] = i;
      if (i < value)
	{
	  index++;
	  partitionALLhelper(value - i,sum, original, arr, index);
	  sum = sum - i;
	  index--;
	}
     }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
    
}

void partitionAll(int value)
{ 
  int * arr = malloc(sizeof(int)*value);
  printf("partitionAll %d\n", value);
  partitionALLhelper(value,0,value,arr,0);
  free(arr);
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partitionINCRhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j;
  for(i = 1; i <= value; i++)
    { 
      if ((index == 0) || ((index > 0) && (i > arr[index - 1])))
	{
	  sum = sum + i;
	  arr[index] = i;
	  if (i < value)
	    {
	      index++;
	      partitionINCRhelper(value - i,sum, original, arr, index);
	      sum = sum - i;
	      index--;
	    }
	}
    }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
    
}
void partitionIncreasing(int value)
{
  int * arr = malloc(sizeof(int)*value);
  printf("partitionIncreasing %d\n", value);
  partitionINCRhelper(value,0,value,arr,0);
  free(arr);
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionDECRhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j;
  for(i = value; i >= 1; i--)
    { 
      if ((index == 0) || (arr[index - 1] > i))
	{
	  sum = sum + i;
	  arr[index] = i;
	  if (i < value)
	    {
	      index++;
	      partitionDECRhelper(value - i, sum, original, arr, index);
	      index--;
	    }
	  if (sum == original)
	    {
	      printf("= %d",arr[0]);
	      if (index > 0)
		{
		  for(j = 1; j <= index; j++)
		    {
		      printf(" + %d",arr[j]);
		    }
		}
	      printf("\n");
	    }
	  sum = sum - i;
	}
    }
}

void partitionDecreasing(int value)
{
  int * arr = malloc(sizeof(int) * value);
  printf("partitionDecreasing %d\n", value);
  partitionDECRhelper(value,0,value,arr,0);
  free(arr);
}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partitionODDhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j;
  for(i = 1; i <= value; i += 2)
    { 
      sum = sum + i;
      arr[index] = i;
      if (i < value)
	{
	  index++;
	  partitionODDhelper(value - i,sum, original, arr, index);
	  sum = sum - i;
	  index--;
	}
    }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
    
}

void partitionOdd(int value)
{
  int * arr = malloc(sizeof(int) * value);
  printf("partitionOdd %d\n", value);
  partitionODDhelper(value,0,value,arr,0);
  free(arr);
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEVENhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j;
  for(i = 2; i <= value; i += 2)
    { 
      sum = sum + i;
      arr[index] = i;
      if (i < value)
	{
	  index++;
	  partitionEVENhelper(value - i,sum, original, arr, index);
	  sum = sum - i;
	  index--;
	}
    }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
    
}


void partitionEven(int value)
{
  int * arr = malloc(sizeof(int) * value);
  printf("partitionEven %d\n", value);
  partitionEVENhelper(value,0,value,arr,0);
  free(arr);
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partitionODDEVENhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j;
  if (index % 2 == 0)
    {
      i = 1;
    }
  else
    {
      i = 2;
    }
  while(i <= value)
    { 
      sum = sum + i;
      arr[index] = i;
      if (i < value)
	{
	  index++;
	  partitionODDEVENhelper(value - i,sum, original, arr, index);
	  sum = sum - i;
	  index--;
	}
      i += 2;
    }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
  }
void partitionOddAndEven(int value)
{
  int * arr = malloc(sizeof(int) * value);
  printf("partitionOddAndEven %d\n", value);
  partitionODDEVENhelper(value,0,value,arr,0);
  free(arr);
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionPRIMEhelper(int value, int sum, int original, int * arr, int index)
{
  int i,j, k, count = 0;
  for(i = 1; i <= value; i++ )
    { 
      for(k = 1; k <= i; k++)
      	{
	  if (i % k == 0)
	    {
	      count++;
	    }
      	}
      if(count == 2)
	{
	  sum = sum + i;
	  arr[index] = i;
	  if (i < value)
	    {
	      index++;
	      partitionPRIMEhelper(value - i,sum, original, arr, index);
	      sum = sum - i;
	      index--;
	    }
	}
      count = 0;
    }
  if (sum == original)
    {
      printf("= %d",arr[0]);
      if (index > 0)
	{
	  for(j = 1; j <= index; j++)
	    {
	      printf(" + %d",arr[j]);
	    }
	}
      printf("\n");
    }
}

void partitionPrime(int value)
{
  int * arr = malloc(sizeof(int) * value);
  printf("partitionPrime %d\n", value);
  partitionPRIMEhelper(value,0,value,arr,0);
  free(arr);
}
