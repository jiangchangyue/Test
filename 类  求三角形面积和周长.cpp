#include<iostream>
#include<cmath>
using namespace std;
class Ctriangle
{
public:
    Ctriangle(double x,double y,double z)
    {
        a=x;
        b=y;
        c=z;
    }
    double getperimeter()
    {
        return a+b+c;
    }
    double getarea()
    {
        double p=getperimeter()/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    void display()
    {
        cout<<"ctriangle:"<<"a="<<a<<" "<<"b="<<b<<" "<<"c="<<c<<endl;
        cout<<"perimeter:"<<getperimeter()<<endl;
        cout<<"area:"<<getarea()<<endl;
    }
private:
    double a;
    double b;
    double c;
};
int main()
{
    Ctriangle T(3,4,5);
    T.display();
    return 0;
}
