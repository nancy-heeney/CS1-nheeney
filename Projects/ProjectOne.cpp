#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int unit;
    double g = 9.81;
    double theta;
    double max_h;
    double flight_time;
    double x_distance;
    double max_distance;
    double muzzle_velocity;
    double target_distance;

    cout << "Enter the desired units. Press 1 for feet and 2 for meters: \n";
    cin >> unit;

    cout << "Enter desired angle in degrees: \n";
    cin >> theta;

    theta = theta * M_PI / 180;

    cout << "Enter desired muzzle velocity: \n";
    cin >> muzzle_velocity;

    cout << "Enter target distance: \n";
    cin >> target_distance;

    if (unit == 1)
    {
        muzzle_velocity = muzzle_velocity * 0.3048;
        target_distance = target_distance * 0.3048;
    }


    max_h = pow(muzzle_velocity, 2) * (pow(sin(theta), 2)) / (g * 2);

    flight_time = ((2 * muzzle_velocity) * (sin(theta))) / g;

    x_distance = (pow(muzzle_velocity, 2) * sin (theta * 2)) / g;

    max_distance = (pow(muzzle_velocity, 2) * sin ((45 * (M_PI / 180)) * 2)) / g;

    if (unit == 2)
    {
        cout << "\nFlight time is: " << fixed << setprecision(2) << flight_time << endl;

        cout << "Max height is: " << fixed << setprecision(2) << max_h << endl;

        cout << "Distance is: " << fixed << setprecision(1) << x_distance << endl;

        if(x_distance>max_distance)
        {
            cout << "Your projectile will not make it to the target" << endl;
        }
    }
    else if (unit == 1)
    {
        cout << "\nFlight time is: " << fixed << setprecision(2) << flight_time << endl;

        cout << "Max height is: " << fixed << setprecision(2) << max_h / 0.3048 << endl;

        cout << "Distance is: " << fixed << setprecision(1) << x_distance / 0.3048 << endl;

        if(x_distance>max_distance)
        {
            cout << "Your projectile will not make it to the target" << endl;
        }
    }

    return 0;
}

