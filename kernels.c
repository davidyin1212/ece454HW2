/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * ECE454 Students: 
 * Please fill in the following team struct 
 */
team_t team = {
    "",              /* Team name */

    "Zhiwen Yin",     /* First member full name */
    "zhiwen.yin@utoronto.ca",  /* First member email address */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/*
 * ECE 454 Students: Write your rotate functions here:
 */ 

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j, i1;
    int x = dim-1;
    int T = 16;

    for (j = 0; j < dim; j+=T) {
        for (i = 0; i < dim; i+=T) {
            for (i1 = i; i1 < i + T; i1++)    
                dst[RIDX(x - j, i1, dim)] = src[RIDX(i1, j, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 1, i1, dim)] = src[RIDX(i1, j + 1, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 2, i1, dim)] = src[RIDX(i1, j + 2, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 3, i1, dim)] = src[RIDX(i1, j + 3, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 4, i1, dim)] = src[RIDX(i1, j + 4, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 5, i1, dim)] = src[RIDX(i1, j + 5, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 6, i1, dim)] = src[RIDX(i1, j + 6, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 7, i1, dim)] = src[RIDX(i1, j + 7, dim)];  
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 8, i1, dim)] = src[RIDX(i1, j + 8, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 9, i1, dim)] = src[RIDX(i1, j + 9, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 10, i1, dim)] = src[RIDX(i1, j + 10, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 11, i1, dim)] = src[RIDX(i1, j + 11, dim)];  
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 12, i1, dim)] = src[RIDX(i1, j + 12, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 13, i1, dim)] = src[RIDX(i1, j + 13, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 14, i1, dim)] = src[RIDX(i1, j + 14, dim)];
            for (i1 = i; i1 < i + T; i1++)      
                dst[RIDX(x - j + 15, i1, dim)] = src[RIDX(i1, j + 15, dim)];   
        }
    }
}


/* 
 * second attempt (commented out for now)
 */
char rotate_two_descr[] = "second attempt";
void attempt_two(int dim, pixel *src, pixel *dst) 
{
    int i, j, i1, j1;
    int x = dim-1;
    int T = 16;     

    for (i = 0; i < dim; i+=T)
        for (j = 0; j < dim; j+=T)
            for (i1 = i; i1 < i + T; i1++)
                for (j1 = j; j1 < j + T; j1++)      
                    dst[RIDX(x - j1, i1, dim)] = src[RIDX(i1, j1, dim)];
}

/* 
 * third attempt (commented out for now)
 */
char rotate_three_descr[] = "third attempt";
void attempt_three(int dim, pixel *src, pixel *dst) 
{
    int i, j, i1, j1;
    int x = dim-1;
    int T = dim/4;     

    for (j = 0; j < dim; j+=T)
        for (i = 0; i < dim; i+=T)
            for (j1 = j; j1 < j + T; j1++)
                for (i1 = i; i1 < i + T; i1++)      
                    dst[RIDX(x - j1, i1, dim)] = src[RIDX(i1, j1, dim)];
}



/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    add_rotate_function(&attempt_two, rotate_two_descr);   
    add_rotate_function(&attempt_three, rotate_three_descr);   

    //add_rotate_function(&attempt_four, rotate_four_descr);   
    //add_rotate_function(&attempt_five, rotate_five_descr);   
    //add_rotate_function(&attempt_six, rotate_six_descr);   
    //add_rotate_function(&attempt_seven, rotate_seven_descr);   
    //add_rotate_function(&attempt_eight, rotate_eight_descr);   
    //add_rotate_function(&attempt_nine, rotate_nine_descr);   
    //add_rotate_function(&attempt_ten, rotate_ten_descr);   
    //add_rotate_function(&attempt_eleven, rotate_eleven_descr);   

    /* ... Register additional rotate functions here */
}

