// NewListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "NewListDlg.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewListDlg dialog


CNewListDlg::CNewListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewListDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CNewListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewListDlg)
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewListDlg, CDialog)
	//{{AFX_MSG_MAP(CNewListDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewListDlg message handlers

void CNewListDlg::OnCancel() 
{
	// TODO: Add extra cleanup here	
	CDialog::OnCancel();
}

void CNewListDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_strName.IsEmpty()){
		MessageBox("请输入列表名");
		return;
	}

	CString strFileName;
	int i;
	for(i=0;i<10;i++)
		if(fileList[i].strFileName.IsEmpty())
			break;
	nCurrentList=i;
	strFileName.Format("00%d.lst",i);
	fileList[i].strFileName=strFileName;
	fileList[i].strMenu=m_strName;
	strFileName.Format("%s\\%s",strCurrentDir,strFileName);
	CString strlist;
	strlist.Format("%s\\listname.dat",strCurrentDir);
	ofstream outfile(strlist,ios::app),out(strFileName,ios::out);
	outfile<<fileList[i].strMenu;
	outfile<<"*-*-*-*";
	outfile<<fileList[i].strFileName;
	outfile<<endl;
	outfile.close();
	out.close();

	CDialog::OnOK();
}
