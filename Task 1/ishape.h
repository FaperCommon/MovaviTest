#ifndef ISHAPE_H
#define ISHAPE_H
#include "iostream"
#include "math.h"

class IShape
{
public:
    double virtual  Area() = 0;
    virtual ~IShape(){}
};
//Class Square--------------
class Square:public IShape{
public:
    Square():lenght(0.0){}
    Square(double l)
    {
        if(l > 0)
            lenght = l;
        else throw "lenght must be > 0\n";
    }

    double Area()override
    {
        return lenght*lenght;
    }
    ~Square() override{}
private:
    double lenght;
};
//Class Rectangle--------------
class Rectangle:public IShape{
public:
    Rectangle():width (0.0),height (0.0){}
    Rectangle(double w, double h)
    {
        if(w > 0 && h > 0){width = w; height = h;}
        else throw "width and height must be > 0\n";
    }

    double Area() override { return width * height; }
    ~Rectangle() override{}
private:
    double width;
    double height;
};
//Class Circle--------------

class Circle:public IShape{
public:
    Circle():radius(0.0){}
    Circle(double r)
    {
        if(r > 0){radius = r;}
        else throw "radious must be > 0\n";
    }
    ~Circle() override{}
    virtual double Area() override{return radius*radius*M_PI; }
private:
    double radius;
};
//Class Triangle--------------
class Triangle:IShape{
public:
    Triangle():side1(0.0), side2 (0.0),side3 (0.0){}
    Triangle(double s1, double s2, double s3)
    {
        if(s1 > 0 && s2 > 0 && s3 > 0){side1 = s1; side2 = s2; side3 = s3;}
        else throw "sides must be > 0\n";
    }
    double Area()override
    {
        double p = (side1+side2+side3)/2;
        if()
        return (((std::sqrt(p*(p-side1)*(p-side2)*(p-side3)))*2)/side1)*side1*0.5;
    }

    virtual ~Triangle() override{}
private:
    double side1;
    double side2;
    double side3;
};

#endif // ISHAPE_H
