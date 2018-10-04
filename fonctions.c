#include "fonctions.h"



int h(FILE* map)
{
    int h = 0;
    char c = 'a';
    fseek(map, 0, SEEK_SET);
    while (c != EOF)
    {
        c = fgetc(map);
        if (c == '\n')
        {
            h++;
        }
    }
    return h+1;
}
int l(FILE* map)
{
    int l = 0;
    fseek(map, 0, SEEK_SET);
    while (fgetc(map) != '\n')
    {
        l++;
    }
    return l - 1;
}
void afm(int vmap[100][100], int l, int h)
{
    int i, j;
    printf("\n");
    for (i = 0; i < l; i++)
    {
        printf(" _");
    }
    for (i = 0; i < h; i++)
    {
        printf("\n");
        for (j = 0; j < l; j++)
        {
            if (vmap[i][j] == -1)
            {
                printf("  ");
            }
            else if (vmap[i][j] == -2)
            {
                printf(" X");
            }
            else if (vmap[i][j] == 0)
            {
                printf(" 0");
            }
            else
            {
                printf(" %d", vmap[i][j]);
            }
        }
        printf(" |");
    }
    printf("\n");
    for (i = 0; i < l; i++)
    {
        printf(" _");
    }
    printf(" |\n");
}


void AI(int vmap[100][100], int l, int h, int x, int y, int date)
{
    date++;
    if (x > l || y > h)
    {
        return ;
    }

    int up=0,down=0,right=0,left=0;

    if (vmap[y - 1][x] == -1)
    {
        vmap[y - 1][x] = date;
        up++;
        //AI(vmap, l, h, x, y - 1, date);
    }
    
    if (vmap[y + 1][x] == -1)
    {
        vmap[y + 1][x] = date;
        down++;
        //AI(vmap, l, h, x, y + 1, date);
    }
    
    if (vmap[y][x - 1] == -1)
    {
        left++;
        vmap[y][x - 1] = date;
        //AI(vmap, l, h, x - 1, y, date);
    }
    if (vmap[y][x + 1] == -1)
    {
        vmap[y][x + 1] = date;
        right++;
        //AI(vmap, l, h, x + 1, y, date);
    }

    if(up)
    {
        AI(vmap, l, h, x, y - 1, date);
    }
    if(down)
    {
        AI(vmap, l, h, x, y + 1, date);
    }
    if(right)
    {
         AI(vmap, l, h, x + 1, y, date);
    }
    if(left)
    {
         AI(vmap, l, h, x - 1, y, date);
    }

}

int *zeropos(int vmap[100][100],int l,int h)
{
    int *p=malloc(2 * sizeof(int));
    for(int i=0;i<h;i++)
    {
        for(int j=0;j < l; j++)
        {
            if (vmap[i][j]==0)
            {
                p[0]=j;
                p[1]=i;
                return p;
            }
        }
    }
    return p;
}