#include <stdio.h>
#define TRUE 1
#define FALSE 0


int count_ints(fp, val)
FILE *fp;
int *val;
{
    int c, innum, count;

    count = 0;
    innum = FALSE;

    while ((c = getc(fp)) != EOF) {
        if (c >= '0' && c <= '9') {
            if (!innum) {
                innum = TRUE;
                count++;
            }
        } else {
            innum = FALSE;
        }
    }
    *val = count;
    return 1;
}

main(argc, argv)
int argc;
char *argv[];
{
    FILE *fp;
    int count;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1); 
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open %s\n", argv[1]);
        exit(1);
    }

    count_ints(fp, &count);

    fclose(fp);
    
    printf("Number of digit-only substrings: %d\n", count);
    return 0;
}