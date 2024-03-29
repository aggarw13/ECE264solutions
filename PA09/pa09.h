#ifndef PA09_H
#include<stdlib.h>
#define PA09_H

typedef struct leaf {
    int value;
    struct leaf *left;
    struct leaf *right;
} HuffNode;

typedef struct Stack
{
  HuffNode * treeNode;
  struct Stack * below;
}Stacknode;

int readHeader(char *);
Stacknode * Stack_pop(Stacknode *);
Stacknode * Stack_push(Stacknode *, HuffNode *);
HuffNode * create_Huffmanntree(char *);
HuffNode * create_HufftreeBit(char *);
void Stack_destroy(Stacknode * Stack);
void tree_destroy(HuffNode *);
void Huff_postOrderPrint(HuffNode * root, void * fp);

#endif /* pa09.h */

