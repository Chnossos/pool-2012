/* *****************************************************************************
** Write a function that displays in the ascending order all the different
** combinations of three different digits.
**
** This gives something like that:
** "012, 013, ..., 023, ..., 789"
**
** 987 is not here vecause 789 is already there.
** 999 is not here because that number's digits are not all different.
**
** The function shall be prototyped as follows:
** int	my_aff_comb();
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

int my_aff_comb(void);

int	my_aff_comb()
{
  char	a;
  char	b;
  char	c;
  int	l;

  l = 0;
  a = '0' - 1;
  while (++a <= '7')
  {
    b = a;
    while (++b <= '8')
    {
      c = b;
      while (++c <= '9')
      {
	l += write(1, &a, 1);
	l += write(1, &b, 1);
	l += write(1, &c, 1);
	if (a != '7' || b != '8' || c != '9')
	  l += write(1, ", ", 2);
      }
    }
  }
  return (l);
}

#ifdef MY_AFF_COMB

int	main()
{
  my_aff_comb();
  return (0);
}

#endif /* !MY_AFF_COMB */
