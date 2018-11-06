#if !defined(AFX_TIMESTATIC_H__C69ED7E2_E9C5_4078_BD89_764D349BCAEE__INCLUDED_)
#define AFX_TIMESTATIC_H__C69ED7E2_E9C5_4078_BD89_764D349BCAEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TimeStatic.h : header file
//
 
/////////////////////////////////////////////////////////////////////////////
// CTimeStatic window

class CTimeStatic : public CStatic
{
// Construction
public:
	CTimeStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeStatic)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTimeStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTimeStatic)
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMESTATIC_H__C69ED7E2_E9C5_4078_BD89_764D349BCAEE__INCLUDED_)
