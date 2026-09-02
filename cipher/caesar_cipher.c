/**
 * @file
 * @brief A [caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) is a 
 * substitution cipher that replaces each letter in a text by another located 
 *  a given number of positions along the alphabet.
 * @author [Andrey Gonçalves Barreto Isidoro](https://github.com/agbi623)
 */

#include <string.h>  /// for strcmp
#include <stdio.h>   /// for Input/Output
#include <ctype.h>   /// for isalpha, isupper and islower
#include <assert.h>  /// for assert

#define MAX_STRING_LENGTH 99  // max length of a string or a char *

/*
 * @brief calculates the encrypted char for the encryption
 * @param c the character to be used
 * @param key the key to be used
 * @returns the encrypted char
 */
int calculate_offset(char c, int key)
{
	int new_c;
	
	// calculates the offset based on the character's case
	if (isupper(c))
	{
		new_c = (((int)c - 'A') + key) % 26;
	}
	else
	{
		new_c = (((int)c - 'a') + key) % 26;
	}
	
	if (new_c < 0) new_c += 26;
	
	return isupper(c) ? new_c + 'A' : new_c + 'a';
}

/* @brief encrypts the passed text using the passed key integer variable
 * @param text the text to be encrypted
 * @param key used for shifting a letter, shifts left when negative, right 
 * when positive
 * @returns void
 */ 
void caesar_cipher(char *text, int key)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (isalpha(text[i])) text[i] = calculate_offset(text[i], key);
	}
}

/*
 * @brief tests the caesar_cipher function by passing some strings to it
 * @returns void
 */
void test(void)
{
	char first[] = "ILOVETV";
	char second[] = "ILOVETV";
	char third[] = "The smoke... was blue.";
	char fourth[] = "They think they are the fuckin big shot, like the world revolves around them. It\'s funny at times though x\'D";
	
	caesar_cipher(first, 15);
	assert(strcmp(first, "XADKTIK") == 0);
	printf("First test OK\n");
	
	caesar_cipher(second, -15);
	assert(strcmp(second, "TWZGPEG") == 0);
	printf("Second test OK\n");
	
	caesar_cipher(third, 35);
	assert(strcmp(third, "Cqn bvxtn... fjb kudn.") == 0);
	printf("Third test OK\n");
	
	caesar_cipher(fourth, -81);
	assert(strcmp(fourth, "Qebv qefkh qebv xob qeb crzhfk yfd pelq, ifhb qeb tloia obslisbp xolrka qebj. Fq\'p crkkv xq qfjbp qelrde u\'A") == 0);
	printf("Fourth test OK\n");
}

/*
 * @brief main function; calls the test function
 * @returns 0 if all tests pass
 */
int main(void)
{
	test();
	
	return 0;
}
