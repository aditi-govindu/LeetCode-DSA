/*
Q69. Description: Given a non-negative integer x, compute and return the square root of x.

Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
*/

int mySqrt(int x)
{
    unsigned int i = 1;
    int cpy = x/2 + 1;
    while(cpy > 0)
    {
        if(i*i == x)
            return i;
        else if (i*i > x)
            return i-1;
        i++;
    }
    return NULL;
}