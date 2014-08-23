// Qs726View.h : interface of the CQs726View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_QS726VIEW_H__21E5BD6C_9373_45D8_BAE4_9EC3374FFF1C__INCLUDED_)
#define AFX_QS726VIEW_H__21E5BD6C_9373_45D8_BAE4_9EC3374FFF1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CQs726View : public CFormView
{
protected: // create from serialization only
	CQs726View();
	DECLARE_DYNCREATE(CQs726View)

public:
	//{{AFX_DATA(CQs726View)
	enum { IDD = IDD_QS726_FORM };
	double	m_Band1;
	double	m_Band2;
	double	m_Band3;
	double	m_Band4;
	double	m_Band5;
	double	m_Band6;
	double	m_RefLane;
	double	m_RefRatio;
	double	m_Result_p;
	double	m_Result_R;
	double	m_Result_Q1;
	double	m_Result_Q2;
	double	m_Result_Q3;
	double	m_Result_Q4;
	double	m_IniVal_p;
	double	m_IniVal_R;
	double	m_IniVal_Q1;
	double	m_IniVal_Q2;
	double	m_IniVal_Q3;
	double	m_IniVal_Q4;
	//}}AFX_DATA

// Attributes
public:
	CQs726Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQs726View)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_ChooseMode;
	virtual ~CQs726View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CQs726View)
	afx_msg void OnCalculate();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit4();
	afx_msg void OnChangeEdit5();
	afx_msg void OnChangeEdit6();
	afx_msg void OnChangeEdit7();
	afx_msg void OnChangeEdit8();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnButton1();
	afx_msg void OnChangeEdit15();
	afx_msg void OnChangeEdit16();
	afx_msg void OnChangeEdit17();
	afx_msg void OnChangeEdit18();
	afx_msg void OnChangeEdit19();
	afx_msg void OnChangeEdit20();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Qs726View.cpp
inline CQs726Doc* CQs726View::GetDocument()
   { return (CQs726Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QS726VIEW_H__21E5BD6C_9373_45D8_BAE4_9EC3374FFF1C__INCLUDED_)
