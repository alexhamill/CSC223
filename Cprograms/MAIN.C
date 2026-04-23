#include <stdio.h>


main(argc, argv)
int argc;
char *argv[];
{
    FILE *fp;
    int count;

    if (argc != 3) {
        printf("Usage: %s <infilename> <outfilename>\n", argv[0]);
        exit(1); 
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open %s\n", argv[1]);
        exit(1);
    }
    fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Cannot open %s\n", argv[2]);
        exit(1);
    }

    
    count_ints(fp, &count);

    fclose(fp);
    
    printf("Number of digit-only substrings: %d\n", count);
    return 0;
}