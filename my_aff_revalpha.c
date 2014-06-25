/* *****************************************************************************
** Write a function that displays the alphabet in lowercase on a single line, in
** descending order from the letter 'z'.
**
** The function shall be prototyped as follows:
**
** int	my_aff_revalpha();
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include <unistd.h>

int	my_aff_revalpha()
{
  char	c;
  int	l;

  l = 0
  c = 'z';
  while (c-- >= 'a')
    l += write(1, &c, 1);
  return (l);
}

int	my_aff_revalpha_smart()
{
  return (write(1, "zyxwvutsrqponmlkjihgfedcba", 26));
}

#ifdef MY_AFF_REVALPHA

int	main()
{
  my_aff_revalpha();
  return (0);
}

#endif /* !MY_AFF_REVALPHA */
