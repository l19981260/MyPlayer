// MyPlayer.h : main header file for the MYPLAYER application
//

#if !defined(AFX_MYPLAYER_H__FC36D71C_69F2_49FD_85F9_09B776D01580__INCLUDED_)
#define AFX_MYPLAYER_H__FC36D71C_69F2_49FD_85F9_09B776D01580__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "SkinButton.h"
#include "TimeStatic.h"
#include "TransparentStatic.h"
#include "SlideButton.h"
#include "VolumeButton.h"
#include "PlayListDlg.h"
#include "LyricDlg.h"
#include "MenuDlg.h"
#include <vfw.h>
#pragma comment(lib,"vfw32.lib")
/////////////////////////////////////////////////////////////////////////////
// CMyPlayerApp:
// See MyPlayer.cpp for the implementation of this class
#define  WM_PLAY      WM_USER+1
#define  MODE_SINGLE  0
#define  MODE_SEQ     1
#define  MODE_RAND    2
#define IDI_ICON WM_USER+4
#define MYWM_NOTIFYICON WM_USER+5


typedef struct _filelist
{
	CString strMenu;
	CString strFileName;
}FILELIST,*PFILELIST;
class CMyPlayerApp : public CWinApp
{
public:
	HANDLE m_hMutex;
	void SequenceOrder();
	void RandOrder();
	CMyPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyPlayerApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CStringArray m_strPlayListArray;
extern CMyPlayerApp theApp;
extern int m_nPlayOrder[2000];
extern int m_nNowPlaying;
extern UINT m_nPlayMode;
extern HWND hAudio;
extern FILELIST fileList[10];
extern int nCurrentList;
extern CString strCurrentDir;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPLAYER_H__FC36D71C_69F2_49FD_85F9_09B776D01580__INCLUDED_)
