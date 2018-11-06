// MyPlayer.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerApp

BEGIN_MESSAGE_MAP(CMyPlayerApp, CWinApp)
	//{{AFX_MSG_MAP(CMyPlayerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerApp construction

CMyPlayerApp::CMyPlayerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyPlayerApp object

CMyPlayerApp theApp;
CStringArray m_strPlayListArray;
int m_nPlayOrder[2000];
int m_nNowPlaying;
UINT m_nPlayMode;
HWND hAudio;
FILELIST fileList[10];
int nCurrentList;
CString strCurrentDir;
/////////////////////////////////////////////////////////////////////////////
// CMyPlayerApp initialization

BOOL CMyPlayerApp::InitInstance()
{
	AfxEnableControlContainer();

	m_hMutex=CreateMutex(NULL,FALSE,"“Ù¿÷≤•∑≈∆˜");

	if (GetLastError()==ERROR_ALREADY_EXISTS )	
	{
		HWND hwnd=FindWindow(NULL,"“Ù¿÷≤•∑≈∆˜");
		
		if(hwnd!=NULL){
			if(IsWindowVisible(hwnd))
				return FALSE;
		    SendMessage(hwnd,MYWM_NOTIFYICON,NULL,(LPARAM)WM_LBUTTONDOWN);
		}
       return FALSE ;
	}


	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
    hAudio=NULL;	
	TCHAR szCurDir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH,szCurDir);
	strCurrentDir=szCurDir;
	m_nPlayMode=MODE_RAND;

	CMyPlayerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

void CMyPlayerApp::RandOrder()
{
	int nNum;
	BOOL fInsert;
	BOOL fFound;
	int i;
	for(i=0;i<m_strPlayListArray.GetSize();i++){
		fInsert=FALSE;
		while(!fInsert){
			nNum=rand()%m_strPlayListArray.GetSize();
			fFound=FALSE;
			for(int j=0;j<i;j++){
				if(m_nPlayOrder[j]==nNum){
					fFound=TRUE;
					break;
				}
			}
			if(!fFound){
				m_nPlayOrder[i]=nNum;
				fInsert=TRUE;
			}
		}
	}
	m_nPlayOrder[i]=0;
}

void CMyPlayerApp::SequenceOrder()
{
	int i;
	for(i=0;i<m_strPlayListArray.GetSize();i++)
		m_nPlayOrder[i]=i;
	m_nPlayOrder[i]=0;
}

int CMyPlayerApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	CloseHandle(m_hMutex);
	return CWinApp::ExitInstance();
}
