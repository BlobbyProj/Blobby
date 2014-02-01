#include "rectangle.h"

Rectangle::Rectangle(double X, double Y, double W, double H){
    Point p;
    p.x = X;
    p.y = Y;
    position = p;
    width = W;
    height = H;
}
/*
int main() {
    Rectangle * r = new Rectangle(15, 20, 60, 50);
    Rectangle r =
    
    return 0;
}*/