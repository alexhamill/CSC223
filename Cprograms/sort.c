#include <stdio.h>
#include "SORT.H"

merge(arr, beg, mid, end)
int arr[];
int beg, mid, end;
{
    int i, j, index, k;
    int temp[SIZE];

    i     = beg;
    j     = mid + 1;
    index = beg;

    while ((i <= mid) && (j <= end))
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

    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }

    for (k = beg; k < index; k++)
        arr[k] = temp[k];
}

merge_sort(arr, beg, end)
int arr[];
int beg, end;
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

main(argc, argv)
int argc;
char *argv[];
{
    FILE *infp, *outfp;
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
        exit();
    }

    for (i = 0; i < count; i++)
    {
        fprintf(outfp, "%d\n", data[i]);
    }
    fclose(outfp);

    puts("Done. File saved.\n");
}