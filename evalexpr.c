#include "my_getnbr.c"
#include "my_put_nbr.c"

#if defined(__GNUC__) && !defined(__clang__)

#include <stdbool.h>

static int	calculate(char operator, int nb1, int nb2)
{
  static bool	initialized = false;
  static char	const * const operators = "+-*/%";
  static int	(*ops[5])(int, int);
  int		i;

  if (!initialized)
  {
    ops[0] = __extension__({ int f(int n1, int n2) { return (n1 + n2); } &f; });
    ops[1] = __extension__({ int f(int n1, int n2) { return (n1 - n2); } &f; });
    ops[2] = __extension__({ int f(int n1, int n2) { return (n1 * n2); } &f; });
    ops[3] = __extension__({ int f(int n1, int n2) { return (n1 / n2); } &f; });
    ops[4] = __extension__({ int f(int n1, int n2) { return (n1 % n2); } &f; });
    initialized = true;
  }
  i = 0;
  while (operators[i] && operators[i] != operator)
    ++i;
  return (ops[i](nb1, nb2));
}

#else

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

#endif

static int	get_matching_parenthesis(char *expr)
{
  int		lvl;
  int		i;

  lvl = 1;
  i = 0;
  while (lvl > 0 && expr[++i])
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
  char		*op;
  int		i;

  op = NULL;
  i = -1;
  while (expr[++i])
    if (expr[i] == '+' || expr[i] == '-')
      op = expr + i;
    else if (expr[i] == '(')
      i = get_matching_parenthesis(expr + i);
  if (op)
  {
    while (op > expr && (*(op - 1) == '+' || *(op - 1) == '-'))
      --op;
    return (op);
  }
  i = -1;
  while (expr[++i])
    if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
      return (expr + i);
    else if (expr[i] == '(')
      i = get_matching_parenthesis(expr + i);
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
    if (operator_loc == expr)
      return (calculate(operator, evalexpr(expr), my_getnbr(operator_loc + 1)));
    else
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
