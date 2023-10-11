int main() {
    int k, x, y;
    float PI = 3.14159265359;
    sscanf(Stdio.stdin->gets(), "%d", k);
    sscanf(Stdio.stdin->gets(), "%d %d", x, y);
    float a = k * PI / 180;
    write(sprintf("%.12f %.12f", (cos(a) * x - sin(a) * y), (sin(a) * x + cos(a) * y)));

    return 0;
}