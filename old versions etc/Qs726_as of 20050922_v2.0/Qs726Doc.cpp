// Qs726Doc.cpp : implementation of the CQs726Doc class
//

#include "stdafx.h"
#include "Qs726.h"

#include "Qs726Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQs726Doc

IMPLEMENT_DYNCREATE(CQs726Doc, CDocument)

BEGIN_MESSAGE_MAP(CQs726Doc, CDocument)
	//{{AFX_MSG_MAP(CQs726Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQs726Doc construction/destruction

CQs726Doc::CQs726Doc()
{
	// TODO: add one-time construction code here

}

CQs726Doc::~CQs726Doc()
{
}

BOOL CQs726Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
    m_DocBand1=0;
	m_DocBand2=0;
	m_DocBand3=0;
	m_DocBand4=0;
	m_DocBand5=0;
	m_DocBand6=0;
	m_DocRefLane=0;
	m_DocRefRatio=1;

	m_DocResult_p=0;
	m_DocResult_R=0;
	m_DocResult_Q1=0;
	m_DocResult_Q2=0;
	m_DocResult_Q3=0;
	m_DocResult_Q4=0;

	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CQs726Doc serialization

void CQs726Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar<<m_DocBand1<<m_DocBand2<<m_DocBand3<<m_DocBand4<<m_DocBand5<<m_DocBand6
		   <<m_DocRefLane<<m_DocRefRatio<<m_DocResult_p<<m_DocResult_R<<m_DocResult_Q1
		   <<m_DocResult_Q2<<m_DocResult_Q3<<m_DocResult_Q4;
	}
	else
	{
		// TODO: add loading code here
		ar>>m_DocBand1>>m_DocBand2>>m_DocBand3>>m_DocBand4>>m_DocBand5>>m_DocBand6
		   >>m_DocRefLane>>m_DocRefRatio>>m_DocResult_p>>m_DocResult_R>>m_DocResult_Q1
		   >>m_DocResult_Q2>>m_DocResult_Q3>>m_DocResult_Q4;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CQs726Doc diagnostics

#ifdef _DEBUG
void CQs726Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CQs726Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQs726Doc commands
