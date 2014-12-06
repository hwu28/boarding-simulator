#include "fsim.h"
#include <stdlib.h>
#include <time.h>

int n = R*S;
int used[R*S] = {0};
int seed, hs = 0, ut = 1;
int getr(int lim)
{
	int gmax = ((((long)RAND_MAX)+1)/lim)*lim-1, r;
	if (!hs)
	{
		if (ut)
			seed = time((void *)0);
		srand(seed);
	}
	while ((r = rand()) > gmax);
	return r%lim;
}
st getst(void)
{
	st s = inv;
	if (!n)
		return inv;
	int p = getr(n), i = -1;
	while (p--)
	{
		i++;
		while (used[i])
			i++;
	}
	used[i] = 1;
	n--, s.r = i/S, s.s = i%S, s.v = 1;
	return s;
}
