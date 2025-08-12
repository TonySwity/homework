#include <stdio.h>
#include <math.h>

float sinus(float x_deg) {
    const float eps = 0.001f;
    const float pi = 3.1415926535f;
    float x_rad = x_deg * (pi / 180.0f);
    
    if (x_rad == 0.0f) {
        return 0.0f;
    }
    
    float sum = 0.0f;
    float term = x_rad;
    int k = 1;
    
    do {
        sum += term;
        term = term * (-x_rad * x_rad) / ((2.0f * k) * (2.0f * k + 1.0f));
        k++;
    } while (fabsf(term) >= eps);
    
    return sum;
}

int main(int argc, char** argv) {
	float num;

	scanf("%f", &num);
	printf("%0.3f", sinus(num));

	return 0;
}