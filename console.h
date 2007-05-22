#ifdef DEBUG
#define DEBUG_CONSOLE
#endif

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "libvnc/libvnc.h"

#define	qemu_malloc(s) malloc((s))
#define	qemu_mallocz(s) calloc(1, (s))
#define	qemu_free(p) free((p))

/* control characters */
#define BEL 0x07
#define BS 0x08
#define HT 0x09
#define LF 0x0A
#define VT 0x0B
#define FF 0x0C
#define CR 0x0D
#define SO 0x0E
#define SI 0x0F
#define CAN 0x18
#define ESC 0x1B
#define DEL 0x7F
#define CSI 0x9B

struct CharDriverState {
    void *opaque;
    int (*chr_write)(struct CharDriverState *s, const uint8_t *buf, int len);
};
typedef struct CharDriverState CharDriverState;

CharDriverState *text_console_init(DisplayState *);
void kbd_put_keysym(int keysym);
void console_select(unsigned int index);
void console_set_input(CharDriverState *s, int fd, void *opaque);
int console_input_fd(CharDriverState *s);

int mouse_is_absolute(void *);
void mouse_event(int dx, int dy, int dz, int buttons_state, void *opaque);

void dump_console_to_file(CharDriverState *chr, char *fn);
