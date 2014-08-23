// SteepdnFsolver.cpp: implementation of the CSteepdnFsolver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Qs726.h"
#include "SteepdnFsolver.h"
#include "math.h"
#define EPSILON 1.0e-15

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSteepdnFsolver::CSteepdnFsolver()
{
/*p=0;
R=0;
Q1=0;
Q2=0;
Q3=0;
Q4=0;*/
}

CSteepdnFsolver::~CSteepdnFsolver()
{

}

///////////////////////////////
void CSteepdnFsolver::CalR7Mode(double P1, double P2, double P3, double P4, double P5, double P6)
{
	int M=7,N=7;//
	double* x;
	x=new double[7];
	x[0]=p; x[1]=R; x[2]=Q1; x[3]=Q2; x[4]=Q3; x[5]=Q4; x[6]=q;
	int i,j,k,maxiter=10000;
	double alpha,gtg,dfgtdfg,normf0,normf1;
	static double fk[7],Df[7][7],xx[7],g[7],dfg[7];//
	k=0;	//iter count
	ff7(x,fk,P1,P2,P3,P4,P5,P6);//
	normf0=0.0;
	for(i=0;i<M;i++) normf0=normf0+fk[i]*fk[i];
again: k=k+1;
	   ff7(x,fk,P1,P2,P3,P4,P5,P6);//
	   fd7(x,Df);//
	   gtg=0.0;
	   for(i=0;i<N;i++)
	   {
		   g[i]=0.0;
		   for(j=0;j<M;j++) g[i]=g[i]+Df[j][i]*fk[j];
		   g[i]=2.0*g[i];
		   gtg=gtg+g[i]*g[i];
	   }
	   dfgtdfg=0.0;
	   for(i=0;i<M;i++)
	   {
		   dfg[i]=0.0;
		   for(j=0;j<N;j++) dfg[i]=dfg[i]+Df[i][j]*g[j];
		   dfgtdfg=dfgtdfg+dfg[i]*dfg[i];
	   }
	   alpha=0.5*gtg/dfgtdfg;
	   do
	   {
		   for(i=0;i<N;i++) xx[i]=x[i]-alpha*g[i];
		   ff7(xx,fk,P1,P2,P3,P4,P5,P6);//
		   normf1=0.0;
		   for(i=0;i<N;i++) normf1=normf1+fk[i]*fk[i];
		   alpha=0.5*alpha;
	   }
	   while(normf1>normf0);
	   normf0=normf1;
	   for(i=0;i<N;i++) x[i]=xx[i];
	   normf1=sqrt(normf1);
	   if(normf1<EPSILON) goto endd;
	   if(k>maxiter) goto endd;
	   goto again;
endd: iter=k;
	  p=x[0];
	  R=x[1];
	  Q1=x[2];
	  Q2=x[3];
	  Q3=x[4];
	  Q4=x[5];//
	  q=x[6];
	  delete[] x;
}

void CSteepdnFsolver::CalR6Mode(double P1,double P2,double P3,double P4,double P5)
{
	int M=6,N=6;//
	double* x;
	x=new double[6];
	x[0]=p; x[1]=R; x[2]=Q1; x[3]=Q2; x[4]=Q3; x[5]=q;
	int i,j,k,maxiter=10000;
	double alpha,gtg,dfgtdfg,normf0,normf1;
	static double fk[6],Df[6][6],xx[6],g[6],dfg[6];//
	k=0;	//iter count
	ff6(x,fk,P1,P2,P3,P4,P5);//
	normf0=0.0;
	for(i=0;i<M;i++) normf0=normf0+fk[i]*fk[i];
again: k=k+1;
	   ff6(x,fk,P1,P2,P3,P4,P5);//
	   fd6(x,Df);//
	   gtg=0.0;
	   for(i=0;i<N;i++)
	   {
		   g[i]=0.0;
		   for(j=0;j<M;j++) g[i]=g[i]+Df[j][i]*fk[j];
		   g[i]=2.0*g[i];
		   gtg=gtg+g[i]*g[i];
	   }
	   dfgtdfg=0.0;
	   for(i=0;i<M;i++)
	   {
		   dfg[i]=0.0;
		   for(j=0;j<N;j++) dfg[i]=dfg[i]+Df[i][j]*g[j];
		   dfgtdfg=dfgtdfg+dfg[i]*dfg[i];
	   }
	   alpha=0.5*gtg/dfgtdfg;
	   do
	   {
		   for(i=0;i<N;i++) xx[i]=x[i]-alpha*g[i];
		   ff6(xx,fk,P1,P2,P3,P4,P5);//
		   normf1=0.0;
		   for(i=0;i<N;i++) normf1=normf1+fk[i]*fk[i];
		   alpha=0.5*alpha;
	   }
	   while(normf1>normf0);
	   normf0=normf1;
	   for(i=0;i<N;i++) x[i]=xx[i];
	   normf1=sqrt(normf1);
	   if(normf1<EPSILON) goto endd;
	   if(k>maxiter) goto endd;
	   goto again;
endd: iter=k;
	  p=x[0];
	  R=x[1];
	  Q1=x[2];
	  Q2=x[3];
	  Q3=x[4];//
	  q=x[5];
	  delete[] x;
}

void CSteepdnFsolver::CalR5Mode(double P1,double P2,double P3,double P4)
{
	int M=5,N=5;//
	double* x;
	x=new double[5];
	x[0]=p; x[1]=R; x[2]=Q1; x[3]=Q2; x[4]=q;
	int i,j,k,maxiter=10000;
	double alpha,gtg,dfgtdfg,normf0,normf1;
	static double fk[5],Df[5][5],xx[5],g[5],dfg[5];//
	k=0;	//iter count
	ff5(x,fk,P1,P2,P3,P4);//
	normf0=0.0;
	for(i=0;i<M;i++) normf0=normf0+fk[i]*fk[i];
again: k=k+1;
	   ff5(x,fk,P1,P2,P3,P4);//
	   fd5(x,Df);//
	   gtg=0.0;
	   for(i=0;i<N;i++)
	   {
		   g[i]=0.0;
		   for(j=0;j<M;j++) g[i]=g[i]+Df[j][i]*fk[j];
		   g[i]=2.0*g[i];
		   gtg=gtg+g[i]*g[i];
	   }
	   dfgtdfg=0.0;
	   for(i=0;i<M;i++)
	   {
		   dfg[i]=0.0;
		   for(j=0;j<N;j++) dfg[i]=dfg[i]+Df[i][j]*g[j];
		   dfgtdfg=dfgtdfg+dfg[i]*dfg[i];
	   }
	   alpha=0.5*gtg/dfgtdfg;
	   do
	   {
		   for(i=0;i<N;i++) xx[i]=x[i]-alpha*g[i];
		   ff5(xx,fk,P1,P2,P3,P4);//
		   normf1=0.0;
		   for(i=0;i<N;i++) normf1=normf1+fk[i]*fk[i];
		   alpha=0.5*alpha;
	   }
	   while(normf1>normf0);
	   normf0=normf1;
	   for(i=0;i<N;i++) x[i]=xx[i];
	   normf1=sqrt(normf1);
	   if(normf1<EPSILON) goto endd;
	   if(k>maxiter) goto endd;
	   goto again;
endd: iter=k;
	  p=x[0];
	  R=x[1];
	  Q1=x[2];
	  Q2=x[3];//
	  q=x[4];
	  delete[] x;
}

void CSteepdnFsolver::CalR4Mode(double P1,double P2,double P3)
{
	int M=4,N=4;//
	double* x;
	x=new double[4];
	x[0]=p; x[1]=R; x[2]=Q1; x[3]=q;
	int i,j,k,maxiter=10000;
	double alpha,gtg,dfgtdfg,normf0,normf1;
	static double fk[4],Df[4][4],xx[4],g[4],dfg[4];//
	k=0;	//iter count
	ff4(x,fk,P1,P2,P3);//
	normf0=0.0;
	for(i=0;i<M;i++) normf0=normf0+fk[i]*fk[i];
again: k=k+1;
	   ff4(x,fk,P1,P2,P3);//
	   fd4(x,Df);//
	   gtg=0.0;
	   for(i=0;i<N;i++)
	   {
		   g[i]=0.0;
		   for(j=0;j<M;j++) g[i]=g[i]+Df[j][i]*fk[j];
		   g[i]=2.0*g[i];
		   gtg=gtg+g[i]*g[i];
	   }
	   dfgtdfg=0.0;
	   for(i=0;i<M;i++)
	   {
		   dfg[i]=0.0;
		   for(j=0;j<N;j++) dfg[i]=dfg[i]+Df[i][j]*g[j];
		   dfgtdfg=dfgtdfg+dfg[i]*dfg[i];
	   }
	   alpha=0.5*gtg/dfgtdfg;
	   do
	   {
		   for(i=0;i<N;i++) xx[i]=x[i]-alpha*g[i];
		   ff4(xx,fk,P1,P2,P3);//
		   normf1=0.0;
		   for(i=0;i<N;i++) normf1=normf1+fk[i]*fk[i];
		   alpha=0.5*alpha;
	   }
	   while(normf1>normf0);
	   normf0=normf1;
	   for(i=0;i<N;i++) x[i]=xx[i];
	   normf1=sqrt(normf1);
	   if(normf1<EPSILON) goto endd;
	   if(k>maxiter) goto endd;
	   goto again;
endd: iter=k;
	  p=x[0];
	  R=x[1];
	  Q1=x[2];//
	  q=x[3];
	  delete[] x;
}

/////////////////////////
/* before 2005-11-14:

void CSteepdnFsolver::ff4(double x[], double f[], double P1, double P2, double P3)
{
	f[0]=x[1]*x[0]-P1;
	f[1]=x[1]*(1-x[0])*x[0]-P2;
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3;
	f[3]=x[2]+x[1]-1;
}

void CSteepdnFsolver::ff5(double x[], double f[], double P1, double P2, double P3, double P4)
{
	f[0]=(x[1]+x[3])*x[0]-P1;
	f[1]=x[1]*(1-x[0])*x[0]-P2;
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3;
	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4;
	f[4]=x[3]+x[2]+x[1]-1;
}

void CSteepdnFsolver::ff6(double x[], double f[], double P1, double P2, double P3, double P4, double P5)
{
	f[0]=(x[1]+x[3]+x[4])*x[0]-P1;
	f[1]=(x[1]+x[4])*(1-x[0])*x[0]-P2;
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3;
	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4;
	f[4]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]+x[2]*x[0]-P5;
	f[5]=x[4]+x[3]+x[2]+x[1]-1;

}

void CSteepdnFsolver::ff7(double x[], double f[], double P1, double P2, double P3, double P4, double P5, double P6)
{
	f[0]=(x[1]+x[3]+x[4]+x[5])*x[0]-P1;
	f[1]=(x[1]+x[4]+x[5])*(1-x[0])*x[0]-P2;
	f[2]=(x[1]+x[5])*(1-x[0])*(1-x[0])*x[0]-P3;
	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4;
	f[4]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]+x[2]*x[0]-P5;
	f[5]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]+(x[2]+x[3])*(1-x[0])*x[0]-P6;
	f[6]=x[5]+x[4]+x[3]+x[2]+x[1]-1;
}

/////////////////////////
void CSteepdnFsolver::fd4(double x[], double df[][3])
{
	df[0][0]=x[1];
	df[0][1]=x[0];
	df[0][2]=0;

	df[1][0]=x[1]*(1-2*x[0]);
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=0;

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=0;

	df[3][0]=0;
	df[3][1]=1;
	df[3][2]=1;
}

void CSteepdnFsolver::fd5(double x[], double df[][4])
{
	df[0][0]=x[1]+x[3];
	df[0][1]=x[0];
	df[0][2]=0;
	df[0][3]=x[0];

	df[1][0]=x[1]*(1-2*x[0]);
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=0;
	df[1][3]=0;

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=0;
	df[2][3]=0;

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=0;
	df[3][3]=0;

	df[4][0]=0;
	df[4][1]=1;
	df[4][2]=1;
	df[4][3]=1;
}

void CSteepdnFsolver::fd6(double x[], double df[][5])
{
	df[0][0]=x[1]+x[3]+x[4];
	df[0][1]=x[0];
	df[0][2]=0;
	df[0][3]=x[0];
	df[0][4]=x[0];

	df[1][0]=(x[1]+x[4])*(1-2*x[0]);
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=0;
	df[1][3]=0;
	df[1][4]=(1-x[0])*x[0];

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=0;
	df[2][3]=0;
	df[2][4]=0;

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=0;
	df[3][3]=0;
	df[3][4]=0;

	df[4][0]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-5*x[0])+x[2];
	df[4][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[4][2]=x[0];
	df[4][3]=0;
	df[4][4]=0;

	df[5][0]=0;
	df[5][1]=1;
	df[5][2]=1;
	df[5][3]=1;
	df[5][4]=1;
}

void CSteepdnFsolver::fd7(double x[], double df[][6])
{
	df[0][0]=x[1]+x[3]+x[4]+x[5];
	df[0][1]=x[0];
	df[0][2]=0;
	df[0][3]=x[0];
	df[0][4]=x[0];
	df[0][5]=x[0];

	df[1][0]=(x[1]+x[4]+x[5])*(1-2*x[0]);
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=0;
	df[1][3]=0;
	df[1][4]=(1-x[0])*x[0];
	df[1][5]=(1-x[0])*x[0];

	df[2][0]=(x[1]+x[5])*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=0;
	df[2][3]=0;
	df[2][4]=0;
	df[2][5]=(1-x[0])*(1-x[0])*x[0];

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=0;
	df[3][3]=0;
	df[3][4]=0;
	df[3][5]=0;

	df[4][0]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-5*x[0])+x[2];
	df[4][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[4][2]=x[0];
	df[4][3]=0;
	df[4][4]=0;
	df[4][5]=0;

	df[5][0]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*(1-6*x[0])+(x[2]+x[3])*(1-2*x[0]);
	df[5][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[5][2]=(1-x[0])*x[0];
	df[5][3]=(1-x[0])*x[0];
	df[5][4]=0;
	df[5][5]=0;

	df[6][0]=0;
	df[6][1]=1;
	df[6][2]=1;
	df[6][3]=1;
	df[6][4]=1;
	df[6][5]=1;
}
*/

//new==================

void CSteepdnFsolver::ff4(double x[], double f[], double P1, double P2, double P3)
{
	f[0]=x[1]*x[0]-P1+x[2]*x[3];
	f[1]=x[1]*(1-x[0])*x[0]-P2+x[2]*x[3]*(1-x[3]);
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3+x[2]*x[3]*(1-x[3])*(1-x[3]);
	f[3]=x[2]+x[1]-1;
}

void CSteepdnFsolver::fd4(double x[], double df[][4])
{
	df[0][0]=x[1];
	df[0][1]=x[0];
	df[0][2]=x[3];
	df[0][3]=x[2];

	df[1][0]=x[1]*(1-2*x[0]);
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=(1-x[3])*x[3];
	df[1][3]=x[2]*(1-2*x[3]);

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=(1-x[3])*(1-x[3])*x[3];
	df[2][3]=x[2]*(1-4*x[3]+3*x[3]*x[3]);

	df[3][0]=0;
	df[3][1]=1;
	df[3][2]=1;
	df[3][3]=0;
}

//=========================================

void CSteepdnFsolver::ff5(double x[], double f[], double P1, double P2, double P3, double P4)
{
	f[0]=(x[1]+x[3])*x[0]-P1 +x[2]*x[4];
	f[1]=x[1]*(1-x[0])*x[0]-P2 +x[2]*x[4]*(1-x[4])+x[3]*(1-x[0])*x[4];
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3 +x[2]*x[4]*(1-x[4])*(1-x[4])+x[3]*(1-x[0])*x[4]*(1-x[4]);
	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4 +x[2]*x[4]*(1-x[4])*(1-x[4])*(1-x[4])+x[3]*(1-x[0])*x[4]*(1-x[4])*(1-x[4]);
	f[4]=x[3]+x[2]+x[1]-1;
}

void CSteepdnFsolver::fd5(double x[], double df[][5])
{
	df[0][0]=x[1]+x[3];
	df[0][1]=x[0];
	df[0][2]=x[4];
	df[0][3]=x[0];
	df[0][4]=x[2];

	df[1][0]=x[1]*(1-2*x[0])-x[3]*x[4];
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=x[4]*(1-x[4]);
	df[1][3]=(1-x[0])*x[4];
	df[1][4]=x[2]*(1-2*x[4])+x[3]*(1-x[0]);

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=x[4]*(1-x[4])*(1-x[4]);
	df[2][3]=(1-x[0])*x[4]*(1-x[4]);
	df[2][4]=x[2]*(1-4*x[4]+3*x[4]*x[4])+x[3]*(1-x[0])*(1-2*x[4]);

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]) -x[3]*x[4]*(1-x[4])*(1-x[4]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=x[4]*(1-x[4])*(1-x[4])*(1-x[4]);
	df[3][3]=(1-x[0])*x[4]*(1-x[4])*(1-x[4]);
	df[3][4]=x[2]*(1-6*x[4]+9*x[4]*x[4]-4*x[4]*x[4]*x[4])+x[3]*(1-x[0])*(1-4*x[4]+3*x[4]*x[4]);

	df[4][0]=0;
	df[4][1]=1;
	df[4][2]=1;
	df[4][3]=1;
	df[4][4]=0;
}

//=============================

void CSteepdnFsolver::ff6(double x[], double f[], double P1, double P2, double P3, double P4, double P5)
{
	f[0]=(x[1]+x[3]+x[4])*x[0]-P1 + x[2]*x[5];
	f[1]=(x[1]+x[4])*(1-x[0])*x[0]-P2 + x[2]*(1-x[5])*x[5] + x[3]*(1-x[0])*x[5];
	f[2]=x[1]*(1-x[0])*(1-x[0])*x[0]-P3 + x[2]*(1-x[5])*(1-x[5])*x[5] + x[3]*(1-x[0])*(1-x[5])*x[5] + x[4]*(1-x[0])*(1-x[0])
*x[5];
	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4 + x[2]*(1-x[5])*(1-x[5])*(1-x[5])*x[5] + x[3]*(1-x[0])*(1-x[5])*(1-x[5])*x[
5] + x[4]*(1-x[0])*(1-x[0])*(1-x[5])*x[5];
	f[4]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P5 + x[2]*(1-x[5])*(1-x[5])*(1-x[5])*(1-x[5])*x[5] + x[3]*(1-x[0])*(1
-x[5])*(1-x[5])*(1-x[5])*x[5] + x[4]*(1-x[0])*(1-x[0])*(1-x[5])*(1-x[5])*x[5];
	f[5]=x[4]+x[3]+x[2]+x[1]-1;
}

void CSteepdnFsolver::fd6(double x[], double df[][6])
{
	df[0][0]=x[1]+x[3]+x[4];
	df[0][1]=x[0];
	df[0][2]=x[5];
	df[0][3]=x[0];
	df[0][4]=x[0];
	df[0][5]=x[2];

	df[1][0]=(x[1]+x[4])*(1-2*x[0]) - x[3]*x[5];
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=(1-x[5])*x[5];
	df[1][3]=(1-x[0])*x[5];
	df[1][4]=(1-x[0])*x[0];
	df[1][5]=x[2]*(1-2*x[5])+x[3]*(1-x[0]); 

	df[2][0]=x[1]*(1-4*x[0]+3*x[0]*x[0]) -x[3]*(1-x[5])*x[5] +x[4]*x[5]*(-2+2*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=(1-x[5])*(1-x[5])*x[5];
	df[2][3]=(1-x[0])*(1-x[5])*x[5];
	df[2][4]=(1-x[0])*(1-x[0])*x[5];
	df[2][5]=x[2]*(1-4*x[5]+3*x[5]*x[5])+x[3]*(1-x[0])*(1-2*x[5])+ x[4]*(1-x[0])*(1-x[0]);

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]) -x[3]*(1-x[5])*(1-x[5])*x[5] +x[4]*(1-x[5])*x[5]*(-2+2*x[0]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=(1-x[5])*(1-x[5])*(1-x[5])*x[5];
	df[3][3]=(1-x[0])*(1-x[5])*(1-x[5])*x[5] ;
	df[3][4]=(1-x[0])*(1-x[0])*(1-x[5])*x[5];
	df[3][5]=x[2]*(1-6*x[5]+9*x[5]*x[5]-4*x[5]*x[5]*x[5]) + x[3]*(1-x[0])*(1-4*x[5]+3*x[5]*x[5]) + x[4]*(1-x[0])*(1-x[0])*
(1-2*x[5]);

	df[4][0]=x[1]*(1-8*x[0]+18*x[0]*x[0]-16*x[0]*x[0]*x[0]+5*x[0]*x[0]*x[0]*x[0]) -x[3]*(1-x[5])*(1-x[5])*(1-x[5])*x[5] +x
[4]*(1-x[5])*(1-x[5])*x[5]*(-2+2*x[0]);
	df[4][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[4][2]=(1-x[5])*(1-x[5])*(1-x[5])*(1-x[5])*x[5];
	df[4][3]=(1-x[0])*(1-x[5])*(1-x[5])*(1-x[5])*x[5]; 
	df[4][4]=(1-x[0])*(1-x[0])*(1-x[5])*(1-x[5])*x[5];
	df[4][5]=x[2]*(1-8*x[5]+18*x[5]*x[5]-16*x[5]*x[5]*x[5]+5*x[5]*x[5]*x[5]*x[5]) + x[3]*(1-x[0])*(1-6*x[5]+9*x[5]*x[5]-
4*x[5]*x[5]*x[5]) + x[4]*(1-x[0])*(1-x[0])*(1-4*x[5]+3*x[5]*x[5]);

	df[5][0]=0;
	df[5][1]=1;
	df[5][2]=1;
	df[5][3]=1;
	df[5][4]=1;
	df[5][5]=0;
}

//===========================

void CSteepdnFsolver::ff7(double x[], double f[], double P1, double P2, double P3, double P4, double P5, double P6)
{
	f[0]=(x[1]+x[3]+x[4]+x[5])*x[0]-P1 + x[2]*x[6];

	f[1]=(x[1]+x[4]+x[5])*(1-x[0])*x[0]-P2 + x[2]*(1-x[6])*x[6] + x[3]*(1-x[0])*x[6];

	f[2]=(x[1]+x[5])*(1-x[0])*(1-x[0])*x[0]-P3 + x[2]*(1-x[6])*(1-x[6])*x[6] + x[3]*(1-x[0])*(1-x[6])*x[6] + x[4]*(1-x[0])*(

1-x[0])*x[6];

	f[3]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P4 + x[2]*(1-x[6])*(1-x[6])*(1-x[6])*x[6] + x[3]*(1-x[0])*(1-x[6])*(1-x[6])*x[

6] + x[4]*(1-x[0])*(1-x[0])*(1-x[6])*x[6] + x[5]*(1-x[0])*(1-x[0])*(1-x[0])*x[6];

	f[4]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P5 + x[2]*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0] + x[3]*(1-x[0])*(1

-x[6])*(1-x[6])*(1-x[6])*x[6] + x[4]*(1-x[0])*(1-x[0])*(1-x[6])*(1-x[6])*x[6] + x[5]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[6])*x[6];

	f[5]=x[1]*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0]-P6 + x[2]*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0] + 

x[3]*(1-x[0])*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0] + x[4]*(1-x[0])*(1-x[0])*(1-x[6])*(1-x[6])*(1-x[6])*x[6] + x[5]*(1-x[0])*(1-x[0

])*(1-x[0])*(1-x[6])*(1-x[6])*x[6];

	f[6]=x[5]+x[4]+x[3]+x[2]+x[1]-1;
}


void CSteepdnFsolver::fd7(double x[], double df[][7])
{
	df[0][0]=x[1]+x[3]+x[4]+x[5];
	df[0][1]=x[0];
	df[0][2]=x[6];
	df[0][3]=x[0];
	df[0][4]=x[0];
	df[0][5]=x[0];
	df[0][6]=x[2];

	df[1][0]=(x[1]+x[4]+x[5])*(1-2*x[0]) -x[3]*x[6];
	df[1][1]=(1-x[0])*x[0];
	df[1][2]=(1-x[6])*x[6];
	df[1][3]=(1-x[0])*x[6];
	df[1][4]=(1-x[0])*x[0];
	df[1][5]=(1-x[0])*x[0];
	df[1][6]=x[2]*(1-2*x[6]) + x[3]*(1-x[0]);

	df[2][0]=(x[1]+x[5])*(1-4*x[0]+3*x[0]*x[0]) -x[3]*(1-x[6])*x[6] +x[4]*x[6]*(-2+2*x[0]);
	df[2][1]=(1-x[0])*(1-x[0])*x[0];
	df[2][2]=(1-x[6])*(1-x[6])*x[6];
	df[2][3]=(1-x[0])*(1-x[6])*x[6];
	df[2][4]=(1-x[0])*(1-x[0])*x[6];
	df[2][5]=(1-x[0])*(1-x[0])*x[0];
	df[2][6]=x[2]*(1-4*x[6]+3*x[6]*x[6]) + x[3]*(1-2*x[6]) + x[4]*(1-x[0])*(1-x[0]);

	df[3][0]=x[1]*(1-6*x[0]+9*x[0]*x[0]-4*x[0]*x[0]*x[0]) -x[3]*(1-x[6])*(1-x[6])*x[6] + x[4]*(1-x[6])*x[6]*(-2+2*x[0]) + x
[5]*x[6]*(-3+6*x[0]-3*x[0]*x[0]);
	df[3][1]=(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[3][2]=(1-x[6])*(1-x[6])*(1-x[6])*x[6];
	df[3][3]=(1-x[0])*(1-x[6])*(1-x[6])*x[6];
	df[3][4]=(1-x[0])*(1-x[0])*(1-x[6])*x[6];
	df[3][5]=(1-x[0])*(1-x[0])*(1-x[0])*x[6];
	df[3][6]=x[2]*(1-6*x[6]+9*x[6]*x[6]-4*x[6]*x[6]*x[6]) + x[3]*(1-x[0])*(1-4*x[6]+3*x[6]*x[6]) + x[4]*(1-x[0])*(1-x[0])*
(1-2*x[6]) + x[5]*(1-x[0])*(1-x[0])*(1-x[0]);

	df[4][0]=x[1]*(1-8*x[0]+18*x[0]*x[0]-16*x[0]*x[0]*x[0]+5*x[0]*x[0]*x[0]*x[0]) + x[2]*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6
]) - x[3]*(1-x[6])*(1-x[6])*(1-x[6])*x[6]+ x[4]*(1-x[6])*(1-x[6])*x[6]*(-2+2*x[0]) + x[5]*(1-x[6])*x[6]*(-3+6*x[0]-3*x[0]*x[0]);
	df[4][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[4][2]=(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0];
	df[4][3]=(1-x[0])*(1-x[6])*(1-x[6])*(1-x[6])*x[6];
	df[4][4]=(1-x[0])*(1-x[0])*(1-x[6])*(1-x[6])*x[6];
	df[4][5]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[6])*x[6];
	df[4][6]=x[2]*x[0]*(-4+12*x[6]-12*x[6]*x[6]+4*x[6]*x[6]*x[6]) + x[3]*(1-x[0])*(1-6*x[6]+9*x[6]*x[6]-4*x[6]*x[6]*x[6]) 
+ x[4]*(1-x[0])*(1-x[0])*(1-4*x[6]+3*x[6]*x[6]) + x[5]*(1-x[0])*(1-x[0])*(1-x[0])*(1-2*x[6]);

	df[5][0]=x[1]*((1-x[0])*(1-8*x[0]+18*x[0]*x[0]-16*x[0]*x[0]*x[0]+5*x[0]*x[0]*x[0]*x[0])-((1-x[0])*(1-x[0])*(1-x[0])*(1-x[
0])*x[0])) + x[2]*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6]) + x[3]*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*(1-2*x[0]) + x[4]*(1-x[6])*(1
-x[6])*(1-x[6])*x[6]*(-2+2*x[0]) + x[5]*(1-x[6])*(1-x[6])*x[6]*(-3+6*x[0]-3*x[0]*x[0]);
	df[5][1]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*(1-x[0])*x[0];
	df[5][2]=(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0];
	df[5][3]=(1-x[0])*(1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])*x[0];
	df[5][4]=(1-x[0])*(1-x[0])*(1-x[6])*(1-x[6])*(1-x[6])*x[6];
	df[5][5]=(1-x[0])*(1-x[0])*(1-x[0])*(1-x[6])*(1-x[6])*x[6];
	df[5][6]=(x[3]+x[2])*x[0]*((1-x[6])*(-4+12*x[6]-12*x[6]*x[6]+4*x[6]*x[6]*x[6])-((1-x[6])*(1-x[6])*(1-x[6])*(1-x[6])))+ 
x[4]*(1-x[0])*(1-x[0])*(1-6*x[6]+9*x[6]*x[6]-4*x[6]*x[6]*x[6])+ x[5]*(1-x[0])*(1-x[0])*(1-x[0])*(1-4*x[6]+3*x[6]*x[6]);

	df[6][0]=0;
	df[6][1]=1;
	df[6][2]=1;
	df[6][3]=1;
	df[6][4]=1;
	df[6][5]=1;
	df[6][6]=0;
}






