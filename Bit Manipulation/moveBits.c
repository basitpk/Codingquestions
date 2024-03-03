#include <stdio.h>
#include <math.h>
#include <string.h>

void decimaltoBinary(int val, char bits[20])
{
  int i = 0;
  while(val >0)
  {
    bits[i]=(char)(val%2+48);
    val=val/2;
    i++;
  }
  int k = 0;

  //Reversing the order to get binary string
  while(k < i/2)
  {
    char temp = bits[k];
    bits[k] = bits[i-k-1];
    bits[i-k-1]= temp;
    k++;
  }
  bits[i]='\0';
 
}

int moveBits(int val,int pos1, int pos2, int numBits)
{
  int setBits = (1<<(numBits+1)) -1;
  int mask1 = setBits << pos1;
  int mask2 = setBits << pos2;

  int shiftVal = val & mask1;
  int shift2Val = val & mask2;
//   printf("Mask1 = %d", setBits);
  int res = (val ^ shift2Val)|(shiftVal << (pos2-pos1));
  return res;
}

int main()
{
    int input = 0b1010100111010101;
    int pos1=1;
    int pos2 = 8;
    int numBits = 5;
    char inputStr[20], outputStr[20];
    int res = moveBits(input, pos1, pos2, numBits);
    decimaltoBinary(input, inputStr);
    decimaltoBinary(res, outputStr);
    printf("Input  = %s\n", inputStr);
    // fflush(stdout);
    printf("Output = %s", outputStr);
    return 0;
}