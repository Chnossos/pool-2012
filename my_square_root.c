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

int	my_square_root2(int nb)
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

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Don't forget -lm */

int	main(int ac, char const * const av[])
{
  if (ac > 1)
  {
    printf("1: %d - 2: %d - 3: %d\n",
	   my_square_root(atoi(av[1])),
	   my_square_root2(atoi(av[1])),
	   (int)sqrt(atoi(av[1])));
  }
  return (0);
}

#endif /* !MY_SQUARE_ROOT */
