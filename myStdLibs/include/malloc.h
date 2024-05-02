// windows c only

#ifndef __MALLOC_H__
#define __MALLOC_H__

#include "miniWin_stdlib.h"

// Heap Flag Defaults and Protocols
#define HEAPFLAG_EXECUTABLE     false
#define HEAPFLAG_GEN_EXCEPTIONS false
#define HEAPFLAG_NO_SERIALIZE   false
#define HEAP_INITIALSIZE        0
#define HEAP_MAXSIZE            0
void *initHeap();
BOOL destroyHeap();
BOOL changeHeap(void *heap);

#endif // __MALLOC_H__