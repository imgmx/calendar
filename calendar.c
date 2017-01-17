// A program which shows 'hello, world' on my screen
#include <stdio.h>
#include <time.h>
void calendar();
int is_leap_year(int y, int m);
int month_last_day(int y, int m);
int week_of_day(int y, int m);


int main(void) {
	
	calendar();

	return 0;
}


void calendar() {
	
	int i; 
	int w, last_day;
	int y, m, d;
	
	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	
	y = timeinfo->tm_year + 1900;
	m = timeinfo->tm_mon + 1;
	d = timeinfo->tm_mday;
	
	w = week_of_day(y, m);
	last_day = month_last_day(y, m);
	
	printf("	 %d / %d		\n", y, m);
	printf("Sun Mon Tue Wed Thr Fri Sat \n");
	printf("---------------------------\n");
	
	for (i = 1; i <= w; i++) {
		printf("    ");	
	}  

	for (i = 1; i <= last_day; i++) {
		if (i == d) {
			printf("(%d)", i);
		} else {
			printf("%3d ", i);
		}
		if ((i + w) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
}

int month_last_day (int y, int m) {
	
	int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int last_day, i = m - 1;
	
	if(m == 2) {
		last_day = months[i] + is_leap_year(y, m);
	} else {
		last_day = months[i];
	}
	
	return last_day;
}

int is_leap_year(int y, int m) {
	
	int rc = 0;
	
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		rc = 1;
	}
	return rc;
}

int week_of_day (int y, int m) {
	
	int day;
	
	if (m <= 2) {
		y -= 1;
		m += 12;
	}
	
	day = (5 * y / 4 - y / 100 + y / 400 + ( 26 * m + 16) / 10 + 1) % 7;
	
	return day;
}


	