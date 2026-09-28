/**
 * @file
 * 
 * 
 * @brief The [Newton-Raphson method](https://en.wikipedia.org/wiki/Newton%27s_method)
 * is a root-finding algorithm which successively produces better
 * approximations to the roots of a real-valued function.
 * 
 * 
 * @author [Andrey Gonçalves Barreto Isidoro](https://github.com/agbi623)
 */

#include <stdio.h> 		// for Input/Output
#include <math.h>		// for fabs, sqrtf and log
#include <assert.h>		// for assert

/**
 * @brief Produces better approximations of the root of a.
 * 
 * @details Assigns the next approximation to x_nplus1. If the absolute
 * difference between the next approximation and the current is less than
 * or equal to the provided diff parameter, or if the number of iterations is
 * greater than the logarithm of the a paramater multiplied by 20, 
 * the for loop breaks. Else, the value of x_nplus1 gets assigned to x_n and 
 * the loop continues.
 * 
 * 
 * @param a the value to find the approximate root of
 * 
 * @param diff the maximum deviation to be accepted
 * 
 * 
 * @returns the best approximation of the root
 */
float newtons_method(float a, float diff)
{
    float x_n = a;
    float x_nplus1;

    for (int i = 1; 1; i++)
    {
        x_nplus1 = 0.5 * (x_n + a / x_n);

        if (i > log(a) * 20 || fabs(x_nplus1 - x_n) <= diff) break;

        x_n = x_nplus1;
    }

    return x_nplus1;
}
/**
 * @brief Tests if the implementation is within an acceptable range.
 * 
 * @details Checks if the absolute difference between the return value of
 * newtons_method and the square root is less than or equal to the passed
 * range.
 * 
 * 
 * @param test[] an array containing two values; the first is the number to
 * get the root of and the second is the maximum deviation to be accepted
 * 
 * 
 * @returns whether the aformentioned check is true
 */
int individual_test(float test[])
{
    return fabs(newtons_method(test[0], test[1]) - sqrtf(test[0])) <= test[1];
}

/**
 * @brief passes and asserts some tests to the individual_test() function
 * 
 * 
 * @returns void
 */
void test(void)
{
	float test1[] = {625, 0.1};
    float test2[] = {2, 0.001};
    float test3[] = {1024, 0};

    assert(individual_test(test1));
    printf("Test 1 OK\n");

    assert(individual_test(test2));
    printf("Test 2 OK\n");
    
    assert(individual_test(test3));
    printf("Test 3 OK\n");
}

/**
 * @brief calls the test() function
 * 
 * 
 * @returns 0 if all tests passed
 */
int main(void)
{
    test();

    return 0;
}
