# Net Salary Calculator

Brief
-----
C program that computes the net salary from a gross salary by aggregating several deductions. Each deduction is implemented as a separate function that accepts a pointer to the gross salary and returns the deduction amount. `netSalary` sums all deductions and returns the final net pay.

Goals
-----------------
- Demonstrates use of pointers for parameter passing.
- Each deduction (tax, medication, maternity, social security) is a standalone function.
- Tax brackets:
  - ≤ USD 100 : 0%
  - > USD 100 and ≤ USD 300 : 20%
  - > USD 300 : 28%
- Medication = 5%, Maternity = 0.3%, Social Security = 3%

Compile & run
-------------
```bash
cd NetSalaryCalculator
```

```bash
gcc -Wall -Wextra -o net_salary_calculator net_salary_calculator.c
./net_salary_calculator
```
