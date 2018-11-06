// ScrollText.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "ScrollText.h"
 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ID_TIP   1
/////////////////////////////////////////////////////////////////////////////
// CScrollText

CScrollText::CScrollText()
{
	m_nElapse=1000;
	fStart=FALSE;
	fInit=FALSE;
}

CScrollText::~CScrollText()
{
}


BEGIN_MESSAGE_MAP(CScrollText, CStatic)
	//{{AFX_MSG_MAP(CScrollText)
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScrollText message handlers

void CScrollText::SetToolTipText(CString strText)
{
	m_ToolTip.UpdateTipText(strText,this,ID_TIP);
}

void CScrollText::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD dwStyle=GetStyle();
	SetWindowLong(GetSafeHwnd(),GWL_STYLE, dwStyle|SS_NOTIFY);

	CRect rect;
	GetClientRect(&rect);
	m_ToolTip.Create(this);
	m_ToolTip.SetDelayTime(100);
	m_ToolTip.SetMaxTipWidth(200);
	m_ToolTip.AddTool(this,"",rect,ID_TIP);

	CStatic::PreSubclassWindow();
}

BOOL CScrollText::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_ToolTip.RelayEvent(pMsg);

	return CStatic::PreTranslateMessage(pMsg);
}

void CScrollText::Start()
{
	if(!fInit)
		return;

	SetTimer(1,m_nElapse,NULL);
	fStart=TRUE;
}

void CScrollText::Stop()
{
  if(!fStart)
		return;
   KillTimer(1);
   fStart=FALSE;
}

void CScrollText::SetSpeed(UINT nElapse)
{
	m_nElapse=nElapse;
	if(fStart){
		Stop();
		Start();
	}
}

HBRUSH CScrollText::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0,255,0));   
	// TODO: Return a non-NULL brush if the parent's handler should not be called
    return (HBRUSH)GetStockObject(NULL_BRUSH);
}

void CScrollText::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	strOutText="";
	TCHAR ch;
	for(UINT i=0;i<m_nLength;){
		ch=strTotalText.GetAt(nCounter+i);
		strOutText+=ch;
		i++;
		ch=strTotalText.GetAt(nCounter+i);
		strOutText+=ch;
		i++;
	}   
	Invalidate();
	nCounter++;
	if(nCounter>=strTotalText.GetLength()-m_nLength)
	  nCounter=0;
	CStatic::OnTimer(nIDEvent);
}

void CScrollText::SetText(CString strText)
{
	if(!fInit)
		return;
  strTotalText=strText; 
  for(UINT i=0;i<m_nLength;i++)
	  strTotalText+=" ";
   nCounter=0;  
}

void CScrollText::Init()
{
	CRect rect;
    GetClientRect(&rect);
    m_nLength=rect.Width()/6;
	CString str;
	str.Format("%d",m_nLength);
	fInit=TRUE;
}


void CScrollText::OnDestroy() 
{
	CStatic::OnDestroy();
	
	// TODO: Add your message handler code here
	if(fStart)
		KillTimer(1);
}
