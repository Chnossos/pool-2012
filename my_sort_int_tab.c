/* *****************************************************************************
** Write a function that sort a table made of integers in ascending order.
**
** The parameters are: a pointer to integer and the number of integers in the
** table.
**
** void	my_sort_int_tab(int *tab, int size);
** ****************************************************************************/

void	my_sort_int_tab(int *tab, int size);

void	my_sort_int_tab(int *tab, int size)
{
  int	number;
  int	i;
  int	j;

  i = -1;
  while (++i < size)
  {
    j = i;
    while (++j < size)
    {
      if (tab[j] < tab[i])
      {
	number = tab[i];
	tab[i] = tab[j];
	tab[j] = number;
      }
    }
  }
}

#ifdef MY_SORT_INT_TAB

#include <stdio.h>

int	main()
{
  int	tab[] = { -42, 21, 0, 42, -21 };
  int	tab2[] = { -42, -21, 0, 21, 42 };
  int	i;

  my_sort_int_tab(tab, 5);
  for (i = 0 ; i < 5 ; ++i)
    printf("%d%s", tab[i], (i + 1 < 5 ? ", " : "\n"));
  my_sort_int_tab(tab2, 5);
  for (i = 0 ; i < 5 ; ++i)
    printf("%d%s", tab2[i], (i + 1 < 5 ? ", " : "\n"));
  return (0);
}

#endif /* !MY_SORT_INT_TAB */
