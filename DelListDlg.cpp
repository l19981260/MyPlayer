// DelListDlg.cpp : implementation file
//
 
#include "stdafx.h"
#include "MyPlayer.h"
#include "DelListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelListDlg dialog


CDelListDlg::CDelListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelListDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDelListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelListDlg)
	DDX_Control(pDX, IDC_COMBO_LIST, m_cmbList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelListDlg, CDialog)
	//{{AFX_MSG_MAP(CDelListDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelListDlg message handlers

void CDelListDlg::OnOK() 
{
	// TODO: Add extra validation here
	int n=m_cmbList.GetCurSel();
	if(MessageBox("你确定要删除该播放列表么?","删除播放列表",MB_YESNO)==IDNO)
		return;

	 CPlayListDlg*  pDlg=new CPlayListDlg;
	if(n==0){
		fileList[0].strMenu="默认";
		CString fileName;
		fileName.Format("%s\\000.lst",strCurrentDir);
		ofstream outfile(fileName,ios::out);
		outfile.close();
		if(nCurrentList==0){
			m_strPlayListArray.RemoveAll();
			pDlg->m_playlist.ResetContent();
		}
	}else{     
	   pDlg->DeleteList(n);
	   
	}
	delete pDlg;


	CDialog::OnOK();
}

BOOL CDelListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	for(int i=0;i<10;i++){
		if(!fileList[i].strFileName.IsEmpty())
			m_cmbList.AddString(fileList[i].strMenu);
	}
	m_cmbList.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
