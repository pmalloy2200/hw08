#include <stdio.h>
#include <math.h>

#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_odeiv2.h>

int gliderdemo (double v, double a, double x, double y);

int
main (void)
{
    double v, a = 0., x = 0., y = 2.;


    for (v = .5; v <= 5.; v += 0.1)
    {
        gliderdemo (v, a, x, y);
    }

    return 0;

}
