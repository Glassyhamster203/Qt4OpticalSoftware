#include "calc.h"
#include <math.h>
// singleLen Lens;

double singleLen::calcImageDistance()
{
    // 透镜公式：1/f = 1/do + 1/di
    double di_inverse = 1 / focalLength + 1 / objectDistance;
    imageDistance = 1 / di_inverse;
    return imageDistance;
}

double singleLen::calcAlpha()
{
    calcBeta();
    alpha = beta * beta;
    return alpha;
}

double singleLen::calcBeta()
{
    calcImageDistance();
    beta = imageDistance / objectDistance;
    return beta;
}

double singleLen::calcGamma()
{
    calcImageDistance();
    gamma = objectDistance / imageDistance;
    return gamma;
}

double singleLen::getFocal()
{
    return focalLength;
}
void singleLen::setfocalLength(double f_)
{
    focalLength = f_;
}

void singleLen::setImageDistance(double L_)
{
    imageDistance = L_;
}

void singleLen::setObjectDistance(double L)
{
    objectDistance = L;
}
double singleLen::getObjectDistance()
{
    return objectDistance;
}

double singleLen::getImageDistance()
{
    return imageDistance;
}

double singleLen::getThickNess()
{
    return thickNess;
}


void Double_sided_spherical::setAbel(double Abel)
{
    abelNum = Abel;
}

double Double_sided_spherical::calcFocal(void)
{
    // focalLength = refractiveIndex * firstRadius * secondRadius;
    // focalLength /= (refractiveIndex - 1) * (refractiveIndex * (firstRadius - secondRadius) + (refractiveIndex)*thickNess);
    double focalLength_inv = (refractiveIndex - 1) * (1 / firstRadius - 1 / secondRadius + (refractiveIndex - 1) * thickNess / (refractiveIndex * firstRadius * secondRadius));
    focalLength = 1 / focalLength_inv;
    return focalLength;
}

void Double_sided_spherical::setLenParameter(double d, double n, double R_1, double R_2)
{
    thickNess = d;
    refractiveIndex = n;
    firstRadius = R_1;
    secondRadius = R_2;


}
void Double_sided_spherical::calcMainPoint(void)
{
    imageMainPointLength = -(focalLength * (refractiveIndex - 1) / refractiveIndex * thickNess / firstRadius);
    objectMainPointLength = -(focalLength * (refractiveIndex - 1) / refractiveIndex * thickNess / secondRadius);
}

double Double_sided_spherical::calcAbel(double lambda_n)
{
    double n;
    double L1 = lambda_n * lambda_n - Lambda_Yellow_Sqr;
    double L2 = 1 / lambda_n / lambda_n - 1 / Lambda_Yellow_Sqr;
    double L3 = 1 / lambda_n / lambda_n / lambda_n / lambda_n - 1 / Lambda_Yellow_Sqr / Lambda_Yellow_Sqr;
    n = refractiveIndex;
    n += L1 * (Abel_c[0] + Abel_c[1] * refractiveIndex + Abel_c[2] * refractiveIndex * refractiveIndex);
    n += L2 * (Abel_d[0] + Abel_d[1] * refractiveIndex + Abel_d[2] / abelNum);
    n += L3 * (Abel_e[0] + Abel_e[1] * refractiveIndex + Abel_e[2] / abelNum / abelNum);
    double focalLength_inv_abel = (n - 1) * (1 / firstRadius - 1 / secondRadius + (n - 1) * thickNess / (n * firstRadius * secondRadius));
    return 1/focalLength_inv_abel - focalLength ;
}



