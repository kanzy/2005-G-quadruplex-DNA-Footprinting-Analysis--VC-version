// Qs726.h : main header file for the QS726 application
//

#if !defined(AFX_QS726_H__351D3D67_9CB7_4E48_9A5E_BB94C6F653B9__INCLUDED_)
#define AFX_QS726_H__351D3D67_9CB7_4E48_9A5E_BB94C6F653B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CQs726App:
// See Qs726.cpp for the implementation of this class
//

class CQs726App : public CWinApp
{
public:
	CQs726App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQs726App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CQs726App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QS726_H__351D3D67_9CB7_4E48_9A5E_BB94C6F653B9__INCLUDED_)
