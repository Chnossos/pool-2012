#include <stdio.h>
#include <stdlib.h>

static int	calculate(char operator, int nb1, int nb2)
{
  if (operator == '+')
    return (nb1 + nb2);
  else if (operator == '-')
    return (nb1 - nb2);
  else if (operator == '*')
    return (nb1 * nb2);
  else if (operator == '/')
    return (nb1 / nb2);
  else
    return (nb1 % nb2);
}

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

static char	*find_next_operator(char *expr)
{
  char		*operator;
  int		i;

  operator = NULL;
  i = -1;
  while (expr[++i])
  {
    if (expr[i] == '+' || expr[i] == '-')
      operator = expr + i;
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr) - expr - 1;
  }
  if (operator)
    return (operator);
  i = -1;
  while (expr[++i])
  {
    if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
      return (expr + i);
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr) - expr - 1;
  }
  return (NULL);
}

static int	evalexpr(char *expr)
{
  char		*operator_loc;
  char		operator;

  if (*expr == ' ')
    return (evalexpr(expr + 1));
  if (!(operator_loc = find_next_operator(expr)))
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
    operator = *operator_loc;
    *operator_loc = '\0';
    return (calculate(operator, evalexpr(expr), evalexpr(operator_loc + 1)));
  }
}

int	main(int ac __attribute__((unused)), char *av[])
{
  printf("%d\n", evalexpr(av[1]));
  return (0);
}
