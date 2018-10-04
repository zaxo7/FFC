#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
int main()
{
    //var declaration
    int i=0,j=0;
    char c;
    int vmap[100][100];

    FILE* map = fopen("map.txt", "r+");/*rw file pointer*/


    printf("\t\t\t\tHello world!\n\n");

    int mh = h(map), ml = l(map);//create and init the matrix hight and legth

    fseek(map, 0, SEEK_SET);//set the pointer of the cursor in the begening of the file


    //fill the matrix and converting from char to int matrix
    //-1 : void     -2 : No tree zone     0 : the fire startup
    while(i < mh)
    {
        j=0;
        while(j < ml)
        {
            xo: c= fgetc(map); 
            vmap[i][j] = c;
            if (c == '*')
            {
                vmap[i][j] = -1;
            }
            else if (c == '0')
            {
                vmap[i][j] = 0;
            }
            else if (c == '+')
            {
                vmap[i][j] = -2;
            }
            else
            {
                goto xo;
            }
            j++;
        }
        i++;
    }
    afm(vmap,ml,mh); // print the matrix

    int *zeropo=zeropos(vmap,ml,mh); // find the zero cords

    AI(vmap,ml,mh,zeropo[0],zeropo[1],0); // fill the map with fire date
    
    afm(vmap,ml,mh);// print again

    return 0;
}