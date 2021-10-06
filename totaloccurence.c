#include<stdio.h>
#include<stdbool.h>

int read_row(int x, int y, int a[x][y]) 
{
    printf("Enter the size of your array:");
    scanf("%d %d", &x, &y);
    a[x][y] = 10;    
    while (x < 10 && y < 10)
    {
        printf("Enter row %d:", x);
        x++;
    }
    return x;
}

bool check_input(int x, int y) 

{
    if (x > 9)
        return false;
    else
        return true;
  if (y > 9)
        return false;
    else 
        return true;
}

int compute_row_count(int x, int y, int a[x][y], int count)
{
   a[x][y] = 0;
   for (x = 0; x < 10; x++)
    {
        for (y = 0; y < 10; y++)
        {
            while (y > 0)
            {
                count = y % 10;    
                y /= 10;
            }
            a[y] = y;
        }


    }  
  }  
    return a[x][y];
}

int print_total_count(int x, int y, int a[x][y], int count) 
{
    printf("Total count for each digit:\n");
    a[x][y] = 10;
        for (y = 0; y < 10; y++)
            {
                if (count <= 1)
                    printf("Digit %d occurs %d time\n", y, count);
                if(count >= 2 && y < 10)
                    printf("Digit %d occurs %d times\n", y, count);
            }
        return (y, count);
}

int main (void)
{
int x, y, a[x][y], count;

read_row(x, y, a[x][y]);
  if (check_input(x,y))
    printf("Values are outside of range.");
else 
    break;
compute_row_count(x, y, a[x][y], count);
print_total_count(x, y, a[x][y], count);


return 0;
}
