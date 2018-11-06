// FileAttributeDlg.cpp : implementation file
//
 
#include "stdafx.h"
#include "MyPlayer.h"
#include "FileAttributeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileAttributeDlg dialog


CFileAttributeDlg::CFileAttributeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileAttributeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileAttributeDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFileAttributeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileAttributeDlg)
	DDX_Control(pDX, IDC_STATIC_SIZE, m_stcSize);
	DDX_Control(pDX, IDC_EDIT_PATH, m_edtPath);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFileAttributeDlg, CDialog)
	//{{AFX_MSG_MAP(CFileAttributeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileAttributeDlg message handlers

BOOL CFileAttributeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strCaption;
    int nPos;
	if(!strFileName.IsEmpty()){
		nPos=strFileName.Find("  ",0);
		strFileName=strFileName.Right(strFileName.GetLength()-nPos-2);
		strCaption.Format("\"%s\"ÊôÐÔ",strFileName);
		SetWindowText(strCaption);
	}
	if(nIndex>0){
	 m_edtPath.SetWindowText(m_strPlayListArray.GetAt(nIndex));
	 m_stcSize.SetWindowText(GetFileSize());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CString CFileAttributeDlg::GetFileSize()
{
	if(nIndex<0)
		return "";
	HANDLE hFile=CreateFile(m_strPlayListArray.GetAt(nIndex),
		GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,NULL);
	if(hFile==INVALID_HANDLE_VALUE)
		return "";
	DWORD dwFileSize=::GetFileSize(hFile,NULL);
	CString strFileSize;
	strFileSize.Format("%.2fMB",(float)dwFileSize/(float)(1024*1024));
	CloseHandle(hFile);
	return strFileSize;
}
