#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Hello World!\n");
	printf("PID A: %d\n", (int)getpid());
	return (0);
}
