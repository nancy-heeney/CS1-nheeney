/*
    CS1 - File IO Lab

    Updated by: Nancy Heeney
    Date: 04.26.2024

    The program reads numbers from a file and finds statistical values from those numbers.
    Lab demonstrates the file io and vector application. 
    Statistical value's definitions for mean, median, mode, etc. can be found here: https://www.purplemath.com/modules/meanmode.htm
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const float EPSILON = 1e-4; //accuracy upto 4 decimal points

// function prototypes
void readData(vector<int> &, const string);
int findMax(const vector<int> &);
int findMin(const vector<int> &);
float findMean(const vector<int> &); // average
int findRange(const vector<int> &);
float findMedian(vector<int>);
// bonus implement findMode function
int findMode(const vector<int> &);

void writeData(const vector<int> & numbers);
void test();

int main(int argc, char* argv[]) {
    if (argc == 2 && string(argv[1]) == "test") {
        test();
        return 0;
    }
    vector<int> numbers;
    string inFile;
    cout << "Enter input file name: ";
    getline(cin, inFile);
    readData(numbers, inFile);
    writeData(numbers);
    cout << "All done. Enter to exit...";
    cin.get();
    return 0;
}

void readData(vector<int> & numbers, const string inputFileName) 
{
    // FIXED    
    // read the data until eof marker and store each num into numbers vector
    std::ifstream file(inputFileName);
    if (file.is_open()) 
    {
        // Read the data until eof marker and store each num into numbers vector
        while (file >> num) 
        {
            numbers.push_back(num);
        }
        file.close();
    } 
    else 
    {
        std::cout << "Unable to open file" << std::endl;
    }
    int num;
}

void writeData(const vector<int> & numbers) 
{
    // FIXED
    /*
    Algorithm steps:
    1. Prompt user to enter output file name
    2. Store and use the file name to open the file in write mode
    3. Write output as shown in output.txt file with proper formatting using iomanip
    */
   std::string outputFileName;
    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    // Open the file in write mode
    std::ofstream file(outputFileName);

    // Write output as shown in output.txt file with proper formatting using iomanip
    for (size_t i = 0; i < numbers.size(); i++) 
    {
        file << std::setw(5) << i + 1 << ": " << std::setw(5) << numbers[i] << std::endl;
    }

    file.close();
}

int findMax(const vector<int> & nums) 
{
    int max = nums[0];
    for(int n: nums)
        max = (n>max) ? n : max;
    return max;
}

int findMin(const vector<int> & nums) 
{
    // FIXED - implement function to find and return min value in nums vector
    auto min_it = std::min_element(nums.begin(), nums.end());

    // Check if nums is non-empty and return min value
    if (min_it != nums.end()) 
    {
        return *min_it;
    } 
    else 
    {
        return 0;
    }
    return 0;
} 

float findMean(const vector<int> & nums) 
{
    // same as average
    long long int sum = 0;
    for(int n: nums)
        sum += n;
    return sum/float(nums.size());
}

int findRange(const vector<int> & nums) 
{
    // FIXED - implement function that finds and returns the range value
    // range = max - min
    int min = *std::min_element(nums.begin(), nums.end());
    int max = *std::max_element(nums.begin(), nums.end());

    return max - min;
    
    return 0;
}

float findMedian(vector<int> nums) 
{
    sort(nums.begin(), nums.end());
    float median;
    if (nums.size() % 2 == 0) {  // even set
        median = (nums[nums.size()/2] + nums[nums.size()/2-1])/float(2);
    } else { // odd set
        median = nums[nums.size()/2];
    }
    return median;
}

void test() 
{
    vector<int> numbers = {100, 10, 5, 0, -99, 10, 99};
    //cout << findMean(numbers) << " " << findMean(numbers)-17.857142 << endl;
    assert(fabs(findMean(numbers)-17.857142) <= EPSILON );
    assert(findMax(numbers) == 100);
    assert(findMedian(numbers) == 10);
    vector<int> numbers1 = {10, 10, 10, 0, -10, -10};
    assert(fabs(findMean(numbers1) -1.6667) <= EPSILON  );
    assert(findMax(numbers1) == 10);
    assert(findMedian(numbers1) == 5);
    // FIXED: Write at least two test cases for other functions
    assert(findMin(numbers) == -99);
    assert(findRange(numbers) == 198);

    cerr << "all test cases passed!\n";
}