#include "oscillator.h"
#include <iostream>

Oscillator::Oscillator() {
}

Oscillator::Oscillator(int pphaseSpaceDimensionality) {
    setPhaseSpaceDimensionality(pphaseSpaceDimensionality);
}

/* In this function we can see that everything is hardcoded. When I wrote this function I meant
that oscillator will always have 2 dimensions and all methods are for 2D problems */
Variable Oscillator::solveEquation() {
    Variable var(phaseSpaceDimensionality);
    double h = 0.01;
    double xk, yk, xkp, ykp;
    yk = variable.getVariable(0);
    xk = variable.getVariable(1);
//    std::cout << this << std::endl;
//    std::cout << "x = " << xk << "; y = " << yk << std::endl;
    double delta = getConnectionContribution();
    
// This is Runge-Kutta method

//    Variable k1(phaseSpaceDimensionality), k2(phaseSpaceDimensionality), k3(phaseSpaceDimensionality), k4(phaseSpaceDimensionality);
//    k1.setVariable(0, h * yk);
     
    
// This is Euler method, we want to compare it to 4th order Runge-Kutta and Leapfrog
    
    xkp = xk + h * yk;
    ykp = yk + h * delta;
    
//    std::cout << "xp = " << xkp << "; yp = " << ykp << std::endl;
    var.setVariable(0, ykp);
    var.setVariable(1, xkp);
    return var;
}

double Oscillator::getConnectionContribution() {
    double total = 0;
    for(int i = 0; i < numberOfConnections; i++) {
        total += connections[i].weight * connections[i].source->getVariable(1);
    }
    return total;
}
