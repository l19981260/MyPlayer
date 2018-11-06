#if !defined(AFX_NEWLISTDLG_H__1DF0F1B0_9F7F_4022_8B16_CF0F9C9E1666__INCLUDED_)
#define AFX_NEWLISTDLG_H__1DF0F1B0_9F7F_4022_8B16_CF0F9C9E1666__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewListDlg dialog
class CNewListDlg : public CDialog
{
// Construction
public:
	CNewListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewListDlg)
	enum { IDD = IDD_NEWLIST_DIALOG };
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewListDlg)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLISTDLG_H__1DF0F1B0_9F7F_4022_8B16_CF0F9C9E1666__INCLUDED_)
