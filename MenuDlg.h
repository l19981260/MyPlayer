#if !defined(AFX_MENUDLG_H__3F2BEB0A_2611_42FF_83A5_9FD8699AF9AB__INCLUDED_)
#define AFX_MENUDLG_H__3F2BEB0A_2611_42FF_83A5_9FD8699AF9AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MenuDlg.h : header file
//
 
/////////////////////////////////////////////////////////////////////////////
// CMenuDlg dialog

class CMenuDlg : public CDialog
{
// Construction
public:
	BOOL Create();
	UINT m_nID;
	CWnd* m_pParent;

	CMenuDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMenuDlg)
	enum { IDD = IDD_MENE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMenuDlg)
	afx_msg void OnMove(int x, int y);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUDLG_H__3F2BEB0A_2611_42FF_83A5_9FD8699AF9AB__INCLUDED_)
