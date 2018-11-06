#if !defined(AFX_VOLUMEBUTTON_H__E2E18F7C_60C0_461F_9278_E0F5CEA0A0E3__INCLUDED_)
#define AFX_VOLUMEBUTTON_H__E2E18F7C_60C0_461F_9278_E0F5CEA0A0E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VolumeButton.h : header file

/////////////////////////////////////////////////////////////////////////////
// CVolumeButton window

class CVolumeButton : public CButton
{
// Construction
public:
	CVolumeButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVolumeButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void Init(UINT nBkgndID,CString strTipText);
	UINT GetPos();
	void SetPos(UINT nPos);
	void SetToolTipText(CString strText);
	void SetButtonCursor(HCURSOR hCursor);
	virtual ~CVolumeButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVolumeButton)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	UINT m_nBkgndID;
	void AdjustPosition();
	UINT m_nPos;
	HCURSOR m_hCursor;
	void SetDefaultCursor();
	void DrawLines(CDC*pDC);
	void DrawBackground(CDC*pDC);
	CToolTipCtrl m_ToolTip;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOLUMEBUTTON_H__E2E18F7C_60C0_461F_9278_E0F5CEA0A0E3__INCLUDED_)
