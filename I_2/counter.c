#include <stdio.h>
#include <time.h>

int main() 
{
    time_t start, stop;

    start = time(NULL);

    for (int i = 0; i < 1000; i++)
        for (int j = 0; j < 1000; j++)
            for (int k = 0; k < 1000; k++);

    stop = time(NULL);

    printf("%ld", stop - start);

    return 0;
}
