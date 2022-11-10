#include <iostream>

using std::string;
using std::istream;
using std::ostream;
using std::cout;
using std::endl;

class Rectangle
{
    public:
        Rectangle() = default;
        Rectangle(float len, float wd) : length(len), width(wd) { }
        void setLength(float l) { length = l; }
        void setWidth(float w) { width = w; }
        float getLength() { return length; }
        float getWidth() { return width; }
        float perimeter() 
        { 
            return ((2*length) + (2*width));
        }
        float area()
        {
            return (length*width);
        }
        void show()
        {
            printf("length: %.2f, width: %.2f\n",length,width);
        }
        int sameArea(Rectangle compareTo)
        {
            if (getLength() == compareTo.getLength() && getWidth() == compareTo.getWidth())
                return 1;
            else
                return 0;
        }
        void reset(float len, float w) 
        { 
            this->length = len;
            this->width = w;
        }
    private:
        float length = 0;
        float width = 0;
};

int main()
{
    Rectangle first(5, 2.5);
    Rectangle second(5, 18.9);
    cout << "First rectangle: ";
    first.show();
    printf("First rectangle's area = %.2f, perimeter = %.2f\n",first.area(),first.perimeter());
    cout << "Second rectangle: ";
    second.show();
    printf("Second rectangle's area = %.2f, perimeter = %.2f\n",second.area(),second.perimeter());
    if (first.sameArea(second))
        cout << "\nThey have the same area: " << first.area() << endl;
    else
        cout << "\nThey have different areas" << endl;

    first.reset(15, 6.3);
    cout << "First rectangle after change: ";
    first.show();
    printf("First rectangle's area = %.2f, perimeter = %.2f\n",first.area(),first.perimeter());
    cout << "Second rectangle: ";
    second.show();
    printf("Second rectangle's area = %.2f, perimeter = %.2f\n",second.area(),second.perimeter());
    if (first.sameArea(second))
        cout << "\nThey have the same area: " << first.area() << endl;
    else
        cout << "\nThey have different areas" << endl;
    return 0;
}