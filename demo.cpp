#include <cstdio>
#include <cstdlib>
#include <vector>
#include "spline.h"

void test_spline_circle() {
    std::vector<double> vx;
    std::vector<double> vy;
    std::vector<double> vt;
    double r = 15.0;
    for (int i = 0; i < 360; i++) {
        double psi = deg2rad(i);
        double x = r * cos(psi);
        double y = r * sin(psi);
        vx.push_back(x);
        vy.push_back(y);
        vt.push_back(i);
    }
    plt::axis("equal");
//    plt::plot(vx, vy);
//    plt::plot(vt, vy);
//    plt::show();

    tk::spline spline_x;
    tk::spline spline_y;

    spline_x.set_points(vt,vx);
    spline_y.set_points(vt,vy);

    std::vector<double> x_fit;
    std::vector<double> y_fit;
    for (int i = 0; i < 360; i++) {
        x_fit.push_back(spline_x(i + 0.5));
        y_fit.push_back(spline_y(i + 0.5));
    }
    plt::plot(vt, y_fit);
    plt::plot(x_fit, y_fit);
    plt::show();
}

int main(int argc, char** argv) {

   std::vector<double> X(5), Y(5);
   X[0]=0.1; X[1]=0.4; X[2]=1.2; X[3]=1.8; X[4]=2.0;
   Y[0]=0.1; Y[1]=0.7; Y[2]=0.6; Y[3]=1.1; Y[4]=0.9;

   tk::spline s;
   s.set_points(X,Y);    // currently it is required that X is already sorted

   double x=1.5;

   printf("spline at %f is %f\n", x, s(x));

   return EXIT_SUCCESS;
}
