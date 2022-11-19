/* *****************************************************************************
** Write a function that displays the alphabet in lowercase on a single line, in
** ascending order from the letter 'a'.
**
** The function shall be prototyped as follows:
**
** int	my_aff_alpha();
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

int	my_aff_alpha(void);
int	my_aff_alpha_smart(void);

int	my_aff_alpha()
{
  char	c;
  int	l;

  l = 0;
  c = 'a' - 1;
  while (++c <= 'z')
    l += write(1, &c, 1);
  return (l);
}

int	my_aff_alpha_smart()
{
  return ((int)write(1, "abcdefghijklmnopqrstuvwxyz", 26));
}

#ifdef MY_AFF_ALPHA

int	main()
{
  my_aff_alpha();
  return (0);
}

#endif /* !MY_AFF_ALPHA */
