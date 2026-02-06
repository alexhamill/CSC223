# exercises 

## Exercise 8-6. 

The standard library function cal1oc (n, size) returns a pointer to n objects of size size, with the storage initialized to zero. Write calloc, using alloc either as a model or as a function to be called.

```c
char* calloc(n, size)
unsigned size;
unsigned n;
{
    unsigned length = n * size;
    char *p, *start;
    unsigned i;
    start = alloc(length);
    p = start;
    for (i = 0; i < length; i++){
        *p++ = 0;
    }
    return start;
}
```

## Exercise 8-7. 

alloc accepts a size request without checking its plausibility, free believes that the block it is asked to free contains a valid size field. Improve these routines to take more pains with error checking.

```c 
char* newalloc(n)
unsigned n;
{
    if (n > 100 || n == 0) {
        return NULL;
    }
    char *p;
    p = alloc(n);
    if (p == NULL) {
        return NULL;
    }
    return p;
}
```
```c
free_safe(p)
char *p;
{
    struct header *bp;
    
    if (p == NULL)
        return;
    
    if (p < allocbuf || p >= allocbuf + ALLOCSIZE)
        return;
    
    bp = (struct header *)p - 1;
    
    if (bp->size == 0 || bp->size > ALLOCSIZE)
        return;
}
```
<!-- ## Exercise 8-8.

Write a routine bfree(p, n) which will free an arbitrary block p of n characters into the free list maintained by alloc and free. By using bfree, a user can add a static or external array to the free list at any time.


```c
bfree(p, n)
char *p;
unsigned n;
{
    struct header *bp;
    
    if (p == NULL)
        return;
    
    if (n < sizeof(struct header))
        return;
    
    bp = (struct header *)p;
    
    bp->size = n / sizeof(struct header);
    
    free((char *)(bp + 1));
}
``` -->
