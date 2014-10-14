#include <stdio.h>

#define NUMBER_IN_LINE 16

int main(int argc, char** argv)
{
    FILE* inputfile;
    int c,i;
    char linebuf[NUMBER_IN_LINE+1];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file name\n", argv[0]);
        return 1;
    }

    inputfile = fopen(argv[1],"r");
    if (!inputfile) {
        fprintf(stderr, "File %s not found\n",argv[1]);
        return 1;
    }
    for (;;){
        int j;
        i = 0;

        while ((c = fgetc(inputfile)) != EOF && i < NUMBER_IN_LINE){
            linebuf[i] = c;
            printf("%02x ",c);
            ++i;
        }
        if (i == 0) break;
        linebuf[i] = '\0';
        for (j = 0; j < NUMBER_IN_LINE - i; ++ j){
            printf("   ");
        }
        printf("| %s\n",linebuf);
        if (c == EOF) break;
    }
    return 0;
}

