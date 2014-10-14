#include <stdio.h>
#include <ctype.h>

static const int LINE_LENGTH = 16;

int main(int argc, char** argv)
{
    FILE* inputfile;
    int c,i;
    char linebuf[LINE_LENGTH+1];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    inputfile = fopen(argv[1],"r");
    if (!inputfile)
    {
        fprintf(stderr, "File %s not found\n",argv[1]);
        return 1;
    }
    for (;;){
        int j;
        i = 0;

        while ( i < LINE_LENGTH)
        {
            if ((c = fgetc(inputfile)) == EOF) break;
            if (!isprint(c))
            {
                linebuf[i] = ' ';
            }
            else
            {
            linebuf[i] = c;
            }
            printf("%02x ",c);
            ++i;
        }
        if (i == 0) break;
        linebuf[i] = '\0';
        for (j = 0; j < LINE_LENGTH - i; ++ j)
        {
            printf("   ");
        }
        printf("| %s\n",linebuf);
        if (c == EOF) break;
    }
    return 0;
}

