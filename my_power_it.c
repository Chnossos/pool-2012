/* *****************************************************************************
** Write an iterative function that returns the power of a number.
**
** It will be prototypes as follows:
** int	my_power_it(int nb, int power);
**
** Additional rule:
** Your function must give its answer in less than 2 seconds.
** ****************************************************************************/

int	my_power_it(int nb, int power);

int	my_power_it(int nb, int power)
{
  int	result;

  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  result = 1;
  while (power --> 0)
    result *= nb;
  return (result);
}

#ifdef MY_POWER_IT

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char const * const av[])
{
  if (ac > 2)
    printf("%d\n", my_power_it(atoi(av[1]), atoi(av[2])));
  else
    printf("%d\n", my_power_it(2, 31) - 1); /* Prints INT_MAX value */
  return (0);
}

#endif /* !MY_POWER_IT */
