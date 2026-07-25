#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Structure for Dataset rows
struct Employee {
    int id;
    string name;
    double years_of_experience;
    double salary; // in thousands (e.g., 50 = $50,000)
    int performance_score; // Out of 5
};

int main() {
    // 1. Employee Dataset
    vector<Employee> dataset = {
        {1, "Amit",  2.0,  45.0, 3},
        {2, "Briya", 5.0,  75.0, 4},
        {3, "Chetan",1.5,  40.0, 2},
        {4, "Divya", 8.0,  110.0, 5},
        {5, "Esha",  4.0,  60.0, 3},
        {6, "Farhan",10.0, 130.0, 5},
        {7, "Gita",  3.0,  52.0, 4},
        {8, "Hari",  7.0,  95.0, 4}
    };

    int n = dataset.size();

    cout << "=======================================================\n";
    cout << "               1. EMPLOYEE DATASET                     \n";
    cout << "=======================================================\n";
    cout << setw(5) << "ID" << setw(10) << "Name" << setw(15) << "Experience(Yrs)" << setw(12) << "Salary($K)" << setw(18) << "Perf_Score(1-5)" << endl;
    for (const auto& emp : dataset) {
        cout << setw(5) << emp.id << setw(10) << emp.name << setw(15) << emp.years_of_experience << setw(12) << emp.salary << setw(18) << emp.performance_score << endl;
    }

    // 2. Descriptive Statistics Summary
    double total_sal = 0, total_exp = 0;
    double max_sal = dataset[0].salary, min_sal = dataset[0].salary;
    
    for (const auto& emp : dataset) {
        total_sal += emp.salary;
        total_exp += emp.years_of_experience;
        if (emp.salary > max_sal) max_sal = emp.salary;
        if (emp.salary < min_sal) min_sal = emp.salary;
    }
    
    double mean_sal = total_sal / n;
    double mean_exp = total_exp / n;

    cout << "\n=======================================================\n";
    cout << "               2. STATISTICAL SUMMARY                  \n";
    cout << "=======================================================\n";
    cout << "Total Employees Analyzed : " << n << endl;
    cout << "Average Experience       : " << mean_exp << " Years" << endl;
    cout << "Average Salary           : $" << mean_sal << "K" << endl;
    cout << "Highest Salary           : $" << max_sal << "K" << endl;
    cout << "Lowest Salary            : $" << min_sal << "K" << endl;

    // 3. Pearson Correlation Calculation
    double sum_X = 0, sum_Y = 0, sum_XY = 0;
    double sum_X2 = 0, sum_Y2 = 0;

    for (const auto& emp : dataset) {
        double x = emp.years_of_experience;
        double y = emp.salary;

        sum_X += x;
        sum_Y += y;
        sum_XY += (x * y);
        sum_X2 += (x * x);
        sum_Y2 += (y * y);
    }

    double num = (n * sum_XY) - (sum_X * sum_Y);
    double den = sqrt(((n * sum_X2) - (sum_X * sum_X)) * ((n * sum_Y2) - (sum_Y * sum_Y)));
    double correlation = num / den;

    cout << "\n=======================================================\n";
    cout << "               3. CORRELATION ANALYSIS                 \n";
    cout << "=======================================================\n";
    cout << "Pearson Correlation between Experience & Salary: " << fixed << setprecision(4) << correlation << endl;
    if (correlation > 0.8) {
        cout << "Insight: Strong Positive Correlation! (As experience grows, salary increases significantly.)\n";
    } else {
        cout << "Insight: Weak or No clear linear relationship.\n";
    }

    // 4. Data Visualization (ASCII Scatter Plot)
    cout << "\n=======================================================\n";
    cout << "         4. VISUALIZATION (EXPERIENCE VS SALARY)       \n";
    cout << "=======================================================\n";
    cout << "Salary ($K)\n";
    cout << "^ \n";
    
    for (int sal_level = 140; sal_level >= 30; sal_level -= 15) {
        cout << setw(3) << sal_level << " | ";
        for (int exp_level = 1; exp_level <= 11; ++exp_level) {
            bool point_found = false;
            for (const auto& emp : dataset) {
                if (abs(emp.years_of_experience - exp_level) < 1.0 && abs(emp.salary - sal_level) <= 10) {
                    cout << "O "; // Data point marker
                    point_found = true;
                    break;
                }
            }
            if (!point_found) cout << "  ";
        }
        cout << "\n";
    }
    cout << "    " << string(26, '-') << " > Experience (Years)\n";
    cout << "      1  2  3  4  5  6  7  8  9  10 11\n";

    return 0;
}
