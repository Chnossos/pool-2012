/* *****************************************************************************
** The purpose is to write the eval_expr function.
**
** It must be prototyped like this:
** int  eval_expr(char *str);
**
** This function takes a character string as parameter that represents an
** arethmetical expression. Example: "3 + 42 * (1 - 2 / (3 + 4) - 1 % 21) + 1"
**
** This expression will have to be calculated, and the result returned as return
** value by the function.
**
** The string that you will receive will be valid (no bugs, no bad address, no
** letter nor syntax error, no division by zero...).
**
** The 5 operators must be supported:
**   + for addition
**   - for substraction
**   * for multiplication
**   / for division
**   % for modulo
**
** The functions also has to handle any number of parenthesises.
*
** Additional rule: Expressions like "-1" or "--2" or "4+-+-5" must be handled.
** ****************************************************************************/

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
  {
    if (expr[i] == '+' || expr[i] == '-')
      op = expr + i;
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr + i);
  }
  i = -1;
  while (!op && expr[++i])
  {
    if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
      op = expr + i;
    else if (expr[i] == '(')
      i += get_matching_parenthesis(expr + i);
  }
  return (op);
}

static int	eval_expr(char *expr)
{
  char		*op_loc;
  char		op;

  while (*expr == ' ')
    ++expr;
  if (!(op_loc = find_next_operator(expr)) && *expr == '(')
  {
      expr[get_matching_parenthesis(expr)] = '\0';
      return (eval_expr(++expr));
  }
  else if (op_loc)
  {
    while (op_loc > expr &&
	   (*(op_loc - 1) == '+' || *(op_loc - 1) == '-' || *(op_loc - 1) == ' '))
      --op_loc;
    while (*op_loc == ' ')
      ++op_loc;
    if (op_loc != expr)
    {
      op = *op_loc;
      *op_loc = '\0';
      return (calculate(op, eval_expr(expr), eval_expr(op_loc + 1)));
    }
  }
  return (my_getnbr(expr));
}

int	main(int ac, char *av[])
{
  if (ac > 1)
  {
    my_put_nbr(eval_expr(av[1]));
    my_putchar('\n');
  }
  return (0);
}
