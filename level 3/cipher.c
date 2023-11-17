#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LOWERCASELOWER 97
#define LOWERCASEUPPER 122
#define UPPERCASELOWER 65
#define UPPERCASEUPPER 90


int main()
{
  FILE *cipher;
  char *decode, currChar;
  long length=0;
  cipher = fopen("level 3.txt", "r");

  if (cipher != NULL)
  {
    fseek(cipher, 0, SEEK_END);
    length = ftell(cipher);
    fseek(cipher, 0, SEEK_SET);

    decode = malloc(length*sizeof(char));
    if(decode == NULL)
    {
      printf("fail to load into memory");
      return -1;
    }
    fread(decode, sizeof(char), length, cipher);
  }

  int offset = 10;

  for (int i=0; i<length; i++)
  {
    if( *(decode+i) >= UPPERCASELOWER && *(decode+i) <= UPPERCASEUPPER)
    {
      if (*(decode+i)-offset < UPPERCASELOWER)
      {
        *(decode+i) = *(decode+i)-offset + (UPPERCASEUPPER-UPPERCASELOWER);
      } else
      {
        *(decode+i) = *(decode+i)-offset;
      }
    } else if (*(decode+i) >= LOWERCASELOWER && *(decode+i) <= LOWERCASEUPPER)
    {
      if (*(decode+i)-offset < LOWERCASELOWER)
      {
        *(decode+i) = *(decode+i)-offset + (LOWERCASEUPPER-LOWERCASELOWER)+1;
      } else
      {
        *(decode+i) = *(decode+i)-offset;
      }
    } 

  }

  printf("The Decoded Message:\n%s", decode);

  return 0;
}