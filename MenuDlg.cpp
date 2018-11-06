// MenuDlg.cpp : implementation file
//
 
#include "stdafx.h"
#include "MyPlayer.h"
#include "MenuDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg dialog


CMenuDlg::CMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMenuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMenuDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pParent=pParent;
	m_nID=CMenuDlg::IDD;
}


void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMenuDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
	//{{AFX_MSG_MAP(CMenuDlg)
	ON_WM_MOVE()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuDlg message handlers



void CMenuDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	
}

BOOL CMenuDlg::Create()
{
   	return CDialog::Create(m_nID, m_pParent);
}

void CMenuDlg::OnKillFocus(CWnd* pNewWnd) 
{
//	CDialog::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
   ShowWindow(SW_HIDE);
}

void CMenuDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
   DestroyWindow();
	CDialog::OnLButtonDown(nFlags, point);
}
