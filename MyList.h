#if !defined(AFX_MYLIST_H__AEEDA4D0_2732_433D_88B3_6D1449102494__INCLUDED_)
#define AFX_MYLIST_H__AEEDA4D0_2732_433D_88B3_6D1449102494__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyList.h : header file
#include "FileAttributeDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CMyList window

class CMyList : public CListBox
{
// Construction
public:
	CMyList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyList)
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL CheckRemoveAbleDisk();
	CString strRemoveAbleDisk;

	CString strFilePath;
	CString GetFileName(CString strFileName);
	virtual ~CMyList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyList)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileAttribute();
	afx_msg void OnSendDisk();
	afx_msg void OnSendFolder();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLIST_H__AEEDA4D0_2732_433D_88B3_6D1449102494__INCLUDED_)
