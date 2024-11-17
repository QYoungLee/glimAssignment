
// MFCTest_PictureDlg.h: 헤더 파일
//

#pragma once
#include <map> // 파일명과 좌표를 저장하기 위한 map 사용

// CMFCTestPictureDlg 대화 상자
class CMFCTestPictureDlg : public CDialogEx
{
private: 
	CImage m_circle;
	std::map<CString, CPoint> m_frameData;



	// 생성입니다.
public:
	
	CMFCTestPictureDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_PICTURE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDraw();
	int m_nX1;
	int m_nY1;
	int m_nX2;
	int m_nY2;
	afx_msg void OnBnClickedAction();
	int m_nRadius;
	afx_msg void OnBnClickedOpen();
};
