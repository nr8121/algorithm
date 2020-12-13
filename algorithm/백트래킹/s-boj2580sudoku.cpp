#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>
#include <vector>


int sudoku[9][9];
int x[81];
int y[81];




void print_sudoku()
{
    for(int i = 0 ; i < 9; i++)
    {
        printf("%d %d %d %d %d %d %d %d %d\n",sudoku[i][0],sudoku[i][1],sudoku[i][2],sudoku[i][3],sudoku[i][4],sudoku[i][5],sudoku[i][6],sudoku[i][7],sudoku[i][8]);
    }
}

void find_zero()
{
    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                
            }
        }
    }
}

int check_zero()
{
    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return 0;
}
int check(position p)
{
    
    for(int i = 0 ; i < 9 ; i++)
    {
        if(sudoku[p.x][i] == p.value)
        {
            return -1;
        }
        else if(sudoku[i][p.y] == p.value)
        {
            return -1;
        }
    }
    int x = 3*(p.x/3);
    int y = 3*(p.y/3);
    for(int i = x; i < x+3 ;i++)
    {
        for(int j = y; j < y+3; j++)
        {
            if(sudoku[i][j] == p.value)
            {
                return -1;
            }
        }
    }
    return 0;
}
int solve(int depth, int end)
{
    if(depth == end)
    {
        return 0;
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        list.at(depth).value = i+1;
        if(check(list.at(depth)) == 0)
        {
            sudoku[list.at(depth).x][list.at(depth).y] = list.at(depth).value;
            if(solve(depth+1,end) == 0)
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
        
    }

    sudoku[list.at(depth).x][list.at(depth).y] = 0;

    return -1;

}



int main()
{

    
    for(int i = 0 ; i < 9 ; i++)
    {   
        scanf("%d %d %d %d %d %d %d %d %d",&sudoku[i][0],&sudoku[i][1],&sudoku[i][2],&sudoku[i][3],&sudoku[i][4],&sudoku[i][5],&sudoku[i][6],&sudoku[i][7],&sudoku[i][8]);
    }
    
    find_zero();

    solve(0, list.size());
    print_sudoku();
    

    return 0;
}
/*
typedef struct position
{
    int x;
    int y;
    int value;
}position;

int sudoku[9][9];
std::vector<position> list;



void print_sudoku()
{
    for(int i = 0 ; i < 9; i++)
    {
        printf("%d %d %d %d %d %d %d %d %d\n",sudoku[i][0],sudoku[i][1],sudoku[i][2],sudoku[i][3],sudoku[i][4],sudoku[i][5],sudoku[i][6],sudoku[i][7],sudoku[i][8]);
    }
}

void find_zero()
{
    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                position p;
                p.x = i;
                p.y = j;
                p.value = 0;
                list.push_back(p);
            }
        }
    }
}

int check_zero()
{
    for(int i = 0 ; i < 9; i++)
    {
        for(int j = 0 ; j < 9; j++)
        {
            if(sudoku[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return 0;
}
int check(position p)
{
    
    for(int i = 0 ; i < 9 ; i++)
    {
        if(sudoku[p.x][i] == p.value)
        {
            return -1;
        }
        else if(sudoku[i][p.y] == p.value)
        {
            return -1;
        }
    }
    int x = 3*(p.x/3);
    int y = 3*(p.y/3);
    for(int i = x; i < x+3 ;i++)
    {
        for(int j = y; j < y+3; j++)
        {
            if(sudoku[i][j] == p.value)
            {
                return -1;
            }
        }
    }
    return 0;
}
int solve(int depth, int end)
{
    if(depth == end)
    {
        return 0;
    }
    for(int i = 0 ; i < 9 ; i++)
    {
        list.at(depth).value = i+1;
        if(check(list.at(depth)) == 0)
        {
            sudoku[list.at(depth).x][list.at(depth).y] = list.at(depth).value;
            if(solve(depth+1,end) == 0)
            {
                return 0;
            }
        }
        else
        {
            continue;
        }
        
    }

    sudoku[list.at(depth).x][list.at(depth).y] = 0;

    return -1;

}



int main()
{

    
    for(int i = 0 ; i < 9 ; i++)
    {   
        scanf("%d %d %d %d %d %d %d %d %d",&sudoku[i][0],&sudoku[i][1],&sudoku[i][2],&sudoku[i][3],&sudoku[i][4],&sudoku[i][5],&sudoku[i][6],&sudoku[i][7],&sudoku[i][8]);
    }
    
    find_zero();

    solve(0, list.size());
    print_sudoku();
    

    return 0;
}

*/