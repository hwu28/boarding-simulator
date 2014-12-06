#ifndef FSIM_H
#define FSIM_H

#define R 40
#define S 6

typedef struct st { //structure for each passenger
	int r; //row number
	int s; //seat position
	int v; //is this person valid / are they still waiting
	int t; //it takes time to put luggage in the overhead bins
	int f; //about to finish
} st;
static st inv = {0};
static int eq(st a, st b)
{
	return !(a.r-b.r || a.s-b.s || a.v-b.v || a.t-b.t || a.f-b.f);
}

extern st getst(void);

#endif
