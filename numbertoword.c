#include<string.h>
#include<stdio.h>
#define BUF_SIZE 20
// strings at index 0 is not used, it is to make array
// indexing simple
char* one[] = { "", "one ", "two ", "three ", "four ",
                "five ", "six ", "seven ", "eight ",
                "nine ", "ten ", "eleven ", "twelve ",
                "thirteen ", "fourteen ", "fifteen ",
                "sixteen ", "seventeen ", "eighteen ",
                "nineteen "
              };
// strings at index 0 and 1 are not used, they is to
// make array indexing simple
char* ten[] = { "", "", "twenty ", "thirty ", "forty ",
                "fifty ", "sixty ", "seventy ", "eighty ",
                "ninety "
              };
char * numToWords(int n, char* s, char *str, int len)
{
    memset(str,0,len);
    // if n is more than 19, divide it
    if (n > 19)
    {
        strcat(str,ten[n / 10]);
        strcat(str,one[n % 10]);
    }
    else
    {
        strcat(str,one[n]);
    }
    // if n is non-zero
    if (n)
    {
        strcat(str,s);
    }
    return str;
}
// Function to print a given number in words
char* convertToWords(long n, char *out)
{
    char str[BUF_SIZE] = {0};
    // handles digits at ten millions and hundred
    // millions places (if any)
    strcat(out, numToWords((n / 10000000), "crore ",str,BUF_SIZE));
    // handles digits at hundred thousands and one
    // millions places (if any)
    strcat(out, numToWords(((n / 100000) % 100), "lakh ",str,BUF_SIZE));
    // handles digits at thousands and tens thousands
    // places (if any)
    strcat(out, numToWords(((n / 1000) % 100), "thousand ",str,BUF_SIZE));
    // handles digit at hundreds places (if any)
    strcat(out, numToWords(((n / 100) % 10), "hundred ",str,BUF_SIZE));
    //Increase code readability
    if (n > 100 && n % 100)
    {
        strcat(out, "and ");
    }
    // handles digits at ones and tens places (if any)
    strcat(out, numToWords((n % 100), "",str,BUF_SIZE));
    return out;
}
int main()
{
    //Get input number from user
    long num;
    char str[60] = {0};
    
    printf("Enter any number: ");
    scanf("%ld", &num);
    // convert given number in words
    printf( "%s",convertToWords(num,str));
    return 0;
}
