// VolumeButton.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "VolumeButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ID_TIP 1
/////////////////////////////////////////////////////////////////////////////
// CVolumeButton
 
CVolumeButton::CVolumeButton()
{
}

CVolumeButton::~CVolumeButton()
{
}


BEGIN_MESSAGE_MAP(CVolumeButton, CButton)
	//{{AFX_MSG_MAP(CVolumeButton)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVolumeButton message handlers

void CVolumeButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	CDC*pDC;
	pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	DrawBackground(pDC);
	DrawLines(pDC);
}

void CVolumeButton::PreSubclassWindow() 
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

BOOL CVolumeButton::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_ToolTip.RelayEvent(pMsg);
	return CButton::PreTranslateMessage(pMsg);
}

BOOL CVolumeButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_hCursor!=NULL){
		::SetCursor(m_hCursor);
		return TRUE;
	}
	return FALSE;
}

void CVolumeButton::SetButtonCursor(HCURSOR hCursor)
{
	m_hCursor=hCursor;
}

void CVolumeButton::DrawBackground(CDC*pDC)
{
	CBitmap bitmap;
	BITMAP  m_bitmap;
	CDC MemDC;

	bitmap.LoadBitmap(m_nBkgndID);
	bitmap.GetBitmap(&m_bitmap);
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bitmap);

	pDC->BitBlt(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,&MemDC,
		0,0,SRCCOPY);

	bitmap.DeleteObject();
	MemDC.DeleteDC();
}

void CVolumeButton::DrawLines(CDC*pDC)
{
	if(m_nPos<=0)
		return;

    CPen pen(PS_SOLID,2,RGB(200,97,0));
	CPen* pOldPen=pDC->SelectObject (&pen);
    
	UINT nHeight=64;
	UINT nSpace=4;
		
	CPoint pointBegin,pointEnd;
	
	pointBegin.x=0;
	pointEnd.x=7;

	for(UINT i=0;i<m_nPos;i++){
        pointBegin.y=nHeight-nSpace*i;
        pointEnd.y=pointBegin.y;
    	pDC->MoveTo(pointBegin);
    	pDC->LineTo(pointEnd);
	}

	pDC->SelectObject (pOldPen);
}

void CVolumeButton::SetDefaultCursor()
{
	m_hCursor=LoadCursor(NULL,MAKEINTRESOURCE(32649));
}

void CVolumeButton::SetToolTipText(CString strText)
{
  m_ToolTip.UpdateTipText(strText,this,ID_TIP);
}

void CVolumeButton::SetPos(UINT nPos)
{
  m_nPos=nPos;
  Invalidate();
}

UINT CVolumeButton::GetPos()
{
	return m_nPos;
}

void CVolumeButton::AdjustPosition()
{
	CWnd*pParent=GetParent();

	CBitmap bitmap;
	BITMAP  m_bitmap;
	CRect   rect;

	GetWindowRect(&rect);
	pParent->ScreenToClient(&rect);

	bitmap.LoadBitmap(m_nBkgndID);
	bitmap.GetBitmap(&m_bitmap);
	rect.right=rect.left+m_bitmap.bmWidth;
	rect.bottom=rect.top+m_bitmap.bmHeight;

	MoveWindow(&rect,TRUE);

	bitmap.DeleteObject();
  
}

void CVolumeButton::Init(UINT nBkgndID,CString strTipText)
{
  m_nBkgndID=nBkgndID;
  m_ToolTip.UpdateTipText(strTipText,this,ID_TIP);
  m_nPos=0;
  AdjustPosition();
}



void CVolumeButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
     CRect rect;
	 GetClientRect(rect);
	 if(rect.PtInRect(point)){
		 int n=64-(point.y/4)*4;
		 if(n<0)
			 n=0;
		 m_nPos=(UINT)n/4;
		 Invalidate();		 
	 }
	CButton::OnLButtonDown(nFlags, point);
}
