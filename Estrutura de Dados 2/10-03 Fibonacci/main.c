#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint64_t fib(int n)
{
    if(n <= 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

uint64_t ffib_(int n, uint64_t* mem)
{
    if(mem[n] != 0)
        return mem[n];
    uint64_t e, d;
    e = ffib_(n-1, mem);
    d = ffib_(n-2, mem);
    mem[n] = e + d;
    return e + d;
}

uint64_t ffib(int n)
{
    uint64_t* mem;
    mem = calloc(n+1, sizeof(uint64_t));
    mem[0] = 1;
    mem[1] = 1;

    uint64_t res = ffib_(n, mem);
    free(mem);
    return res;
}

int main(int argc, char** argv)
{
    int n;
    n = atoi(argv[1]);
    printf("f(%ld) = %ld\n",n, ffib(n));
    return EXIT_SUCCESS;
}