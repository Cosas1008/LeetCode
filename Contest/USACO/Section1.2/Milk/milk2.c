/*
ID: yuweiic1
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 255
char line[MAXLINE];

struct milking{
	int start;
	int end;
};

typedef struct milking milk;

/*
// qsort
// https://stackoverflow.com/questions/1787996/c-library-function-to-do-sort
*/

int comp(const void * element1, const void * element2)
{
	milk first = *((milk*)element1);
	milk second = *((milk*)element2);
	if(first.start > second.start){
		return 1;
	}else{
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	FILE* fin, *fout;
	fin = fopen("milk2.in", "r");
	int t_start, t_end, n, i;
	fgets(line, MAXLINE, fin);
	sscanf(line, "%d",&n);
	milk list[n];
	for(i = 0; i < n; i++){
		fgets(line, MAXLINE, fin);
		sscanf(line, "%d %d",&t_start, &t_end);
		list[i].start = t_start;
		list[i].end = t_end;
	}
	fclose(fin);
	// sorting list(struct milk) according to the start time
	qsort(list,sizeof(list)/sizeof(*list), sizeof(milk), comp);

	// calculate the time interval for milk/not-milk
	int cs = 0, ce = 0, m_milk = 0, m_nmilk = 0, interval;
	cs = list[0].start;
	ce = list[0].end;
	for(i =0; i < n; i++){
		int s = list[i].start;
		int e = list[i].end;
		//printf("S: %4d; E: %4d\n", s, e);	// debug
		if(s > ce){
			interval = s - ce; // start time - current end_milk time
			if(interval > m_nmilk){
				m_nmilk = interval;
			}
			cs = s;
			ce = e;
		}else if(e > ce){
			ce = e; // current end_milk time postoned to end time
		}
		interval = ce - cs;
		if(interval > m_milk){
			m_milk = interval;
		}

	}
	fout = fopen("milk2.out","w");
	fprintf(fout,"%d %d\n", m_milk, m_nmilk);
	fclose(fout);
	return 0;
}