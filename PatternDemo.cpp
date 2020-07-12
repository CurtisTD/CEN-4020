// patternDemo:
// M8 ICA Group 2
// Group Members: Christopher Reiner, Curtis Davis, Miguelangel Rodriguez, Pravin Henderson

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

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

        //Virtual function for cloning a shape
        //Will return a pointer to a cloned shape
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

//This class holds the concrete shape classes derived from the abstract shape class. 
//It allows main() to get a cloned shape and load the shape cache with the extended shapes.
class ShapeCache {
    private:
        //Hashmap of shapes, concrete classes
        vector<Shape*> shapeMap;

    public:
        //Returns a pointer to a cloned shape based on what type of shape is called from main()
        Shape* getShape(string shapeToFind) {
            for(int i = 0; i < (int)shapeMap.size(); i++) {
                if( shapeMap[i]->getType() == shapeToFind ) {
                    return shapeMap[i]->clone(); //Clone the shape
                }
            }
            cout << "Shape not found: " << shapeToFind << endl;
            return 0;
        }

        //Loads the cache with sample shapes to be used
        void loadCache(){
            Rectangle* rect = new Rectangle();
            Circle* circ = new Circle();
            Square* square = new Square();

            rect->type = "Rectangle";
            circ->type = "Circle";
            square->type = "Square";
            
            shapeMap.push_back(rect);
            shapeMap.push_back(circ);
            shapeMap.push_back(square);

        }
};

int main() {
    
    //Object with hashmap of shapes
    ShapeCache shapeCache;

    //Loads the cache with arbitrary cocnrete class shapes
    shapeCache.loadCache();
    
    //Gets a pointer to the clone of an object
    Shape* circ1 = shapeCache.getShape("Circle");
    Shape* rect1 = shapeCache.getShape("Rectangle");
    Shape* sqr1 = shapeCache.getShape("Square");

    //Sets the id's of the shapes
    circ1->setId("Circle 1");
    rect1->setId("Rectangle 1");
    sqr1->setId("Square 1");

    //Prints out the clones' types and ids
    cout << circ1->getType() << " -> and its ID: ";
    cout << circ1->getId() << endl;

    cout << rect1->getType() << " -> and its ID: ";
    cout << rect1->getId() << endl;

    cout << sqr1->getType() << " -> and its ID: ";
    cout << sqr1->getId() << endl;

    return EXIT_SUCCESS;
}