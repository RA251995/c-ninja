int global_initialized_integer = 123456789;
char global_uninitialized_char;

int _start() {
    char character = 'a';
    int integer = global_initialized_integer;
    float decimal_number = 1.23;
    double decimal_number_more_precision = 0.23;

    global_uninitialized_char = character;

    long int uninitialized;

    static unsigned int static_integer = 987654321;

    global_uninitialized_char = 2;
}
