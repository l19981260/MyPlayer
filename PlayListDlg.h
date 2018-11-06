#if !defined(AFX_PLAYLISTDLG_H__58542A84_1049_43B4_84D8_CFFAD98C2468__INCLUDED_)
#define AFX_PLAYLISTDLG_H__58542A84_1049_43B4_84D8_CFFAD98C2468__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PlayListDlg.h : header file
#include "NewListDlg.h"
#include "RenameDlg.h"
#include "DelListDlg.h"
#include "MyList.h"
/////////////////////////////////////////////////////////////////////////////
// CPlayListDlg dialog

class CPlayListDlg : public CDialog
{
// Construction
public:
	BOOL IsFileExist(CString strFileName);
	BOOL DeleteList(int nIndex);
	BOOL SaveList(int nIndex);
	BOOL OpenList(int nIndex);
	void AddFolderFiles(CString strDir);
	BOOL IsSupportFile(CString strFileName);
	CString GetFileTitle(CString strFileName);
	BOOL fInited;
	void SetFont(HDC);
	void InitButtons();
	void DrawBackground(CDC*pDC);
	BOOL Create();
    int  m_nID;
	CWnd* m_pParent;
	CPlayListDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPlayListDlg)
	enum { IDD = IDD_PLAYLIST_DIALOG };
	CMyList	m_playlist;
	CSkinButton	m_btnList;
	CSkinButton	m_btnDel;
	CSkinButton	m_btnAdd;
	CSkinButton	m_btnClose;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlayListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PostNcDestroy();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPlayListDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnBtnClose();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMove(int x, int y);
	afx_msg void OnDblclkPlaylist();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDel();
	afx_msg void OnBtnList();
	afx_msg void OnAddFile();
	afx_msg void OnAddFolder();
	afx_msg void OnDelSelect();
	afx_msg void OnDelAll();
	afx_msg void OnListNew();
	afx_msg void OnListDel();
	afx_msg void OnListOpen1();
	afx_msg void OnListOpen2();
	afx_msg void OnListOpen3();
	afx_msg void OnListOpen4();
	afx_msg void OnListOpen5();
	afx_msg void OnListOpen6();
	afx_msg void OnListOpen7();
	afx_msg void OnListOpen8();
	afx_msg void OnListOpen9();
	afx_msg void OnListOpen10();
	afx_msg void OnListSave();
	afx_msg void OnListRename();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLAYLISTDLG_H__58542A84_1049_43B4_84D8_CFFAD98C2468__INCLUDED_)
