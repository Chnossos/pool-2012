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
**
** Additional rules (added as a challenge by myself):
** 	- Expressions like "-1" or "--2" or "4+-+-5" must be handled.
** 	- Any amount of spaces around operands must be handled.
** ****************************************************************************/

#include "my_getnbr.c"

/* No need to include the whole <stdlib.h> just for this ... */
#ifndef NULL
# define NULL (void *)0
#endif

#if !defined(__GNUC__) || defined(__clang__)

/* Basic version with a classic repeated if-else construction, no fun ... */

static int	calculate(char op, int nb1, int nb2)
{
  if (op == '+')
    return (nb1 + nb2);
  else if (op == '-')
    return (nb1 - nb2);
  else if (op == '*')
    return (nb1 * nb2);
  else if (op == '/')
    return (nb1 / nb2);
  else
    return (nb1 % nb2);
}

#else

/* *****************************************************************************
** Toying with GCC "lambda" extension :P
** Does that still count as less than 5 functions in the same file ? Dunno.
** Sadly, the address of these lambda functions are not constant, so we cannot
** initialize the function pointer array at declaration, thus a fallback to a
** classic static boolean flag.
** ****************************************************************************/

#include <stdbool.h>

static int			calculate(char op, int nb1, int nb2)
{
  static char const * const	operators = "+-*/%";
  static bool			initialized = false;
  static int			(*ops[5])(int, int);
  int				i;

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
  while (operators[i] && operators[i] != op)
    ++i;
  return (ops[i](nb1, nb2));
}

#endif

/**
 * Takes a valid expression beginning with an opening parenthesis and returns
 * the index of its matching closing parenthesis.
 *
 * Any sub-level of matching parentheses is ignored.
 *
 * (1 * (2 + 3) * 2)
 * ^---------------^
 *
 * @param expr
 * 	The string containing the expression to be parsed.
 * @return
 * 	The index of the closing parenthesis matching the first parenthesis.
 */
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

/**
 * Finds the next splitting point of the expression.
 *
 * First looks for the last + or - operator, skipping any sub-expression
 * surrounded by matching paentheses. If no such operator is found, then looks
 * for the first *, / or % operator. If no operator is found at all, returns
 * @c NULL.
 *
 * @param expr
 * 	The string containing the expression to be parsed.
 * @return
 * 	A pointer to the splitting point in the expression, or NULL if none is
 * 	found.
 */
static char	*find_next_operator(char *expr)
{
  char		*op;
  int		i;

  op = NULL;
  i = -1;
  while (expr[++i])
  {
    if (expr[i] == '(')
      i += get_matching_parenthesis(expr + i);
    else if (expr[i] == '+' || expr[i] == '-')
      op = expr + i;
  }
  i = -1;
  while (!op && expr[++i])
  {
    if (expr[i] == '(')
      i += get_matching_parenthesis(expr + i);
    else if (expr[i] == '*' || expr[i] == '/' || expr[i] == '%')
      op = expr + i;
  }
  return (op);
}

/**
 * Evaluates a valid mathematical expression recursively and returns the result.
 *
 * First tries to find a top-level operator in order to split the expression.
 * A top-level operator is an operator that is outside of any expression
 * surrounded by matching parentheses.
 *
 * If such an operator cannot be found, and the expression begins with an
 * opening parenthesis (all spaces are skipped in the parsing process), then
 * removes the parentheses and start a new evaluation with the sub-expression.
 *
 * If no parenthesis is found, then the whole expression is actually a number.
 *
 * If a + or - operator has been found, we check there is more right before it
 * to handle expressions such as "-+-2" or "1 * --2", and the process continue
 * as described below with other operators.
 *
 * If a *, / or % operator has been found, it is removed and an evaluation of
 * the two surrounding expressions begin, whose results are used as operands to
 * the calculation with the previously found operator.
 *
 * @param expr
 * 	The string containing the expression to be parsed.
 * @return
 * 	The result of the evaluation.
 */
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
    while (op_loc > expr && (*(op_loc - 1) == '+' ||
			     *(op_loc - 1) == '-' || *(op_loc - 1) == ' '))
      --op_loc;
    while (*op_loc == ' ')
      ++op_loc;
    if (op_loc > expr)
    {
      op = *op_loc;
      *op_loc = '\0';
      return (calculate(op, eval_expr(expr), eval_expr(op_loc + 1)));
    }
  }
  return (my_getnbr(expr));
}

#ifdef EVALEXPR

#include "my_put_nbr.c"

int	main(int ac, char *av[])
{
  if (ac > 1)
  {
    my_put_nbr(eval_expr(av[1]));
    my_putchar('\n');
  }
  return (0);
}

#endif /* !EVALEXPR */
