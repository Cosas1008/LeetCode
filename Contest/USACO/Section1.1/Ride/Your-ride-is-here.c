/*
ID: yuweiic1
LANG: C
TASK: ride 
*/
#include <stdio.h>
#include <stdlib.h>

int lengthOfString(char* inchar);

int main()
{
    char cha[7], chb[7];    
    int i, j, ma, mb, lengthOfa, lengthOfb;
    i = j = 0;
    ma = mb = 1;
    FILE *fin, *fout;
    fin  = fopen("ride.in", "r");
    if( fin == NULL )
   {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
   }else{
        fscanf(fin, "%s\n%s", cha, chb);
        fout = fopen("ride.out", "w");
    }
    
    lengthOfa = lengthOfString(cha);
    for(i; i < lengthOfa; i++)
    {
        ma *= (cha[i]- 64);
    }
    
    lengthOfb = lengthOfString(chb);
    for(j; j < lengthOfb; j++)
    {
        mb *= (chb[j]- 64);
    }
    
    if((ma %47) == (mb %47)){
        fprintf(fout, "GO\n");
    }else{
        fprintf(fout, "STAY\n");
    }
    
    fclose(fin);
    fclose(fout);
    exit(0);

}
int lengthOfString(char* inchar)
{
    int i, returnLength = 0;
    for(i= 0; i < 6; i++)
    {
        if(inchar[i] == 0)
            break;
        else
            returnLength++;
    }
    return returnLength;
}
