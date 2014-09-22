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
  *a = *b;
  *b = tmp;
  return (0);
}

#ifdef MY_SWAP

#include <assert.h>
#include <stdio.h>

int	main()
{
  int	a;
  int	b;

  a = 42;
  b = 21;
  my_swap(&a, &b);
  assert(a == 21 && b == 42);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_SWAP */
