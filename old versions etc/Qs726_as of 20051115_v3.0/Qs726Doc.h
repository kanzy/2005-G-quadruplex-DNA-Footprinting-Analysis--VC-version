// Qs726Doc.h : interface of the CQs726Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QS726DOC_H__C772A86C_87FE_409E_8658_1884A2AE34F0__INCLUDED_)
#define AFX_QS726DOC_H__C772A86C_87FE_409E_8658_1884A2AE34F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQs726Doc : public CDocument
{
protected: // create from serialization only
	CQs726Doc();
	DECLARE_DYNCREATE(CQs726Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQs726Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	double m_DocResult_q;
	double m_DocResult_p;
	double m_DocResult_R;
	double m_DocResult_Q1;
	double m_DocResult_Q2;
	double m_DocResult_Q3;
	double m_DocResult_Q4;

	double m_DocBand1;
	double m_DocBand2;
	double m_DocBand3;
	double m_DocBand4;
	double m_DocBand5;
	double m_DocBand6;
	double m_DocRefLane;
	double m_DocRefRatio;

	virtual ~CQs726Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQs726Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QS726DOC_H__C772A86C_87FE_409E_8658_1884A2AE34F0__INCLUDED_)
