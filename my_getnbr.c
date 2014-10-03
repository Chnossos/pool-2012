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

int	my_getnbr(char *str);

int	my_getnbr(char *str)
{
  int	sign;
  int	nbr;

  sign = 1;
  while (*str == '+' || *str == '-')
  {
    if (*str++ == '-')
      sign = -sign;
  }
  nbr = 0;
  while (*str >= '0' && *str <= '9')
  {
    if ((nbr * 10 + sign * (*str - '0')) / 10 != nbr)
      return (0);
    nbr = nbr * 10 + sign * (*str++ - '0');
  }
  return (nbr);
}

#ifdef MY_GETNBR

#include <assert.h>
#include <stdio.h>

int	main()
{
  assert(my_getnbr("+---+--++---+---+---+-42") == -42);
  assert(my_getnbr("42a43") == 42);
  assert(my_getnbr("11000000000000000000000042") == 0);
  assert(my_getnbr("-1000000000000000000000042") == 0);
  assert(my_getnbr("2147483647") == 2147483647);
  assert(my_getnbr("-2147483648") == -2147483648);
  assert(my_getnbr("0") == 0);
  puts("Everything is OK");
  return (0);
}

#endif /* !MY_GETNBR */
