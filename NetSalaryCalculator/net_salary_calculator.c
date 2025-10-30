/*
 * Calculates the net salary after tax, medication, maternity, and social security deductions.
 * Demonstrates use of pointer-based parameter passing and modular functions.
 */

#include <stdio.h>

float calcTax(float *gross) {
    if (*gross <= 100)
        return 0;
    else if (*gross <= 300)
        return 0.2 * (*gross);
    else
        return 0.28 * (*gross);
}

float medication(float *gross) {
    return 0.05 * (*gross);
}

float maternity(float *gross) {
    return 0.003 * (*gross);
}

float socialSecurity(float *gross) {
    return 0.03 * (*gross);
}

float netSalary(float *gross) {
    float totalDeductions = calcTax(gross) + medication(gross) + maternity(gross) + socialSecurity(gross);
    return (*gross) - totalDeductions;
}

int main() {
    float gross;
    printf("Enter gross salary: ");
    scanf("%f", &gross);
    printf("Net salary: %.2f\n", netSalary(&gross));
    return 0;
}
