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



// Constants
const double g = 9.81; // Acceleration due to gravity (m/s^2)
const double dt = 0.01; // Time step (s)
const double airDensity = 1.225; // Air density at sea level (kg/m^3)
const double dragCoefficient = 0.47; // Drag coefficient for a sphere
const double radius = 0.1; // Radius of the projectile (m)
const double area = M_PI * radius * radius; // Cross-sectional area (m^2)
const double mass = 3.0; // Mass of the projectile (kg)
// Function to calculate the acceleration due to air resistance

double get_distance(double angle, double speed, bool print = false);

void airResistance(double vx, double vy, double &ax, double &ay)
{
    double speed = std::sqrt(vx * vx + vy * vy);
    double force = 0.5 * airDensity * dragCoefficient * area * speed * speed;
    ax = -force / mass * (vx / speed);
    ay = -force / mass * (vy / speed);
}

double get_distance(double angle, double muzzle, bool print)
{
    double vx, vy;
    double x = 0, y = 0, time=0, ax=0, ay=0, max_height = 0; // Initial position (m)
    vx = muzzle * std::cos(angle * M_PI / 180);
    vy = muzzle * std::sin(angle * M_PI / 180);
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

    if(print == true)
    {
        std::cout << "The maximum height of the projectile is " << std::fixed << std::setprecision(2) << max_height << "!\n" << std::endl;
        std::cout << "The distance traveled by the projectile is " << std::fixed << std::setprecision(2) << x << "!\n" << std::endl;
        std::cout << "The time it took for the projectile to fall back to the ground is " << std::fixed << std::setprecision(1) << time << "!\n" << std::endl;
    }
    return x;

}
int main() {

    int choice;

    std::cout << "Select a mode please: " << std::endl;

    std::cout << "1. Calculate projectile distance given a muzzle velocity and angle. " << std::endl;

    std::cout << "2. Given a maximum muzzle velocity and a target distance, create a comma seperated target of distances and print the angles and velocities needed to hit the target if it's possible. " << std::endl;

    std::cout <<"3. Given a maximum muzzle velocity, generate a table in a formatted text file of distances. " << std::endl;

    std::cin >> choice;
    std::cout << std::endl;

    if(choice == 1)
    {
        double muzzle;
        double angle;
        std::cout << "Give me a muzzle velocity and an angle, please: " << std::endl;
        std::cout << "Muzzle: ";
        std::cin >> muzzle;
        std::cout << "Angle: ";
        std::cin >> angle;
        std::cout << std::endl;

        get_distance(angle,muzzle, true);
    }
    else if(choice == 2)
    {
        std::ofstream fout;

        fout.open("table.txt");

        int rows, columns;
        std::cout << "Give me the size of the array (row and column) please: " << std::endl;
        std::cin >> rows >> columns;
        std::cout << "Give me the maximum velocity please: " << std::endl;
        double max_velocity;
        std::cin >> max_velocity;
        std::cout << "Give me the target distance please: " << std::endl;
        double target_distance;
        std::cin >> target_distance;
        
        
    }
    else if(choice == 3)
    {
        std::ofstream fout;

        fout.open("formatedtable.txt");
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