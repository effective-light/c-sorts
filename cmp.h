#ifndef _CMP_H_
#define _CMP_H_

#include <stdbool.h>

typedef int (*cmp_t)(const void *, const void *);

void swap(void *, void *, size_t);

#endif // _CMP_H_
