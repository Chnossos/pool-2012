/* *****************************************************************************
** Write a recusive function that returns the factorial operation of the number
** given as a parameter.
**
** It will be prototyped as follows:
** int	my_factorielle_rec(int nb);
**
** Additional rule:
** It will give the same answers as the function my_factorielle_it.
** ****************************************************************************/

int	my_factorielle_rec(int nb);

int	my_factorielle_rec(int nb)
{
  if (nb < 0 || nb > 12)
    return (0);
  if (nb == 0)
    return (1);
  return (nb * my_factorielle_rec(nb - 1));
}

#ifdef MY_FACTORIELLE_REC

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char const * const av[])
{
  int	i;
  int	j;

  if (ac > 1)
    printf("%d\n", my_factorielle_rec(atoi(av[1])));
  else
  {
    for (i = 0 ; (j = my_factorielle_rec(i)) ; ++i)
      printf("%2d: %d\n", i, j);
  }
  return (0);
}

#endif /* !MY_FACTORIELLE_REC */
