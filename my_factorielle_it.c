/* *****************************************************************************
** Write an iterative function that returns a number. This number is the result
** of the factorial operation from the number fiven as a parameter to the
** function.
**
** In case of any errors, the function should return 0.
**
** It will be prototyped as follows:
** int	my_factorielle_it(int nb);
**
** You need to manage if the factorial operation of the number overflows (which
** is an error).
**
** Additional rule:
** Your function must give its answer in less than 2 seconds.
** ****************************************************************************/

int my_factorielle_it(int nb);

int	my_factorielle_it(int nb)
{
  int	result;

  if (nb < 0 || nb > 12)
    return (0);
  if (nb == 0)
    return (1);
  result = 1;
  while (nb > 1)
    result *= nb--;
  return (result);
}

#ifdef MY_FACTORIELLE_IT

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char const * const av[])
{
  int	i;
  int	j;

  if (ac > 1)
    printf("%d\n", my_factorielle_it(atoi(av[1])));
  else
  {
    for (i = 0 ; (j = my_factorielle_it(i)) ; ++i)
      printf("%2d: %d\n", i, j);
  }
  return (0);
}

#endif /* !MY_FACTORIELLE_IT */
