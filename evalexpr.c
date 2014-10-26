#include <stdio.h>
#include <stdlib.h>

static int	my_add(int nb1, int nb2)
{
  return (nb1 + nb2);
}

static int	my_sub(int nb1, int nb2)
{
  return (nb1 - nb2);
}

static int	my_mul(int nb1, int nb2)
{
  return (nb1 * nb2);
}

static int	my_div(int nb1, int nb2)
{
  return (nb1 / nb2);
}

static int	my_mod(int nb1, int nb2)
{
  return (nb1 % nb2);
}

static int	(*g_operations[])(int, int) =
{
  &my_add,
  &my_sub,
  &my_mul,
  &my_div,
  &my_mod
};

static char	*get_matching_parenthesis(char *expr)
{
  int		lvl;
  int		i;

  lvl = 1;
  i = 0;
  while (expr[++i] && lvl > 0)
  {
    if (expr[i] == '(')
      ++lvl;
    else if (expr[i] == ')')
      --lvl;
  }
  return (expr + i);
}

static int	index_of(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != c)
    ++i;
  return (str[i] ? i : -1);
}

static char	*find_next_operator(char *expr)
{
  char		*operator;
  int		i;

  operator = NULL;
  i = -1;
  while (expr[++i])
  {
    if (index_of("+-", expr[i]) != -1)
      operator = expr + i;
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr) - expr - 1;
  }
  if (operator)
    return (operator);
  i = -1;
  while (expr[++i])
  {
    if (index_of("*/%", expr[i]) != -1)
      return (expr + i);
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr) - expr - 1;
  }
  return (NULL);
}

static int	evalexpr(char *expr)
{
  char		*operator;
  int		(*operation)(int, int);
  int		sign;

  if (*expr == ' ')
    return (evalexpr(expr + 1));
  if (!(operator = find_next_operator(expr)))
  {
    if (*expr == '(')
    {
      *get_matching_parenthesis(expr) = '\0';
      return (evalexpr(++expr));
    }
    return (atoi(expr));
  }
  else
  {
    operation = g_operations[index_of("+-*/%", *operator)];
    *operator = '\0';
    sign = (operator > expr && *(operator - 1) == '-') ? -1 : 1;
    return (operation(evalexpr(expr), evalexpr(operator + 1)) * sign);
  }
}

int	main(int ac __attribute__((unused)), char *av[])
{
  printf("%d\n", evalexpr(av[1]));
  return (0);
}
