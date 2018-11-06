#if !defined(AFX_LYRICDLG_H__8799792B_FAD6_4AC3_B8C2_3C47B0B31778__INCLUDED_)
#define AFX_LYRICDLG_H__8799792B_FAD6_4AC3_B8C2_3C47B0B31778__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LyricDlg.h : header file
//

#include <fstream>
using namespace std;


#define MAXCOUNT  100
/////////////////////////////////////////////////////////////////////////////
// CLyricDlg dialog
typedef  struct _star
{
	int x;
	int y;
	int speed;
	int size;
} STAR,*PSTAR;

typedef struct _lyric
{
	int time;
	CString strLyric;
}LYRIC,*PLYRIC;

class CLyricDlg : public CDialog
{
// Construction
public:
	void SetPlayListWnd(CWnd*pWnd);
	CWnd* m_pPlaylistWnd;
	BOOL fHideMain;
	BOOL OpenLyric(CString strLyricPath,int nIndex);
	void InvalidateCtrl();
	CBitmap* m_pOldBitmap;
	CBitmap m_MainBitmap;
	CDC m_MainDC;
	CFont m_font;
	void SlideClick();
	int m_nCurrentLine;
	void CountStep();
	int nStep;
	void SortLyric();
	int nCounter;
	int GetTime(CString strTime);
	void AnalyseLine(CString strLine);
	int m_nTotalLines;
	LYRIC m_lyric[1000];
	BOOL IsExistFile(CString strFileName);
	BOOL OpenLyric(int nIndex);
	BOOL fInited;
	void GetLyric(CString strFileName);
	void DrawText(CDC*pDC);
	void InitStar();
	void DrawStar(CDC*pDC,int nIndex);
	void NewStar(int nIndex);
	STAR m_star[MAXCOUNT];
	void CleanScreen();
	BOOL Create();
	int m_nID;
	CWnd* m_pParent;
	CLyricDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLyricDlg)
	enum { IDD = IDD_LYRIC_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLyricDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLyricDlg)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnHideMain();
	afx_msg void OnHideLyric();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LYRICDLG_H__8799792B_FAD6_4AC3_B8C2_3C47B0B31778__INCLUDED_)
