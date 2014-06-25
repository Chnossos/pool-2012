/* *****************************************************************************
** Write a recursive function that returns the power of a number.
**
** It will be prototyped as follows:
** int	my_power_rec(int nb, int power);
**
** Additional rule:
** It will give the same answers as my_power_it.
** ****************************************************************************/

int	my_power_rec(int nb, int power)
{
  if (power == 1)
    return (nb);
  if (power == 0)
    return (1);
  if (power < 0)
    return (0);
  return (nb * my_power_rec(nb, power - 1));
}

#ifdef MY_POWER_REC

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char const * const av[])
{
  if (ac > 2)
    printf("%d\n", my_power_rec(atoi(av[1]), atoi(av[2])));
  else
  {
    printf("%d\n", my_power_rec(2, 31));
  }
  return (0);
}

#endif /* !MY_POWER_REC */
