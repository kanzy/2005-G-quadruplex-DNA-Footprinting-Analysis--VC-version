// SteepdnFsolver.h: interface for the CSteepdnFsolver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEEPDNFSOLVER_H__ECC9AF9F_D8F3_4E95_9167_8124F854D641__INCLUDED_)
#define AFX_STEEPDNFSOLVER_H__ECC9AF9F_D8F3_4E95_9167_8124F854D641__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSteepdnFsolver  
{
public:

	CSteepdnFsolver();
	~CSteepdnFsolver();

	void ff4(double x[3], double f[4], double P1, double P2, double P3);
	void ff5(double x[4], double f[5], double P1, double P2, double P3,double P4);
	void ff6(double x[5], double f[6], double P1, double P2, double P3,double P4,double P5);
	void ff7(double x[6], double f[7], double P1, double P2, double P3,double P4,double P5,double P6);
	
	void fd4(double x[3], double df[4][3]);
	void fd5(double x[4], double df[5][4]);
	void fd6(double x[5], double df[6][5]);
	void fd7(double x[6], double df[7][6]);

	void CalR7Mode(double P1,double P2,double P3,double P4,double P5,double P6);
	void CalR6Mode(double P1,double P2,double P3,double P4,double P5);
	void CalR5Mode(double P1,double P2,double P3,double P4);
	void CalR4Mode(double P1,double P2,double P3);

	int iter;
	double R;
	double p;
	double Q1;
	double Q2;
	double Q3;
	double Q4;

};

#endif // !defined(AFX_STEEPDNFSOLVER_H__ECC9AF9F_D8F3_4E95_9167_8124F854D641__INCLUDED_)
