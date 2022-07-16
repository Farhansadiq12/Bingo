/*
BINGO Game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define w 75 
#define v 5

void FillCard(int m, int n, int arr[m][n]);
void printBingo(int m, int n, int arr[m][n]);
void Picknumber(int x, int arr[x]);
int CheckRow(int m, int arr[v][m]);
int CheckCol(int n, int bingo[n][v]);
void printlines(int number);
int searchbingo(int m, int n, int arr[m][n], int s, int arr1[s]);

void FillCard(int m, int n, int arr[m][n])
{
    int random, i; 
    int col = 5, row = 5, s = 1, e = 15, o = 0, size = 25;
    m = 5, n = 5;
    int DUP[size];
    
    srand(time(0));
    
    while(o < size)
    {
        for(col = 0; col < n; col++)
        {
            for(row = 0; row < m; row++)
            {
                random = rand() % (e - s + 1) + s;
                
                for(i = 0; i < 25; i++)
                {
                    
                for(int j = i + 1; j < size; j++)
                {
                    if(DUP[i] == DUP[j])
                    {
                        random = rand() % (e - s + 1) + s;
                        DUP[j] = random;
                        i = 0;
                        j = i + 1;
                    }
                }
                }
                
            DUP[o] = random;
            arr[row][col] = random;
            o++;
            }
            
            e = e + 15;
            s = s + 15;
        
        }
    }
    arr[2][2] = 0;
}

void printBingo(int m, int n, int arr[m][n])
{
    int a = 0;
    int row = 5, col = 5;

    printf("\n \tB\t\tI\t\tN\t\tG\t\tO\n");
    
    while(a < 80)
    {
        printf("-");
        a++;
    }
    
    for(row = 0; row < m; row++)
    {
        printf("\n");
        
        for(col = 0; col < n; col++)
        {
            if(arr[row][col] == 0)
            {
                printf("|\tX\t");
            }
            else
            {
                printf("|\t%d\t",arr[row][col]);
            }

        }
        
        printf("|\n");
        a = 0;
        
        while(a < 80)
        {
           printf("-");
            a++;
        }
    }
    printf("\n");
}

void Picknumber(int x,int arr[x])
{
    int s = 1;
    int e = x;
    int c;
    int z;
    int DUP[x + 1];
    
    int random = rand() % (e - s + 1) + s;
    
    while(z < x)
    {
        for(int i = 0; i < x - 1; i++)
        {
            random = rand() % (e - s + 1) + s;
            
            for(int j = i + 1; j < x; j++)
            {
                if(arr[i] == arr[j])
                {
                    random = rand() % (e - s + 1) + s;
                    arr[j] = random;
                    i = 0;
                    j = i + 1;
                }
            }
        }
        
        DUP[z] = random;
        arr[z] = random;
        z++;
    }
}

int CheckRow(int m, int arr[v][m])
{
    int a = 0;
    int b = 0;
    m = 5;
    
    while(m > 0)
    {
        for(int i = 5; i > 0; i--)
        {
            if(arr[m - 1][i - 1] == 0)
            {
                b++;
                
                if(b == 5)
                {
                    a = 1;
                }
            }
        }
        
        m--;
        b = 0;
    }

    return a;
}

int CheckCol(int n,int arr[n][v])
{
    
    int a = 0;
    int b = 0;
    n = 5;
    
    while(n > 0)
    {
        for(int i = 5; i > 0; i--)
        {
            if(arr[i - 1][n - 1] == 0)
            {
                b++;
                
                if(b == 5)
                {
                    a = 1;
                }
            }
        }
        
        n--;
        b = 0;
    }

    return a;
}

void printlines (int number)
{
    if(number > 0 && number < 16)
    {
        printf("\nThe next number is B%d\n",number);
    }
    else if(number > 15 && number < 31)
    {
        printf("\nThe next number is I%d\n",number);
    }
    else if(number > 30 && number < 46)
    {
        printf("\nThe next number is N%d\n",number);
    }
    else if(number > 45 && number < 61)
    {
        printf("\nThe next number is G%d\n",number);
    }
    else if(number > 60 && number < 76)
    {
        printf("\nThe next number is O%d\n",number);
    }
}

int searchbingo(int m, int n, int arr[m][n], int s, int arr1[s])
{
    int z;
    
    for(m = 0; m < 5; m++)
    {
        for(n = 0; n < 5; n++)
        {
            if(arr1[s] == arr[n][m])
            {
                arr[n][m] = 0;
                z = 1;
            }
            else if((arr1[s] != arr[n][m]) && (m == 4 && m == 4 && z == 0))
            {
                z = 0;
            }
        }
    }
    return z;
}

int main(void)
{
    int row = 5, col = 5;
    int bingo[row][col];
    int keeptrack[w];
    int q; 
    
    FillCard(row, col, bingo);
    Picknumber(w, keeptrack);
    
    while(q < w)
    {
        char val;
        printBingo(row, col, bingo);
        printlines(keeptrack[q]);
        
        printf("\nDo you have it? (Y/N)");
        scanf("%c%*c", &val);

        if(val =='y'||val =='Y')
        {
             int d = searchbingo(col, row, bingo, q, keeptrack);
             if(d == 0)
             {
                 printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
             }
        }
        
        if((CheckRow(row, bingo) == 1) && (CheckCol(col, bingo) == 1))
        {
            printf("You filled out a row and a column - BINGO!!!");
            q = w + 1;
        }
        
        else if(CheckRow(row, bingo) == 1)
        {
            printf("You filled out a row - BINGO!!!");
            q = w + 1;
        }
        else if(CheckCol(col, bingo) == 1)
        {
            printf("You filled out a column - BINGO!!!");
            q = w + 1;
        }
        
        q++;
    }
    
    return 0;
}







