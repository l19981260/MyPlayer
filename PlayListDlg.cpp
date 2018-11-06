// PlayListDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "PlayListDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayListDlg dialog


CPlayListDlg::CPlayListDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlayListDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlayListDlg)
	//}}AFX_DATA_INIT
	m_pParent=pParent;
	m_nID=CPlayListDlg::IDD;
}


void CPlayListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayListDlg)
	DDX_Control(pDX, IDC_PLAYLIST, m_playlist);
	DDX_Control(pDX, IDC_BTN_LIST, m_btnList);
	DDX_Control(pDX, IDC_BTN_DEL, m_btnDel);
	DDX_Control(pDX, IDC_BTN_ADD, m_btnAdd);
	DDX_Control(pDX, IDC_BTN_CLOSE, m_btnClose);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayListDlg, CDialog)
	//{{AFX_MSG_MAP(CPlayListDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	ON_WM_CTLCOLOR()
	ON_WM_CREATE()
	ON_WM_MOVE()
	ON_LBN_DBLCLK(IDC_PLAYLIST, OnDblclkPlaylist)
	ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, OnBtnDel)
	ON_BN_CLICKED(IDC_BTN_LIST, OnBtnList)
	ON_COMMAND(IDC_ADD_FILE, OnAddFile)
	ON_COMMAND(IDC_ADD_FOLDER, OnAddFolder)
	ON_COMMAND(IDC_DEL_SELECT, OnDelSelect)
	ON_COMMAND(IDC_DEL_ALL, OnDelAll)
	ON_COMMAND(IDC_LIST_NEW, OnListNew)
	ON_COMMAND(IDC_LIST_DEL, OnListDel)
	ON_COMMAND(IDL_LIST_OPEN1,OnListOpen1)
	ON_COMMAND(IDL_LIST_OPEN2,OnListOpen2)
	ON_COMMAND(IDL_LIST_OPEN3,OnListOpen3)
	ON_COMMAND(IDL_LIST_OPEN4,OnListOpen4)
	ON_COMMAND(IDL_LIST_OPEN5,OnListOpen5)
	ON_COMMAND(IDL_LIST_OPEN6,OnListOpen6)
	ON_COMMAND(IDL_LIST_OPEN7,OnListOpen7)
	ON_COMMAND(IDL_LIST_OPEN8,OnListOpen8)
	ON_COMMAND(IDL_LIST_OPEN9,OnListOpen9)
	ON_COMMAND(IDL_LIST_OPEN10,OnListOpen10)
	ON_COMMAND(IDC_LIST_SAVE, OnListSave)
	ON_COMMAND(IDC_LIST_RENAME, OnListRename)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayListDlg message handlers

BOOL CPlayListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitButtons();
	fInited=TRUE;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CPlayListDlg::Create()
{
	return CDialog::Create(m_nID, m_pParent);
}

void CPlayListDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
   return;
}

void CPlayListDlg::PostNcDestroy() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete this;
}

void CPlayListDlg::OnOK() 
{
	// TODO: Add extra validation here
	return;
	CDialog::OnOK();
}

void CPlayListDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM (point.x, point.y));
	CDialog::OnLButtonDown(nFlags, point);
}

void CPlayListDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	DrawBackground(&dc);
	// Do not call CDialog::OnPaint() for painting messages
}


void CPlayListDlg::DrawBackground(CDC*pDC)
{
	CBitmap bitmap;
	BITMAP  m_bitmap;
	CDC MemDC;

	bitmap.LoadBitmap(IDB_PLAYLIST_MAIN);
	bitmap.GetBitmap(&m_bitmap);
	MemDC.CreateCompatibleDC(pDC);

	MemDC.SelectObject(&bitmap);

	pDC->BitBlt(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,&MemDC,
		0,0,SRCCOPY);

	bitmap.DeleteObject();
	MemDC.DeleteDC();


}

void CPlayListDlg::InitButtons()
{
	CRect rect;
	rect.top=0;
	rect.left=263;
	rect.right=300;
	rect.bottom=10;
	m_btnClose.MoveWindow(&rect,TRUE);
	m_btnClose.Init(IDB_PLCLOSE_NORMAL,IDB_PLCLOSE_OVER,"关闭播放列表");
    
	rect.top=224;
	rect.left=24;
	m_btnAdd.MoveWindow(&rect,TRUE);
	m_btnAdd.Init(IDB_ADD_NORMAL,IDB_ADD_OVER,"添加歌曲");

	rect.left=57;
	m_btnDel.MoveWindow(&rect,TRUE);
	m_btnDel.Init(IDB_DEL_NORMAL,IDB_DEL_OVER,"删除歌曲");

	rect.left=90;
	m_btnList.MoveWindow(&rect,TRUE);
	m_btnList.Init(IDB_LIST_NORMAL,IDB_LIST_OVER,"列表操作");

}

void CPlayListDlg::OnBtnClose() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
    CSkinButton *pButton=(CSkinButton*)(m_pParent->GetDlgItem(IDC_BTN_PLAYLIST_SHOW));
	pButton->SetBitmap(IDB_PLAYLIST_SHOW_NORMAL,IDB_PLAYLIST_SHOW_OVER);
	pButton->SetToolTipText("显示播放列表");
}

HBRUSH CPlayListDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
     HBRUSH  hBrush=CreateSolidBrush(RGB(0,0,0));
	// TODO: Return a different brush if the default is not desired
	return hBrush;
}

LRESULT CPlayListDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(message==WM_CTLCOLORLISTBOX){
		HBRUSH hListBrush;
		hListBrush=CreateSolidBrush(RGB(0,0,0));
		::SetBkMode((HDC)wParam,TRANSPARENT);	
		SetTextColor((HDC)wParam,RGB(0,255,0));
		SetBkColor((HDC)wParam,RGB(0,0,0));
	//	SetFont((HDC)wParam);
		return (LRESULT)hListBrush;
	}
	return CDialog::WindowProc(message, wParam, lParam);
}

void CPlayListDlg::SetFont(HDC hDC)
{
	CDC*pDC;
	pDC=CDC::FromHandle(hDC);

	CFont font,*pOldFont;	
	LOGFONT logFont;
	pDC->GetCurrentFont()->GetLogFont(&logFont);

	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfHeight=12;
	logFont.lfWeight=10;
	lstrcpy(logFont.lfFaceName,"宋体");
	font.CreateFontIndirect(&logFont);

	pOldFont=pDC->SelectObject(&font);

}

int CPlayListDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	fInited=FALSE;
	return 0;
}

void CPlayListDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	if(fInited){
		CRect rectParent;
		CRect rect;
		m_pParent->GetWindowRect(&rectParent);
		if(y>=rectParent.bottom-5&&y<=rectParent.bottom+5){
			rect.top=rectParent.bottom;
			rect.left=rectParent.left;
			rect.right=rect.left+283;
			rect.bottom=rect.top+252;
			MoveWindow(&rect,TRUE);
		}
	}
}

void CPlayListDlg::OnDblclkPlaylist() 
{
	// TODO: Add your control notification handler code here
	int n=m_playlist.GetCurSel();
	if(n<0)
		return ;
	::SendMessage(m_pParent->m_hWnd,WM_PLAY,(WPARAM)n,NULL);
}

void CPlayListDlg::OnBtnAdd() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	GetDlgItem(IDC_BTN_ADD)->GetWindowRect(&rect);
	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU_ADD);
    m_Menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON,
		       rect.left, rect.bottom,this,NULL);
}

void CPlayListDlg::OnBtnDel() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	GetDlgItem(IDC_BTN_DEL)->GetWindowRect(&rect);
	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU_DEL);
    m_Menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON,
		       rect.left, rect.bottom,this,NULL);
}

void CPlayListDlg::OnBtnList() 
{
	// TODO: Add your control notification handler code here
	CRect rect;
	GetDlgItem(IDC_BTN_LIST)->GetWindowRect(&rect);
	CMenu m_Menu,m_AddMenu;
	m_Menu.CreatePopupMenu();
	m_AddMenu.CreatePopupMenu();
	for(int i=0;i<10;i++){
		if(!fileList[i].strMenu.IsEmpty()){
			if(i==nCurrentList)
	            m_AddMenu.AppendMenu(MF_STRING|MF_CHECKED,IDL_LIST_OPEN1+i,fileList[i].strMenu);
			else
				m_AddMenu.AppendMenu(MF_STRING,IDL_LIST_OPEN1+i,fileList[i].strMenu);
		}
	}

    m_Menu.AppendMenu(MF_POPUP,(UINT)m_AddMenu.m_hMenu,"打开播放列表");
	m_Menu.AppendMenu(MF_STRING,IDC_LIST_SAVE,"保存播放列表");
	m_Menu.AppendMenu(MF_STRING,IDC_LIST_NEW,"新建播放列表");	
	m_Menu.AppendMenu(MF_STRING,IDC_LIST_DEL,"删除播放列表");
	m_Menu.AppendMenu(MF_STRING,IDC_LIST_RENAME,"重命名列表");

	
	m_Menu.TrackPopupMenu(TPM_RIGHTBUTTON,
		       rect.left, rect.bottom,this,NULL);
}
CString CPlayListDlg::GetFileTitle(CString strFileName)
{
	CString str;

	int nPos=-1;
	int nOldPos=-1;
	while((nPos=strFileName.Find("\\",nPos+1))>0)
		nOldPos=nPos;
   str=strFileName.Right(strFileName.GetLength()-nOldPos-1);
   strFileName=str.Left(str.GetLength()-4);  
	
   return strFileName;
}
BOOL CPlayListDlg::IsSupportFile(CString strFileName)
{
	CString strType=strFileName.Right(4);
	strType.MakeUpper();
	if(strType==".MP3"||
		strType==".WAV"||
		strType==".WMA")
		return TRUE;
	
	return FALSE;
}

void CPlayListDlg::OnAddFile() 
{
	// TODO: Add your command handler code here
	CString strFilter="所有支持文件(*.mp3,*.wav,*.wma)|*.mp3;*.wav;*.wma||";
	CFileDialog fdlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,strFilter);
	if(fdlg.DoModal()==IDOK){
		CString strFileName=fdlg.GetPathName();
		m_strPlayListArray.Add(strFileName);
		CString strShortName=GetFileTitle(strFileName);
		CString strFormat;
		if(m_playlist.GetCount()+1<10)
			strFormat.Format("0%d  %s",m_playlist.GetCount()+1,strShortName);
		else
			strFormat.Format("%d  %s",m_playlist.GetCount()+1,strShortName);
		m_playlist.AddString(strFormat);

		if(m_nPlayMode==MODE_RAND)
		   theApp.RandOrder();
		else
			theApp.SequenceOrder();
	}
}

void CPlayListDlg::OnAddFolder() 
{
	// TODO: Add your command handler code here
	LPMALLOC pMalloc;
	if(SHGetMalloc(&pMalloc)==NOERROR){
		BROWSEINFO  bi;
		char szBuffer[MAX_PATH];
		LPITEMIDLIST pidl;
         
		bi.hwndOwner=GetSafeHwnd();
		bi.pidlRoot=NULL;
		bi.pszDisplayName=szBuffer;
		bi.lpszTitle=TEXT("选择文件夹");
		bi.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
		bi.lpfn = NULL;
		bi.lParam=0;

		pidl=SHBrowseForFolder(&bi);

		if(pidl!=NULL){
			if(SHGetPathFromIDList(pidl,szBuffer))
			{
				AddFolderFiles(szBuffer);
				if(m_nPlayMode==MODE_RAND)
		           theApp.RandOrder();
	        	else
		        	theApp.SequenceOrder();
			}
			pMalloc->Free(pidl);
		}
		pMalloc->Release();
	}
   
}

void CPlayListDlg::AddFolderFiles(CString strDir)
{
	_chdir(strDir);

	CString strPathName;
	CString strShortName;
	CString strFormat;
	HANDLE hFind;
	WIN32_FIND_DATA wfd;
	hFind=FindFirstFile(_T("*.*"),&wfd);
	if(hFind==INVALID_HANDLE_VALUE)
		return;

	if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
        if(IsSupportFile(wfd.cFileName)){
			strPathName.Format("%s\\%s",strDir,wfd.cFileName);
			m_strPlayListArray.Add(strPathName);
			strShortName=GetFileTitle(wfd.cFileName);
			if(m_playlist.GetCount()+1<10)
				strFormat.Format("0%d  %s",m_playlist.GetCount()+1,strShortName);
			else
				strFormat.Format("%d  %s",m_playlist.GetCount()+1,strShortName);
			m_playlist.AddString(strFormat);
		}
	}

	while(FindNextFile(hFind,&wfd)){
		if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)){
        if(IsSupportFile(wfd.cFileName)){
			strPathName.Format("%s\\%s",strDir,wfd.cFileName);
			m_strPlayListArray.Add(strPathName);
			strShortName=GetFileTitle(wfd.cFileName);
			if(m_playlist.GetCount()+1<10)
				strFormat.Format("0%d  %s",m_playlist.GetCount()+1,strShortName);
			else
				strFormat.Format("%d  %s",m_playlist.GetCount()+1,strShortName);
			m_playlist.AddString(strFormat);
		}
	}
	}
    FindClose(hFind);
}

void CPlayListDlg::OnDelSelect() 
{
	// TODO: Add your command handler code here
	int n=m_playlist.GetCurSel();
	if(n<0)
		return;
	m_strPlayListArray.RemoveAt(n,1);
	CString strGet;
	CString strFileTitle;
	CString strFormat;
	int nPos;
	int i;
	for(i=n;i<m_playlist.GetCount()-1;i++){
		m_playlist.GetText(i+1,strGet);
        nPos=strGet.Find("  ",0);
		strFileTitle=strGet.Right(strGet.GetLength()-nPos);
		if(i+1<10)
			strFormat.Format("0%d%s",i+1,strFileTitle);
		else
			strFormat.Format("%d%s",i+1,strFileTitle);
		m_playlist.InsertString(i,strFormat);
		m_playlist.DeleteString(i+1);
	}
	m_playlist.DeleteString(i);

	if(m_nPlayMode==MODE_RAND)
		theApp.RandOrder();
	else
		theApp.SequenceOrder();
/*	m_playlist.ResetContent();
	for(int i=0;i<m_strPlayListArray.GetSize();i++){
		strFileTitle=GetFileTitle(m_strPlayListArray.GetAt(i));
        if(i+1<10)
           strFormat.Format("0%d  %s",i+1,strFileTitle);
		else
			strFormat.Format("%d  %s",i+1,strFileTitle);
		m_playlist.AddString(strFormat);
	}*/

}

void CPlayListDlg::OnDelAll() 
{
	// TODO: Add your command handler code here
	m_strPlayListArray.RemoveAll();
	m_playlist.ResetContent();
}


void CPlayListDlg::OnListNew() 
{
	// TODO: Add your command handler code here
	CNewListDlg dlg;
	SaveList(nCurrentList);
	if(dlg.DoModal()==IDOK){		
		m_strPlayListArray.RemoveAll();
		m_playlist.ResetContent();
	}
	
}

void CPlayListDlg::OnListDel() 
{
	// TODO: Add your command handler code here
	CDelListDlg dlg;
	dlg.DoModal();
}
void CPlayListDlg::OnListOpen1()
{
	SaveList(nCurrentList);
	OpenList(0);
	nCurrentList=0;
}
void CPlayListDlg::OnListOpen2()
{
	SaveList(nCurrentList);
	OpenList(1);
	nCurrentList=1;
}
void CPlayListDlg::OnListOpen3()
{
	SaveList(nCurrentList);
	OpenList(2);
	nCurrentList=2;
}
void CPlayListDlg::OnListOpen4()
{
	SaveList(nCurrentList);
	OpenList(3);
	nCurrentList=3;

}
void CPlayListDlg::OnListOpen5()
{
	SaveList(nCurrentList);
	OpenList(4);
	nCurrentList=4;
}
void CPlayListDlg::OnListOpen6()
{
	SaveList(nCurrentList);
	OpenList(5);
	nCurrentList=5;
}
void CPlayListDlg::OnListOpen7()
{
	SaveList(nCurrentList);
	OpenList(6);
	nCurrentList=6;
}
void CPlayListDlg::OnListOpen8()
{
	SaveList(nCurrentList);
     OpenList(7);
	 nCurrentList=7;
}
void CPlayListDlg::OnListOpen9()
{
	SaveList(nCurrentList);
     OpenList(8);
	 nCurrentList=8;
}
void CPlayListDlg::OnListOpen10()
{
	SaveList(nCurrentList);
	OpenList(9);
    nCurrentList=9;
}

BOOL CPlayListDlg::OpenList(int nIndex)
{
	if(nIndex<0||nIndex>=10)
		return FALSE;

	CString strFileName;
	strFileName.Format("%s\\%s",strCurrentDir,fileList[nIndex].strFileName);
    if(!IsFileExist(strFileName)){
		DeleteList(nIndex);
		return FALSE;
	}
	
	m_strPlayListArray.RemoveAll();
	m_playlist.ResetContent();

	ifstream infile(strFileName,ios::in);
	if(!infile)
		return FALSE;

	TCHAR szTemp[MAX_PATH];
	CString strTitle;
	CString strFormat;
	int i=0;

	while(infile.getline(szTemp,MAX_PATH)){
		if(lstrlen(szTemp)>0){
           m_strPlayListArray.Add(szTemp);
		   strTitle=GetFileTitle(szTemp);
		   if(i+1<10)
		     strFormat.Format("0%d  %s",i+1,strTitle);
		   else
			   strFormat.Format("%d  %s",i+1,strTitle);
		   m_playlist.AddString(strFormat);
		   i++;
		}
	}
	infile.close();

	if(m_nPlayMode==MODE_RAND)
	   theApp.RandOrder();
	else
		theApp.SequenceOrder();
	m_nNowPlaying=0;

    ::SendMessage(m_pParent->m_hWnd,WM_PLAY,(WPARAM)m_nPlayOrder[0],NULL);

	if(i>0)
		return TRUE;
	
	return FALSE;
}

BOOL CPlayListDlg::SaveList(int nIndex)
{
	if(nIndex<0||nIndex>=10)
		return FALSE;
	CString strFileName;
	strFileName.Format("%s\\%s",strCurrentDir,fileList[nIndex].strFileName);

	ofstream outfile(strFileName,ios::out);
	if(!outfile)
		return FALSE;
	for(int i=0;i<m_strPlayListArray.GetSize();i++){
		outfile<<m_strPlayListArray.GetAt(i);
		outfile<<endl;
	}
	outfile.close();
	
	return TRUE;
}

void CPlayListDlg::OnListSave() 
{
	// TODO: Add your command handler code here
	SaveList(nCurrentList);
}

void CPlayListDlg::OnListRename() 
{
	// TODO: Add your command handler code here
	CRenameDlg dlg;
	dlg.DoModal();
}

BOOL CPlayListDlg::DeleteList(int nIndex)
{
	CString strOldName;
	int i = 0;
	for(i=nIndex;i<9;i++){
		if(!fileList[i+1].strFileName.IsEmpty()){		
             fileList[i].strMenu=fileList[i+1].strMenu;			
			 CopyFile(fileList[i+1].strFileName,fileList[i].strFileName,FALSE);		
		}else{
			DeleteFile(fileList[i].strFileName);
			fileList[i].strFileName="";
			fileList[i].strMenu="";
		}
	}
	ofstream outfile("listname.dat",ios::out);
	for( i=0;i<10;i++){
		if(!fileList[i].strFileName.IsEmpty()){
			outfile<<fileList[i].strMenu<<"*-*-*-*";
			outfile<<fileList[i].strFileName<<endl;
		}		
	}
    outfile.close();

	if(nIndex==nCurrentList){
		m_strPlayListArray.RemoveAll();
		m_playlist.ResetContent();
		nCurrentList=-1;
	}
	return TRUE;
}



BOOL CPlayListDlg::IsFileExist(CString strFileName)
{
	HANDLE hFind;
	WIN32_FIND_DATA wfd;
	hFind=FindFirstFile(strFileName,&wfd);
	if(hFind==INVALID_HANDLE_VALUE)
		return FALSE;
    FindClose(hFind);
	return TRUE;

}

