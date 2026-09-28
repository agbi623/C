#include <stdio.h>
#include <math.h>
#include <assert.h>

float newtons_method(float a, float diff)
{
    float x_n = a;
    float x_nplus1;

    for (int i = 1; i <= log(a) * 20; i++)
    {
        x_nplus1 = 0.5 * (x_n + a / x_n);

        if (fabs(x_nplus1 - x_n) <= diff) break;

        x_n = x_nplus1;
    }

    return x_nplus1;
}

int test(float test[])
{
    return fabs(newtons_method(test[0], test[1]) - sqrtf(test[0])) <= test[1];
}

int main(void)
{
    float test1[] = {625, 0.1};
    float test2[] = {2, 0.001};
    float test3[] = {1024, 0};

    assert(test(test1));
    printf("Test 1 OK\n");

    assert(test(test2));
    printf("Test 2 OK\n");
    
    assert(test(test3));
    printf("Test 3 OK\n");

    return 0;
}
