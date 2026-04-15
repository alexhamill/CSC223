#include <stdio.h>

#define SIZE 100
#define ERROR -1

merge(arr, b, m, e)
int *arr;       
int b;
int m;
int e;
{
    int i, j, index, k;
    int temp[SIZE];

    i = b;
    j = m + 1;
    index = b;

    while ((i <= m) && (j <= e))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }

    if (i > m)
    {
        while (j <= e)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= m)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }

    for (k = b; k < index; k++)
    {
        arr[k] = temp[k];
    }
}

merge_sort(arr, b, e)
int *arr;
int b;
int e;
{
    int m;
    if (b < e)
    {
        m = (b + e) / 2;
        merge_sort(arr, b, m);
        merge_sort(arr, m + 1, e);
        merge(arr, b, m, e);
    }
}

main(argc, argv)
int argc;
char *argv[];
{
    int infp, outfp;
    int data[SIZE];
    int count, i;

    if (argc != 3)
    {
        puts("Usage: msort input.dat output.dat\n");
        return;
    }

    if ((infp = fopen(argv[1], "r")) == NULL)
    {
        puts("Can't open input file\n");
        return;
    }

    count = 0;
    while (count < SIZE && (fscanf(infp, "%d", &data[count]) != EOF))  
    {
        count++;
    }
    fclose(infp);

    merge_sort(data, 0, count - 1);

    if ((outfp = fopen(argv[2], "w")) == NULL)
    {
        puts("Can't create output file\n");
        exit(1);
    }

    for (i = 0; i < count; i++)
    {
        fprintf(outfp, "%d\n", data[i]);
    }
    fclose(outfp);

    puts("Done. File saved.\n");
}