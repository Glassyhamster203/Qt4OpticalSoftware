#ifndef CALC_H
#define CALC_H
#include <mainwindow.h>
#include <math.h>

#define Millimetre_Union 1000000
#define Micrometer_Union 1000
#define Nanometer_Union 1000000000
#define Lambda_Yellow_Sqr 0.34527376
#define Max_Wavelength 0.76
#define Min_Wavelength 0.40


class singleLen
{

protected:
    double imageDistance;
    double objectDistance;
    double focalLength;

private:
    double alpha;
    double beta;
    double gamma;

public:
    double calcImageDistance(void);
    // double calcObjectDistance(void);
    // double calcfocalLength(void);
    double calcAlpha(void);
    double calcBeta(void);
    double calcGamma(void);
    double getFocal(void);
    double thickNess;
    void setImageDistance(double L_);
    void setObjectDistance(double L);
    void setfocalLength(double f_);
    double getObjectDistance();
    double getImageDistance();
    double getThickNess();
};

class Double_sided_spherical : public singleLen
{

public:
    double calcFocal(void);
    void setLenParameter(double d, double n, double R_1, double R_2);
    void setAbel(double Abel);
    void calcMainPoint(void);
    double calcAbel(double lambda_n);
    double imageMainPointLength;
    double objectMainPointLength;
    double firstRadius;
    double secondRadius;

private:
    double Abel_c[3] = {-0.335562,0.41207,-0.127723};
    double Abel_d[3] = {-0.0141585,0.010522,0.115844};
    double Abel_e[3] = {-0.000113289,-0.000028339,0.734981};
    double abelNum;


    double refractiveIndex;
};

#endif // CALC_H
