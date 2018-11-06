// MyPlayerDlg.h : header file
//

#if !defined(AFX_MYPLAYERDLG_H__610001D2_C0A8_4E19_8C5B_D7A920C5EABA__INCLUDED_)
#define AFX_MYPLAYERDLG_H__610001D2_C0A8_4E19_8C5B_D7A920C5EABA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CMyPlayerDlg dialog
class CMyPlayerDlg : public CDialog
{
// Construction
public:
	CString m_strLyricPath;
	void DeleteNotifyIcon();
	void CreateNotifyIcon();
	BOOL fPlay;
	void DestroyMenuDlg();
	CMenuDlg* m_pMenuDlg;
	int m_nVolume;
	void WriteConfig();
    BOOL ReadConfig();
	BOOL IsFileExist(CString strFileName);
	BOOL  GetFileList(CString strLine,int nIndex);
	void InitFileList();
	int nRollTextCounter;
	void CirculatePlay();
	void DropFilesInPlayList(HDROP hDrop);
	void DropFilesInMain(HDROP hDrop);
	BOOL IsSupportFile(CString strFileName);
	void GetDropFiles(HDROP hDrop);
	void FormatTitle(CString strFile);
	BOOL fPlaying;
	UINT m_nTime;
	void Play(int nIndex);
	CString GetFileTitle(CString strFileName);
	BOOL IsLyricDlgAttach();
	BOOL IsPlayListAttach();
	void MoveLyricWindow();
	void MovePlayListWindow();
	BOOL fInited;
	void CreateLyric();
	CLyricDlg* m_pLyricDlg;
	void CreatePlayList();
	CPlayListDlg* m_pPlayListDlg;
	void InitSize();
	void ExitPlayer();
	void MoveSlide();
	void InitText();
	void CountTime();
	CString strTime;
	void InitRect();
	CRect rectTitle;
	CRect rectTime;
	void DrawTime(CDC*pDC);
	void RollText();
	CString strOutText;
	CString strTitle;
	void DrawText(CDC*pDC);
	void DrawMainPicture(CDC*pDC);
	void InitButtons();
	CMyPlayerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyPlayerDlg)
	enum { IDD = IDD_MYPLAYER_DIALOG };
	CSkinButton	m_btnShowMenu;
	CSkinButton	m_btnLyric;
	CVolumeButton	m_volume;
	CSlideButton	m_slide;
	CTransparentStatic	m_stcMode;
	CTransparentStatic	m_stcPlay;
	CSkinButton	m_btnStop;
	CSkinButton	m_btnPrev;
	CSkinButton	m_btnPLShow;
	CSkinButton	m_btnPlay;
	CSkinButton	m_btnOpen;
	CSkinButton	m_btnNext;
	CSkinButton	m_btnMin;
	CSkinButton	m_btnHide;
	CSkinButton	m_btnExit;
	CButton	m_buttonOK;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPlayerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyPlayerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBtnExit();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStaticMode();
	afx_msg void OnStaticPlay();
	afx_msg void OnBtnVolume();
	afx_msg void OnBtnSlide();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnBtnPlaylistShow();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnBtnLyric();
	afx_msg void OnBtnOpen();
	afx_msg void OnBtnNext();
	afx_msg void OnBtnPlay();
	afx_msg void OnBtnPrev();
	afx_msg void OnBtnStop();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBtnShowmenu();
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnMenuNext();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuPlay();
	afx_msg void OnMenuPrev();
	afx_msg void OnMenuRand();
	afx_msg void OnMenuSeq();
	afx_msg void OnMenuSingle();
	afx_msg void OnMenuStop();
	afx_msg void OnMenuVoldown();
	afx_msg void OnMenuPause();
	afx_msg void OnMenuVolslc();
	afx_msg void OnMenuVolup();
	afx_msg void OnAboutStar();
	afx_msg void OnNotifyIcon(WPARAM wParam,LPARAM lParam);
	afx_msg void OnBtnHide();
	afx_msg void OnBtnMin();
	afx_msg void OnSetLyricpath();
	afx_msg void OnMenuOpenLyricpath();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPLAYERDLG_H__610001D2_C0A8_4E19_8C5B_D7A920C5EABA__INCLUDED_)
