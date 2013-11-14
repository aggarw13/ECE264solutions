#include "pa09.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

// Function for reading header from input file
int readHeader(char * input_file)
{
  if (input_file[strlen(input_file) - 1] == 't')
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
      
      /*
      int clength 
      HuffNode * chartree = create_Huffmanntree(ftpr, clength);
      return chartree;
    }
  else
    {
      HuffNode * bittree = create_HufftreeBit(ftpr);
      return bittree;
      }*/
  /*
  char * headerinput = malloc(sizeof(char) * MAX_STRL);
  if(headerinput == NULL)
    {
      return NULL;
    }
  else
    {
      fgets(headerinput,MAX_STRL,ftpr);
      return headerinput;
    }
    }*/

//Function for retrieving the Huffman Tree from the header
  Stacknode * Stack_pop(Stacknode * Stack)
  {
    if(Stack == NULL)
      {
	return NULL;
      }
    Stacknode * top = Stack;
    Stack = Stack -> below;
    free(top);
    return Stack;
  }

 Stacknode * Stack_push(Stacknode * Stack,HuffNode * Node)
 {
   Stacknode * top = malloc(sizeof(Stacknode));
   top -> below = Stack;
   top -> treeNode = Node;
   return top;
 }

HuffNode * create_Node(char letter)
{
  HuffNode * Node = malloc(sizeof(HuffNode));
  Node -> value =  letter;
  Node -> right = NULL;
  Node -> left = NULL;
  return Node;
}

HuffNode * create_Huffmanntree(char * inputf)
{ 
  FILE * ftpr = fopen(inputf,"r");
  int tree_comp = 0;
  //nt count1 = 0;
  //t count0 = 0;
  char ch;
  HuffNode * root = NULL;
  Stacknode * Stack = NULL;
  while(tree_comp == 0)
    {
      ch = fgetc(ftpr);
      if(ch == '1')
	{
	  ch = fgetc(ftpr);
	  HuffNode * Node = create_Node(ch);
	  Stack = Stack_push(Stack, Node);
	}
      else if(ch == '0')
	{
	  root = Stack -> treeNode;
	  Stack = Stack_pop(Stack);
	  if(Stack == NULL)
	    {
	      tree_comp = 2;
	    }
	  else 
	    {
	      HuffNode * Node = Stack -> treeNode;
	      Stack = Stack_pop(Stack);
	      HuffNode * nonleaf = create_Node(' ');
	      nonleaf -> right = root;
	      nonleaf -> left = Node;
	      Stack = Stack_push(Stack, nonleaf);
	    }
	}
    }
  fclose(ftpr);
  Stack_destroy(Stack);
  return root;
}

HuffNode * create_HufftreeBit(char * inputf)
 {
   FILE * ftpr2 = fopen(inputf,"r");
   if(ftpr2 == NULL)
     {
       printf("\nError! The  input bit representation header could not be opened\n");
       return NULL;
     }
   int bit_tree_comp = 0;
   int counter = 1;
   HuffNode * bitroot = NULL;
   Stacknode  * Stack = NULL;
   unsigned char ch1,ch2;
   fread(&ch1,sizeof(unsigned char),1,ftpr2);
   while((bit_tree_comp == 0)&&(fread(&ch2,sizeof(unsigned char),1,ftpr2)))
     {
       unsigned char check2 = (ch1 << (counter - 1)) & 0x80;
       check2 >>= 7;
       // printf("\ncheck 2: %d\n", check2);
       if(check2 == 1)
	 {
	   // printf("Hello 1 Counter : %d\n",counter);
	   ch1 = ((ch1 << counter) | (ch2 >> (8 - counter)));
	   HuffNode * Node = create_Node(ch1);
	   Stack = Stack_push(Stack, Node);
	   counter++;
	 }
       else
	 {
	   // printf("Hello 0 Counter : %d\n",counter);
	   bitroot = Stack -> treeNode;
	   Stack = Stack_pop(Stack);
	   if(Stack == NULL)
	     {
	       bit_tree_comp = 1;
	       break;
	     }
	   else
	     {
	       HuffNode * Node = Stack -> treeNode;
	       Stack = Stack_pop(Stack);
	       HuffNode * nonleaf = create_Node('0');
	       nonleaf -> right = bitroot;
	       nonleaf -> left = Node;
	       Stack = Stack_push(Stack, nonleaf);
	     }
	   counter++;
	 }
       if((check2 == 0) && (counter <= 8))
	 {
	   fseek(ftpr2,-1*sizeof(unsigned char),SEEK_CUR);
	   ch2 = ch1;
	 }
       if((check2 == 1) && (counter == 9))
	 {
	   fread(&ch2,sizeof(unsigned char),1,ftpr2);
	 } 
       if(counter == 9)
	 {
	   counter = 1;
	 }
       ch1 = ch2;
     }
   fclose(ftpr2);
   Stack_destroy(Stack);
   return bitroot;
 }

void tree_destroy(HuffNode *root)
{
  if(root == NULL)
    {
      return;
    }
  if(root -> left != NULL)
    {
      tree_destroy(root -> left);
    }
  if(root -> right != NULL)
    {
      tree_destroy(root -> right);
    }
  free(root);
}

void Stack_destroy(Stacknode * Stack)
{
  Stacknode * below;
  while(Stack != NULL)
    {
      below = Stack;
      Stack = Stack -> below;
      free(below);
    }
}

void Huff_postOrderPrint(HuffNode *tree, FILE * fp)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }
    // FILE * fp = fopen(outputf,"a+");
    /* if(fp == NULL)
    {
      printf("Error! The output filename argument could not be opened.");
      return;
      }*/
    // Recursive case: post-order traversal

    // Visit left
    fprintf(fp,"Left\n");
    Huff_postOrderPrint(tree->left,fp);
    fprintf(fp,"Back\n");
    // Visit right
    fprintf(fp,"Right\n");
    Huff_postOrderPrint(tree->right,fp);
    fprintf(fp,"Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) {
      fprintf(fp,"Leaf: %c\n", tree->value);
    }
    //fclose(fp);
}



  /*
  int i;
  if(check == 1)
    {
      for(i = 0; i < strlen(header); i++)
	{
	  if(header[i] == 1)
	    {
	      i++;
	      if(header[i] == ' ')
		{
		  i++;
		}
	      HuffNode * Node = create_Node(header[i]);
  */
  
  
  

