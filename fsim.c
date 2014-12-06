#include <stdio.h>
#include "fsim.h"

#define dl 200000

int t = 0, cs = 1, cp = 8; //time, cost of step, cost of putting luggage away
int in = 0;

st q[R] = {{0}}; //current queue in the aisle
int state[R][S] = {{0}}; //state of each seat; just a boolean, so we can use a char

void step(int i) //can the ith passenger move?
{
	if (!q[i].v)
		return;
	if (q[i].t)
		q[i].t--;
	else if (q[i].r == i)
	{
		if (q[i].f)
			state[q[i].r][q[i].s] = 1, q[i] = inv;
		else
			q[i].t = cp, q[i].f = 1;
	}
	else if (!q[i+1].v)
		q[i+1] = q[i], q[i] = inv, q[i+1].t = cs;
	/*else wait*/
}
int ahead() //updates each passenger; moves forward one tick
{
	int i;
	for (i = R-1; i >= 0; i--)
		step(i);
	in = 0;
	for (i = 0; i < R; i++)
		if (!eq(q[i], inv))
			in++;
	if (eq(q[0], inv))
	{
		q[0] = getst(); //getst() gets the st structure for the next passenger
		if (eq(q[0], inv) && !in)
			return 0;
	}
	t++;
	return 1;
}
void viz()
{
	printf("\e[H\e[2J");
	int s, r;
	for (s = 0; s < S; s++)
	{
		if (s == S/2)
		{
			for (r = 0; r < R; r++)
			{
				char c;
				if (!q[r].v)	c = '=';
				else if (q[r].f)c = 'X';
				else		c = '@';
				putchar(c);
			}
			puts("");
		}
		for (r = 0; r < R; r++)
			putchar(state[r][s] ? '#' : '.');
		puts("");
	}
	usleep(dl);
}
int main(int argv, char **argc) //call with --viz for visualization
{
	int doviz = 0;
	if (argv > 1)
		doviz = !strcmp("--viz", argc[1]);
	do if (doviz)
		viz();
	while (ahead());
	printf("%d\n", t);
	return 0;
}
