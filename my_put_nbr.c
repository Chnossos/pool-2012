/* *****************************************************************************
** Write a function that displays a number given as parameter. The function must
** be able to displayer all the possibile values of an int.
**
** The function shall be prototyped as follows:
** int	my_put_nbr(int nb);
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include "my_putchar.c"

int	my_put_nbr(int nb);

/* WARNING: This works because the C MODULO operator IS NOT the
** same as the math MODULO operator. The C one is the remainder operator. */
int	my_put_nbr(int nb)
{
  int	length;

  length = 0;
  if (nb >= 10)
    length = my_put_nbr(nb / 10);
  else if (nb < 0)
  {
    length = my_putchar('-');
    if (nb <= -10)
      length += my_put_nbr(-(nb / 10));
    return (length + my_putchar('0' - nb % 10));
  }
  return (length + my_putchar('0' + nb % 10));
}

#ifdef MY_PUT_NBR

#include <limits.h>

int	main()
{
  /* Test the limits */
  my_put_nbr(INT_MIN);
  my_putchar('\n');
  my_put_nbr(INT_MAX);
  my_putchar('\n');
  /* Test single digits and 0 */
  my_put_nbr(1);
  my_putchar('\n');
  my_put_nbr(0);
  my_putchar('\n');
  my_put_nbr(-1);
  my_putchar('\n');
  return (0);
}

#endif /* !MY_PUT_NBR */
