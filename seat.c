#include "fsim.h"

int n = R*S;
st getst(void)
{
	st s = inv;
	if (!n)
		return inv;
	n--, s.r = n%R, s.s = n/R, s.v = 1;
	return s;
}
