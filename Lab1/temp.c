#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(void) {
   time_t start, end;
   double elapsed;  // seconds
   start = time(0);
   end = time(100);
   int terminate = 1;
   while (terminate) {
     
     elapsed = difftime(end, start);
     if (elapsed >= 90.0 /* seconds */)
       terminate = 0;
     else{  // No need to sleep when 90.0 seconds elapsed.
       sleep(50000);
	printf("sleep");}
   }
   printf("done..\n");
   return 0;
 }
