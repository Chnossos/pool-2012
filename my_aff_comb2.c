/* *****************************************************************************
** Write a function that displays all the different combinations of two numbers
** between 0 and 99, in the ascending order.
**
** This gives something like that:
** "00 01, 00 02, ..., 01 99, 02 03, ..., 98 99"
**
** The function shall be prototyped as follows:
** int	my_aff_comb2();
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include "my_putchar.c"

int my_aff_comb2(void);

int	my_aff_comb2()
{
  int	nb1;
  int	nb2;
  int	l;

  l = 0;
  nb1 = -1;
  while (++nb1 <= 98)
  {
    nb2 = nb1;
    while (++nb2 <= 99)
    {
      l += my_putchar('0' + nb1 / 10);
      l += my_putchar('0' + nb1 % 10);
      l += my_putchar(' ');
      l += my_putchar('0' + nb2 / 10);
      l += my_putchar('0' + nb2 % 10);
      if (nb1 != 98 || nb2 != 99)
	l += write(1, ", ", 2);
    }
  }
  return (l);
}

#ifdef MY_AFF_COMB2

int	main()
{
  my_aff_comb2();
  return (0);
}

#endif /* !MY_AFF_COMB2 */
