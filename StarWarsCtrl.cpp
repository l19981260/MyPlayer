
#include "stdafx.h"
#include "resource.h"
#include "StarWarsCtrl.h"
#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define getrandom(min,max) ((rand()%(int)(((max)+1)-(min)))+(min));


CStarWarsCtrl::CStarWarsCtrl()
{
	// 保护bit位图DC
	m_pOldBitmap = NULL;

	m_Font.CreateFont(22, 0, 0, 0, FW_BOLD,
                       FALSE, FALSE, 0, ANSI_CHARSET,
                       OUT_DEFAULT_PRECIS, 
                       CLIP_DEFAULT_PRECIS,
                       DEFAULT_QUALITY, 
                       DEFAULT_PITCH|FF_SWISS, "Tahoma");
	m_nScrollSpeed = 2;
	m_nStarsSpeed = 20;
}

CStarWarsCtrl::~CStarWarsCtrl()
{
	if (m_pOldBitmap != NULL)
		m_MainDC.SelectObject(m_pOldBitmap);  
}


BEGIN_MESSAGE_MAP(CStarWarsCtrl, CStatic)
	//{{AFX_MSG_MAP(CStarWarsCtrl)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//初始化
void CStarWarsCtrl::PreSubclassWindow() 
{
	CClientDC dc(this);

	GetClientRect(m_rectClient);

	// initialize stars
	for (int i = 0; i < NUM_STARS; i++)
	{
		m_StarArray[i].x = getrandom(0, 1024);
		m_StarArray[i].x -= 512;
		m_StarArray[i].y = getrandom(0, 1024);
		m_StarArray[i].y -= 512;
		m_StarArray[i].z = getrandom(0, 512);
		m_StarArray[i].z -= 256;
	}

	m_TextLines.Add("test1");
	m_TextLines.Add("test2");
	m_TextLines.Add("test3");
	m_TextLines.Add("test4");
	m_TextLines.Add("test5");
	m_TextLines.Add("test6");
	m_TextLines.Add("test7");
	m_TextLines.Add("test8");


	m_TextLines.Add("test9");
	m_TextLines.Add("test10");
	m_TextLines.Add("test11");
	m_TextLines.Add("test12");
	m_TextLines.Add("test13");
	m_TextLines.Add("test14");
	m_TextLines.Add("test15");
	m_TextLines.Add("test16");
	m_TextLines.Add("test17");
	m_TextLines.Add("test18");
	m_TextLines.Add("test19");
	m_TextLines.Add("test20");
	m_TextLines.Add("test21");

	m_nScrollPos = m_rectClient.Height();

	// 计算速度，方便字幕的滚动
	DWORD t1 = GetTickCount();
	InvalidateCtrl();
	DWORD t2 = GetTickCount();

	t2 -= t1; 

	m_nScrollSpeed = (m_nScrollSpeed * t2)/50;

	SetTimer(1, 75, NULL);

	CStatic::PreSubclassWindow();
}


	//请求重绘窗口
void CStarWarsCtrl::OnPaint() 
{
	CPaintDC dc(this); 
	
	CDC memDC;
	CBitmap memBitmap;
	CBitmap* oldBitmap;

	// 建立一个内存DC，避免切换时的窗口闪烁
	memDC.CreateCompatibleDC(&dc);
	memBitmap.CreateCompatibleBitmap(&dc, m_rectClient.Width(), m_rectClient.Height());
	oldBitmap = (CBitmap *)memDC.SelectObject(&memBitmap);

	if (memDC.GetSafeHdc() != NULL)
	{
		//1.在内存DC上贴位图
		memDC.BitBlt(0, 0, m_rectClient.Width(), m_rectClient.Height(), &m_MainDC, 0, 0, SRCCOPY);
		//2.将结果回送到显示器
		dc.BitBlt(0, 0, m_rectClient.Width(), m_rectClient.Height(), &memDC, 0, 0, SRCCOPY);
	}
	memDC.SelectObject(oldBitmap);
}


	//大小更改
void CStarWarsCtrl::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);
	
	GetClientRect(m_rectClient);

	// 破坏主位图DC后重建
	CClientDC dc(this);
	if (m_pOldBitmap && m_MainBitmap.GetSafeHandle() && m_MainDC.GetSafeHdc())
	{
		m_MainDC.SelectObject(m_pOldBitmap);
		m_MainBitmap.DeleteObject();
		m_MainBitmap.CreateCompatibleBitmap(&dc, m_rectClient.Width(), m_rectClient.Height());
		m_pOldBitmap = m_MainDC.SelectObject(&m_MainBitmap);
	}
}


	//画星星
void CStarWarsCtrl::DoStars(CDC *pDC)
{
	m_MainDC.SetBkColor(RGB(0,0,0));
	m_MainDC.SetTextColor(RGB(255,255,255));
	m_MainDC.FillSolidRect(m_rectClient, RGB(0,0,0));

	int nFunFactor = 100;
	int x, y, z;
	for(int i = 0; i < NUM_STARS; i++)
	{
        m_StarArray[i].z = m_StarArray[i].z - m_nStarsSpeed;
        if (m_StarArray[i].z > 255)
		{
			m_StarArray[i].z = -255;
		}
        if (m_StarArray[i].z < -255)
		{
			m_StarArray[i].z = 255;
		}
        
		z = m_StarArray[i].z + 256;
        x = (m_StarArray[i].x * nFunFactor / z) + (m_rectClient.Width() / 2);
        y = (m_StarArray[i].y * nFunFactor / z) + (m_rectClient.Height() / 2);
		
		CPen myPen;

		int nColor = 255 - m_StarArray[i].z;
		myPen.CreatePen(PS_COSMETIC, 1, RGB(nColor,nColor,nColor));

		CPen *pOldPen = (CPen *)m_MainDC.SelectObject(&myPen);
		//开始画星
		m_MainDC.Ellipse(CRect(x, y, x+3, y+3));
		m_MainDC.SelectObject(pOldPen);
    }
}


	//在主DC位图上画矩阵->显示歌词
void CStarWarsCtrl::InvalidateCtrl()
{
	// 如果未建立内存DC
	CClientDC dc(this);

	// 设置
	if (m_MainDC.GetSafeHdc() == NULL)
	{
		m_MainDC.CreateCompatibleDC(&dc);
		m_MainBitmap.CreateCompatibleBitmap(&dc, m_rectClient.Width(), m_rectClient.Height());
		m_pOldBitmap = m_MainDC.SelectObject(&m_MainBitmap);
	}
  
	DoStars(&dc);	
	DoScrollText(&dc);

	// 重绘
	InvalidateRect(m_rectClient);
} 


//显示更新
void CStarWarsCtrl::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
		InvalidateCtrl();

	CStatic::OnTimer(nIDEvent);
}


	//字幕滚动
void CStarWarsCtrl::DoScrollText(CDC *pDC)
{
	int nPosX =0;
	int nPosY =0;

	CDC memDC;
	CBitmap memBitmap;
	CFont *oldFont;

	memDC.CreateCompatibleDC(pDC);
	memBitmap.CreateCompatibleBitmap(pDC, m_rectClient.Width(), m_rectClient.Height());
	memDC.SelectObject(&memBitmap);
	memDC.SetBkColor(RGB(0,0,0));
	memDC.SetTextColor(RGB(0,255,0));
    memDC.SetBkMode(TRANSPARENT);

	oldFont = memDC.SelectObject(&m_Font);

	
	memDC.BitBlt(0, 0, m_rectClient.Width(), m_rectClient.Height(), NULL, 0, 0, BLACKNESS);
	
	// 画字幕
	for(int i=0; i < m_TextLines.GetSize(); i++)
	{
		// 设置分隔线位置
		CSize size = memDC.GetTextExtent(m_TextLines.GetAt(i));

		nPosY = m_nScrollPos + (i * size.cy);
		if (nPosY > 0)
		{
			nPosX = (m_rectClient.Width() / 2) - (size.cx / 2);

			if (nPosY > 255)
			{
				memDC.SetTextColor(RGB(255, 255, 255));
			}
			else
			{
				memDC.SetTextColor(RGB(nPosY, nPosY, nPosY));
			}
			
			memDC.TextOut(nPosX, nPosY, m_TextLines.GetAt(i));
		}
		else
		{
			if (i == (m_TextLines.GetSize()-1))
			{
				m_nScrollPos = m_rectClient.Height();
			}
		}
	}

	int nWidth = m_rectClient.Width();
	int nHeight = m_rectClient.Height();

	for (int y=0; y <nHeight; y++)
	{
		double nScale = (double)y/(double)nHeight;
		int nOffset = (int)(nWidth - nWidth*nScale)/2;
		m_MainDC.StretchBlt(nOffset, y, (int)(nWidth*nScale), 1, &memDC, 0, y, nWidth, 1, SRCPAINT);
	}

	memDC.SelectObject(oldFont);

	m_nScrollPos = m_nScrollPos - m_nScrollSpeed;
}


	//滚动速度
void CStarWarsCtrl::SetScrollSpeed(int nSpeed)
{
	m_nScrollSpeed = nSpeed;
}


	//星星的速度
void CStarWarsCtrl::SetStarSpeed(int nSpeed)
{
	m_nStarsSpeed = nSpeed;
}


	//版本信息
/*CString CStarWarsCtrl::GetVersionInformation(LPCTSTR lpszModuleName)
{
	CString strResult;
	BYTE		*pDataBlock = NULL;
	DWORD FAR	*translation;
	DWORD FAR	*buffer;     
	DWORD		dwHandle;
	UINT		nBytes;
	
	
	LPTSTR lpszExeName = const_cast<LPTSTR>(lpszModuleName); 

	char szName[512];

	
	nBytes = (UINT)GetFileVersionInfoSize(lpszExeName, &dwHandle);

	if (nBytes)
	{
		pDataBlock = new BYTE[nBytes];

		
		if (GetFileVersionInfo(lpszExeName, dwHandle, nBytes, pDataBlock))
		{
			if (VerQueryValue(pDataBlock, "\\VarFileInfo\\Translation", (VOID FAR * FAR *)&translation, (UINT FAR *)&nBytes)) 
			{
				
				wsprintf(szName, "\\StringFileInfo\\%04x%04x\\PrivateBuild", LOWORD(*translation), HIWORD(*translation));

				if (VerQueryValue(pDataBlock, szName, (VOID FAR * FAR *)&buffer, (UINT FAR *)&nBytes)) 
				{
					strResult.Format((char far *)buffer);
				}
			}
			else 
			{
				MessageBoxA("版本出错","Error",MB_OK);
			}
		}
		if (pDataBlock)
			delete[] pDataBlock;
	}
	return strResult;
}*/


void CStarWarsCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
    // open URL in the browser.

	CStatic::OnLButtonDown(nFlags, point);
}
