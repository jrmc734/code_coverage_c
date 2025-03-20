#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main()
{
    int mcdc_total = 4;
    int mcdc_passed = 0;

    printf("Starting testes ... \n");
    int testFailCount = 0;

    // Test Preparation
    char *answer_1 = generation_type(1982);
    char *expected_answer_1 = "Millennials";
    
    char *answer_2 = generation_type(1996);
    char *expected_answer_2 = "Generation Z";

    char *answer_3 = generation_type(2015);
    char *expected_answer_3 = "Error";

    char *answer_4 = generation_type(1900);
    char *expected_answer_4 = "Error";

    const int answer_5 = anything(12, 18, -1);
    const int expected_answer_5 = 1;

    const int answer_6 = anything(12, 21, 1);
    const int expected_answer_6 = 1;

    const int answer_7 = anything(12, 21, -1);
    const int expected_answer_7 = 0;

    const int answer_8 = anything(7, 18, -1);
    const int expected_answer_8 = 0;

    // Test Cases

    // Test 1 
    if(strcmp(answer_1, expected_answer_1) == 0)
    {
        printf("(1) Test PASSED\n");
    }
    else
    {
        printf("(1) Test FAILED\n");
        testFailCount++;
    }

    // Test 2
    if(strcmp(answer_2, expected_answer_2) == 0)
    {
        printf("(2) Test PASSED\n");
    }
    else
    {
        printf("(2) Test FAILED\n");
        testFailCount++;
    }

    // Test 3
    if(strcmp(answer_3, expected_answer_3) == 0)
    {
        printf("(3) Test PASSED\n");
    }
    else
    {
        printf("(3) Test FAILED\n");
        testFailCount++;
    }

    // Test 4
    if(strcmp(answer_4, expected_answer_4) == 0)
    {
        printf("(4) Test PASSED\n");
    }
    else
    {
        printf("(4) Test FAILED\n");
        testFailCount++;
    }

    printf("Executing MC/DC tests [FUNCTION ANYTHING] ...\n");
    // Test 5 MC/DC
    if(answer_5 == expected_answer_5)
    {
        printf(" MC/DC (5) Test PASSED\n");
        mcdc_passed++;
    }
    else
    {
        printf(" MC/DC (5) Test FAILED\n");
        testFailCount++;
    }

    // Test 6 MC/DC
    if(answer_6 == expected_answer_6)
    {
        printf(" MC/DC (6) Test PASSED\n");
        mcdc_passed++;
    }
    else
    {
        printf(" MC/DC (6) Test FAILED\n");
        testFailCount++;
    }

    // Test 7 MC/DC
    if(answer_7 == expected_answer_7)
    {
        printf(" MC/DC (7) Test PASSED\n");
        mcdc_passed++;
    }
    else
    {
        printf(" MC/DC (7) Test FAILED\n");
        testFailCount++;
    }

    // Test 8 MC/DC
    if(answer_8 == expected_answer_8)
    {
        printf(" MC/DC (8) Test PASSED\n");
        mcdc_passed++;
    }
    else
    {
        printf(" MC/DC (8) Test FAILED\n");
        testFailCount++;
    }

    printf("\nCobertura MC/DC = %.f \n\n",(float) ((100*mcdc_passed)/mcdc_total));

    return(testFailCount);
}
