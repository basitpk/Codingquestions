/**
 Implement a string reverse API with only arguments source and destination buffer using recursion


 Aksed in Juniper Networks

**/


#include <stdio.h>
#include <stdlib.h>

void reverse(char *str, char *buffer) {
  static int pos = 0;
  if (*str) {
    reverse(str + 1, buffer);
    *(buffer+pos) = *str;
    pos++;
  }
  *(buffer+pos) = '\0';
}

int main() {
  char str[] = "Hello, world!";
  char buffer[100];

  reverse(str, buffer);

  printf("The reversed string is: %s\n", buffer);

  return 0;
}