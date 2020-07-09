// ICA_Group 2:
//Group Members: Christopher Reiner, Curtis Davis, Miguelangel Rodriguez, Pravin Henderson

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Shape {
    private:
        string id;

    public:
        string type;

        //Outputs type of shape, virtual function
        string getType() {
            return type;
        }

        //Returns id of shape
        string getId() {
            return id;
        }

        //Sets id of shape
        void setId(string idParam) {
            id = idParam;
        }

        //Virtual function for cloning
        virtual Shape* clone() const = 0;
};

//Circle class derived from abstract shape class
class Circle : public Shape {
    public:
        Shape* clone() const {
            return new Circle(*this);
        }
};

//Rectangle class derived from abstract shape class
class Rectangle : public Shape {
    public:
        Shape* clone() const {
            return new Rectangle(*this);
        }
};

//Square class derived from abstract shape class
class Square : public Shape {
    public: 
        Shape* clone() const {
            return new Square(*this);
        }
};


int main() {

    Rectangle rect;
    Circle circ;
    Square square;

    rect.type = "Rectangle";
    circ.type = "Circle";
    square.type = "Square";

    cout << rect.getType() << endl;
    cout << circ.getType() << endl;
    cout << square.getType() << endl;

    return EXIT_SUCCESS;
}