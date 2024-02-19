#include <stdio.h>
#include <math.h>

int moveBits(int val,int pos1, int pos2, int numBits)
{
  int setBits = (1<<(numBits+1)) -1;
  int mask1 = setBits << pos1;
  int mask2 = setBits << pos2;

  int shiftVal = val & mask1;
  int shift2Val = val & mask2;
  printf("Mask1 = %d", setBits);
  int res = (val ^ shift2Val)|(shiftVal << (pos2-pos1));
  return res;
}

int main()
{
    int input = 0b1010100111010101;
    int pos1=1;
    int pos2 = 8;
    int numBits = 5;
    int res = moveBits(input, pos1, pos2, numBits);
    printf("Output = %d", res);
    return 0;
}