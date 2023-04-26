#pragma once
#include "gmsh.h"
#include <string>
#include "TopoDS_Shape.hxx"


class Mesher 
{
public: 

    class Options 
    {
    public:

    void setDimension(int dimension);

    int getDimension();

    void setSize(int mySize);

    int getSize();

    void setName(std::string myName);

    std::string getName();
 
    private:
        int dim;
        double size;
        std::string fileName; 
    };

Mesher();
~Mesher();
void set_options(int dimensions,double mySize, std::string myName);
void mesh();
void import(TopoDS_Shape shape);

// Refine the mesh of the current model by uniformly splitting the elements.
void refine();

    
private:
    Options options;
};
