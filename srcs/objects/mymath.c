#include "t_float.h"
#include <math.h>

t_float	mypow(t_float val, int time)
{
	t_float	rtn;

	rtn = 1;
	while (time)
	{
		rtn *= val;
		time--;
	}
	return (rtn);
}

t_float	find_small_solution(t_float sol1, t_float sol2)
{
	t_float	ignore;

	ignore = 0.001;
	if (sol1 > ignore && (sol1 < sol2 || sol2 < ignore))
		return (sol1);
	else if (sol2 > ignore && (sol2 < sol1 || sol1 < ignore))
		return (sol2);
	return (-1);
}

t_float	find_quadratic_formula(t_float a, t_float b, t_float c)
{
	t_float	discrim;
	t_float	sol1;
	t_float	sol2;

	discrim = b * b - 4.0 * a * c;
	if (discrim < 0)
		return (-1);
	sol1 = (-b + (t_float)sqrt(discrim)) / (2 * a);
	sol2 = (-b - (t_float)sqrt(discrim)) / (2 * a);
	return (find_small_solution(sol1, sol2));
}
