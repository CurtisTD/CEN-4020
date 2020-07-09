// ICA_Group 2:
//Group Members: Christopher Reiner, Curtis Davis, Miguelangel Rodriguez, Pravin Henderson

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


class ShapeCache {
    private:
        //Hashmap of shapes
        vector<Shape*> shapeMap;

    public:
        Shape* getShape(string shapeToFind) {
            for(int i = 0; i < (int)shapeMap.size(); i++) {
                if( shapeMap[i]->getType() == shapeToFind ) {
                    return shapeMap[i]->clone();
                }
            }
            cout << "Shape not found: " << shapeToFind << endl;
            return 0;
        }

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

    //Loads the cache with arbitrary shapes
    shapeCache.loadCache();
    
    //Gets a clone of an object
    Shape* circ = shapeCache.getShape("Circle");
    Shape* rect = shapeCache.getShape("Rectangle");
    Shape* sqr = shapeCache.getShape("Square");

    //Prints out the clones
    cout << circ->getType() << endl;
    cout << rect->getType() << endl;
    cout << sqr->getType() << endl;

    return EXIT_SUCCESS;
}