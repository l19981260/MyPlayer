// LyricDlg.cpp : implementation file
//
 
#include "stdafx.h"
#include "MyPlayer.h"
#include "LyricDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CLyricDlg dialog

CLyricDlg::CLyricDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLyricDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLyricDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pParent=pParent;
	m_nID=CLyricDlg::IDD;
}


void CLyricDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLyricDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLyricDlg, CDialog)
	//{{AFX_MSG_MAP(CLyricDlg)
	ON_WM_CTLCOLOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_MOVE()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDC_HIDE_MAIN, OnHideMain)
	ON_COMMAND(IDC_HIDE_LYRIC, OnHideLyric)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLyricDlg message handlers

BOOL CLyricDlg::Create()
{
	return CDialog::Create(m_nID, m_pParent);
}

void CLyricDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	return;
	CDialog::OnCancel();
}

void CLyricDlg::OnOK() 
{
	// TODO: Add extra validation here
	return;
	CDialog::OnOK();
}

HBRUSH CLyricDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	HBRUSH hBrush=::CreateSolidBrush(RGB(0,0,0));
	// TODO: Return a different brush if the default is not desired
	return hBrush;
}

void CLyricDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM (point.x, point.y));
	CDialog::OnLButtonDown(nFlags, point);
}

void CLyricDlg::CleanScreen()
{
	CRect rect;
	GetClientRect(&rect);
	
	CDC*pDC=GetDC();

	pDC->FillSolidRect(&rect,RGB(0,0,0));

}

void CLyricDlg::NewStar(int nIndex)
{
	CRect rect;
	GetClientRect(&rect);
    m_star[nIndex].x=rand()%rect.Width();
	m_star[nIndex].y=0;
	m_star[nIndex].speed=rand()%50+2;
	m_star[nIndex].size=rand()%4;
}

void CLyricDlg::DrawStar(CDC *pDC, int nIndex)
{
	CPen pen(PS_SOLID,m_star[nIndex].size,RGB(255,255,255));
	CPen*pOldPen;
	pOldPen=m_MainDC.SelectObject(&pen);
	m_MainDC.MoveTo(m_star[nIndex].x,m_star[nIndex].y);
	m_MainDC.LineTo(m_star[nIndex].x,m_star[nIndex].y);
	m_MainDC.SelectObject(pOldPen);
}

void CLyricDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent==1)
      InvalidateCtrl();
	CDialog::OnTimer(nIDEvent);
}

int CLyricDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,500,NULL);
	fInited=FALSE;
	return 0;
}

void CLyricDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(1);
}

BOOL CLyricDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitStar();  
	fInited=TRUE;
	m_nTotalLines=0;



	LOGFONT logFont={sizeof(logFont)};
    
	logFont.lfCharSet=134;
	logFont.lfWidth=6;
	logFont.lfHeight=12;
	logFont.lfWeight=10;
	lstrcpy(logFont.lfFaceName,"宋体");
	m_font.CreateFontIndirect(&logFont);

	fHideMain=FALSE;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLyricDlg::InitStar()
{
    srand(time(0));
  	CRect rect;
	GetClientRect(&rect);
    for(int i=0;i<MAXCOUNT;i++){
		m_star[i].x=rand()%rect.Width();
		m_star[i].y=rand()%rect.Height();
		m_star[i].speed=rand()%50+2;
		m_star[i].size=rand()%4;
	}
	  
}


void CLyricDlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here	
	if(fInited){
		CRect rectParent;
		CRect rect;
		m_pParent->GetWindowRect(&rectParent);
		GetWindowRect(&rect);
		if(rect.left<=rectParent.right+5&&rect.left>=rectParent.right-5){
		  rect.left=rectParent.right;
		  rect.top=rectParent.top;
		  rect.right=rect.left+283;
		  rect.bottom=rect.top+374;
		  MoveWindow(&rect,TRUE);
		}
	}
}

void CLyricDlg::DrawText(CDC *pDC)
{
	if(m_nTotalLines==0)
		return;

	CDC memDC;
	CBitmap memBitmap;
	memDC.CreateCompatibleDC(pDC);
    memBitmap.CreateCompatibleBitmap(pDC, 283, 374);
	memDC.SelectObject(&memBitmap);
	memDC.SetBkColor(RGB(0,0,0));
	memDC.SetTextColor(RGB(0,255,0));
    memDC.SetBkMode(TRANSPARENT);

	nCounter-=nStep;

	CFont *pOldFont;	

	pOldFont=memDC.SelectObject(&m_font);

	memDC.BitBlt(0, 0,283, 374,NULL, 0, 0, BLACKNESS);

	CRect rect;
	GetClientRect(&rect);
	rect.top=nCounter;
	rect.bottom=rect.top+26;
    memDC.SetBkColor(RGB(0,0,0));

	for(int i=0;i<m_nTotalLines;i++){
		if(rect.top<=182&&rect.top>=155)
	    	memDC.SetTextColor(RGB(255,255,0));
		else if(rect.top<20)
			memDC.SetTextColor(RGB(0,100,0));
		else if(rect.top<156)
			memDC.SetTextColor(RGB(0,150,0));
		else
			memDC.SetTextColor(RGB(0,250,0));

		memDC.DrawText(m_lyric[i].strLyric,&rect,DT_CENTER);
		rect.top+=26;
		rect.bottom=rect.top+26;
	}  
    m_MainDC.BitBlt(0,0,283,374,&memDC,0,0,SRCPAINT);
	memDC.SelectObject(pOldFont);

}

void CLyricDlg::GetLyric(CString strFileName)
{
	
	ifstream infile(strFileName,ios::in);
	if(!infile)
		return;
	TCHAR szTemp[1000];
	int nLength;
	while(infile.getline(szTemp,1000)){
       nLength=lstrlen(szTemp);
	   if(nLength>0&&szTemp[nLength-1]!=']'){
         AnalyseLine(szTemp);		
	   }
	}

	if(m_nTotalLines>0)
      SortLyric();
   
	infile.close(); 
}

BOOL CLyricDlg::OpenLyric(int nIndex)
{
	if(nIndex<0||nIndex>=m_strPlayListArray.GetSize())
		return FALSE;
	CString strFileName=m_strPlayListArray.GetAt(nIndex);
	CString strLyricName=strFileName.Left(strFileName.GetLength()-3);
	strLyricName+="lrc";

	m_nTotalLines=0;
	m_nCurrentLine=0;
	nStep=0;
    nCounter=195;

	CSkinButton*pButton=new CSkinButton;
	pButton=(CSkinButton*)m_pParent->GetDlgItem(IDC_BTN_LYRIC);
    
	if(IsExistFile(strLyricName)){
		GetLyric(strLyricName);
		if(m_nTotalLines>0){
     	   nStep=15/m_lyric[0].time;
		   if(!IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_HIDE_NORMAL,IDB_LYRIC_HIDE_OVER);
			   pButton->SetToolTipText("关闭歌词");
			   ShowWindow(SW_SHOW);
		   }
		   return TRUE;
		}else{
		   if(IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
			   pButton->SetToolTipText("打开歌词");
			   ShowWindow(SW_HIDE);
		   }
		}
	}else{
		if(IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
			   pButton->SetToolTipText("打开歌词");
			   ShowWindow(SW_HIDE);
		   }
	}

   return FALSE;
}

BOOL CLyricDlg::IsExistFile(CString strFileName)
{
	HANDLE hFind;
	WIN32_FIND_DATA wfd;
	hFind=FindFirstFile(strFileName,&wfd);
	if(hFind==INVALID_HANDLE_VALUE)
		return FALSE;

    FindClose(hFind);
	return TRUE;
}
void CLyricDlg::AnalyseLine(CString strLine)
{
	CString strLyricLine;
	CString strTimeLine;
	int nLength=strLine.GetLength();
	int nTime;
	int nPos=-1;
	int nOldPos=-1;

	while((nPos=strLine.Find("]",nPos+1))>0)
		nOldPos=nPos;

	if(nOldPos==-1)
		return;
	strLyricLine=strLine.Right(nLength-nOldPos-1);   

   

	nPos=-1;
	int nTimePos;
	while((nPos=strLine.Find("[",nPos+1))>=0){
		strTimeLine=strLine.Right(nLength-nPos-1);
		nTimePos=strTimeLine.Find("]",0);
		strTimeLine=strTimeLine.Left(nTimePos);	
		nTime=GetTime(strTimeLine);
		if(nTime>0){
           m_lyric[m_nTotalLines].strLyric=strLyricLine;
		   m_lyric[m_nTotalLines].time=nTime;
		   m_nTotalLines++;
		}
	}	

}

int CLyricDlg::GetTime(CString strTime)
{
	int nPos=0;
	int nTime;
	int nMinute;
	int nSecond;
	TCHAR szMinute[10];
	TCHAR szSecond[10];
	lstrcpy(szMinute,"");
	lstrcpy(szSecond,"");
	CString strGet;
	nPos=strTime.Find(":",0);
	if(nPos<0)
		return -1;

	if(nPos==0){
		nMinute=0;
	}else{
		strGet=strTime.Left(nPos);
		lstrcpy(szMinute,strGet);
		nMinute=atoi(szMinute);	
	}
	
	strGet=strTime.Right(strTime.GetLength()-nPos-1);
	if(strGet.GetLength()==1)	
	   strGet=strGet.Left(1);
	else if(strGet.GetLength()>=2)
		strGet=strGet.Left(2);
	else
		return -1;

	lstrcpy(szSecond,strGet);	

	nSecond=atoi(szSecond);

	nTime=nMinute*60+nSecond;

	return nTime;
}

void CLyricDlg::SortLyric()
{
	LYRIC lyricTemp;

	for(int i=m_nTotalLines-1;i>0;i--)
		for(int j=0;j<i;j++){
			if(m_lyric[j].time>m_lyric[j+1].time){
				lyricTemp=m_lyric[j];
				m_lyric[j]=m_lyric[j+1];
				m_lyric[j+1]=lyricTemp;			
			}
		}
   
}

void CLyricDlg::CountStep()
{
	if(hAudio==NULL)
		return;
	int nTime=MCIWndGetPosition(hAudio)/MCIWndGetSpeed(hAudio);
	if(nTime<m_lyric[0].time)
		return;
	if(nTime==m_lyric[m_nCurrentLine].time)
		nCounter=208-(m_nCurrentLine+1)*26;
	int space=m_lyric[m_nCurrentLine+1].time-m_lyric[m_nCurrentLine].time;
	if(space>0)
	  nStep=15/space;

	if(m_nCurrentLine+1==m_nTotalLines-1){
		int ntotal=MCIWndGetLength(hAudio)/MCIWndGetSpeed(hAudio);
		nStep=3;
		return;
	}
	if(nTime>=m_lyric[m_nCurrentLine+1].time){
		m_nCurrentLine+=1;		
	}
}

void CLyricDlg::SlideClick()
{
	if(hAudio==NULL)
		return;
	int nTime=MCIWndGetPosition(hAudio)/MCIWndGetSpeed(hAudio);

	for(int i=0;i<m_nTotalLines-1;i++){
		if(m_lyric[i].time<=nTime&&m_lyric[i+1].time>nTime){
			m_nCurrentLine=i;
			nCounter=208-(m_nCurrentLine+1)*26;
		}
	}

}

void CLyricDlg::OnPaint() 
{
	CPaintDC dc(this);

	CDC memDC;
	CBitmap memBitmap;
	CBitmap* oldBitmap;

	// to avoid flicker, establish a memory dc, draw to it 
	// and then BitBlt it to the client
	memDC.CreateCompatibleDC(&dc);
	memBitmap.CreateCompatibleBitmap(&dc,283,374);
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap);

	if (memDC.GetSafeHdc() != NULL)
	{
		// first drop the bitmap on the memory dc
		memDC.BitBlt(0, 0, 283, 374, &m_MainDC, 0, 0, SRCCOPY);
		// finally send the result to the display
		dc.BitBlt(0, 0, 283, 374, &memDC, 0, 0, SRCCOPY);
	}
	memDC.SelectObject(oldBitmap);

	// Do not call CDialog::OnPaint() for painting messages
}

void CLyricDlg::InvalidateCtrl()
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	if(dc==NULL)
		return;


	if (m_MainDC.GetSafeHdc()==NULL)
	{
		m_MainDC.CreateCompatibleDC(&dc);
		m_MainBitmap.CreateCompatibleBitmap(&dc, 283,374);
		m_pOldBitmap = m_MainDC.SelectObject(&m_MainBitmap);
	}

	m_MainDC.SetBkColor(RGB(0,0,0));
	m_MainDC.SetTextColor(RGB(255,255,255));
	m_MainDC.FillSolidRect(CRect(0,0,283,374), RGB(0,0,0));

	CRect rect;
	GetClientRect(&rect);

	for(int i=0;i<MAXCOUNT;i++){		
    	DrawStar(&dc,i);
		m_star[i].y+=m_star[i].speed;
		if(m_star[i].y>=rect.Height())
			NewStar(i);
	}  
	if(m_nTotalLines>0){
    CountStep();
	DrawText(&dc);
	}

	Invalidate();

}

BOOL CLyricDlg::OpenLyric(CString strLyricPath, int nIndex)
{
	if(nIndex<0||nIndex>=m_strPlayListArray.GetSize())
		return FALSE;

	CString strFileName=m_strPlayListArray.GetAt(nIndex);
	CString strLyricName;

	int nPos=-1;
	int nOldPos=-1;
	while((nPos=strFileName.Find("\\",nPos+1))>0)
		nOldPos=nPos;

	strFileName=strFileName.Right(strFileName.GetLength()-nOldPos-1);
	strFileName=strFileName.Left(strFileName.GetLength()-3);
	strFileName+="lrc";
	strLyricName.Format("%s\\%s",strLyricPath,strFileName);	
  

	m_nTotalLines=0;
	m_nCurrentLine=0;
	nStep=0;
    nCounter=195;

	CSkinButton*pButton=new CSkinButton;
	pButton=(CSkinButton*)m_pParent->GetDlgItem(IDC_BTN_LYRIC);
    
	if(IsExistFile(strLyricName)){
		GetLyric(strLyricName);
		if(m_nTotalLines>0){
     	   nStep=15/m_lyric[0].time;
		   if(!IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_HIDE_NORMAL,IDB_LYRIC_HIDE_OVER);
			   pButton->SetToolTipText("关闭歌词");
			   ShowWindow(SW_SHOW);
		   }
		   return TRUE;
		}else{
		   if(IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
			   pButton->SetToolTipText("打开歌词");
			   ShowWindow(SW_HIDE);
		   }
		}
	}else{
		if(IsWindowVisible()&&m_pParent->IsWindowVisible()){
			   pButton->SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
			   pButton->SetToolTipText("打开歌词");
			   ShowWindow(SW_HIDE);
		   }
	}

   return FALSE;


}

void CLyricDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	ClientToScreen(&point);
	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU_HIDEMAIN);

    fHideMain=!m_pParent->IsWindowVisible();

	if(fHideMain)
		m_Menu.CheckMenuItem(IDC_HIDE_MAIN,MF_CHECKED);
	m_Menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON,point.x,
		point.y,this,NULL);
	CDialog::OnRButtonDown(nFlags, point);
}

void CLyricDlg::OnHideMain() 
{
	// TODO: Add your command handler code here	
	if(!fHideMain){
		m_pParent->ShowWindow(SW_HIDE);
		if(m_pPlaylistWnd!=NULL)
			m_pPlaylistWnd->ShowWindow(SW_HIDE);
	}else{
		m_pParent->ShowWindow(SW_SHOW);
		if(m_pPlaylistWnd!=NULL)
			m_pPlaylistWnd->ShowWindow(SW_SHOW);
	}
}

void CLyricDlg::SetPlayListWnd(CWnd *pWnd)
{
	m_pPlaylistWnd=pWnd;
}

void CLyricDlg::OnHideLyric() 
{
	// TODO: Add your command handler code here
/*	ShowWindow(SW_HIDE);
	CSkinButton*pButton=(CSkinButton*)m_pParent->GetDlgItem(IDC_BTN_LYRIC);
    pButton->SetBitmap(IDB_LYRIC_SHOW_NORMAL,IDB_LYRIC_SHOW_OVER);
	pButton->SetToolTipText("打开歌词");*/
	m_pParent->SendMessage(WM_COMMAND,IDC_BTN_LYRIC,0);
}


