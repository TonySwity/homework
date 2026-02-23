#include <stdio.h>
#include <stdlib.h>

/* struct tree and datatype are provided by the platform:
typedef struct tree {
    datatype key;
    struct tree *left, *right;
} tree;
*/

typedef struct {
  int minHd, maxHd;
  int count;
} Info;

static void dfsInfo(tree *n, int hd, Info *inf) {
  if (!n)
    return;
  if (hd < inf->minHd)
    inf->minHd = hd;
  if (hd > inf->maxHd)
    inf->maxHd = hd;
  inf->count++;
  dfsInfo(n->left, hd - 1, inf);
  dfsInfo(n->right, hd + 1, inf);
}

void btUpView(tree *root) {
  if (!root)
    return;

  Info inf = {0, 0, 0};
  dfsInfo(root, 0, &inf);

  int width = inf.maxHd - inf.minHd + 1;
  int offset = -inf.minHd;

  char *seen = (char *)calloc((size_t)width, sizeof(char));
  datatype *top = (datatype *)malloc((size_t)width * sizeof(datatype));

  tree **qNode = (tree **)malloc((size_t)inf.count * sizeof(tree *));
  int *qHd = (int *)malloc((size_t)inf.count * sizeof(int));

  int head = 0, tail = 0;
  qNode[tail] = root;
  qHd[tail] = 0;
  tail++;

  while (head < tail) {
    tree *cur = qNode[head];
    int hd = qHd[head];
    head++;

    int idx = hd + offset;
    if (!seen[idx]) {
      seen[idx] = 1;
      top[idx] = cur->key;
    }

    if (cur->left) {
      qNode[tail] = cur->left;
      qHd[tail] = hd - 1;
      tail++;
    }
    if (cur->right) {
      qNode[tail] = cur->right;
      qHd[tail] = hd + 1;
      tail++;
    }
  }

  int first = 1;
  for (int i = 0; i < width; i++) {
    if (seen[i]) {
      if (!first)
        printf(" ");
      printf("%d", (int)top[i]);
      first = 0;
    }
  }

  free(qHd);
  free(qNode);
  free(top);
  free(seen);
}
