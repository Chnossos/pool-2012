/* *****************************************************************************
** Write a function that displays all digits in a single line,
** in the ascending order.
**
** The function shall be prototyped as follows:
**
** int	my_aff_chiffre();
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include <unistd.h>

int	my_aff_chiffre(void);

int	my_aff_chiffre()
{
  char	c;
  int	l;

  l = 0;
  c = '0' - 1;
  while (++c <= '9')
    l += write(1, &c, 1);
  return (l);
}

int	my_aff_chiffre_smart(void);

int	my_aff_chiffre_smart()
{
  return ((int)write(1, "0123456789", 10));
}

#ifdef MY_AFF_CHIFFRE

int	main()
{
  my_aff_chiffre();
  return (0);
}

#endif /* !MY_AFF_CHIFFRE */
