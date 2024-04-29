#include <iostream>
#include <cmath>

const int MAX_ANGLE = 90;
const int MAX_VELOCITY = 100;
const int ARRAY_DIM = 10;

double distance(int angle, int velocity) {
    double theta = angle * M_PI / 180.0; // convert angle from degrees to radians
    double v = velocity * 1.0; // convert velocity from integer to double
    return v * v * sin(2 * theta) / 9.8;
}

int main() {
    double distanceArray[ARRAY_DIM][ARRAY_DIM];

    // Calculate distances for each combination of angle and velocity
    for (int i = 0; i < ARRAY_DIM; i++) {
        for (int j = 0; j < ARRAY_DIM; j++) {
            int angle = i * MAX_ANGLE / ARRAY_DIM;
            int velocity = j * MAX_VELOCITY / ARRAY_DIM;
            distanceArray[i][j] = distance(angle, velocity);
        }
    }

    // Output the table as a CSV file
    FILE *csv_file = fopen("distances.csv", "w");
    for (int i = 0; i < ARRAY_DIM; i++) {
        for (int j = 0; j < ARRAY_DIM; j++) {
            fprintf(csv_file, "%.2f,", distanceArray[i][j]);
        }
        fprintf(csv_file, "\n");
    }
    fclose(csv_file);

    return 0;
}