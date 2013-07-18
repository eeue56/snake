#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


struct seg {
	int x;
	int y;
	struct seg *succ;
	int front;
	char dir;
};

struct snack {
	int x;
	int y;
	int points;
	bool shroom;
};

/*
*  A recursive function to create s simple linked list of type struct seg
*
*/
struct seg* initworm(int len, int y, int startx) {
	struct seg *n = (struct seg*) malloc(sizeof(struct seg));
	n->x = startx;
	n->y = y;
	n->front = 0;
	if(len>0) {
		if(len == 1){
			n->front = 1;
			n->dir = 'd';
		}else {
			n->succ = initworm(len-1, y, startx+1);
		}
	}
	return n;
}

/*
*  Deletes all nodes in the list starting with seg
*
*/
void delsegs(struct seg *first) {
	int front = 0;
	struct seg *ptr = first;
	struct seg *tmp;
	while(front ==0) {
		front = ptr->front;
		tmp = ptr->succ;
		free(ptr);
		ptr = tmp;
	}
}
