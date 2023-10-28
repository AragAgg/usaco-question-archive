pair<int, int> getRatio(int a, int b) {
    int g = __gcd(a, b);
    a /= g;
    b /= g;
    return {a, b};
}
