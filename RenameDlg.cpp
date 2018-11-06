// RenameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "RenameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
 
/////////////////////////////////////////////////////////////////////////////
// CRenameDlg dialog


CRenameDlg::CRenameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRenameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRenameDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CRenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRenameDlg)
	DDX_Control(pDX, IDC_COMBO_LIST, m_cmbList);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRenameDlg, CDialog)
	//{{AFX_MSG_MAP(CRenameDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRenameDlg message handlers

void CRenameDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strName.IsEmpty()){
		MessageBox("«Î ‰»Î√˚≥∆");
		return;
	}
	int n=m_cmbList.GetCurSel();
	fileList[n].strMenu=m_strName;
	ofstream outfile("listname.dat",ios::out);
	for(int i=0;i<10;i++){
		if(!fileList[i].strFileName.IsEmpty()){
			outfile<<fileList[i].strMenu;
			outfile<<"*-*-*-*";
			outfile<<fileList[i].strFileName;
			outfile<<endl;
		}
	}
	outfile.close();

	CDialog::OnOK();
}

BOOL CRenameDlg::OnInitDialog() 
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
