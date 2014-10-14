#include <stdio.h>
#include <ctype.h>

static const int LINE_LENGTH = 16;

int main(int argc, char** argv)
{
    FILE* input_file;
    int c,i;
    char line_buf[LINE_LENGTH+1];
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "ar");
    if (!input_file)
    {
        fprintf(stderr, "File %s not found\n", argv[1]);
        return 1;
    }
    fclose(input_file);
    input_file = fopen(argv[1], "r");

    for (;;)
    {
        int j;
        i = 0;

        while ( i < LINE_LENGTH)
        {
            if ((c = fgetc(input_file)) == EOF) break;
            if (!isprint(c))
            {
                line_buf[i] = ' ';
            }
            else
            {
            line_buf[i] = c;
            }
            printf("%02x ", c);
            ++i;
        }
        if (i == 0) break;
        line_buf[i] = '\0';
        for (j = 0; j < LINE_LENGTH - i; ++j)
        {
            printf("   ");
        }
        printf("| %s\n", line_buf);
        if (c == EOF) break;
    }
    return 0;
}

