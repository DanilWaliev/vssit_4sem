int func1(int arg) {
    int result = 0;
    result = (arg - 32) * 5 / 9;
    return result;
}

int func2(int arg1, int arg2) {
    arg1 += arg2;
    return arg1;
}

int main() {
    int a, b;
    a = func1(100);     // 100 = 0x64
    b = func2(8, 16);   // 16 = 0x10
    return 0;
}