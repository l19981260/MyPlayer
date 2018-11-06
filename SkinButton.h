#if !defined(AFX_SKINBUTTON_H__0BB3DC00_8775_4611_A01E_7285C6B95876__INCLUDED_)
#define AFX_SKINBUTTON_H__0BB3DC00_8775_4611_A01E_7285C6B95876__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkinButton.h : header file

/////////////////////////////////////////////////////////////////////////////
// CSkinButton window

class CSkinButton : public CButton
{
// Construction
public:
	CSkinButton();

// Attributes
public:

// Operations
	
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkinButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void Init(UINT nNormalID,UINT nMouseOverID,CString strTipText);
	BOOL SetBitmap(UINT nNormalID,UINT nMouseOverID);
	void SetToolTipText(CString strText);
	BOOL SetButtonCursor(HCURSOR hCursor);
	virtual ~CSkinButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSkinButton)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void AdjustPosition();
	CWnd* pWndParent;
	UINT m_nMouseOverID;
	UINT m_nNormalID;
	CToolTipCtrl m_ToolTip;
	void SetDefaultCursor();
	HCURSOR m_hCursor;
	BOOL m_bMouseOver;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SKINBUTTON_H__0BB3DC00_8775_4611_A01E_7285C6B95876__INCLUDED_)
