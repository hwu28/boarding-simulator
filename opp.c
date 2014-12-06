#include "fsim.h"

int n = R*S;
st getst(void)
{
	st s = inv;
	if (!n)
		return inv;
	n--, s.r = R-1-n/S, s.s = n%S, s.v = 1;
	return s;
}
