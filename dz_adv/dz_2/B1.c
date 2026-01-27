#include <stdint.h>
#include <stdio.h>

typedef struct list {
  uint64_t address;
  size_t size;
  char comment[64];
  struct list *next;
} list;

uint64_t totalMemoryUsage(list *head) {
  if (head == NULL)
    return 0;

  uint64_t max_addr = head->address;
  size_t max_size = head->size;

  list *cur = head->next;

  while (cur != NULL) {

    max_size += cur->size;
    max_addr = cur->address;

    cur = cur->next;
  }

  return max_size;
}

int main(void) { return 0; }
