#include <stdbool.h>
#include "my_getnbr.c"
#include "my_put_nbr.c"

static int	calculate(char operator, int nb1, int nb2)
{
  static bool	initialized = false;
  static char	const * const operators = "+-*/%";
  static int	(*operations[5])(int, int);
  int		i;

  if (!initialized)
  {
    operations[0] = ({ int f(int n1, int n2) { return (n1 + n2); } &f; });
    operations[1] = ({ int f(int n1, int n2) { return (n1 - n2); } &f; });
    operations[2] = ({ int f(int n1, int n2) { return (n1 * n2); } &f; });
    operations[3] = ({ int f(int n1, int n2) { return (n1 / n2); } &f; });
    operations[4] = ({ int f(int n1, int n2) { return (n1 % n2); } &f; });
    initialized = true;
  }
  i = 0;
  while (operators[i] && operators[i] != operator)
    ++i;
  return (operations[i](nb1, nb2));
}

static int	get_matching_parenthesis(char *expr)
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
  return (i);
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
      i = get_matching_parenthesis(expr + i);
  }
  if (operator)
    return (operator);
  i = -1;
  while (expr[++i])
  {
    if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
      return (expr + i);
    else if (expr[i] == '(')
      i = get_matching_parenthesis(expr + i);
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
      expr[get_matching_parenthesis(expr)] = '\0';
      return (evalexpr(++expr));
    }
    return (my_getnbr(expr));
  }
  else
  {
    operator = *operator_loc;
    *operator_loc = '\0';
    return (calculate(operator, evalexpr(expr), evalexpr(operator_loc + 1)));
  }
}

int	main(int ac, char *av[])
{
  if (ac > 1)
  {
    my_put_nbr(evalexpr(av[1]));
    my_putchar('\n');
  }
  return (0);
}
