// AnalFsolver.h: interface for the CAnalFsolver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANALFSOLVER_H__12BCC0F5_3109_4213_870B_1A92A79EB8D1__INCLUDED_)
#define AFX_ANALFSOLVER_H__12BCC0F5_3109_4213_870B_1A92A79EB8D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAnalFsolver  
{
public:
	double Q9nt;

	CAnalFsolver();
	virtual ~CAnalFsolver();
	double R;
	double p;
	double Q1;
	double Q2;
	double Q3;
	double Q4;

	void CalR7Mode(double P1,double P2,double P3,double P4,double P5,double P6);
	void CalR6Mode(double P1,double P2,double P3,double P4,double P5);
	void CalR5Mode(double P1,double P2,double P3,double P4);
	void CalR4Mode(double P1,double P2,double P3);

};

#endif // !defined(AFX_ANALFSOLVER_H__12BCC0F5_3109_4213_870B_1A92A79EB8D1__INCLUDED_)
