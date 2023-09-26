
// calculatorDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
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


// CcalculatorDlg 对话框



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//将文本框与定义的字符串关联
	DDX_Text(pDX, IDC_EDIT1, str1);
	DDX_Text(pDX, IDC_EDIT2, str2);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, &CcalculatorDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_Dian, &CcalculatorDlg::OnBnClickedButtonDian)
	ON_BN_CLICKED(IDC_BUTTON_ClearEntry, &CcalculatorDlg::OnBnClickedButtonClearentry)
	ON_BN_CLICKED(IDC_BUTTON_ClearAll, &CcalculatorDlg::OnBnClickedButtonClearall)
	ON_BN_CLICKED(IDC_BUTTON_Jia, &CcalculatorDlg::OnBnClickedButtonJia)
	ON_BN_CLICKED(IDC_BUTTON_Jian, &CcalculatorDlg::OnBnClickedButtonJian)
	ON_BN_CLICKED(IDC_BUTTON_Chen, &CcalculatorDlg::OnBnClickedButtonChen)
	ON_BN_CLICKED(IDC_BUTTON_Chu, &CcalculatorDlg::OnBnClickedButtonChu)
	ON_BN_CLICKED(IDC_BUTTON_Calculate, &CcalculatorDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_BUTTON_Ans, &CcalculatorDlg::OnBnClickedButtonAns)
	ON_BN_CLICKED(IDC_BUTTON_Mo, &CcalculatorDlg::OnBnClickedButtonMo)
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalculatorDlg::SaveFirstValue()
{
	UpdateData(TRUE);
	if (str1 == "Ans")
	{
		num1 = _wtof(str2);
	}
	else 
	{
		num1 = _wtof(str1);//字符串转化为数字
	}
	tmpstr = str1;
	str1 = L"";
	UpdateData(FALSE);
}
bool FLAG_ERROR = FALSE;
double CcalculatorDlg::Calculate()
{
	FLAG_ERROR = FALSE;
	UpdateData(TRUE);
	if (str1 == "Ans")
	{
		num2 = _wtof(str2);
	}
	else
	{
		num2 = _wtof(str1);
	}
	double result=0.0f;
	switch (FU)
	{
	case FLAG_JIA:
		result = num1 + num2;
		break;
	case FLAG_JIAN:
		result = num1 - num2;
		break;
	case FLAG_CHEN:
		result = num1 * num2;
		break;
	case FLAG_CHU:
		if (num2 == 0)
		{
			FLAG_ERROR=TRUE;
		}
		else
		{
			result = num1 / num2;
		}
		break;
	case FLAG_MO:
		if (num2 == 0)
		{
			FLAG_ERROR = TRUE;
		}
		else
		{
			result = (int)num1 % (int)num2;
		}
		break;
	
	}
	
	num1 = 0.0f;
	num2 = 0.0f;
	return result;
}

void CcalculatorDlg::PutResult(double result)
{
	UpdateData(TRUE);
	str1 = L"";
	if (FLAG_ERROR)
	{
		str2 = L"ERROR!";
	}
	else
	{
		if (result - int(result) < 1e-8)
		{
			str2.Format(L"%d", (int)result);
		}
		else
		{
			str2.Format(L"%f", result);
		}
	}
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButton0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"0";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"1";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"2";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"3";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"4";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"5";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"6";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"7";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"8";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 += L"9";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonDian()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str1.Find('.') == -1)
	{
		str1 += ".";
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonClearentry()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str1.IsEmpty() == FALSE)
	{
		str1 = str1.Left(str1.GetLength() - 1);
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonClearall()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	str1 = L"";
	str2 = L"";
	num1 = 0.0f;
	num2 = 0.0f;
	FU = FLAG_JIA;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonJia()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	FU = FLAG_JIA;
	str1 = L"";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonJian()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	FU = FLAG_JIAN;
	str1 = L"";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonChen()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	FU = FLAG_CHEN;
	str1 = L"";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonChu()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	FU = FLAG_CHU;
	str1 = L"";
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonCalculate()
{
	// TODO: 在此添加控件通知处理程序代码
	double result;
	result= Calculate();
	PutResult(result);
}



void CcalculatorDlg::OnBnClickedButtonAns()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (str1 == ""&&str2!="")
	{
		str1 += L"Ans";
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonMo()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveFirstValue();
	FU = FLAG_MO;
	str1 = L"";
	UpdateData(FALSE);
}
