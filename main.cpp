#include "capacitor.h"
#include <iostream>

int main() {
	const double dt = 1e-10;
	const double finalTime = 5e-6;
	const int numSteps = finalTime / dt;
	const double R = 1e3;
	const double C = 100e-12;
	const double I = 1e-2; 
	const double V0 = 10.0;

	
	Capacitor cap;
    	cap.time = new double[numSteps];
    	cap.voltage = new double[numSteps];
    	cap.current = new double[numSteps];
    	cap.C = C;
	
	
	cap.time[0] = 0.0;
    	cap.voltage[0] = 0.0;
    	cap.current[0] = I;


	simulateConstantCurrent(cap, I, dt, numSteps);
    	std::cout << "Constant Current Case:" << std::endl;
    	printResults(cap, numSteps, 200);


	cap.time[0] = 0.0;
    	cap.voltage[0] = 0.0;
    	cap.current[0] = V0 / R;


	simulateConstantVoltage(cap, V0, R, dt, numSteps);
    	std::cout << "\nConstant Voltage Case:" << std::endl;
    	printResults(cap, numSteps, 200);


	delete[] cap.time;
    	delete[] cap.voltage;
    	delete[] cap.current;

    return 0;
}
