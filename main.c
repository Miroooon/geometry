#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	double x;
  	double y;
  	double r;
} Circle;

void print_circle(Circle *c);
int scan_errors(char *str, Circle *c);

int main() {
  	FILE *file;
  	file = fopen("c.txt", "r");
  	if (!file) {
    		printf("Can`t open file\n");
    		return -1;
  	}
  	char str[MAX];
  	Circle *c = (Circle *)malloc(sizeof(Circle));
  	while (!feof(file)) {
    		fgets(str, MAX, file);
    		if (scan_errors(str, c) == -1) {
      			return -1;
    		}
   		 print_circle(c);
  	}

  	fclose(file);
  	return 0;
}

int scan_errors(char *str, Circle *c) {
  	char circle[7] = "circle\0";
  	for (int i = 0; circle[i] != '\0'; i++) {
    		if (circle[i] != str[i]) {
      			printf("Name Error\n");
      			return -1;
    		}
  	}
  	char temp_x[MAX];
  	char temp_y[MAX];
  	char temp_r[MAX];
  	if (str[6] != '(') {
    		printf("Missing Bracket\n");
    		return -1;
  	}
  	if (str[7] < '0' || str[7] > '9') {
    		printf("Syntax Error\n");
    		return -1;
  	}
  	int i = 7;
 	for (int j = 0; str[i] != ' '; i++, j++) {
    		if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
      			printf("Coordinate Error\n");
      			return -1;
    		}
    		temp_x[j] = str[i];
  	}
  	c->x = atof(temp_x);
  	i++;
  	if (str[i] < '0' || str[i] > '9') {
    		printf("Syntax Error\n");
    		return -1;
  	}

  	for (int j = 0; str[i] != ','; i++, j++) {
    		if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
      			printf("Coordinate Error\n");
      			printf("%c\n", str[i]);
      			return -1;
    		}
    		temp_y[j] = str[i];
  	}
  	i += 2;
  	c->y = atof(temp_y);
  	if (str[i] < '0' || str[i] > '9') {
    		printf("Syntax Error\n");
    		return -1;
  	}

  	for (int j = 0; str[i] != ')'; i++, j++) {
    		if (str[i] == '\0') {
      			printf("Syntax Error\n");
      			return -1;
    		}
    		if ((str[i] < '0' || str[i] > '9') && str[i] != '.') {
      			printf("Coordinate Error\n");
      			return -1;
    		}
    		temp_r[j] = str[i];
  	}
  	c->r = atof(temp_r);
  	if (str[i] != ')') {
    		printf("Missing Bracket\n");
    		return -1;
  	}

  	return 0;
}

void print_circle(Circle *c) {
  	printf("circle(%f %f, %f)\n", c->x, c->y, c->r);
}
