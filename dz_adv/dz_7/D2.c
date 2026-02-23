tree *findBrother(tree *root, int key) {
  tree *cur = root;
  while (cur) {
    if (key == (int)cur->key)
      break;
    if (key < (int)cur->key)
      cur = cur->left;
    else
      cur = cur->right;
  }
  if (!cur)
    return 0;
  if (!cur->parent)
    return 0;

  tree *p = cur->parent;
  if (p->left == cur)
    return p->right ? p->right : 0;
  if (p->right == cur)
    return p->left ? p->left : 0;

  return 0;
}
