// TransparentStatic.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "TransparentStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define  ID_TIP    1
/////////////////////////////////////////////////////////////////////////////
// CTransparentStatic

CTransparentStatic::CTransparentStatic()
{

}

CTransparentStatic::~CTransparentStatic()
{
}


BEGIN_MESSAGE_MAP(CTransparentStatic, CStatic)
	//{{AFX_MSG_MAP(CTransparentStatic)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransparentStatic message handlers


void CTransparentStatic::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD dwStyle=GetStyle();
	SetWindowLong(GetSafeHwnd(),GWL_STYLE,dwStyle|SS_NOTIFY);

	SetDefaultCursor();

	CRect rect;
	GetClientRect(&rect);
	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(100);
	m_ToolTip.SetMaxTipWidth(200);
	m_ToolTip.AddTool(this,"",rect,ID_TIP);

	CStatic::PreSubclassWindow();
}

HBRUSH CTransparentStatic::CtlColor(CDC* pDC, UINT nCtlColor)
{
	// TODO: Change any attributes of the DC here
//	pDC->SetBkMode(TRANSPARENT);
	pDC->SetBkColor(RGB(0,0,0));
	pDC->SetTextColor(RGB(0,255,0));
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return (HBRUSH)GetStockObject(NULL_BRUSH);
}

BOOL CTransparentStatic::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	m_ToolTip.RelayEvent(pMsg);
	return CStatic::PreTranslateMessage(pMsg);
}

void CTransparentStatic::SetCursor(HCURSOR hCursor)
{
  m_hCursor=hCursor;
}

void CTransparentStatic::SetToolTipText(CString strText)
{
	m_ToolTip.UpdateTipText(strText,this,ID_TIP);

}

void CTransparentStatic::SetDefaultCursor()
{
  m_hCursor=LoadCursor(NULL,MAKEINTRESOURCE(32649));
}

BOOL CTransparentStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if(m_hCursor!=NULL){
		::SetCursor(m_hCursor);
		return TRUE;
	}

	return FALSE;
}
