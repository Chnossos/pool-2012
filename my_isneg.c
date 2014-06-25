/* *****************************************************************************
** Write a function displays 'N' or 'P' depending on the sign of the integer
** passed as parameter. if n is negative, display 'N', otherwise, if n is
** positive or null then display 'P'.
**
** The function shall be prototyped as follows:
** int	my_isneg(int n);
**
** Additional rule:
** The function shall return the number of characters printed out.
** ****************************************************************************/

#include <unistd.h>

int	my_isneg(int n)
{
  return (write(1, n < 0 ? "N" : "P", 1));
}

#ifdef MY_ISNEG

int	main()
{
  write(1, "my_isneg(0) = ", 14);
  my_isneg(0);
  write(1, "\nmy_isneg(1) = ", 15);
  my_isneg(1);
  write(1, "\nmy_isneg(-1) = ", 16);
  my_isneg(-1);
  write(1, "\n", 1);
  return (0);
}

#endif /* !MY_ISNEG */
