#include <stdio.h>

#define MAX_SIZE 64
#define NULL_NODE -1

struct node {
    int value;
    int parent;
    int left;
    int right;
};

struct node storage[MAX_SIZE];
int storage_size;
int root;


new_node(val, par)
int val, par;
{
    int i;
    i = storage_size++;
    storage[i].value  = val;
    storage[i].parent = par;
    storage[i].left   = NULL_NODE;
    storage[i].right  = NULL_NODE;
    return i;
}

swap_vals(a, b)
int a, b;
{
    int tmp;
    tmp = storage[a].value;
    storage[a].value = storage[b].value;
    storage[b].value = tmp;
}


insert(val)
int val;
{
    int i, par, pval;

    if (storage_size >= MAX_SIZE) {
        printf("full!!\n");
        return;
    }


    par = (storage_size == 0) ? NULL_NODE : (storage_size - 1) / 2;
    i = new_node(val, par);

    if (i == 0) {
        root = 0;
    } else {
        
        if (storage[par].left == NULL_NODE)
            storage[par].left = i;
        else
            storage[par].right = i;
    }

    
    for (;;) {
        int p;
        p = storage[i].parent;
        if (p == NULL_NODE) break;
        pval = storage[p].value;
        if (storage[i].value <= pval) break;
        swap_vals(i, p);
        i = p;
    }

    printf("Inserted %d.\n", val);
}

remove_leaf(i)
int i;
{
    int last, par;
    last = storage_size - 1;

    if (i != last) {
        storage[i].value = storage[last].value;
        par = storage[last].parent;
        storage[i].parent = par;
        if (par != NULL_NODE) {
            if (storage[par].left == last)
                storage[par].left = i;
            else
                storage[par].right = i;
        }
    }

    par = storage[last].parent;
    if (par != NULL_NODE) {
        if (storage[par].left == last)
            storage[par].left = NULL_NODE;
        else
            storage[par].right = NULL_NODE;
    }

    storage_size--;
}

remove(i)
int i;
{
    int c, lc, rc;

    if (i < 0 || i >= storage_size) {
        printf("Index %d out of range.\n", i);
        return;
    }

    c = i;
    for (;;) {
        lc = storage[c].left;
        rc = storage[c].right;

        if (lc == NULL_NODE && rc == NULL_NODE) {
            remove_leaf(c);
            break;
        }

        if (rc == NULL_NODE ||
            (lc != NULL_NODE && storage[lc].value >= storage[rc].value)) {
            swap_vals(c, lc);
            c = lc;
        } else {
            swap_vals(c, rc);
            c = rc;
        }
    }

    printf("Removed index %d.\n", i);
}


print_heap()
{
    int i;
    if (storage_size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Heap (%d nodes):\n", storage_size);
    printf(" index  val  par  L   R\n");
    printf("  ---  ---  ---  ---  ---\n");
    for (i = 0; i < storage_size; i++) {
        printf(" %3d  %3d  %3d  %3d  %3d\n",
            i,
            storage[i].value,
            storage[i].parent,
            storage[i].left,
            storage[i].right);
    }
    printf("   max=%d\n", storage[0].value);
}



main()
{
    char cmd;
    int  val, n;

    storage_size = 0;
    root      = NULL_NODE;

    printf("Max Heap (struct nodes)\n");
    printf("  i <num>  insert\n");
    printf("  r <num>  remove \n");
    printf("  p        print\n");
    printf("  q        quit\n\n");

    for (;;) {
        printf("> ");
        cmd = getchar();
        switch (cmd) {
        case 'i':
            n = scanf("%d", &val);
            if (n < 1)
                printf("Usage: i <number>\n");
            else
                insert(val);
            break;
        case 'r':
            n = scanf("%d", &val);
            if (n < 1)
                printf("Usage: r <number>\n");
            else
                remove(val);
            break;
        case 'p':
            print_heap();
            break;
        case 'q':
            printf("Bye.\n");
            exit(0);
        case '\n':
        case ' ':
            break;
        default:
            printf("Unknown: %c\n", cmd);
            break;
        }
        while ((n = getchar()) != '\n' && n != EOF)
            ;
    }
}