#if !defined(AFX_DELLISTDLG_H__86B72D77_57BF_49E3_86E9_40AB1224AF70__INCLUDED_)
#define AFX_DELLISTDLG_H__86B72D77_57BF_49E3_86E9_40AB1224AF70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelListDlg.h : header file
#include "PlayListDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CDelListDlg dialog

class CDelListDlg : public CDialog
{
// Construction
public:
	CDelListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDelListDlg)
	enum { IDD = IDD_DEL_LIST_DIALOG };
	CComboBox	m_cmbList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDelListDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELLISTDLG_H__86B72D77_57BF_49E3_86E9_40AB1224AF70__INCLUDED_)
