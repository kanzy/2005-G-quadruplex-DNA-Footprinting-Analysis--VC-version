// AnalFsolver.cpp: implementation of the CAnalFsolver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Qs726.h"
#include "AnalFsolver.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAnalFsolver::CAnalFsolver()
{
p=0;
R=0;
Q1=0;
Q2=0;
Q3=0;
Q4=0;
Q9nt=0;
}

CAnalFsolver::~CAnalFsolver()
{

}


void CAnalFsolver::CalR5Mode(double P1, double P2, double P3, double P4)
{
	/*/using (2.1),(2.2),(2.3)&(2.6):
	  p=(P2-P3)/P2;
	  R=(P2*P2*P2)/(P3*(P2-P3));
	  Q1=(P2-P3-P1*P2)/(P2-P3);  
	  Q2=P2*(P1*P3-P2*P2)/(P3*(P2-P3)); 
	/*/

	/*/using (2.1),(2.3),(2.4)&(2.6):
	  p=(P3-P4)/P3;
	  R=P3/(p*(1-p)*(1-p));
	  Q2=P1/p-R;
	  Q1=1-R-Q2;
	//    above is older than 2005-09-22*/
	p=P1+P2+P3+P4;
	R=(P2/(p*(1-p))+P3/(p*(1-p)*(1-p))+P4/(p*(1-p)*(1-p)*(1-p)))/3;
	Q2=(P1-R*p)/p;
	Q1=1-R-Q2;
	Q9nt=0;

}


void CAnalFsolver::CalR7Mode(double P1, double P2, double P3, double P4, double P5, double P6)
{
	p=P1+P2+P3+P4+P5+P6;
	R=P4/(p*(1-p)*(1-p)*(1-p));
	Q4=(P3-R*(1-p)*(1-p)*p)/((1-p)*(1-p)*p);
	Q1=(P5-R*(1-p)*(1-p)*(1-p)*(1-p)*p)/p;
	Q3=(P2-R*(1-p)*p)/((1-p)*p)-Q4;
	Q2=1-R-Q1-Q3-Q4;

}


void CAnalFsolver::CalR6Mode(double P1,double P2,double P3,double P4,double P5)
{
	p=P1+P2+P3+P4+P5;
	R=(P3/(p*(1-p)*(1-p))+P4/(p*(1-p)*(1-p)*(1-p)))/2;
	Q3=(P2-R*(1-p)*p)/(p*(1-p));
	Q2=(P1-R*p)/p-Q3;
	Q1=1-R-Q2-Q3;

}



void CAnalFsolver::CalR4Mode(double P1,double P2,double P3)
{
	p=P1+P2+P3;
	R=(P1/p+P2/(p*(1-p))+P3/(p*(1-p)*(1-p)))/4;
	Q1=1-R;

}