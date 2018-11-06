#if !defined(AFX_FILEATTRIBUTEDLG_H__792A3978_A896_4663_9BA6_B33E7F4887B1__INCLUDED_)
#define AFX_FILEATTRIBUTEDLG_H__792A3978_A896_4663_9BA6_B33E7F4887B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FileAttributeDlg.h : header file

/////////////////////////////////////////////////////////////////////////////
// CFileAttributeDlg dialog

class CFileAttributeDlg : public CDialog
{
// Construction
public:
	CString GetFileSize();
	CString strFileName;
	int nIndex;
	CFileAttributeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFileAttributeDlg)
	enum { IDD = IDD_FILEATTRIBUTE_DIALOG };
	CStatic	m_stcSize;
	CEdit	m_edtPath;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileAttributeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFileAttributeDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEATTRIBUTEDLG_H__792A3978_A896_4663_9BA6_B33E7F4887B1__INCLUDED_)
