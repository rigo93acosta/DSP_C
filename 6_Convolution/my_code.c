#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

extern double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
extern  double  Impulse_response[IMP_RSP_LENGTH];
        double Output_signal[SIG_LENGTH+IMP_RSP_LENGTH];
        double Output_sum_signal[SIG_LENGTH];



void convolution(double *sig_src_arr,
                 double *sig_dest_arr,
                 double *imp_response_arr,
                 int sig_src_length,
                 int imp_response_length
                 );

// Add running sum 
void calc_running_sum(double *sig_src_arr,
                  double *sig_dest_arr,
                  int sig_src_length
                 );

int main()
{
    FILE *input_sig_fptr, *imp_rsp_fptr,*output_sig_fptr;
    
    // Running sum
    FILE *output_sum_sig_fptr;

     convolution(InputSignal_f32_1kHz_15kHz,
                 Output_signal,
                 Impulse_response,
                 SIG_LENGTH,
                 IMP_RSP_LENGTH
                 );

    calc_running_sum(InputSignal_f32_1kHz_15kHz,
                     Output_sum_signal,
                     SIG_LENGTH
                    );

    input_sig_fptr = fopen("input_signal.dat","w");
    imp_rsp_fptr   = fopen ("impulse_response.dat","w");
    output_sig_fptr = fopen("output_signal.dat","w");
    output_sum_sig_fptr = fopen("output_sum_signal.dat","w");

    for(int i=0;i<SIG_LENGTH;i++)
    {
      fprintf(input_sig_fptr,"\n%f",InputSignal_f32_1kHz_15kHz[i]);
    }
    fclose(input_sig_fptr);

    for(int i=0;i<IMP_RSP_LENGTH;i++)
    {
      fprintf(imp_rsp_fptr,"\n%f",Impulse_response[i]);
    }
    fclose(imp_rsp_fptr);

    for(int i=0;i<SIG_LENGTH+IMP_RSP_LENGTH-1;i++)
    {
      fprintf(output_sig_fptr,"\n%f",Output_signal[i]);
    }
    fclose(output_sig_fptr);
 
    for (int i =0; i<SIG_LENGTH; i++) {
      fprintf(output_sum_sig_fptr,"\n%f",Output_sum_signal[i]);
    }
    fclose(output_sum_sig_fptr);
    return 0;
}


void convolution( double *sig_src_arr,
                  double *sig_dest_arr,
                  double *imp_response_arr,
                  int sig_src_length,
                  int imp_response_length
                 )
{
    int i,j;
    for(i=0;i<sig_src_length+imp_response_length-1;i++)
    {
        sig_dest_arr[i] =0;
    }

      for(i=0;i<sig_src_length;i++)
      {
          for(j=0;j<imp_response_length;j++)
          {
              sig_dest_arr[i+j] += sig_src_arr[i]*imp_response_arr[j];

          }
      }

}

void calc_running_sum( double *sig_src_arr,
                  double *sig_dest_arr,
                  int sig_src_length
                 )
{
    int i;
    sig_dest_arr[0] = sig_src_arr[0];
    for(i=1;i<sig_src_length;i++)
    {
        sig_dest_arr[i] = sig_dest_arr[i-1] + sig_src_arr[i];
    }
}


