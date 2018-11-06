// TimeStatic.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "TimeStatic.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeStatic

CTimeStatic::CTimeStatic()
{
}

CTimeStatic::~CTimeStatic()
{
}


BEGIN_MESSAGE_MAP(CTimeStatic, CStatic)
	//{{AFX_MSG_MAP(CTimeStatic)
	ON_WM_CTLCOLOR_REFLECT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeStatic message handlers

void CTimeStatic::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD dwStyle=GetStyle();//ÐÞ¸ÄÊôÐÔ
	SetWindowLong(GetSafeHwnd(),GWL_STYLE, dwStyle|SS_NOTIFY);

	CStatic::PreSubclassWindow();
}

HBRUSH CTimeStatic::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255,200,0));
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return (HBRUSH)GetStockObject(NULL_BRUSH);
}
