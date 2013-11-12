#ifndef PA09_H
#define PA09_H

typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;

char *  readHeader(FILE * ftpr);
HuffNode * create_Huffmanntree(int check, char * input);
void Huff_postOrderPrint(HuffNode *tree);
#endif

