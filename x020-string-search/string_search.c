#include "string_search.h"
#include <assert.h>

int naiveSearch(const char *hayStack, const char *needle, size_t start) {
    size_t hlen = strlen(hayStack);
    size_t nlen = strlen(needle);

    assert(start >= 0 && start < hlen);

    if (nlen > (hlen - start)) {
        return -1;
    }

    return 0;
}
