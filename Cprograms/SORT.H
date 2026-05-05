#ifndef SORT_H
#define SORT_H

#define NULL 0
#define TRUE 1
#define FALSE 0
#define MAXNUMS 500
#define BASE 10
#define MAXDIGITS 5
#define MAXSIZE 256

/* ==============UTILITIES==============*/

void swap(a, b)
int *a;
int *b;
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

/* =============BUBBLE SORT=============*/

bubble_sort(arr, n)
int arr[];
int n;
{
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j+1]) {
        swap(&arr[j], &arr[j+1]);
      }
    }
  }
}

/* ===========INSERTION SORT============*/

insertion_sort(arr, n)
int arr[];
int n;
{
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = arr[i];
    j = i - 1;
    while((j >= 0) && (temp < arr[j])) {
      arr[j+1] = arr[j--];
    }
    arr[j+1] = temp;
  }
}

/* ===========SELECTION SORT============*/

int smallest(arr, k, n)
int arr[];
int k, n;
{
  int pos, small, i;
  pos = k;
  small = arr[k];
  for (i = k + 1; i < n; i++) {
    if (arr[i] < small) {
      small = arr[i];
      pos = i;
    }
  }
  return pos;
}

selection_sort(arr, n)
int arr[];
int n;
{
  int k, pos;
  for (k = 0; k < n; k++) {
    pos = smallest(arr, k, n);
    swap(&arr[k], &arr[pos]);
  }
}

/* ==============MERGE SORT==============*/

merge(arr, b, m, e)
int arr[];
int b, m, e;
{
  int i, j, k, s;
  int temp[MAXSIZE];

  i = b;
  j = m + 1;
  k = 0;
  s = e - b;

  while (i <= m && j <= e)
    temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
  if (i > m)
    while (j <= e)
      temp[k++] = arr[j++];
  else
    while (i <= m)
      temp[k++] = arr[i++];
  for (k = 0; k <= s; k++)
    arr[k+b] = temp[k];
}

msort(arr, left, right)
int arr[];
int left, right;
{
  int mid;
  if (left < right)
  {
    mid = left + (right - left) / 2;
    msort(arr, left, mid);
    msort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

merge_sort(arr, n)
int arr[];
int n;
{
  if (n <= 0) return;
  msort(arr, 0, n-1);
}

/* ==============QUICK SORT==============*/

int partition(arr, b, e)
int arr[];
int b, e;
{
  int l, r, temp, loc, flag;
  loc = l = b;
  r = e;
  flag = FALSE;

  while (flag != TRUE) {
    while ((arr[loc] <= arr[r]) && (loc != r)) r--;
    if (loc == r)
      flag = TRUE;
    else
      if (arr[loc] > arr[r]) {
        swap(&arr[loc], &arr[r]);
        loc = r;
      }
    if (flag != TRUE) {
      while ((arr[loc] >= arr[l]) && (loc != l)) l++;
      if (loc == l)
        flag = TRUE;
      else
        if (arr[loc] < arr[l]) {
          swap(&arr[loc], &arr[l]);
          loc = l;
        }
    }
  }
  return loc;
}

qsort(arr, b, e)
int arr[];
int b, e;
{
  int loc;
  if (b < e) {
    loc = partition(arr, b, e);
    qsort(arr, b, loc-1);
    qsort(arr, loc+1, e);
  }
}

void quick_sort(arr, n)
int arr[];
int n;
{
  qsort(arr, 0, n-1);
}

/* ==============RADIX SORT==============*/

counting_sort(arr, tmp, cnt, n, pos)
int arr[];
int tmp[];
int cnt[];
int n;
int pos;
{
  int i;
  int d;
  int base;
  base = 1;
  for (i = 0; i < pos; i++)
    base *= BASE;
  for (i = 0; i < BASE; i++)
    cnt[i] = 0;
  for (i = 0; i < n; i++) {
    d = (arr[i] / base) % BASE;
    cnt[d]++;
  }
  for (i = 1; i < BASE; i++)
    cnt[i] += cnt[i - 1];
  for (i = n - 1; i >= 0; i--) {
    d = (arr[i] / base) % BASE;
    cnt[d]--;
    tmp[cnt[d]] = arr[i];
  }
  for (i = 0; i < n; i++)
    arr[i] = tmp[i];
}

radix_sort(arr, n)
int arr[];
int n;
{
  int tmp[MAXNUMS];
  int cnt[BASE];
  int pass;
  for (pass = 0; pass < MAXDIGITS; pass++)
    counting_sort(arr, tmp, cnt, n, pass);
}

/* ==============HEAP SORT==============*/

reheap_up(heap, n)
int heap[];
int n;
{
  int i, val;
  i = n - 1;
  val = heap[i];
  while ((i > 0) && (heap[i/2] < val)) {
    heap[i] = heap[i/2];
    i /= 2;
  }
  heap[i] = val;
}

reheap_down(heap, n)
int heap[];
int n;
{
  int i, child, left, right;
  i = 0;
  while (TRUE) {
    left = 2 * i + 1;
    if (left >= n) return;             /* heap[i] is a leaf node */
    right = left + 1;
    child = left;
    if (right < n && heap[right] > heap[left])
      child = right;
    if (heap[i] >= heap[child]) return; /* It's now a heap */
    swap(&heap[i], &heap[child]);
    i = child;
  }
}

heapify(arr, n)
int arr[];
int n;
{
  int i;
  for (i = 1; i <= n; i++) {
    reheap_up(arr, i);
  }
}

heap_sort(arr, n)
int arr[];
int n;
{
  int e, i;
  heapify(arr, n);
  for (e = n - 1; e > 1; e--) {
    swap(&arr[0], &arr[e]);
    reheap_down(arr, e-1);
  }
}

/* ==============TREE SORT==============*/

struct tree {
  struct tree *left;
  int num;
  struct tree *right;
};

insert(tpp, n)
struct tree **tpp;
int n;
{
  struct tree *tree_node;
  tree_node = *tpp;
  if (tree_node == NULL) {
    tree_node = alloc(8);
    tree_node->num = n;
    tree_node->left  = NULL;
    tree_node->right = NULL;
    *tpp = tree_node;
    return 0;
  }
  if (n < tree_node->num)
    insert(&(tree_node->left),  n);
  else
    insert(&(tree_node->right), n);
  return 0;
}

inorder(tree_node, arr, ip)
struct tree *tree_node;
int arr[];
int *ip;
{
  if (tree_node == NULL)
    return 0;
  inorder(tree_node->left,  arr, ip);
  arr[(*ip)++] = tree_node->num;
  inorder(tree_node->right, arr, ip);
  return 0;
}

free_tree(tree_node)
struct tree *tree_node;
{
  if (tree_node == NULL)
    return 0;
  free_tree(tree_node->left);
  free_tree(tree_node->right);
  free(tree_node);
  return 0;
}

tree_sort(arr, n)
int arr[];
int n;
{
  int i, index;
  struct tree *root;

  root = NULL;
  for (i = 0; i < n; i++)
    insert(&root, arr[i]);

  index = 0;
  inorder(root, arr, &index);
  free_tree(root);
}

#endif //SORT_H
