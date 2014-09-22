/* *****************************************************************************
** Write a function that returns the integer square root of a number if it
** exists and 0 if it's not a whole number.
**
** It will be prototyped as follows:
** int	my_square_root(int nb);
**
** Additional rule:
** Your function must give its answer in less than 2 seconds.
** ****************************************************************************/

int	my_square_root(int nb);

int	my_square_root(int nb)
{
  int	root;
  int	tmp;

  root = 0;
  tmp = nb - 2 * root - 1;
  while (tmp >= 0)
    tmp = tmp - 2 * root++ - 1;
  return (root * root == nb ? root : 0);
}

#ifdef MY_SQUARE_ROOT

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
  assert(my_square_root(4) == 2);
  assert(my_square_root(3) == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_SQUARE_ROOT */
