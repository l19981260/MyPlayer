// MyPlayerDlg.cpp : implementation file

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyPlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "StarWarsCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CStarWarsCtrl m_starWar;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_STARWARS, m_starWar);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerDlg dialog

CMyPlayerDlg::CMyPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyPlayerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyPlayerDlg)
	DDX_Control(pDX, IDC_BTN_SHOWMENU, m_btnShowMenu);
	DDX_Control(pDX, IDC_BTN_LYRIC, m_btnLyric);
	DDX_Control(pDX, IDC_BTN_VOLUME, m_volume);
	DDX_Control(pDX, IDC_BTN_SLIDE, m_slide);
	DDX_Control(pDX, IDC_STATIC_MODE, m_stcMode);
	DDX_Control(pDX, IDC_STATIC_PLAY, m_stcPlay);
	DDX_Control(pDX, IDC_BTN_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BTN_PREV, m_btnPrev);
	DDX_Control(pDX, IDC_BTN_PLAYLIST_SHOW, m_btnPLShow);
	DDX_Control(pDX, IDC_BTN_PLAY, m_btnPlay);
	DDX_Control(pDX, IDC_BTN_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BTN_NEXT, m_btnNext);
	DDX_Control(pDX, IDC_BTN_MIN, m_btnMin);
	DDX_Control(pDX, IDC_BTN_HIDE, m_btnHide);
	DDX_Control(pDX, IDC_BTN_EXIT, m_btnExit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CMyPlayerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTN_EXIT, OnBtnExit)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_STATIC_MODE, OnStaticMode)
	ON_BN_CLICKED(IDC_STATIC_PLAY, OnStaticPlay)
	ON_BN_CLICKED(IDC_BTN_VOLUME, OnBtnVolume)
	ON_BN_CLICKED(IDC_BTN_SLIDE, OnBtnSlide)
	ON_BN_CLICKED(IDC_BTN_PLAYLIST_SHOW, OnBtnPlaylistShow)
	ON_WM_MOVE()
	ON_BN_CLICKED(IDC_BTN_LYRIC, OnBtnLyric)
	ON_BN_CLICKED(IDC_BTN_OPEN, OnBtnOpen)
	ON_BN_CLICKED(IDC_BTN_NEXT, OnBtnNext)
	ON_BN_CLICKED(IDC_BTN_PLAY, OnBtnPlay)
	ON_BN_CLICKED(IDC_BTN_PREV, OnBtnPrev)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTN_SHOWMENU, OnBtnShowmenu)
	ON_WM_KILLFOCUS()
	ON_COMMAND(IDC_MENU_NEXT, OnMenuNext)
	ON_COMMAND(IDC_MENU_OPEN, OnMenuOpen)
	ON_COMMAND(IDC_MENU_PLAY, OnMenuPlay)
	ON_COMMAND(IDC_MENU_PREV, OnMenuPrev)
	ON_COMMAND(IDC_MENU_RAND, OnMenuRand)
	ON_COMMAND(IDC_MENU_SEQ, OnMenuSeq)
	ON_COMMAND(IDC_MENU_SINGLE, OnMenuSingle)
	ON_COMMAND(IDC_MENU_STOP, OnMenuStop)
	ON_COMMAND(IDC_MENU_VOLDOWN, OnMenuVoldown)
	ON_COMMAND(IDC_MENU_PAUSE, OnMenuPause)
	ON_COMMAND(IDC_MENU_VOLSLC, OnMenuVolslc)
	ON_COMMAND(IDC_MENU_VOLUP, OnMenuVolup)
	ON_COMMAND(IDC_ABOUT_STAR, OnAboutStar)
	//ON_MESSAGE(MYWM_NOTIFYICON,OnNotifyIcon)
	ON_BN_CLICKED(IDC_BTN_HIDE, OnBtnHide)
	ON_BN_CLICKED(IDC_BTN_MIN, OnBtnMin)
	ON_COMMAND(IDC_SET_LYRICPATH, OnSetLyricpath)
	ON_COMMAND(IDC_MENU_OPEN_LYRICPATH, OnMenuOpenLyricpath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyPlayerDlg message handlers

BOOL CMyPlayerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	InitButtons();
	InitRect();
	InitText();
	InitSize();
	CreateLyric();
	CreatePlayList();
	m_pMenuDlg=NULL;
	InitFileList();

	strTitle="                欢迎来到音乐播放器                ";
    strTime="00:00";
	m_nTime=0;
    fInited=TRUE;
	fPlaying=FALSE;
     fPlay=TRUE;
	nRollTextCounter=0;
    
	SetWindowText("BUG");

	m_strLyricPath="";

	if(ReadConfig()){
		m_pPlayListDlg->OpenList(nCurrentList);	
		m_volume.SetPos(m_nVolume);	
		if(m_nPlayMode==MODE_SEQ)
			OnStaticMode();
		if(m_nPlayMode==MODE_SINGLE){
			OnStaticMode();
			OnStaticMode();
		}
	}else{
		m_nPlayMode=MODE_RAND;
		nCurrentList=0;
	    m_pPlayListDlg->OpenList(nCurrentList);	
		m_nVolume=8;
		m_volume.SetPos(m_nVolume);	
	}

    CreateNotifyIcon();
    SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	m_pLyricDlg->SetPlayListWnd(m_pPlayListDlg);
	return TRUE;  // return TRUE  unless you set the focus to a control
}



// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyPlayerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		DrawMainPicture(&dc);
		DrawText(&dc);
		DrawTime(&dc);
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyPlayerDlg::InitButtons()
{
	CRect rect;
	rect.right=1000;
	rect.bottom=1000;

	rect.left=224;
	rect.top=42;
	m_btnOpen.MoveWindow(&rect,TRUE);
	m_btnOpen.Init(IDB_OPEN_NORMAL,IDB_OPEN_OVER,"打开文件");

	rect.left-=18;
	m_btnNext.MoveWindow(&rect,TRUE);
	m_btnNext.Init(IDB_NEXT_NORMAL,IDB_NEXT_OVER,"下一首");

	rect.left-=19;
	m_btnPrev.MoveWindow(&rect,TRUE);
	m_btnPrev.Init(IDB_PREV_NORMAL,IDB_PREV_OVER,"上一首");

	rect.left-=18;
	m_btnPlay.MoveWindow(&rect,TRUE);
	m_btnPlay.Init(IDB_PLAY_NORMAL,IDB_PLAY_OVER,"播放");

	rect.left-=20;
	m_btnStop.MoveWindow(&rect,TRUE);
	m_btnStop.Init(IDB_STOP_NORMAL,IDB_STOP_OVER,"停止");

	rect.top=0;
	rect.left=240;

	m_btnHide.MoveWindow(&rect,TRUE);
	m_btnHide.Init(IDB_HIDE_NORMAL,IDB_HIDE_OVER,"隐藏窗体");

	rect.left+=14;
	m_btnMin.MoveWindow(&rect,TRUE);
	m_btnMin.Init(IDB_MIN_NORMAL,IDB_MIN_OVER,"最小化");

	rect.left+=14;
	m_btnExit.MoveWindow(&rect,TRUE);
	m_btnExit.Init(IDB_EXIT_NORMAL,IDB_EXIT_OVER,"关闭");

	rect.top=100;
	rect.left=269;
	m_btnPLShow.MoveWindow(&rect,TRUE);
	m_btnPLShow.Init(IDB_PLAYLIST_HIDE_NORMAL,IDB_PLAYLIST_HIDE_OVER,"关闭播放列表");

	rect.top=81;
	rect.left=145;
	m_slide.MoveWindow(&rect,TRUE);
	m_slide.Init(IDB_SLIDEBKGND,IDB_SLIDE,"当前进度");

	rect.top=18;
	rect.left=274;
	m_volume.MoveWindow(&rect,TRUE);
	m_volume.Init(IDB_VOLUME,"调节音量");

	rect.top=88;
	rect.left=269;
	m_btnLyric.MoveWindow(&rect,TRUE);
	m_btnLyric.Init(IDB_LYRIC_HIDE_NORMAL,IDB_LYRIC_HIDE_OVER,"关闭歌词");
    
	rect.top=3;
	rect.left=3;
	m_btnShowMenu.MoveWindow(&rect,TRUE);
	m_btnShowMenu.Init(IDB_MENUSHOW,IDB_MENUSHOW,"主菜单");
}

void CMyPlayerDlg::DrawMainPicture(CDC*pDC)
{
	CDC MemDC;
	CBitmap bitmap;
	BITMAP m_bitmap;

	bitmap.LoadBitmap(IDB_MAIN);
	bitmap.GetBitmap(&m_bitmap);
	MemDC.CreateCompatibleDC(pDC);
	MemDC.SelectObject(&bitmap);
	
	pDC->BitBlt(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight,&MemDC,
		0,0,SRCCOPY);

	bitmap.DeleteObject();
	MemDC.DeleteDC();
}

void CMyPlayerDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM (point.x, point.y));
     DestroyMenuDlg();
	CDialog::OnLButtonDown(nFlags, point);
}

void CMyPlayerDlg::DrawText(CDC *pDC)
{
	pDC->SetBkMode(TRANSPARENT);

	CFont font,*pOldFont;	
	LOGFONT logFont;
	pDC->GetCurrentFont()->GetLogFont(&logFont);

	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfWeight=10;
	lstrcpy(logFont.lfFaceName,"华文彩云");
	font.CreateFontIndirect(&logFont);

	pOldFont=pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(255,255,0));
	pDC->TextOut(21,48,"Love You Forever");

	font.DeleteObject();

    
	logFont.lfWidth=6;
	logFont.lfHeight=12;
	logFont.lfWeight=0;
	lstrcpy(logFont.lfFaceName,"宋体");
	font.CreateFontIndirect(&logFont);
	pDC->SelectObject(&font);


	pDC->SetTextColor(RGB(0,255,0));
	pDC->TextOut(22,35,strOutText);
	pDC->TextOut(22,66,"状态:");
	pDC->TextOut(75,90,"");
	pDC->SetTextColor(RGB(0,150,0));
	pDC->TextOut(60,103,"");

   font.DeleteObject();

	pDC->SelectObject(pOldFont);
	

}

void CMyPlayerDlg::OnBtnExit() 
{
	// TODO: Add your control notification handler code here
    ExitPlayer();
}

int CMyPlayerDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	fInited=FALSE;

	DragAcceptFiles(TRUE);

	return 0;
}

void CMyPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

    RollText();
	if(fPlaying){
	   CountTime();
       MoveSlide();
	   CirculatePlay();
	}

	CDialog::OnTimer(nIDEvent);
}

void CMyPlayerDlg::RollText()
{
	TCHAR ch;
	strOutText="";
	for(UINT i=0;i<16;){
		ch=strTitle.GetAt(nRollTextCounter+i);
		strOutText+=ch;
		i++;		
	}
	nRollTextCounter+=2;
	if(nRollTextCounter>=strTitle.GetLength()-16)
		nRollTextCounter=0;

	InvalidateRect(&rectTitle,TRUE);
}

void CMyPlayerDlg::DrawTime(CDC *pDC)
{
	pDC->SetBkMode(TRANSPARENT);

	CFont font,*pOldFont;	
	LOGFONT logFont;
	pDC->GetCurrentFont()->GetLogFont(&logFont);

	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfHeight=16;
	logFont.lfWeight=1000;
//	logFont.lfQuality=100;
	lstrcpy(logFont.lfFaceName,"方正舒体");
	font.CreateFontIndirect(&logFont);

	pOldFont=pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(255,200,0));
	pDC->TextOut(180,60,strTime);

	font.DeleteObject();
	pDC->SelectObject(pOldFont);

	pDC->MoveTo(180,68);
	pDC->LineTo(225,68);
}



void CMyPlayerDlg::InitRect()
{	
	rectTitle.top=35;
	rectTitle.left=22;
	rectTitle.right=120;
	rectTitle.bottom=50;  

	rectTime.left=180;
	rectTime.top=60;
	rectTime.right=220;
	rectTime.bottom=75;
}

void CMyPlayerDlg::CountTime()
{
    m_nTime=MCIWndGetPosition(hAudio)/MCIWndGetSpeed(hAudio);
	int nMinute=m_nTime/60;
	int nSecond=m_nTime%60;
	if(nMinute<10){
		if(nSecond<10)
		  strTime.Format("0%d:0%d",nMinute,nSecond);
		else
			strTime.Format("0%d:%d",nMinute,nSecond);
	}else{
		if(nSecond<10)
		  strTime.Format("%d:0%d",nMinute,nSecond);
		else
			strTime.Format("%d:%d",nMinute,nSecond);
	}	   
	InvalidateRect(&rectTime,TRUE);
}

void CMyPlayerDlg::InitText()
{
	m_stcPlay.SetToolTipText("播放/暂停");
	m_stcMode.SetToolTipText("播放模式");

	CRect rect;
	rect.top=66;
	rect.left=55;
	rect.right=83;
	rect.bottom=80;
	m_stcPlay.MoveWindow(&rect,TRUE);

	rect.left=90;
	rect.right=115;
	m_stcMode.MoveWindow(&rect,TRUE);

}

void CMyPlayerDlg::OnStaticMode() 
{
	// TODO: Add your control notification handler code here
	static int nCounter=0;
	nCounter++;
	if(nCounter==3)
		nCounter=0;
	switch(nCounter){
	case 0:
		m_stcMode.SetWindowText("随机");
		m_nPlayMode=MODE_RAND;
		theApp.RandOrder();
		break;
	case 1:
		m_stcMode.SetWindowText("顺序");
		m_nPlayMode=MODE_SEQ;
		m_nNowPlaying=m_nPlayOrder[m_nNowPlaying];
		theApp.SequenceOrder();		
		break;
	case 2:
		m_stcMode.SetWindowText("单曲");
		m_nPlayMode=MODE_SINGLE;
		break;		
	}
	


}

void CMyPlayerDlg::OnStaticPlay() 
{
	// TODO: Add your control notification handler code here
	if(hAudio==NULL)
		return;	
	fPlay=!fPlay;
	if(fPlay){
		m_stcPlay.SetWindowText("播放");
		MCIWndResume(hAudio);
	}
	else{
		m_stcPlay.SetWindowText("暂停");
		MCIWndPause(hAudio);
	}
}

void CMyPlayerDlg::MoveSlide()
{ 
  if(hAudio!=NULL)
   m_slide.SetSlidePos(MCIWndGetPosition(hAudio)); 
}

void CMyPlayerDlg::OnBtnVolume() 
{
	// TODO: Add your control notification handler code here
	m_nVolume=m_volume.GetPos();
	 int nSetVol=63*m_nVolume;
	 if(nSetVol>1000)
		   nSetVol=1000;
	 if(hAudio!=NULL)
	  MCIWndSetVolume(hAudio,nSetVol);
}

void CMyPlayerDlg::OnBtnSlide() 
{
	// TODO: Add your control notification handler code here
	if(hAudio==NULL)
		return;
	int n=m_slide.GetSlidePos();
	if(n>MCIWndGetLength(hAudio))
		n=MCIWndGetLength(hAudio);
   m_slide.SetSlidePos(n);
   MCIWndSeek(hAudio,m_slide.GetSlidePos());
   MCIWndPlay(hAudio);
   m_pLyricDlg->SlideClick();
   OnTimer(1);
}

void CMyPlayerDlg::ExitPlayer()
{
   WriteConfig();
   if(nCurrentList<0)
	   nCurrentList=0;
   m_pPlayListDlg->SaveList(nCurrentList);
   KillTimer(1);
   DeleteNotifyIcon();
   PostQuitMessage(0);
}

void CMyPlayerDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	return;
	CDialog::OnCancel();
}
void CMyPlayerDlg::OnOK() 
{
	// TODO: Add extra validation here
//	return;
	CDialog::OnOK();
}

void CMyPlayerDlg::InitSize()
{
  CRect rect;
  rect.top=100;
  rect.left=100;
  rect.right=rect.left+283;
  rect.bottom=rect.top+122;
  MoveWindow(&rect,TRUE);
}
void CMyPlayerDlg::InitFileList()
{
	ifstream infile("listname.dat",ios::in);
	if(!infile)
		return;
    TCHAR  szTemp[512];
    int nIndex=0;
	while(infile.getline(szTemp,512)){
		if(lstrlen(szTemp)>0){
			if(GetFileList(szTemp,nIndex))
				nIndex++;
			if(nIndex>=10)
				break;
		}
	}
	infile.close();
    if(nIndex>0)
		return;
	CString strFileName;
	strFileName.Format("%s\\000.lst",strCurrentDir);
	ofstream outfile("listname.dat",ios::out),out(strFileName,ios::out);
	 outfile<<"默认*-*-*-*000.lst"<<endl;
	outfile.close();
	fileList[0].strMenu="默认";
	fileList[0].strFileName="000.lst";
}
BOOL CMyPlayerDlg::GetFileList(CString strLine,int nIndex)
{
   int nPos;
   nPos=strLine.Find("*-*-*-*",0);
   if(nPos<0)
	   return FALSE;
   fileList[nIndex].strMenu=strLine.Left(nPos);
   fileList[nIndex].strFileName=strLine.Right(strLine.GetLength()-nPos-7);
   return TRUE;
}


void CMyPlayerDlg::OnBtnPlaylistShow() 
{
	// TODO: Add your control notification handler code here
	 if(m_pPlayListDlg!=NULL)
		if(m_pPlayListDlg->IsWindowVisible()){
			m_pPlayListDlg->ShowWindow(SW_HIDE);
		    m_btnPLShow.SetBitmap(IDB_PLAYLIST_SHOW_NORMAL,IDB_PLAYLIST_SHOW_OVER);
          	m_btnPLShow.SetToolTipText("显示播放列表");
		}else{
			m_pPlayListDlg->ShowWindow(SW_SHOW);
			m_btnPLShow.SetBitmap(IDB_PLAYLIST_HIDE_NORMAL,IDB_PLAYLIST_HIDE_OVER);
			m_btnPLShow.SetToolTipText("关闭播放列表");
		}
}

void CMyPlayerDlg::CreatePlayList()
{
  	m_pPlayListDlg =new CPlayListDlg(this);
	m_pPlayListDlg->Create();

    if(m_pPlayListDlg==NULL)
		return;
	
	m_pPlayListDlg->ShowWindow(SW_SHOW);
	MovePlayListWindow();
	
}

void CMyPlayerDlg::CreateLyric()
{
	m_pLyricDlg =new CLyricDlg(this);
	m_pLyricDlg->Create();
	m_pLyricDlg->ShowWindow(SW_SHOW);
	MoveLyricWindow();

}

void CMyPlayerDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here

	if(fInited){	
	  if(IsPlayListAttach())
         MovePlayListWindow();
	  if(IsLyricDlgAttach())
	     MoveLyricWindow();
	}
    

}

void CMyPlayerDlg::MovePlayListWindow()
{
   	CRect rectParent;
	CRect rect;
	
	GetWindowRect(&rectParent);
	rect.top=rectParent.top+rectParent.Height();
	rect.left=rectParent.left;
	rect.bottom=rect.top+252;
	rect.right=rect.left+283;
	m_pPlayListDlg->MoveWindow(&rect,TRUE);
}

void CMyPlayerDlg::MoveLyricWindow()
{
	CRect rectParent;
	CRect rect;
	
	GetWindowRect(&rectParent);
	rect.top=rectParent.top;
	rect.left=rectParent.left+283;
	rect.bottom=rect.top+374;
	rect.right=rect.left+283;
	m_pLyricDlg->MoveWindow(&rect,TRUE);

}

BOOL CMyPlayerDlg::IsPlayListAttach()
{
	CRect rectParent;
	CRect rect;
	GetWindowRect(&rectParent);
    m_pPlayListDlg->GetWindowRect(&rect);
	if(rect.top>=rectParent.bottom-10&&rect.top<=rectParent.bottom+10)
		return TRUE;

	return FALSE;
}

BOOL CMyPlayerDlg::IsLyricDlgAttach()
{
	CRect rectParent;
	CRect rect;
	GetWindowRect(&rectParent);
    m_pLyricDlg->GetWindowRect(&rect);
	if(rect.left>=rectParent.right-10&&rect.left<=rectParent.right+10)
		return TRUE;
	return FALSE;
}

void CMyPlayerDlg::OnBtnLyric() 
{
	// TODO: Add your control notification handler code here
	if(m_pLyricDlg!=NULL){
		if(m_pLyricDlg->IsWindowVisible()){
			m_pLyricDlg->ShowWindow(SW_HIDE);
		    m_btnLyric.SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
			m_btnLyric.SetToolTipText("打开歌词");
		}else{
			m_pLyricDlg->ShowWindow(SW_SHOW);
		    m_btnLyric.SetBitmap(IDB_LYRIC_HIDE_NORMAL,IDB_LYRIC_HIDE_OVER);
			m_btnLyric.SetToolTipText("关闭歌词");
		}
	}
}

void CMyPlayerDlg::OnBtnOpen() 
{
	// TODO: Add your control notification handler code here
	CString strFilter="所有支持文件(*.mp3,*.wav,*.wma)|*.mp3;*.wav;*.wma||";
	CFileDialog fdlg(TRUE,NULL,NULL,OFN_HIDEREADONLY,strFilter);
	if(fdlg.DoModal()==IDOK){
       CString strFileName=fdlg.GetPathName();	   	   
	  
	   m_strPlayListArray.RemoveAll();
	   m_strPlayListArray.Add(strFileName);
	   CString strList,strFile;
	   strFile=GetFileTitle(strFileName);
	   strList.Format("01  %s",strFile);
	   m_pPlayListDlg->m_playlist.ResetContent();
	   m_pPlayListDlg->m_playlist.AddString(strList);

	   Play(0);
	}
}

CString CMyPlayerDlg::GetFileTitle(CString strFileName)
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

void CMyPlayerDlg::Play(int nIndex)
{
	if(nIndex>=m_strPlayListArray.GetSize())
		return;
	CString strFileName=m_strPlayListArray.GetAt(nIndex);
    if(!IsFileExist(strFileName)){
		m_pPlayListDlg->m_playlist.DeleteString(nIndex);
		m_strPlayListArray.RemoveAt(nIndex,1);
		return;
	}
	if(hAudio!=NULL){
		   MCIWndDestroy(hAudio);
		   hAudio=NULL;
	   }
	   try{
	   hAudio=MCIWndCreate(GetSafeHwnd(),AfxGetInstanceHandle(),
		           WS_CHILD|MCIWNDF_NOMENU,strFileName);
	   }catch(...)
	   {
		   if(nIndex>=0){
		  m_pPlayListDlg->m_playlist.DeleteString(nIndex);
		 m_strPlayListArray.RemoveAt(nIndex,1);
		   }
		   return;
	   }
	   if(hAudio!=NULL){
		   MCIWndPlay(hAudio);	
		   if(!m_strLyricPath.IsEmpty()){
				if(!m_pLyricDlg->OpenLyric(m_strLyricPath,nIndex))
					m_pLyricDlg->OpenLyric(nIndex);
		   }else
			   m_pLyricDlg->OpenLyric(nIndex);
		   
    	   
           strTitle=GetFileTitle(strFileName);		  
		   FormatTitle(strTitle);
		   nRollTextCounter=0;
		   m_nTime=0;
		   fPlaying=TRUE;
		   m_slide.SetRange(0,MCIWndGetLength(hAudio));
		   m_slide.SetSlidePos(0);
		   m_pPlayListDlg->m_playlist.SetCurSel(nIndex);

		   int nSetVol=63*m_nVolume;
		   if(nSetVol>1000)
			   nSetVol=1000;
		   MCIWndSetVolume(hAudio,nSetVol);
	   }
}

void CMyPlayerDlg::FormatTitle(CString strFile)
{
	CString strTemp="                ";
	strFile=strTemp+strFile;
	strFile=strFile+strTemp;
	strTitle=strFile;
}

void CMyPlayerDlg::GetDropFiles(HDROP hDrop)
{
	CPoint point;
	CRect rect;
	GetClientRect(&rect);
	DragQueryPoint(hDrop,&point);

	if(point.x<=rect.Width()&&point.y<=rect.Height()){
		DropFilesInMain(hDrop);
		return;
	}
	
	DropFilesInPlayList(hDrop);
	
}

BOOL CMyPlayerDlg::IsSupportFile(CString strFileName)
{
	CString strType=strFileName.Right(4);
	strType.MakeUpper();
	if(strType==".MP3"||
		strType==".WAV"||
		strType==".WMA")
		return TRUE;
	
	return FALSE;
}

LRESULT CMyPlayerDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	switch(message){
	case WM_DROPFILES:
		{
		 HDROP hDropInfo;
	     hDropInfo=(HDROP)wParam;
	     GetDropFiles(hDropInfo);
	     DragFinish(hDropInfo);
		 break;		
		}
	case WM_PLAY:
		{
			int n=(int)wParam;			
		    Play(n);
			if(m_nPlayMode==MODE_RAND){
				for(int i=0;i<m_strPlayListArray.GetSize();i++)	{
					if(m_nPlayOrder[i]==n){
						m_nNowPlaying=i;
						break;
					}
				}
			}else{
				m_nNowPlaying=n;
			}
			
		}
	}
	
	return CDialog::WindowProc(message, wParam, lParam);
}

void CMyPlayerDlg::DropFilesInMain(HDROP hDrop)
{
	m_strPlayListArray.RemoveAll();
	m_pPlayListDlg->m_playlist.ResetContent();
	UINT nFiles;
	TCHAR szFileName[MAX_PATH];
	CString strFormat;
	CString strShortName;
	nFiles=DragQueryFile(hDrop,(UINT)0xffffffff,NULL,NULL);
	for(UINT i=0;i<nFiles;i++){		
		DragQueryFile(hDrop,i,szFileName,MAX_PATH);
		if(IsSupportFile(szFileName)){
			m_strPlayListArray.Add(szFileName);
			strShortName=GetFileTitle(szFileName);
			int n=m_pPlayListDlg->m_playlist.GetCount();
			if(n+1<10)
				strFormat.Format("0%d  %s",n+1,strShortName);
			else
				strFormat.Format("%d  %s",n+1,strShortName);
			m_pPlayListDlg->m_playlist.AddString(strFormat);
		}
	}

	

	if(m_strPlayListArray.GetSize()>0){
		if(m_nPlayMode==MODE_RAND)
		   theApp.RandOrder();
		else
			theApp.SequenceOrder();

		m_nNowPlaying=0;
		Play(m_nPlayOrder[0]);
	}

}

void CMyPlayerDlg::DropFilesInPlayList(HDROP hDrop)
{
	UINT nFiles;
	TCHAR szFileName[MAX_PATH];
	CString strFormat;
	CString strShortName;
	nFiles=DragQueryFile(hDrop,(UINT)0xffffffff,NULL,NULL);
	for(UINT i=0;i<nFiles;i++){		
		DragQueryFile(hDrop,i,szFileName,MAX_PATH);
		if(IsSupportFile(szFileName)){
			m_strPlayListArray.Add(szFileName);
			strShortName=GetFileTitle(szFileName);
			int n=m_pPlayListDlg->m_playlist.GetCount();
			if(n+1<10)
				strFormat.Format("0%d  %s",n+1,strShortName);
			else
				strFormat.Format("%d  %s",n+1,strShortName);
			m_pPlayListDlg->m_playlist.AddString(strFormat);
		}
	}

	if(m_nPlayMode==MODE_RAND)
		  theApp.RandOrder();
	else
		  theApp.SequenceOrder();
   
}

void CMyPlayerDlg::OnBtnNext() 
{
	// TODO: Add your control notification handler code here
	if(m_strPlayListArray.GetSize()==0)
		return;

	m_nNowPlaying++;
	if(m_nNowPlaying>=m_strPlayListArray.GetSize())
		m_nNowPlaying=0;
	Play(m_nPlayOrder[m_nNowPlaying]);
}

void CMyPlayerDlg::OnBtnPlay() 
{
	// TODO: Add your control notification handler code here
	int n=m_pPlayListDlg->m_playlist.GetCurSel();
	if(n<0){
		if(m_strPlayListArray.GetSize()>0){
			Play(m_nPlayOrder[0]);
			m_nNowPlaying=0;		
		}
		return;
	}

	Play(n);

	if(m_nPlayMode==MODE_RAND){
		for(int i=0;i<m_strPlayListArray.GetSize();i++){
			if(m_nPlayOrder[i]==n){
				m_nNowPlaying=i;
				break;
			}
		}
	}else{
		m_nNowPlaying=n;
	}
	
}

void CMyPlayerDlg::OnBtnPrev() 
{
	// TODO: Add your control notification handler code here
	if(m_strPlayListArray.GetSize()==0)
		return;

	m_nNowPlaying--;
	if(m_nNowPlaying<0)
		m_nNowPlaying=m_strPlayListArray.GetSize()-1;
	Play(m_nPlayOrder[m_nNowPlaying]);
}

void CMyPlayerDlg::OnBtnStop() 
{
	// TODO: Add your control notification handler code here
	if(hAudio!=NULL){		
		MCIWndStop(hAudio);
		m_nTime=0;
		fPlaying=FALSE;
		strTime="00:00";
		m_slide.SetSlidePos(0);
	    InvalidateRect(&rectTime,TRUE);
	}
}



void CMyPlayerDlg::CirculatePlay()
{
	if(hAudio==NULL)
		return;
	if(MCIWndGetPosition(hAudio)>=MCIWndGetLength(hAudio)){
		if(m_nPlayMode!=MODE_SINGLE){		
			m_nNowPlaying++;
			m_nNowPlaying%=m_strPlayListArray.GetSize();		
		}
		Play(m_nPlayOrder[m_nNowPlaying]);	
	}
}




BOOL CMyPlayerDlg::IsFileExist(CString strFileName)
{
	HANDLE hFind;
	WIN32_FIND_DATA wfd;
	hFind=FindFirstFile(strFileName,&wfd);
	if(hFind==INVALID_HANDLE_VALUE)
		return FALSE;
    FindClose(hFind);
	return TRUE;
}

BOOL CMyPlayerDlg::ReadConfig()
{
	CString strFileName;
	strFileName.Format("%s\\config.dat",strCurrentDir);
	if(!IsFileExist(strFileName))
		return FALSE;
	
	ifstream infile(strFileName,ios::in);
	if(!infile)
		return FALSE;
	TCHAR szTemp[500];
	CString strGet;
	TCHAR  szNum[10];
    int nPos;

	infile.getline(szTemp,500);
	strGet=szTemp;
	if(strGet.IsEmpty())
		return FALSE;

	nPos=strGet.Find("playlist:",0);
	if(nPos<0)
		return FALSE;
	strGet=strGet.Right(strGet.GetLength()-9);
	lstrcpy(szNum,strGet);
	nCurrentList=atoi(szNum);
    ///////////////////////

	infile.getline(szTemp,500);
	strGet=szTemp;
	if(strGet.IsEmpty())
		return FALSE;

	nPos=strGet.Find("playmode:",0);
	if(nPos<0)
		return FALSE;
	strGet=strGet.Right(strGet.GetLength()-9);
	lstrcpy(szNum,strGet);
	m_nPlayMode=atoi(szNum);
	////////////////////////////

	infile.getline(szTemp,500);
	strGet=szTemp;
	if(strGet.IsEmpty())
		return FALSE;

	nPos=strGet.Find("volume:",0);
	if(nPos<0)
		return FALSE;
	strGet=strGet.Right(strGet.GetLength()-7);
	lstrcpy(szNum,strGet);
	m_nVolume=atoi(szNum);

	////////////////////////////

	infile.getline(szTemp,500);
	strGet=szTemp;
	if(strGet.IsEmpty())
		return TRUE;

	nPos=strGet.Find("lyricpath:",0);
	if(nPos<0)
		return TRUE;
	m_strLyricPath=strGet.Right(strGet.GetLength()-10);
	
     infile.close();

	 return TRUE;	

}

void CMyPlayerDlg::WriteConfig()
{
	CString strFileName;
	strFileName.Format("%s\\config.dat",strCurrentDir);
	ofstream outfile(strFileName,ios::out);
	if(!outfile)
		return;
	outfile<<"playlist:"<<nCurrentList<<endl;
	outfile<<"playmode:"<<m_nPlayMode<<endl;
	outfile<<"volume:"<<m_nVolume<<endl;
	outfile<<"lyricpath:"<<m_strLyricPath<<endl;

	outfile.close();
}

void CMyPlayerDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
    
	DestroyMenuDlg();
	CDialog::OnRButtonDown(nFlags, point);
}

void CMyPlayerDlg::OnBtnShowmenu() 
{
	// TODO: Add your control notification handler code here
   CRect rect;
   m_btnShowMenu.GetWindowRect(&rect);   
    
   CMenu m_Menu,m_PlayMenu,m_VolumeMenu,m_ModeMenu,m_LyricMenu;

   m_PlayMenu.CreatePopupMenu();
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PLAY,"播放");
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PAUSE,"暂停");
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_STOP,"停止");
   m_PlayMenu.AppendMenu(MF_SEPARATOR,0,"");
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PREV,"上一首");
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_NEXT,"下一首");
   m_PlayMenu.AppendMenu(MF_SEPARATOR,0,"");
   m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_OPEN,"打开...");

   m_VolumeMenu.CreatePopupMenu();
   m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLUP,"增大");
   m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLDOWN,"减少");
   m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLSLC,"静音");

   m_ModeMenu.CreatePopupMenu();
   m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_RAND,"随机");
   m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_SEQ,"顺序");
   m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_SINGLE,"单曲");

   m_LyricMenu.CreatePopupMenu();
   if(!m_strLyricPath.IsEmpty()){	   
	   m_LyricMenu.AppendMenu(MF_STRING,IDC_MENU_OPEN_LYRICPATH,m_strLyricPath);
	   m_LyricMenu.AppendMenu(MF_SEPARATOR,0,"");
   }
   m_LyricMenu.AppendMenu(MF_STRING,IDC_SET_LYRICPATH,"设置播放歌词路径..."); 

   m_Menu.CreatePopupMenu();
   m_Menu.AppendMenu(MF_STRING,IDC_ABOUT_STAR,"欢迎来到音乐播放器...");
   m_Menu.AppendMenu(MF_SEPARATOR,0,"卧槽");
   m_Menu.AppendMenu(MF_POPUP,(UINT)m_PlayMenu.m_hMenu,"播放控制");
   m_Menu.AppendMenu(MF_POPUP,(UINT)m_VolumeMenu.m_hMenu,"音量控制");
   m_Menu.AppendMenu(MF_POPUP,(UINT)m_ModeMenu.m_hMenu,"播放模式");
   m_Menu.AppendMenu(MF_SEPARATOR,0,"怎么会有bug");
   m_Menu.AppendMenu(MF_POPUP,(UINT)m_LyricMenu.m_hMenu,"歌词路径");
   m_Menu.AppendMenu(MF_SEPARATOR,0,"一定是我看错了");
   m_Menu.AppendMenu(MF_STRING,IDC_BTN_EXIT,"退出");   
  
   
   m_Menu.TrackPopupMenu(TPM_RIGHTBUTTON,rect.left,
	   rect.bottom,this,NULL);
  
}

void CMyPlayerDlg::OnKillFocus(CWnd* pNewWnd) 
{
	CDialog::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuNext() 
{
	// TODO: Add your command handler code here
	OnBtnNext();
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuOpen() 
{
	// TODO: Add your command handler code here
	OnBtnOpen();
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuPlay() 
{
	// TODO: Add your command handler code here
	OnBtnPlay();
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuPrev() 
{
	// TODO: Add your command handler code here
	OnBtnPrev();
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuRand() 
{
	// TODO: Add your command handler code here
    if(m_nPlayMode==MODE_SEQ){
		OnStaticMode();
		OnStaticMode();
	}else if(m_nPlayMode==MODE_SINGLE){
		OnStaticMode();
	}
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuSeq() 
{
	// TODO: Add your command handler code here
	if(m_nPlayMode==MODE_SINGLE){
		OnStaticMode();
		OnStaticMode();
	}else if(m_nPlayMode==MODE_RAND){		
		OnStaticMode();
	}

	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuSingle() 
{
	// TODO: Add your command handler code here
	if(m_nPlayMode==MODE_RAND){
		OnStaticMode();
		OnStaticMode();
	}else if(m_nPlayMode==MODE_SEQ){		
		OnStaticMode();
	}
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuStop() 
{
	// TODO: Add your command handler code here
	OnBtnStop();
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuVoldown() 
{
	// TODO: Add your command handler code here
	m_nVolume--;
	if(m_nVolume<0)
		m_nVolume=0;
	m_volume.SetPos(m_nVolume);
	if(hAudio!=NULL){
		int nVol=m_nVolume*63;
		if(nVol>1000)
			nVol=1000;
		MCIWndSetVolume(hAudio,nVol);
	}
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuPause() 
{
	// TODO: Add your command handler code here

	m_stcPlay.SetWindowText("暂停");
	MCIWndPause(hAudio);
    fPlay=FALSE;
	DestroyMenuDlg();
	
}

void CMyPlayerDlg::OnMenuVolslc() 
{
	// TODO: Add your command handler code here
	m_nVolume=0;

	m_volume.SetPos(m_nVolume);
	if(hAudio!=NULL){		
		MCIWndSetVolume(hAudio,0);
	}
	DestroyMenuDlg();
}

void CMyPlayerDlg::OnMenuVolup() 
{
	// TODO: Add your command handler code here
	m_nVolume++;
	if(m_nVolume>16)
		m_nVolume=16;
	m_volume.SetPos(m_nVolume);
	if(hAudio!=NULL){
		int nVol=m_nVolume*63;
		if(nVol>1000)
			nVol=1000;
		MCIWndSetVolume(hAudio,nVol);
	}
	DestroyMenuDlg();
}

void CMyPlayerDlg::DestroyMenuDlg()
{
  if(m_pMenuDlg!=NULL){
		m_pMenuDlg->DestroyWindow();
	   delete m_pMenuDlg;
	   m_pMenuDlg=NULL;
	}
}

void CMyPlayerDlg::OnAboutStar() 
{
	// TODO: Add your command handler code here
    DestroyMenuDlg();
	CAboutDlg  dlg;
	dlg.DoModal();
}

void CMyPlayerDlg::CreateNotifyIcon()
{
	NOTIFYICONDATA nd;
	nd.cbSize=sizeof(NOTIFYICONDATA);
	nd.hWnd=m_hWnd;
	nd.uID=IDI_ICON;
	nd.uFlags = NIF_ICON|NIF_MESSAGE|NIF_TIP; 
    nd.uCallbackMessage=MYWM_NOTIFYICON; 
    nd.hIcon = m_hIcon; 
    strcpy_s(nd.szTip,"音乐播放器");

	Shell_NotifyIcon(NIM_ADD, &nd); 
}

void CMyPlayerDlg::DeleteNotifyIcon()
{
	NOTIFYICONDATA nd;
	nd.cbSize=sizeof(NOTIFYICONDATA);
	nd.hIcon=m_hIcon;
	nd.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP;
	nd.hWnd=m_hWnd;
	nd.uCallbackMessage=MYWM_NOTIFYICON;
	nd.uID=IDI_ICON;

	Shell_NotifyIcon(NIM_DELETE,&nd);
}
void CMyPlayerDlg::OnNotifyIcon(WPARAM wParam,LPARAM lParam)
{
	if(lParam==WM_LBUTTONDOWN)
	{
		UINT MODE;
		MODE=IsWindowVisible()?SW_HIDE:SW_SHOW;
		ShowWindow(MODE);
		m_pPlayListDlg->ShowWindow(MODE);
		m_pLyricDlg->ShowWindow(MODE);
	}else if(lParam==WM_RBUTTONDOWN){
	    CPoint MousePos;
	   GetCursorPos(&MousePos);	 
    
       CMenu m_Menu,m_PlayMenu,m_VolumeMenu,m_ModeMenu,m_LyricMenu;

        m_PlayMenu.CreatePopupMenu();
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PLAY,"播放");
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PAUSE,"暂停");
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_STOP,"停止");
       m_PlayMenu.AppendMenu(MF_SEPARATOR,0,"");
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_PREV,"上一首");
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_NEXT,"下一首");
       m_PlayMenu.AppendMenu(MF_SEPARATOR,0,"");
       m_PlayMenu.AppendMenu(MF_STRING,IDC_MENU_OPEN,"打开...");

       m_VolumeMenu.CreatePopupMenu();
       m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLUP,"增大");
       m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLDOWN,"减少");
       m_VolumeMenu.AppendMenu(MF_STRING,IDC_MENU_VOLSLC,"静音");

       m_ModeMenu.CreatePopupMenu();
       m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_RAND,"随机");
       m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_SEQ,"顺序");
       m_ModeMenu.AppendMenu(MF_STRING,IDC_MENU_SINGLE,"单曲");

       m_LyricMenu.CreatePopupMenu();
       if(!m_strLyricPath.IsEmpty()){	   
    	   m_LyricMenu.AppendMenu(MF_STRING,IDC_MENU_OPEN_LYRICPATH,m_strLyricPath);
    	   m_LyricMenu.AppendMenu(MF_SEPARATOR,0,"");
	   }
      m_LyricMenu.AppendMenu(MF_STRING,IDC_SET_LYRICPATH,"设置播放歌词路径..."); 

      m_Menu.CreatePopupMenu();
      m_Menu.AppendMenu(MF_STRING,IDC_ABOUT_STAR,"欢迎来到音乐播放器...");
      m_Menu.AppendMenu(MF_SEPARATOR,0,"卧槽");
      m_Menu.AppendMenu(MF_POPUP,(UINT)m_PlayMenu.m_hMenu,"播放控制");
      m_Menu.AppendMenu(MF_POPUP,(UINT)m_VolumeMenu.m_hMenu,"音量控制");
      m_Menu.AppendMenu(MF_POPUP,(UINT)m_ModeMenu.m_hMenu,"播放模式");
      m_Menu.AppendMenu(MF_SEPARATOR,0,"怎么可能有bug");
	  m_Menu.AppendMenu(MF_POPUP, (UINT)m_LyricMenu.m_hMenu, "歌词路径");
      m_Menu.AppendMenu(MF_SEPARATOR,0,"这是为什么呢？");
      m_Menu.AppendMenu(MF_STRING,IDC_BTN_EXIT,"退出");   
	
	  SetForegroundWindow();
	  m_Menu.TrackPopupMenu(TPM_RIGHTBUTTON,\
			              MousePos.x,MousePos.y,this,NULL);
	}

}

void CMyPlayerDlg::OnBtnHide() 
{
	// TODO: Add your control notification handler code here
	ShowWindow(SW_HIDE);
	m_pPlayListDlg->ShowWindow(SW_HIDE);
	m_pLyricDlg->ShowWindow(SW_HIDE);
}

void CMyPlayerDlg::OnBtnMin() 
{
	// TODO: Add your control notification handler code here
	CloseWindow();
}

void CMyPlayerDlg::OnSetLyricpath() 
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
		bi.lpszTitle=TEXT("选择你存放歌词的文件夹");
		bi.ulFlags = BIF_RETURNFSANCESTORS | BIF_RETURNONLYFSDIRS;
		bi.lpfn = NULL;
		bi.lParam=0;

		pidl=SHBrowseForFolder(&bi);

		if(pidl!=NULL){
			if(SHGetPathFromIDList(pidl,szBuffer))
			{
				m_strLyricPath=szBuffer;				
			}
			pMalloc->Free(pidl);
		}
		pMalloc->Release();
	}
}

void CMyPlayerDlg::OnMenuOpenLyricpath() 
{
	// TODO: Add your command handler code here
   	ShellExecute(NULL,NULL,m_strLyricPath,NULL,NULL,SW_SHOW);
}
