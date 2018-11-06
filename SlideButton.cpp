// SlideButton.cpp : implementation file
//
 
#include "stdafx.h"
#include "MyPlayer.h"
#include "SlideButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ID_TIP  1
/////////////////////////////////////////////////////////////////////////////
// CSlideButton

CSlideButton::CSlideButton()
{

}

CSlideButton::~CSlideButton()
{
}


BEGIN_MESSAGE_MAP(CSlideButton, CButton)
	//{{AFX_MSG_MAP(CSlideButton)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlideButton message handlers

void CSlideButton::SetBitmap(UINT nBkgnd, UINT nSlide)
{
	m_nBkgnd=nBkgnd;
	nSlide=m_nSlide;
	Invalidate();
}

void CSlideButton::SetDefaultCursor()
{
	m_hCursor=LoadCursor(NULL,MAKEINTRESOURCE(32649));
}

void CSlideButton::SetRange(UINT nMin, UINT nMax)
{
	m_nMin=nMin;
	m_nMax=nMax;
	AdjustPosition();
	Invalidate();
}

void CSlideButton::SetSlidePos(UINT nPos)
{
	m_nCurrentPos=nPos;
	Invalidate();
}

void CSlideButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC*pDC;
	pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	DrawBackground(pDC);
	DrawSlide(pDC);
}

void CSlideButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetDefaultCursor();
	
	CRect rect;
	GetClientRect(&rect);
	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(100);
	m_ToolTip.SetMaxTipWidth(200);
	m_ToolTip.AddTool(this,"",rect,ID_TIP);

	CButton::PreSubclassWindow();
}

BOOL CSlideButton::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_ToolTip.RelayEvent(pMsg);
	return CButton::PreTranslateMessage(pMsg);
}

BOOL CSlideButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_hCursor!=NULL){
		::SetCursor(m_hCursor);
		return TRUE;
	}
	return FALSE;
}

void CSlideButton::SetButtonCursor(HCURSOR hCursor)
{
   m_hCursor=hCursor;
}

void CSlideButton::DrawBackground(CDC*pDC)
{
	CDC MemDC;    
	CBitmap bitmap;
	BITMAP m_bitmap;

	bitmap.LoadBitmap(m_nBkgnd);
	bitmap.GetBitmap(&m_bitmap);

	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bitmap);

	pDC->BitBlt(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,&MemDC,
		0,0,SRCCOPY);

	bitmap.DeleteObject();
	MemDC.DeleteDC();
}

void CSlideButton::DrawSlide(CDC *pDC)
{
	CRect rect;
	GetClientRect(&rect);
	int nWidth=rect.Width();
    	
	CBitmap bitmap;
	BITMAP m_bitmap;
	CDC MemDC;

	bitmap.LoadBitmap(m_nSlide);
	bitmap.GetBitmap(&m_bitmap);

	nWidth-=m_bitmap.bmWidth;
	int x=(int)(((float)nWidth/(float)(m_nMax-m_nMin))*(m_nCurrentPos-m_nMin));
    if(x<0)
		x=0;

	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bitmap);

	pDC->BitBlt(x,0,m_bitmap.bmWidth,m_bitmap.bmHeight,
		&MemDC,0,0,SRCCOPY);

	bitmap.DeleteObject();
	MemDC.DeleteDC();

	m_nWidth=nWidth;
}

void CSlideButton::SetToolTipText(CString strText)
{
	m_ToolTip.UpdateTipText(strText,this,ID_TIP);
}

void CSlideButton::Init(UINT nBkgndID, UINT nSlideID, UINT nMax, UINT nMin, CString strTipText)
{
	m_nBkgnd=nBkgndID;
	m_nSlide=nSlideID;
	m_nMax=nMax;
	m_nMin=nMin;
	m_ToolTip.UpdateTipText(strTipText,this,ID_TIP);
	m_nCurrentPos=m_nMin;
	pWndParent=GetParent();
	AdjustPosition();
}

void CSlideButton::Init(UINT nBkgndID, UINT nSlideID, CString strTipText)
{
	m_nBkgnd=nBkgndID;
	m_nSlide=nSlideID;
	m_nMax=100;
	m_nMin=1;
	m_ToolTip.UpdateTipText(strTipText,this,ID_TIP);
	m_nCurrentPos=m_nMin;
	pWndParent=GetParent();
	AdjustPosition();
}

UINT CSlideButton::GetSlidePos()
{
   return m_nCurrentPos;
}

void CSlideButton::AdjustPosition()
{
	CRect rect;
	CBitmap bitmap;
	BITMAP m_bitmap;

	bitmap.LoadBitmap(m_nBkgnd);
	bitmap.GetBitmap(&m_bitmap);

	GetWindowRect(&rect);
	pWndParent->ScreenToClient(&rect);
	rect.right=rect.left+m_bitmap.bmWidth;
	rect.bottom=rect.top+m_bitmap.bmHeight;
	MoveWindow(&rect,TRUE);

	bitmap.DeleteObject();
  
}

void CSlideButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point)){
		m_nCurrentPos=(UINT)((float)point.x/(float)m_nWidth*(m_nMax-m_nMin))+m_nMin;
	}
	CButton::OnLButtonDown(nFlags, point);
}

void CSlideButton::GetRange(UINT &nMax, UINT &nMin)
{
  nMax=m_nMax;
  nMin=m_nMin;
}
