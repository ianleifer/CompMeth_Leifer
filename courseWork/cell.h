#ifndef CELL_H
#define CELL_H

#include "variable.h"

class Cell {
public:
    Cell();
    Variable tick();
    void addConnection(Cell *source, double weight);
    void setPhaseSpaceDimensionality(int pphaseSpaceDimensionality);
    double getVariable(int dim);
protected:
    int phaseSpaceDimensionality;
    int numberOfConnections;
    struct Connection {
        Cell *source;
        double weight;
    };
    std::vector<Connection> connections;
    
    Variable variable;
    virtual Variable solveEquation() = 0;
};

#endif
