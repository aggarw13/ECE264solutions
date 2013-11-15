#include "pa09.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char ** argv)
{
  if(argc != 3)
    {
      printf("ERROR! There should be three input arguments, the object file, the input file and the output file");
      return EXIT_FAILURE;
    }

  FILE * ftpr;
  ftpr = fopen(argv[1],"r");
  if(ftpr == NULL)
    {
      printf("\n Error! The input file could not be opened");
      return EXIT_FAILURE;
    }
  fclose(ftpr);
  HuffNode * Huffmannroot = NULL;
  int filetype =  readHeader(argv[1]);
  if(filetype == 0)
    {
      Huffmannroot = create_Huffmanntree(argv[1]);
    }
  else
    {
      Huffmannroot = create_HufftreeBit(argv[1]);
    }
  FILE * ftpr2 = fopen(argv[2],"w");
  if(ftpr2 == NULL)
    {
      printf("Error! The output filename argument could not be opened.");
      return EXIT_FAILURE;
    }
  Huff_postOrderPrint(Huffmannroot, ftpr2);
  tree_destroy(Huffmannroot);
  fclose(ftpr2);
  return EXIT_SUCCESS;
}
