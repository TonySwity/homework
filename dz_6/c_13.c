#include <stdio.h>
#include <math.h>

float cosinus(float x_deg) {
    const float eps = 0.001f;
    const float pi = 3.1415926535f;
    float x_rad = x_deg * (pi / 180.0f);
    
    float sum = 1.0f;      // Первый член ряда (n=0)
    float term = 1.0f;     // Текущий член ряда
    int k = 1;             // Счетчик членов ряда

    // Вычисление суммы ряда до достижения заданной точности
    while (1) {
        // Рекуррентное вычисление следующего члена ряда:
        // term_{k} = term_{k-1} * (-x²) / ((2k-1) * 2k)
        term = term * (-x_rad * x_rad) / ((2.0f * k - 1.0f) * (2.0f * k));
        
        // Проверка достижения требуемой точности
        if (fabsf(term) < eps) break;
        
        // Добавление члена к сумме и увеличение счетчика
        sum += term;
        k++;
    }
    
    return sum;
}

int main() {
    float num;
    scanf("%f", &num);
    
    printf("%.3f", cosinus(num));
    return 0;
}