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
#include <math.h>		// for fabs, sqrtf and logf
#include <ctype.h>		// for tolower
#include <assert.h>		// for assert

/**
 * @brief Produces better approximations of the root of a.
 *
 * @details Assigns the absolute value of the a parameter to itself. Inside
 * the loop, assigns the next approximation to x_nplus1. If the absolute
 * difference between the next approximation and the current is less than
 * or equal to the diff parameter, or if the number of iterations is greater
 * than the logarithm of the a paramater multiplied by 20, the for loop breaks.
 * Else, the value of x_nplus1 gets assigned to x_n and the loop continues.
 * If the visualize parameter is 1 (true), each approximation is printed.
 *
 *
 * @param a the positive value to find the approximate root of
 *
 * @param diff the maximum deviation to be accepted
 * 
 * @param visualize whether the user chose to visualize the process
 *
 *
 * @returns the best approximation of the root
 */
double newtons_method(double a, double diff, int visualize)
{
    a = fabs(a);

    double x_n = a;
    double x_nplus1;
    
    int i;

	if (visualize) printf("Start of approximations\n");

    for (i = 1; 1; i++)
    {
		if (visualize) printf("x_%d: %.12lf\n", i - 1, x_n);
		
        x_nplus1 = 0.5 * (x_n + a / x_n);

        if (i > logf(a) * 20 || fabs(x_nplus1 - x_n) <= diff) break;

        x_n = x_nplus1;
    }
    
    if (visualize) printf("Final approximation (x_%d): %.12lf\n\n", i, x_nplus1);

    return x_nplus1;
}
/**
 * @brief Tests if the implementation is within an acceptable range.
 *
 * @details Checks if the absolute difference between the return value
 * of newtons_method and the square root is less than or equal to the
 * passed deviation tolerance.
 * 
 * 
 * @param test[] an array containing two values; the first is the number to
 * get the root of and the second is the maximum deviation to be accepted
 * 
 * @param visualize whether the user chose to visualize the process
 *
 *
 * @returns whether the aforementioned check is true
 */
int individual_test(double test[], int visualize)
{
    return fabs(newtons_method(test[0], test[1], visualize) - sqrtf(fabs(test[0]))) <= test[1];
}

/**
 * @brief Tests a given number of values.
 * 
 * @details Iterates through the tests[] array and passes each element to 
 * individual_test(). If the visualize parameter is 1 (true), the current test,
 * the number to take the root of and the accepted deviation are printed.
 * 
 * 
 * @param visualize whether the user chose to visualize the process
 *
 *
 * @returns void
 */
void test(int visualize)
{
	double test1[] = {625, 0.1};
    double test2[] = {2, 0.001};
    double test3[] = {1024, 0};
    double test4[] = {-25, 0};
    
    double *tests[] = {test1, test2, test3, test4};
    
	int tests_num = 4;
	
	for (int i = 0; i < tests_num; i++)
	{
		if (visualize)
		{
			printf("------------\n");
			printf("Test %d\n", i + 1);
			printf("a: %.12lf\n", tests[i][0]);
			printf("Precision: %.12lf\n\n", tests[i][1]);
		}
		
	    assert(individual_test(tests[i], visualize));
	    printf("Test %d OK\n", i + 1);
	    
		if (visualize) printf("\n");
	}
}

/**
 * @brief asks if the user would like to visualize 
 * then calls the test() function
 *
 *
 * @returns 0 if all tests passed
 */
int main(void)
{
	int visualize = 0;
	
	printf("Would you like to see the process? (y/N) - ");
	if (tolower(getchar()) == 'y') visualize = 1;
	printf("\n");
	
	test(visualize);

    return 0;
}
