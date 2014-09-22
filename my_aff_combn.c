/* *****************************************************************************
** Write a function that displays all the combinations of n digit(s), in the
** ascending order.
**
** If n = 2, it shall display something like:
** "01, 02, 03, ..., 09, 12, ..., 79, 89"
**
** The function shall be prototyped as follows:
** int	my_aff_combn(int n);
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include <stdbool.h>
#include <stdlib.h>
#include "my_put_nbr.c"

int my_aff_combn(int n);

static int	first(int n)
{
  if (n == 1)
    return (0);
  return first(n - 1) * 10 + n - 1;
}

static int	last(int n)
{
  int	nbr;

  nbr = 0;
  while (n)
    nbr = nbr * 10 + (10 - n--);
  return (nbr);
}

static int	print(int nbr, int n)
{
  int	count;
  int	tmp;
  int	l;

  l = 0;
  tmp = nbr;
  count = (nbr == 0 ? 1 : 0);
  while (tmp)
  {
    ++count;
    tmp /= 10;
  }
  if (count < n)
    l += write(1, "0", 1);
  return (l + my_put_nbr(nbr));
}

static bool	is_valid(int nbr)
{
  if (nbr < 10)
    return (true);
  return ((nbr % 10) > ((nbr / 10) % 10) && is_valid(nbr / 10));
}

int	my_aff_combn(int n)
{
  int	beg;
  int	end;
  int	l;

  l = 0;
  if (n >= 1 && n <= 10)
  {
    beg = first(n);
    end = last(n);
    l += print(beg, n);
    while (++beg <= end)
    {
      if (is_valid(beg))
      {
	l += write(1, ", ", 2);
	l += print(beg, n);
      }
    }
  }
  return (l);
}

#ifdef MY_AFF_COMBN

int	main(int ac, char const * const av[])
{
  if (ac > 1)
    return (my_aff_combn(atoi(av[1])));
  return (1);
}

#endif /* !MY_AFF_COMBN */
