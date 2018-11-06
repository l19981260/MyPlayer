#if !defined(AFX_SLIDEBUTTON_H__747B63AD_39DB_430B_8602_3CD9BF681F2F__INCLUDED_)
#define AFX_SLIDEBUTTON_H__747B63AD_39DB_430B_8602_3CD9BF681F2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SlideButton.h : header file

/////////////////////////////////////////////////////////////////////////////
// CSlideButton window

class CSlideButton : public CButton
{
// Construction
public:
	CSlideButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlideButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void GetRange(UINT &nMax,UINT &nMin);
	UINT GetSlidePos();
	void Init(UINT nBkgndID,UINT nSlideID,CString strTipText);
	void Init(UINT nBkgndID,UINT nSlideID,UINT nMax,UINT nMin,CString strTipText);
	void SetToolTipText(CString strText);
	void SetButtonCursor(HCURSOR hCursor);
	void SetSlidePos(UINT nPos);
	void SetRange(UINT nMin,UINT nMax);
	void SetBitmap(UINT nBkgnd,UINT nSlide);
	virtual ~CSlideButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlideButton)
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	UINT m_nWidth;
	void AdjustPosition();
	void DrawSlide(CDC*pDC);
	void DrawBackground(CDC*pDC);
	UINT m_nCurrentPos;
	UINT m_nMax;
	UINT m_nMin;
	void SetDefaultCursor();
	HCURSOR m_hCursor;
	CToolTipCtrl m_ToolTip;
	CWnd* pWndParent;
	UINT m_nSlide;
	UINT m_nBkgnd;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDEBUTTON_H__747B63AD_39DB_430B_8602_3CD9BF681F2F__INCLUDED_)
