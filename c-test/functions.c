int f(int x) {
    int output = x * x;
    return output;
}

int g(int x) {
    int output = x + x;
    return output;
}

int h(int x) {
    int output = g(f(x));
    return output;
}
