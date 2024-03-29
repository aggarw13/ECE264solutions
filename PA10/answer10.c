#include "pa10.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *, int*);
void permute(int *, int , int);
#define TRUE 1
#define FALSE 0

/**
 * Returns a pointer to a new empty stack.
 */
Stack * Stack_create()
{
  Stack * stack = malloc(sizeof(Stack));
  if(stack != NULL){
    stack -> list = NULL;
    return stack;
  }
    return NULL;
}

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you _must_ free the entire contained linked-list.
 * Also, you must safely to _nothing_ if stack == NULL. 
 */
void Stack_destroy(Stack * stack)
{
  if(stack == NULL)
    {
      return;
    }
  while(stack -> list -> next != NULL)
    {
      ListNode * list = stack -> list;
      stack -> list = stack -> list -> next;
      free(list);
    }
  free(stack);
  return; 
}

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */
int Stack_isEmpty(Stack * stack)
{
  if(stack == NULL)
    {
      return 1;
    }
    return FALSE;
}

/**
 * Pop the front 'value' from the stack.
 *
 * More precisely, this function must do two things:
 * (1) Return the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 */
int Stack_pop(Stack * stack)
{
  if(stack == NULL)
    return -1;
  ListNode * node = stack -> list;
  stack -> list = stack -> list -> next;
  int value = node -> value;
  free(node);
  return value;
}

/**
 * Push an 'value' onto the front of the stack.
 *
 * More precisely, this function must:
 * (1) Create a new ListNode with 'value' for it's value.
 * (2) Push that new ListNode onto the front of the stack's list.
 */
void Stack_push(Stack * stack, int value)
{
  if(stack == NULL)
     return;
  ListNode * node = malloc(sizeof(ListNode));
  node -> value = value;
  node ->  next = stack -> list;
  stack -> list = node; 
}

/**
 * Sort 'array' of length 'len' using Donald Knuth's "StackSort"
 *
 * To do this, you must implement the following pseudo-code:
 * (1) Maintain a 'write_index'. This is where you'll write values to
 *     as you sort them. It starts off as zero.
 * (2) Initialize an empty stack
 * (3) For each input value 'x':
 *     (3.a) While the stack is nonempty and 'x' is larger than the 
 *           front 'value' on the stack, pop 'value' and:
 *           (3.a.i) Write 'value' to array[write_index], and 
 *                   increment write_index.
 *     (3.b) Push x onto the stack.
 * (4) While the stack is nonempty, pop the front 'value' and follow
 *     step (3.a.i).
 *
 * The output should be a sorted array if, and only if, the array
 * is stack-sortable. You can find files full of stack-sortable and
 * stack-unsortable arrays in the 'expected' folder.
 */
void stackSort(int * array, int len)
{
  if(isStackSortable(array,len)){
    Stack * stack = Stack_create();
    int * arrsorted = malloc(sizeof(int)*len);
    int i,j = 0;
    for(i = 0; i < len; i++)
      {
	if((stack -> list== NULL) || (stack -> list -> value > array[i]))
	  Stack_push(stack, array[i]);
	while((stack -> list != NULL) && array[i] > stack -> list -> value)
	  {
	    arrsorted[j] = Stack_pop(stack);
	    j++;
	  }
      	if((stack -> list== NULL) || (stack -> list -> value > array[i]))
	  Stack_push(stack, array[i]);
      }
    if(j != len)
      {
	while(j < len)
	  {
	    arrsorted[j] = Stack_pop(stack);
	    j++;
	  }
      }
    for(i = 0; i < len; i++)
      {
	array[i] = arrsorted[i];
      }
  }
}

/**
 * Return TRUE (1) if the 'array' of length 'len' is stack-sortable.
 *
 * To do this you must:
 * (1) If 'len' is less than 3, return TRUE.
 * (2) Find the maximum value in 'array'.
 * (3) Partition array into two parts: left of max, and right of max.
 * (4) The maximum value in left must be smaller than the minimum
 *     value in right. (Otherwise return FALSE.)
 * (5) Return TRUE if both left and right are stack-sortable.
 *
 * The 'expected' directory contains files for all sortable and 
 * unsortable sequences of length len. You must return TRUE for every
 * sequence in the sortable files, and you must return FALSE for every
 * sequence in the unsortable files.
 */

int find_max(int * arr, int len)
{
  int i,max = 0;
  for(i = 1; i < len; i++)
    {
      if(arr[max] < arr[i])
	max = i;
    }
  return max;
}
int find_min(int * arr, int len)
{
  int i,min = 0;
  for(i = 1; i < len; i++)
    {
      if(arr[min] > arr[i])
	min = i;
    }
  return min;
}

int isStackSortable(int * array, int len)
{
  if(len < 3)
    return TRUE;
  
  int largepos = find_max(array, len);
  if(((largepos == 0) || (largepos == len - 1) || array[find_min(&array[largepos + 1], len - largepos - 1) + largepos + 1] > array[find_max(array,largepos)]) && (isStackSortable(array,largepos))&&(isStackSortable(&array[largepos + 1],len - largepos - 1)))
    {
      return TRUE;
    }
  return FALSE;
  /*for(int i = 1; i < len; i++)
    {
      if(max < arr[i])
	max = arr[i];
      if(min > arr[i])
	min = arr[i];
    }
    return FALSE;*/
}
/**
 * Generates (and prints) all the unique binary tree shapes of size k
 *
 * To do this, you must:
 * (1) Create an array with the elements [1..k] inclusive.
 * (2) Find all the permutations of this array.
 * (3) In the base-case of your permute function, you must test if the
 *     permutation is "stack-sortable"
 * (4) If the permutation is "stack-sortable", then build a binary
 *     tree, and print it using the "Tree_printShape(...)" function.
 *
 * Your genShapes() function must NOT produce duplicate tree shapes.
 * The correct outputs for sizes [1..9] are in the 'expected' 
 * directory.
 */
void swap(int *a, int * b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void permute(int * array, int len, int ind)
{
  if(ind == len - 1){
    if(isStackSortable(array, len))
      {
	TreeNode * root = Tree_build(array,len);
	Tree_printShape(root);
      }
    return;
  }
  int iter;
  for(iter = ind; iter < len; iter++)
    {
      swap(array + iter, array + ind);
      permute(array, len, ind + 1);
      swap(array+iter, array + ind);
    }
}

void genShapes(int k)
{
  int * array = malloc(sizeof(int)*k);
  int i;
  for(i = 0; i < k; i++)
    {
      array[i] = i;
    }
  permute(array, k, 0);
}




