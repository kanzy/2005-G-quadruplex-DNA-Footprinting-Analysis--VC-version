// Qs726View.cpp : implementation of the CQs726View class
//

#include "stdafx.h"
#include "Qs726.h"

#include "Qs726Doc.h"
#include "Qs726View.h"
#include "SteepdnFsolver.h"
#include "AnalFsolver.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQs726View

IMPLEMENT_DYNCREATE(CQs726View, CFormView)

BEGIN_MESSAGE_MAP(CQs726View, CFormView)
	//{{AFX_MSG_MAP(CQs726View)
	ON_BN_CLICKED(IDC_BUTTON3, OnCalculate)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, OnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, OnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT15, OnChangeEdit15)
	ON_EN_CHANGE(IDC_EDIT16, OnChangeEdit16)
	ON_EN_CHANGE(IDC_EDIT17, OnChangeEdit17)
	ON_EN_CHANGE(IDC_EDIT18, OnChangeEdit18)
	ON_EN_CHANGE(IDC_EDIT19, OnChangeEdit19)
	ON_EN_CHANGE(IDC_EDIT20, OnChangeEdit20)
	ON_EN_CHANGE(IDC_EDIT21, OnChangeEdit21)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQs726View construction/destruction

CQs726View::CQs726View()
	: CFormView(CQs726View::IDD)
{
	//{{AFX_DATA_INIT(CQs726View)
	m_Band1 = 0.0;
	m_Band2 = 0.0;
	m_Band3 = 0.0;
	m_Band4 = 0.0;
	m_Band5 = 0.0;
	m_Band6 = 0.0;
	m_RefLane = 0.0;
	m_RefRatio = 0.0;
	m_Result_p = 0.0;
	m_Result_R = 0.0;
	m_Result_Q1 = 0.0;
	m_Result_Q2 = 0.0;
	m_Result_Q3 = 0.0;
	m_Result_Q4 = 0.0;
	m_IniVal_p = 0.0;
	m_IniVal_R = 0.0;
	m_IniVal_Q1 = 0.0;
	m_IniVal_Q2 = 0.0;
	m_IniVal_Q3 = 0.0;
	m_IniVal_Q4 = 0.0;
	m_IniVal_Q9nt = 0.0;
	m_Result_Q9nt = 0.0;
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CQs726View::~CQs726View()
{
}

void CQs726View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQs726View)
	DDX_Text(pDX, IDC_EDIT1, m_Band1);
	DDX_Text(pDX, IDC_EDIT2, m_Band2);
	DDX_Text(pDX, IDC_EDIT3, m_Band3);
	DDX_Text(pDX, IDC_EDIT4, m_Band4);
	DDX_Text(pDX, IDC_EDIT5, m_Band5);
	DDX_Text(pDX, IDC_EDIT6, m_Band6);
	DDX_Text(pDX, IDC_EDIT7, m_RefLane);
	DDX_Text(pDX, IDC_EDIT8, m_RefRatio);
	DDV_MinMaxDouble(pDX, m_RefRatio, 0., 1.);
	DDX_Text(pDX, IDC_EDIT9, m_Result_p);
	DDV_MinMaxDouble(pDX, m_Result_p, 0., 1.);
	DDX_Text(pDX, IDC_EDIT10, m_Result_R);
	DDX_Text(pDX, IDC_EDIT11, m_Result_Q1);
	DDX_Text(pDX, IDC_EDIT12, m_Result_Q2);
	DDX_Text(pDX, IDC_EDIT13, m_Result_Q3);
	DDX_Text(pDX, IDC_EDIT14, m_Result_Q4);
	DDX_Text(pDX, IDC_EDIT15, m_IniVal_p);
	DDX_Text(pDX, IDC_EDIT16, m_IniVal_R);
	DDX_Text(pDX, IDC_EDIT17, m_IniVal_Q1);
	DDX_Text(pDX, IDC_EDIT18, m_IniVal_Q2);
	DDX_Text(pDX, IDC_EDIT19, m_IniVal_Q3);
	DDX_Text(pDX, IDC_EDIT20, m_IniVal_Q4);
	DDX_Text(pDX, IDC_EDIT21, m_IniVal_Q9nt);
	DDX_Text(pDX, IDC_EDIT22, m_Result_Q9nt);
	//}}AFX_DATA_MAP
}

BOOL CQs726View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CQs726View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	CQs726Doc* pDoc=GetDocument();
    m_Band1=pDoc->m_DocBand1;
	m_Band2=pDoc->m_DocBand2;
	m_Band3=pDoc->m_DocBand3;
	m_Band4=pDoc->m_DocBand4;
	m_Band5=pDoc->m_DocBand5;
	m_Band6=pDoc->m_DocBand6;
	m_RefLane=pDoc->m_DocRefLane;
	m_RefRatio=pDoc->m_DocRefRatio;
	m_ChooseMode=0;

	m_Result_p=pDoc->m_DocResult_p;
	m_Result_R=pDoc->m_DocResult_R;
	m_Result_Q1=pDoc->m_DocResult_Q1;
	m_Result_Q2=pDoc->m_DocResult_Q2;
	m_Result_Q3=pDoc->m_DocResult_Q3;
	m_Result_Q4=pDoc->m_DocResult_Q4;
	m_Result_Q9nt=pDoc->m_DocResult_Q9nt;

	UpdateData(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CQs726View printing

BOOL CQs726View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CQs726View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CQs726View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CQs726View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CQs726View diagnostics

#ifdef _DEBUG
void CQs726View::AssertValid() const
{
	CFormView::AssertValid();
}

void CQs726View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CQs726Doc* CQs726View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQs726Doc)));
	return (CQs726Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CQs726View message handlers

void CQs726View::OnCalculate() 
{
	// TODO: Add your control notification handler code here
	//Write QS algorithm here. Calculate m_Result_X:
    double P1,P2,P3,P4,P5,P6;
	P1=m_Band1/(m_RefLane/m_RefRatio);
	P2=m_Band2/(m_RefLane/m_RefRatio);
	P3=m_Band3/(m_RefLane/m_RefRatio);
	P4=m_Band4/(m_RefLane/m_RefRatio);
	P5=m_Band5/(m_RefLane/m_RefRatio);
	P6=m_Band6/(m_RefLane/m_RefRatio);
	
	//CSteepdnFsolver myFsolver;
    CSteepdnFsolver* myFsolver=new CSteepdnFsolver;
	myFsolver->p=m_IniVal_p;
	myFsolver->R=m_IniVal_R/100;
	myFsolver->Q1=m_IniVal_Q1/100;
	myFsolver->Q2=m_IniVal_Q2/100;
	myFsolver->Q3=m_IniVal_Q3/100;
	myFsolver->Q4=m_IniVal_Q4/100;
	myFsolver->Q9nt=m_IniVal_Q9nt/100;

	switch(m_ChooseMode)
	{
	case 1: myFsolver->CalR7Mode(P1,P2,P3,P4,P5,P6);break;
	case 2: myFsolver->CalR6Mode(P1,P2,P3,P4,P5);break;
	case 3: myFsolver->CalR5Mode(P1,P2,P3,P4);break;
	case 4: myFsolver->CalR4Mode(P1,P2,P3);break;
	default: MessageBox("Please choose Exp Mode!","NOTICE",MB_OK);
	}
	m_Result_p=myFsolver->p;
	m_Result_R=100*myFsolver->R;
	m_Result_Q1=100*myFsolver->Q1;
	m_Result_Q2=100*myFsolver->Q2;
	m_Result_Q3=100*myFsolver->Q3;
	m_Result_Q4=100*myFsolver->Q4;
	m_Result_Q9nt=100*myFsolver->Q9nt;
	
	delete myFsolver;

	UpdateData(FALSE);

	CQs726Doc* pDoc=GetDocument();
	pDoc->m_DocResult_p=m_Result_p;
	pDoc->m_DocResult_R=m_Result_R;
	pDoc->m_DocResult_Q1=m_Result_Q1;
	pDoc->m_DocResult_Q2=m_Result_Q2;
	pDoc->m_DocResult_Q3=m_Result_Q3;
	pDoc->m_DocResult_Q4=m_Result_Q4;
	pDoc->m_DocResult_Q9nt=m_Result_Q9nt;
	pDoc->SetModifiedFlag();
}


void CQs726View::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand1=m_Band1;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit2() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand2=m_Band2;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit3() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand3=m_Band3;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit4() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand4=m_Band4;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit5() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand5=m_Band5;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit6() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocBand6=m_Band6;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit7() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocRefLane=m_RefLane;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnChangeEdit8() 
{
	CQs726Doc* pDoc=GetDocument();
	UpdateData(TRUE);
	pDoc->m_DocRefRatio=m_RefRatio;
	pDoc->SetModifiedFlag();
	
}

void CQs726View::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_ChooseMode=1;
}

void CQs726View::OnRadio2() 
{
	m_ChooseMode=2;
}

void CQs726View::OnRadio3() 
{
	m_ChooseMode=3;	
}

void CQs726View::OnRadio4() 
{
	m_ChooseMode=4;	
}

void CQs726View::OnButton1() //"Get Default" Button
{
	// TODO: Add your control notification handler code here
	//2005-09-09 Write Analytical algorithm here. Calculate m_Result_X:
	//2005-09-22 Rewrite to get the Initial Values by Analytical algorithm:
    double P1,P2,P3,P4,P5,P6;
	P1=m_Band1/(m_RefLane/m_RefRatio);
	P2=m_Band2/(m_RefLane/m_RefRatio);
	P3=m_Band3/(m_RefLane/m_RefRatio);
	P4=m_Band4/(m_RefLane/m_RefRatio);
	P5=m_Band5/(m_RefLane/m_RefRatio);
	P6=m_Band6/(m_RefLane/m_RefRatio);
	
	//CSteepdnFsolver myFsolver;
    CAnalFsolver* myFsolver=new CAnalFsolver;
	switch(m_ChooseMode)
	{
	case 1: myFsolver->CalR7Mode(P1,P2,P3,P4,P5,P6);break;
	case 2: myFsolver->CalR6Mode(P1,P2,P3,P4,P5);break;
	case 3: myFsolver->CalR5Mode(P1,P2,P3,P4);break;
	case 4: myFsolver->CalR4Mode(P1,P2,P3);break;
	default: MessageBox("Please choose Exp Mode!","NOTICE",MB_OK);
	}
	m_IniVal_p=myFsolver->p;
	m_IniVal_R=100*myFsolver->R;
	m_IniVal_Q1=100*myFsolver->Q1;
	m_IniVal_Q2=100*myFsolver->Q2;
	m_IniVal_Q3=100*myFsolver->Q3;
	m_IniVal_Q4=100*myFsolver->Q4;
	m_IniVal_Q9nt=100*myFsolver->Q9nt;
	
	delete myFsolver;

	UpdateData(FALSE);
/*
	CQs726Doc* pDoc=GetDocument();
	pDoc->m_DocResult_p=m_Result_p;
	pDoc->m_DocResult_R=m_Result_R;
	pDoc->m_DocResult_Q1=m_Result_Q1;
	pDoc->m_DocResult_Q2=m_Result_Q2;
	pDoc->m_DocResult_Q3=m_Result_Q3;
	pDoc->m_DocResult_Q4=m_Result_Q4;
	pDoc->SetModifiedFlag();
	*/
	
}

void CQs726View::OnChangeEdit15() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit16() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit17() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit18() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit19() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit20() 
{
	UpdateData(TRUE);
	
}

void CQs726View::OnChangeEdit21() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}
