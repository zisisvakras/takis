double defint(double a, double b, double (*f)(double), double epsilon) {
    double area = 0;
    for (double x = a ; x <= b - epsilon ; x += epsilon) {
        area += (*f)(x) * epsilon;
    }
    return area;
}