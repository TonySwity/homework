#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
  char word[20];
  struct list *next;
};

static struct list *add_to_list(struct list *head, const char *w) {
  struct list *node = (struct list *)malloc(sizeof(struct list));
  if (!node)
    return head;
  strncpy(node->word, w, sizeof(node->word) - 1);
  node->word[sizeof(node->word) - 1] = '\0';
  node->next = NULL;

  if (!head)
    return node;

  struct list *p = head;
  while (p->next)
    p = p->next;
  p->next = node;
  return head;
}

static void swap_elements(struct list *a, struct list *b) {
  char tmp[20];
  strcpy(tmp, a->word);
  strcpy(a->word, b->word);
  strcpy(b->word, tmp);
}

static void print_list(const struct list *head) {
  const struct list *p = head;
  while (p) {
    printf("%s", p->word);
    if (p->next)
      putchar(' ');
    p = p->next;
  }
  putchar('\n');
}

static void delete_list(struct list **head) {
  struct list *p = head ? *head : NULL;
  while (p) {
    struct list *n = p->next;
    free(p);
    p = n;
  }
  if (head)
    *head = NULL;
}

static void sort_list(struct list *head) {
  if (!head)
    return;

  int swapped;
  do {
    swapped = 0;
    for (struct list *p = head; p->next; p = p->next) {
      if (strcmp(p->word, p->next->word) > 0) {
        swap_elements(p, p->next);
        swapped = 1;
      }
    }
  } while (swapped);
}

int main(void) {
  char s[4096];

  if (!fgets(s, (int)sizeof(s), stdin))
    return 0;

  char *dot = strchr(s, '.');
  if (dot)
    *dot = '\0';

  struct list *head = NULL;

  char *tok = strtok(s, " \n\r\t");
  while (tok) {
    head = add_to_list(head, tok);
    tok = strtok(NULL, " \n\r\t");
  }

  sort_list(head);
  print_list(head);
  delete_list(&head);
  return 0;
}
