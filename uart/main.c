/* 16550 UART */
typedef struct {
    union {
        volatile unsigned char thr;
        volatile const unsigned char rhr;
    };

    volatile unsigned char ignore0[4];

    union {
        struct {
            volatile const unsigned char data_ready:1;
            volatile const unsigned char overrun_err:1;
            volatile const unsigned char parity_err:1;
            volatile const unsigned char framing_err:1;
            volatile const unsigned char break_interrupt:1;
            volatile const unsigned char thr_empty:1;
            volatile const unsigned char tx_empty:1;
            volatile const unsigned char fifo_data_err:1;
        } __attribute__((packed));
        volatile const unsigned char b;
    } lsr;

    volatile const unsigned char ignore1[2];
} __attribute__((packed)) uart_t;

#define UART0_BASE_ADDRESS (0x10000000)

void putc(uart_t *uart, char c) {
    while (!(uart->lsr.tx_empty));

    uart->thr = (unsigned char)c;
}

char getc(uart_t *uart) {
    if (uart->lsr.data_ready) {
        return uart->rhr;
    }

    return 0;
}

int main() {
    uart_t *uart0 = (uart_t *)UART0_BASE_ADDRESS;
    char c = 0;
    const char welcome_str[] = "!!! Welcome to Echo Terminal !!!\n";

    for (int i = 0; i < sizeof(welcome_str); i++)
    {
        putc(uart0, welcome_str[i]);
    }

    while (1) {
        c = getc(uart0);
        if (c > 0) {
            putc(uart0, c);
        }
    }

    return 0;
}
