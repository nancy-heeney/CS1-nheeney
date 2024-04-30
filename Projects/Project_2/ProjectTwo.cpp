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

        double *distances = new double[rows*columns];
        double *speeds = new double[columns+1];
        double *angles = new double[rows+1];
        for(int i=0; i<=columns; i++) // Fill in speeds array
        {
            double speed_inc = max_velocity/columns;
            *(speeds+i) = i*speed_inc;
            fout << *(speeds+i) << ',';
            std::cout << *(speeds+i) << ',';
        }
        fout << '\n';
        std::cout << '\n';
        for(int i=0; i<=rows; i++) // Fill in angles array
        {
            double angle_inc = 90.0/rows;
            *(angles+i) = i*angle_inc;
        }

        //std::cout << distances << std::endl;

        for(int i=0; i<rows; i++)
        {
            fout << *(angles + i+1) << ',';
            std::cout << *(angles + i+1) << ',';
            for(int j=0; j<columns; j++)
            {
                double val = *(distances + i*columns+j) = get_distance(angles[i+1], speeds[j+1]);
                //double *address_of_current_val;
                //address_current_val = distances;
                std::cout << std::fixed << std::setprecision(2) << val << ',';
                fout << std::fixed << std::setprecision(2) << val << ',';
            }
            std::cout << '\n';
            fout << '\n';
        
        }
        std::cout << "\nI found these results for you: " << std::endl;
        std::cout << "Your angle is: " << std::setw(15) << "Your speed is: " << std::setw(15) << "Your distance is: " << std::setw(15) << std::endl;
        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<columns; j++)
            {
                double val = *(distances + i*columns + j);
                if(fabs(val-target_distance) <= 0.05)
                {
                    std::cout << std::setw(1) << angles[i+1]<< std::setw(15) << speeds[j+1] << std::setw(14) << val << std::endl;
                }
            }
        }

        delete [] distances;
        fout.close();
        
    }
    else if(choice == 3)
    {
        std::ofstream fout;

        fout.open("formatedtable.txt");

        int rows = 15;
        int columns = 30;
        std::cout << "Give me the maximum velocity please: " << std::endl;
        double max_velocity;
        std::cin >> max_velocity;

        double *distances = new double[rows*columns];
        double *speeds = new double[columns+1];
        double *angles = new double[rows+1];
        for(int i=0; i<=columns; i++) // Fill in speeds array
        {
            double speed_inc = max_velocity/columns;
            *(speeds+i) = i*speed_inc;
            fout << *(speeds+i) << std::fixed << std::setprecision(2) << std::setw(10);
            std::cout << *(speeds+i) << std::fixed << std::setprecision(2) << std::setw(10);
        }
        fout << '\n';
        std::cout << '\n';
        for(int i=0; i<=rows; i++) // Fill in angles array
        {
            double angle_inc = 90.0/rows;
            *(angles+i) = i*angle_inc;
        }

        //std::cout << distances << std::endl;

        for(int i=0; i<rows; i++)
        {
            fout << *(angles + i+1) << std::fixed << std::setprecision(2) << std::setw(2);
            std::cout << *(angles + i+1) << std::setw(8);
            for(int j=0; j<columns; j++)
            {
                double val = *(distances + i*columns+j) = get_distance(angles[i+1], speeds[j+1]);
                //double *address_of_current_val;
                //address_current_val = distances;
                std::cout << std::fixed << std::setprecision(2) << val << std::setw(8);
                fout << std::fixed << std::setprecision(2) << val << std::setw(8);
            }
            std::cout << '\n';
            fout << '\n';
        }
        fout.close();

    }

    else
    {
        std::cout << "You're stupid, try again!" << std::endl;
    }

    

    return 0;
}