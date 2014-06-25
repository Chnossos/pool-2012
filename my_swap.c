/* *****************************************************************************
** Write a function that swaps the contents of two integers whose adresses are
** given as parameters.
**
** It will be prototyped as follows:
** int	my_swap(int *a, int *b);
** ****************************************************************************/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *b = *a;
  *a = tmp;
  return (0);
}
