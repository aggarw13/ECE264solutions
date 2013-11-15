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

//Function for remove the top Stacknode from the stack      
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

//Function for creating a stack or pushing Stacknode at the top of the stack
Stacknode * Stack_push(Stacknode * Stack,HuffNode * Node)
 {
   Stacknode * top = malloc(sizeof(Stacknode));
   top -> below = Stack;
   top -> treeNode = Node;
   return top;
 }

//Function for creating and initializing a structure pointer of typee Huffnode
HuffNode * create_Node(char letter)
{
  HuffNode * Node = malloc(sizeof(HuffNode));
  Node -> value =  letter;
  Node -> right = NULL;
  Node -> left = NULL;
  return Node;
}

//Function for creating a binary tree from a character based header read from the input file
HuffNode * create_Huffmanntree(char * inputf)
{ 
  FILE * ftpr = fopen(inputf,"r");
  if(ftpr == NULL)
    {
      printf("Error! The input file sent as the second argument could not be opened");
      return NULL;
    }
  int tree_comp = 0;
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
  return root;
}

//Function for creating a binary tree from a bit-based header representation read from the input file
HuffNode * create_HufftreeBit(char * inputf)
 {
   FILE * ftpr2 = fopen(inputf,"r");
   if(ftpr2 == NULL)
     {
       printf("\nError! The  input bit representation header could not be opened\n");
       return NULL;
     }
   int bit_tree_comp = 0;
   int track = 1; //This variable keeps a trackof the command bit
   HuffNode * bitroot = NULL;
   Stacknode  * Stack = NULL;
   unsigned char ch1,ch2; //The two unsigned char or byte variables represent consecutive byte
   fread(&ch1,sizeof(unsigned char),1,ftpr2);
   while((bit_tree_comp == 0)&&(fread(&ch2,sizeof(unsigned char),1,ftpr2)))
     {
       unsigned char check2 = (ch1 << (track - 1)) & 0x80;//Shifting the the command bit in byte ch1 to the first bit position and masking 
       if(check2 == 128) //Checking if the shifted and masked byte ch1 contains 11 as its command bit
	 {
	   ch1 = ((ch1 << track) | (ch2 >> (8 - track))); // Shifitng the relevant data after command bit of ch1 to the left and the remaining data in byte ch2 to the right and concatenating the data bits in one byte using bitwise OR operation
	   HuffNode * Node = create_Node(ch1);
	   Stack = Stack_push(Stack, Node);
	   track++;
	 }
       else //The control enters the else construct if the command bit in byte ch1 is 0
	 {
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
	   track++;
	 }
       if((check2 == 0) && (track <= 8))
	 {
	   fseek(ftpr2,-1*sizeof(unsigned char),SEEK_CUR);
	   ch2 = ch1;
	 }
       if((check2 == 128) && (track == 9))
	 {
	   fread(&ch2,sizeof(unsigned char),1,ftpr2);
	 } 
       if(track == 9)
	 {
	   track = 1;
	 }
       ch1 = ch2;
     }
   fclose(ftpr2);
   return bitroot;
 }

//Function for destroying the binary tree by freeing the memory allocated to each tree node
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

//Function to print 
void Huff_postOrderPrint(HuffNode *tree, void * fpt)
{
    FILE * fp = (FILE *)fpt;
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



  
  
  

