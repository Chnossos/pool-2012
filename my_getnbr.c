/* *****************************************************************************
** Write a function that returns a number. This number will be given to the
** function as a string (Ex: "842") and needs to be returned as an integer.
**
** We consider that the number will be in base ten. ("0123456789").
**
** It will be prototyped as follows:
** int	my_getnbr(char *);
**
** Your function will manage those strings:
**
** "+---+--++---+---+---+-42" returns -42
** "42a43" returns 42
** "11000000000000000000000042" returns 0 because it doesn't fit into an integer
** "-11000000000000000000000042" returns 0 for the same reason
** ****************************************************************************/

int	my_getnbr(char *str)
{
  int	sign;
  int	prev;
  int	nbr;

  sign = 1;
  while (*str && (*str < '0' || *str > '9'))
  {
    /**/ if (*str == '-')
      sign = -sign;
    else if (*str != '+')
      return (0);
    ++str;
  }
  nbr = 0;
  while (*str >= '0' && *str <= '9')
  {
    prev = nbr;
    nbr = nbr * 10 + sign * (*str - '0');
    if ((prev > 0 && nbr < 0) || (prev < 0 && nbr > 0))
      return (0);
    ++str;
  }
  return (nbr);
}

#ifdef MY_GETNBR

#include <stdio.h>

int	main(int ac, char const * const av[])
{
  if (ac > 1)
    printf("%d\n", my_getnbr(av[1]));
  else
  {
    printf("%d\n", my_getnbr("+---+--++---+---+---+-42"));
    printf("%d\n", my_getnbr("42a43"));
    printf("%d\n", my_getnbr("11000000000000000000000042"));
    printf("%d\n", my_getnbr("-1000000000000000000000042"));
    printf("%d\n", my_getnbr("2147483647"));
    printf("%d\n", my_getnbr("-2147483648"));
  }
  return (0);
}

#endif /* !MY_GETNBR */
