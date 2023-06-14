#include "gmsh.h"
#include "Mesher.h"
#include <string>

namespace tigl {

Mesher::Mesher() { gmsh::initialize(); }
Mesher::~Mesher(){ gmsh::finalize(); }

static Mesher& get_instance()
{
        static Mesher m;
        return m;
}

//Options: dimensions: digit 1-3, min and max elementsize (0-1e+22)
void Mesher::set_options(int dimensions, int min, int max)
{
    options.dim = dimensions;
    options.minelementsize = min;
    options.maxelementsize = max;

    gmsh::option::setNumber("Mesh.MeshSizeMin", options.minelementsize);
    gmsh::option::setNumber("Mesh.MeshSizeMax", options.maxelementsize);
}


// imports an TopoDS_Shape by using a pointer to void
void Mesher::import(TopoDS_Shape shape)
{
    gmsh::vectorpair outDimTags;
    gmsh::model::occ::importShapesNativePointer((void const*)&shape, outDimTags);
    gmsh::model::occ::synchronize();

}

// meshes the previous called Shape (currently without a size option) and save it as .msh
void Mesher::mesh()
{  
    gmsh::model::mesh::generate(options.dim);

    //gmsh::write(options.getName().c_str());
}

// refines the mesh by splitting the Elemnts and saves it as .msh
void Mesher::refine()
{
    gmsh::model::mesh::refine();
    
    //gmsh::write(options.getName().c_str());
}

void Mesher::write(std::string myName)
{

    gmsh::write(myName.c_str());

}
}
