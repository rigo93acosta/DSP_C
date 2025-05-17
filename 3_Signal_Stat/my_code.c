#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define SIG_LENGTH 320
extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];

double mean(double *data, int length);
double variance(double *data, int length, double mean);
double standard(double variance);

int main(void)
{
  double meanResult = mean(InputSignal_f32_1kHz_15kHz, SIG_LENGTH);
  printf("Mean -> %f\n", meanResult);
  double varianceResult = variance(InputSignal_f32_1kHz_15kHz, SIG_LENGTH, meanResult);
  printf("Variance -> %f\n", varianceResult);
  double standardResult = standard(varianceResult);
  printf("Standard Deviation -> %f\n", standardResult);
  return 0;
}

double mean(double *data, int length)
{
    double sum = 0.0;
    for (int i = 0; i < length; i++)
    {
        sum += data[i];
    }
    return sum / (double)length;
}

double variance(double *data, int length, double mean)
{
    double sum = 0.0;
    for (int i = 0; i < length; i++)
    {
        sum += pow(data[i] - mean, 2);
    }
    return sum / (double)(length - 1);
}

double standard(double variance)
{
    return sqrt(variance);
}

