/* *****************************************************************************
** Write a function that swaps the contents of two integers whose adresses are
** given as parameters.
**
** It will be prototyped as follows:
** int	my_swap(int *a, int *b);
** ****************************************************************************/

int	my_swap(int *a, int *b);

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *b = *a;
  *a = tmp;
  return (0);
}

#ifdef MY_SWAP

#include <stdio.h>

int main ()
{
  int a = 21, b = 42;

  printf("before\ta = %d, b = %d\n", a, b);
  my_swap(&a, &b);
  printf("after\ta = %d, b = %d\n", a, b);
  return (0);
}

#endif /* !MY_SWAP_TEST */
