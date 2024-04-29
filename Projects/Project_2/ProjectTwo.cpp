/*
Given a muzzle velocity and angle, calculate the distance, max_height, and flight time of the ball.

Based on the inputted velocity and angle, compute the following values: (20 points)


Flight time in seconds accurate to a hundredth of a second (2 decimals)

Max height in meters and feet (printed to 2 decimal places)

Distance in meters and feet (printed to 1 decimal place)
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

#ifndef M_PI
#define M_PI 3.14159
#endif

// Constants
const double g = 9.81; // Acceleration due to gravity (m/s^2)
const double dt = 0.01; // Time step (s)
const double airDensity = 1.225; // Air density at sea level (kg/m^3)
const double dragCoefficient = 0.47; // Drag coefficient for a sphere
const double radius = 0.3; // Radius of the projectile (m)
const double area = M_PI * radius * radius; // Cross-sectional area (m^2)
const double mass = 3.0; // Mass of the projectile (kg)
// Function to calculate the acceleration due to air resistance

void airResistance(double vx, double vy, double &ax, double &ay) 
{
    double speed = std::sqrt(vx * vx + vy * vy);
    double force = 0.5 * airDensity * dragCoefficient * area * speed * speed;
    ax = -force / mass * (vx / speed);
    ay = -force / mass * (vy / speed);
}

int main() {

    // Initial conditions

    double x = 0, y = 0, time=0, ax=0, ay=0, max_height = 0; // Initial position (m)
    double angle = 1; // Launch angle (degrees)
    double muzzle = 1; // Initial speed (m/s)
    double vx = 0;
    double vy = 0;
    

    int step_num=0;
    int choice = 0;

    std::cout << "Select a mode please: " << std::endl;

    std::cout << "1. Calculate projectile distance given a muzzle velocity and angle. " << std::endl;

    std::cout << "2. Given a maximum muzzle velocity and a target distance, create a comma seperated target of distances and print the angles and velocities needed to hit the target if it's possible. " << std::endl;

    std::cout <<"3. Given a maximum muzzle velocity, generate a table in a formatted text file of distances. " << std::endl;

    std::cin >> choice;
    std::cout << std::endl;

    if(choice == 1)
    {
        std::cout << "Give me a muzzle velocity and an angle, please: " << std::endl;
        std::cout << "Muzzle: ";
        std::cin >> muzzle;
        std::cout << "Angle: ";
        std::cin >> angle;
        std::cout << std::endl;
        double vx = muzzle * std::cos(angle * M_PI / 180);
        double vy = muzzle * std::sin(angle * M_PI / 180);

        while (y >= 0) 
            {
                // Update position
                x += vx * dt;
                y += vy * dt;

                // Calculate acceleration due to air resistance
                airResistance(vx, vy, ax, ay);

                // Update velocity
                vx += ax * dt;
                vy += (ay - g) * dt; // Include gravity

                time += dt;
                if(y > max_height)
                {
                    max_height = y;
                }

                // Break if the projectile hits the ground
                if (y < 0) break;

            }  // End while
        std::cout << "The maximum height of the projectile is " << std::fixed << std::setprecision(2) << max_height << "!" << std::endl;
        std::cout << std::endl;
        std::cout << "The distance traveled by the projectile is " << std::fixed << std::setprecision(2) << x << "!" << std::endl;
        std::cout << std::endl;
        std::cout << "The time it took for the projectile to fall back to the ground is " << std::fixed << std::setprecision(1) << time << "!" << std::endl;
        std::cout << std::endl;
    }
    else if(choice == 2)
    {
        x=1
        
    }
    else if(choice == 3)
    {
        const int MAX_ANGLE = 90;
        const int MAX_VELOCITY = 15 * 30;

        double calculateDistance(double angle, double velocity) 
        {
        double radian = angle * M_PI / 180.0;
        double vx = velocity * cos(radian);
        double vy = velocity * sin(radian);
        double time = vy / 9.81; // assuming g = 9.81 m/s^2
        double distance = vx * time;
        return distance;
        }

        int main() 
        {
            std::vector<std::vector<double>> distanceArray(15, std::vector<double>(30));

            for (int i = 0; i < 15; i++) 
            {
                for (int j = 0; j < 30; j++) 
                {
                    double angle = i * MAX_ANGLE / 15.0;
                    double velocity = j * MAX_VELOCITY / 30.0;
                    distanceArray[i][j] = calculateDistance(angle, velocity);
                }
             }

            // print the array for demonstration
            for (int i = 0; i < 15; i++) 
            {
                for (int j = 0; j < 30; j++) 
                {
                    std::cout << distanceArray[i][j] << "\t";
                }
                std::cout << std::endl;
            }

            return 0;
        }
    }
    else
    {
        std::cout << "You're stupid, try again!" << std::endl;
    }

    // Simulation loop
    /*while (y >= 0) 
    {
        // Update position
        x += vx * dt;
        y += vy * dt;

        // Calculate acceleration due to air resistance
        airResistance(vx, vy, ax, ay);
        //ax = 0;  // make air resistance zero
        //ay = 0;  // make air resistance zero

        // Update velocity
        vx += ax * dt;
        vy += (ay - g) * dt; // Include gravity

        // Output the current position
        std::cout << "Position: (" << x << ", " << y << ")" << ", Time: " << time << std::endl;
        
        //Or plot an asterisk
        step_num++;
        if(step_num%2 == 0)
        {
            std::cout << std::setw((int)(y*50/37.0)) << '*' 
            << std::setw(5) << std::fixed << std::setprecision(1) 
            << y << std::endl;
        } 

        time += dt;
        if(y > max_height)
        {
            max_height = y;
        }

        // Break if the projectile hits the ground
        if (y < 0) break;

    }  // End while 
    */
    // std::cout << "Max height: " << max_height << std::endl;
    // std::cout << area << std::endl;
    return 0;
}