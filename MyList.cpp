// MyList.cpp : implementation file
//

#include "stdafx.h"
#include "MyPlayer.h"
#include "MyList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
 
/////////////////////////////////////////////////////////////////////////////
// CMyList

CMyList::CMyList()
{
}

CMyList::~CMyList()
{
}


BEGIN_MESSAGE_MAP(CMyList, CListBox)
	//{{AFX_MSG_MAP(CMyList)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDC_FILE_ATTRIBUTE, OnFileAttribute)
	ON_COMMAND(IDC_SEND_DISK, OnSendDisk)
	ON_COMMAND(IDC_SEND_FOLDER, OnSendFolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyList message handlers
DWORD WINAPI MyCopyFile(PVOID p)
{
	CMyList*pList=(CMyList*)p;
	CString strFilePath=pList->strFilePath;

	CString strNewFilePath;
  if(strFilePath.IsEmpty())
	   return FALSE;
   int n=pList->GetCurSel();
   if(n<0)
	   return 0;
  
   CString strName;
   CString strMsg;
   strName=pList->GetFileName(m_strPlayListArray.GetAt(n));
 
   strNewFilePath.Format("%s\\%s",strFilePath,strName);
   if(!CopyFile(m_strPlayListArray.GetAt(n),strNewFilePath,TRUE)){
	   int nRet;
	   nRet=MessageBox(pList->m_hWnd,"该文件已经存在，你确实要覆盖它么","文件复制",MB_YESNO);
	   if(nRet==IDYES){
		   CopyFile(m_strPlayListArray.GetAt(n),strNewFilePath,FALSE);
		    strMsg.Format("文件“%s”\n\n从:%s\n\n到:%s\n\n复制完成",strName,
	                 m_strPlayListArray.GetAt(n),strNewFilePath);
		   MessageBox(pList->m_hWnd,strMsg,"文件复制",MB_OK);
		   return 1;
	   }
	   return 0;
   }
   strMsg.Format("文件“%s”\n\n从:%s\n\n到:%s\n\n复制完成",strName,
	                 m_strPlayListArray.GetAt(n),strNewFilePath);
   MessageBox(pList->m_hWnd,strMsg,"文件复制",MB_OK);
   return 1;
}

void CMyList::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CListBox::OnRButtonDown(nFlags, point);
	SendMessage(WM_LBUTTONDOWN,0,MAKELPARAM(point.x,point.y));
	SendMessage(WM_LBUTTONUP,0,MAKELPARAM(point.x,point.y));

    this->ClientToScreen(&point);
    CMenu m_Menu;
	 m_Menu.LoadMenu(IDR_MENU_RBCLICK_LIST);
	 if(!CheckRemoveAbleDisk())
		 m_Menu.EnableMenuItem(IDC_SEND_DISK,1);
	 m_Menu.GetSubMenu(0)->TrackPopupMenu(TPM_RIGHTBUTTON,point.x,
	    	 point.y,this,NULL);

}

void CMyList::OnFileAttribute() 
{
	// TODO: Add your command handler code here
	int n=GetCurSel();
	if(n<0)
		return;
	CString strFile;
	GetText(n,strFile);
	CFileAttributeDlg fdlg;
	fdlg.nIndex=n;
	fdlg.strFileName=strFile;
	fdlg.DoModal();
}

void CMyList::OnSendDisk() 
{
	// TODO: Add your command handler code here
	if(!strRemoveAbleDisk.IsEmpty()){
		strFilePath=strRemoveAbleDisk;
		CreateThread(NULL,0,MyCopyFile,(void*)this,0,NULL);
	}
}

void CMyList::OnSendFolder() 
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
				strFilePath=szBuffer;
			   CreateThread(NULL,0,MyCopyFile,(void*)this,0,NULL);
			}
			pMalloc->Free(pidl);
		}
		pMalloc->Release();
	}  

}

CString CMyList::GetFileName(CString strFileName)
{
	CString strName;
	int nPos=-1;
	int nOldPos=-1;
	while((nPos=strFileName.Find("\\",nPos+1))>0)
		nOldPos=nPos;
	strName=strFileName.Right(strFileName.GetLength()-nOldPos-1);

	return strName;
}

BOOL CMyList::CheckRemoveAbleDisk()
{
   TCHAR szDriverName[512];
   CString strDriverName;
   BOOL fFound=FALSE;;
   DWORD nLength=GetLogicalDriveStrings(sizeof(szDriverName),szDriverName);
    int i;
	for(i=0;i<(int)nLength;i++){
		if(szDriverName[i]!='\0')
			strDriverName+=szDriverName[i];
		else{
			strDriverName=strDriverName.Left(strDriverName.GetLength()-1);
			if(GetDriveType((LPCTSTR)strDriverName)==DRIVE_REMOVABLE){
               strRemoveAbleDisk=strDriverName;
			   fFound=TRUE;
			   break;
			}
			strDriverName="";
		}
	}
   
	return fFound;
}
