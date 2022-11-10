# ***Exercise 7 Solutions***

## **Classes and Objects**
> Classes and Objects<br>
Write the definition for a class called Rectangle that has floating point data members length and width. <br>
The class has the following member functions:<br>
void setlength(float) to set the length data member<br>
void setwidth(float) to set the width data member<br>
float perimeter() to calculate and return the perimeter of the rectangle<br> 
float area() to calculate and return the area of the rectangle<br>
void show() to display the length and width of the rectangle<br>
int sameArea(Rectangle) that has one parameter of type Rectangle. sameArea returns 1 if the two Rectangles have the same area, and returns 0 if they don't.<br>
1.Write the definitions for each of the above member functions.<br>
2.Write main function to create two rectangle objects. Set the length and width of the first rectangle
to 5 and 2.5. Set the length and width of the second rectangle to 5 and 18.9. Display each
rectangle and its area and perimeter.<br>
3.Check whether the two Rectangles have the same area and print a message indicating the result. Set the length and width of the first rectangle to 15 and 6.3. Display each Rectangle and its area and perimeter again. Again, check whether the two Rectangles have the same area and print amessage indicating the result

```
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
```
## **Constructors**
> Consider the definition of the following class:

```
class Sample {
private:
    int x;
    double y;
public:
    Sample(); //Constructor 1
    Sample(int); //Constructor 2
    Sample(int, int); //Constructor 3
    Sample(int, double); //Constructor 4
}
```
> i. Write the definition of the constructor 1 so that the private member variables are initialized to 0

`Sample() : x(0), y(0) { }` or `Sample() = default;`

> ii. Write the definition of the constructor 2 so that the private member variable x is initialized to value of the parameter and the private member variable y is initialized to 0

`Sample(int x_) : x(x_), y(0) { }`

> iii. Write the definition of the constructors 3 and 4 so that the private member variables are initialized according to the values of the parameters.

`Sample(int x_, int y_) : x(x_), y(double(y_) { }`
`Sample(int x_, double y_) : x(x_), y(y_) { }`

## **Struct**
> Give the output of the following program. Assuming all the desired header files are already inclueed, which are required to run the code.

```
struct Pixel{
    int C, R;
};

void Display(Pixel P){
    cout << "Col " << P.C << " Row " << P.R << endl;
}

int main()
{
    Pixel X = {40, 50}, Y, Z;
    Z = X; //Pixel Z = {40, 50}
    X.C += 10; //add 10 to C which was 40 so Pixel X = {50, 50}
    Y = Z; //Pixel Y = {40, 50}
    Y.C += 10; //Pixel Y = {50, 50}
    Y.R += 20; //Pixel Y = {50, 70}
    Z.C -= 15; //Pixel Z = {25, 50}
    Display(X); // {50, 50}
    Display(Y); // {50, 70}
    Display(Z); // {25, 50}
    
    return 0;
}
