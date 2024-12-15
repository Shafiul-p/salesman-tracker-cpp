/*Implement a Salesman class in C++ with private members for name, area, and
an array for daily sales over 30 days. Provide methods to input sales data and
calculate the average sales ratio for the month. Add a static member function to
track and report the total sales across all salesmen.*/
#include <iostream>
#include <string>
using namespace std;

// Class to represent a Salesman
class Salesman {
private:
    string name;          // Name of the salesman
    string area;          // Area of operation
    double daily_sales[30]; // Array to store sales data for 30 days
    double avg;           // Average sales for the month

public:
    static double total;  // Static variable to track total sales across all salesmen

    // Method to input salesman's details (name and area)
    void input_details(string a, string b) {
        name = a;
        area = b;
    }

    // Method to input sales data for a specific day
    void sels(double s, int i) {
        daily_sales[i] = s;
    }

    // Method to calculate the total sales for this salesman
    void calculate() {
        for (int j = 0; j < 30; j++) {
            total += daily_sales[j]; // Accumulate sales into the static total variable
        }
    }

    // Method to display the total and average sales
    void display() {
        avg = total / 30; // Calculate average sales
        cout << "Total Sales: " << total << "\n";
        cout << "Average Sales: " << avg << "\n";
    }
};

// Initialize the static member variable
double Salesman::total = 0.0;

int main() {
    int seler_number;

    // Input the number of salesmen
    cout << "Enter number of salesmen: ";
    cin >> seler_number;

    Salesman s[seler_number]; // Array to store Salesman objects

    // Loop to input data for each salesman
    for (int i = 0; i < seler_number; i++) {
        cout << "\nEntering data for Salesman " << i + 1 << ":" << endl;
        string a, b;
        double c;

        // Input salesman's name and area
        cout << "Enter name: ";
        cin >> a;
        cout << "Enter area: ";
        cin >> b;
        s[i].input_details(a, b);

        // Input sales data for 30 days
        cout << "Enter sales data for 30 days:" << endl;
        for (int j = 0; j < 30; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> c;
            s[i].sels(c, j); // Store daily sales
        }

        // Calculate total sales for the salesman
        s[i].calculate();
    }

    // Display the total and average sales
    cout << "\nFinal Results:" << endl;
    s[0].display(); // Display total and average sales (using the first object for simplicity)

    return 0;
}
