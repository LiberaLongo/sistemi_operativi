#ifndef _DUMP_H
#define  _DUMP_H
#include <stdio.h>
#include <stdint.h>

#define BINARYFMT "%c%c%c%c%c%c%c%c"
#define BINARYPRINT(x) \
	((x) & 0x80) ? '1' : '0', \
	((x) & 0x40) ? '1' : '0', \
	((x) & 0x20) ? '1' : '0', \
	((x) & 0x10) ? '1' : '0', \
	((x) & 0x08) ? '1' : '0', \
	((x) & 0x04) ? '1' : '0', \
	((x) & 0x02) ? '1' : '0', \
	((x) & 0x01) ? '1' : '0'

#define hexdump(v) _hexdump(#v, &v, sizeof(v));
static inline void _hexdump(char *name, void *v, size_t len) {
	uint8_t *byte = v;
	printf("%s: len %d\n", name, len);
	for (int i = 0; i < len; i++)
		printf("%02x ",byte[i]);
	printf("\n");
}

#define bindump(v) _bindump(#v, &v, sizeof(v));
static inline void _bindump(char *name, void *v, size_t len) {
	uint8_t *byte = v;
	printf("%s: len %d\n", name, len);
	for (int i = 0; i < len; i++)
		printf(BINARYFMT " ",BINARYPRINT(byte[i]));
	printf("\n");
}

#endif
