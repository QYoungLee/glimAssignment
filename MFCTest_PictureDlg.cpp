
// MFCTest_PictureDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCTest_Picture.h"
#include "MFCTest_PictureDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDraw();
	afx_msg void OnBnClickedAction();
	afx_msg void OnBnClickedOpen();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CMFCTestPictureDlg 대화 상자



CMFCTestPictureDlg::CMFCTestPictureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCTEST_PICTURE_DIALOG, pParent)
	, m_nX1(0)
	, m_nY1(0)
	, m_nX2(0)
	, m_nY2(0)
	, m_nRadius(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_X1, m_nX1);
	DDX_Text(pDX, IDC_EDIT_Y1, m_nY1);
	DDX_Text(pDX, IDC_EDIT_X2, m_nX2);
	DDX_Text(pDX, IDC_EDIT_Y2, m_nY2);
}

BEGIN_MESSAGE_MAP(CMFCTestPictureDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DRAW, &CMFCTestPictureDlg::OnBnClickedDraw)
	ON_BN_CLICKED(IDC_ACTION, &CMFCTestPictureDlg::OnBnClickedAction)
	ON_BN_CLICKED(IDC_OPEN, &CMFCTestPictureDlg::OnBnClickedOpen)
END_MESSAGE_MAP()


// CMFCTestPictureDlg 메시지 처리기

BOOL CMFCTestPictureDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCTestPictureDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCTestPictureDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCTestPictureDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMFCTestPictureDlg::OnBnClickedDraw()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;


	if (m_circle.IsNull()) { // 초기화되지 않았으면
		m_circle.Create(nWidth, nHeight, nBpp);
	}


	int nX1 = m_nX1;    // 좌표값 가져오기
	int nY1 = m_nY1;

	// 원 그리기 코드
	CClientDC dc(this);
	m_nRadius = rand() % 100 + 10;
	dc.Ellipse(nX1 - m_nRadius, nY1 - m_nRadius, nX1 + m_nRadius, nY1 + m_nRadius);



	UpdateData(FALSE);
}



void CMFCTestPictureDlg::OnBnClickedAction()
{
	UpdateData(TRUE); // UI 값을 멤버 변수로 가져오기

	int nX1 = m_nX1, nY1 = m_nY1;
	int nX2 = m_nX2, nY2 = m_nY2;

	// 실행 파일 경로에서 image 폴더 생성
	TCHAR szPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szPath, MAX_PATH);
	CString strPath(szPath);
	int nPos = strPath.ReverseFind(_T('\\'));
	if (nPos != -1) {
		strPath = strPath.Left(nPos) + _T("\\image");
	}

	if (!CreateDirectory(strPath, NULL) && GetLastError() != ERROR_ALREADY_EXISTS) {
		AfxMessageBox(_T("image 폴더를 생성할 수 없습니다!"));
		return;
	}

	int nStep = 10; // 이동 간격
	int nDx = (nX2 - nX1) == 0 ? 0 : ((nX2 - nX1) > 0 ? nStep : -nStep);
	int nDy = (nY2 - nY1) == 0 ? 0 : ((nY2 - nY1) > 0 ? nStep : -nStep);

	m_frameData.clear();

	CClientDC dc(this);
	int frame = 0;

	while ((nDx > 0 && nX1 <= nX2) || (nDx < 0 && nX1 >= nX2) ||
		(nDy > 0 && nY1 <= nY2) || (nDy < 0 && nY1 >= nY2))
	{
		dc.FillSolidRect(0, 0, 640, 480, RGB(255, 255, 255));
		int nRadius = m_nRadius;
		dc.Ellipse(nX1 - nRadius, nY1 - nRadius, nX1 + nRadius, nY1 + nRadius);

		CImage image;
		if (!image.Create(640, 480, 32)) {
			OutputDebugString(_T("CImage 객체 생성 실패\n"));
			return;
		}
		CDC* pDCImage = CDC::FromHandle(image.GetDC());
		pDCImage->FillSolidRect(0, 0, 640, 480, RGB(255, 255, 255));
		pDCImage->Ellipse(nX1 - nRadius, nY1 - nRadius, nX1 + nRadius, nY1 + nRadius);
		image.ReleaseDC();

		CString frameName;
		frameName.Format(_T("frame_%03d.bmp"), frame++); // 파일 이름만 생성
		CString savePath;
		savePath.Format(_T("%s\\%s"), strPath, frameName);
		image.Save(savePath);

		m_frameData[frameName] = CPoint(nX1, nY1); // 파일 이름만 저장

		nX1 += nDx;
		nY1 += nDy;

		Sleep(100);
		this->Invalidate();
		this->UpdateWindow();
	}
}


void CMFCTestPictureDlg::OnBnClickedOpen()
{
	CFileDialog dlg(TRUE, _T("bmp"), NULL,
		OFN_FILEMUSTEXIST | OFN_HIDEREADONLY,
		_T("Image Files (*.bmp)|*.bmp||"));

	if (dlg.DoModal() == IDOK) {
		CString fileName = dlg.GetFileName(); // 파일 이름 추출

		if (!m_circle.IsNull()) {
			m_circle.Destroy();
		}

		HRESULT result = m_circle.Load(dlg.GetPathName());
		if (FAILED(result)) {
			AfxMessageBox(_T("이미지를 불러올 수 없습니다!"));
			return;
		}

		auto it = m_frameData.find(fileName); // 파일 이름으로 검색
		if (it != m_frameData.end()) {
			CPoint center = it->second;

			CClientDC dc(this);
			m_circle.Draw(dc, 0, 0);

			dc.MoveTo(center.x - 10, center.y - 10);
			dc.LineTo(center.x + 10, center.y + 10);
			dc.MoveTo(center.x - 10, center.y + 10);
			dc.LineTo(center.x + 10, center.y - 10);

			CString text;
			text.Format(_T("(%d, %d)"), center.x, center.y);
			dc.TextOutW(center.x + 15, center.y - 10, text);
		}
		else {
			AfxMessageBox(_T("프레임 데이터가 없습니다!"));
		}
	}
}
