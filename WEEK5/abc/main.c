#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
void pprint(char *filename, char d1, char d2, char d3)
{

	filename[21] = d1;
	filename[22] = d2;
	filename[23] = d3;
	printf("<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Input Size %c%c%ck\n", d1, d2, d3);
	algorithm(filename);
}

int main(int argc, char const *argv[])
{

	char filename_sample[] = "session5_sort_ip1.txt";
	printf("<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("Sample Test Case\n");
	algorithm(filename_sample);
	char filename[] = "session5_sort_ip_rand032k.txt";
	pprint(filename, '0', '3', '2');

	printf("<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>\n");
}
