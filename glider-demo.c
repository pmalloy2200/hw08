/*
 * The program solves the following system of four 
 * first order differential equations, which describe 
 * the motion of a glider
 *
 *   v' = -sin(theta) - v^2 / R
 *   theta' = - cos(theta)/v + v 
 *   x' = v cos(theta)
 *   y' = v sin(theta)
 *
 * Here v is the dimensionless speed of the glider, 
 * theta is the angle that the velocity direction 
 * makes with the horizontal, x and y are
 * dimensionless cartesian coordinates of the glider.
 * 
 * The step-size of the integrator is automatically 
 * adjusted by the controller to maintain the 
 * requested accuracy
 */

#include <stdio.h>
#include <math.h>

#include </usr/include/gsl/gsl_errno.h>
#include </usr/include/gsl/gsl_odeiv2.h>

int func (double t, const double y[], double f[], void *params);

int
gliderdemo (double v, double a, double x, double z)
{
    size_t neqs = 4;            /* number of equations */
    double eps_abs = 1.e-8, eps_rel = 0.;       /* desired precision */
    double stepsize = 1e-6;     /* initial integration step */
    double R = 10.;             /* the aerodynamic efficiency */
    double t = 0., t1 = 120.;   /* time interval */
    int status;
    /* 
     * Initial conditions 
     */
    double y[4] = { v, a, x, z };

    /*
     * Explicit embedded Runge-Kutta-Fehlberg (4,5) method. 
     * This method is a good general-purpose integrator.
     */
    gsl_odeiv2_step *s = gsl_odeiv2_step_alloc (gsl_odeiv2_step_rkf45, neqs);
    gsl_odeiv2_control *c = gsl_odeiv2_control_y_new (eps_abs,
                                                      eps_rel);
    gsl_odeiv2_evolve *e = gsl_odeiv2_evolve_alloc (neqs);

    gsl_odeiv2_system sys = { func, NULL, neqs, &R };

    /*
     * Evolution loop 
     */
    while ((t < t1) && (y[3] > 0))
    {
        status = gsl_odeiv2_evolve_apply (e, c, s, &sys, &t,
                                          t1, &stepsize, y);

        if (status != GSL_SUCCESS)
        {
            printf ("Troubles: % .5e  % .5e  % .5e  % .5e  % .5e\n",
                    t, y[0], y[1], y[2], y[3]);
            break;
        }

        //printf ("% .5e  % .5e  % .5e  % .5e  % .5e\n",          
        //        t, y[0], y[1], y[2], y[3]);
    }
    printf ("% .5e  % .5e  % .5e  % .5e  % .5e\n", v, a, x, z, y[2]);

    gsl_odeiv2_evolve_free (e);
    gsl_odeiv2_control_free (c);
    gsl_odeiv2_step_free (s);

    return 0;
}
