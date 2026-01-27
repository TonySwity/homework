#include <stdint.h>
#include <stdio.h>

typedef struct list {
  uint64_t address;
  size_t size;
  char comment[64];
  struct list *next;
} list;

uint64_t findMaxBlock(list *head) {
  if (head == NULL)
    return 0;

  uint64_t max_addr = head->address;
  size_t max_size = head->size;

  list *cur = head->next;
  while (cur != NULL) {
    if (cur->size > max_size) {
      max_size = cur->size;
      max_addr = cur->address;
    }
    cur = cur->next;
  }

  return max_addr;
}

int main(void) { return 0; }
