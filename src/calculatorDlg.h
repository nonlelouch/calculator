
// calculatorDlg.h: 头文件
//

#pragma once

enum Calculator_Flag//运算符标志
{
	FLAG_JIA,
	FLAG_JIAN,
	FLAG_CHEN,
	FLAG_CHU,
	FLAG_MO

};


// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void SaveFirstValue();	//保存第一个输入值
	double Calculate();		//计算
	void PutResult(double result);

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CString str1;//对话框字符串1
	CString str2;//对话框字符串2
	CString tmpstr;
	double num1;
	double num2;
	Calculator_Flag FU;//运算符


public:
	
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonDian();
	afx_msg void OnBnClickedButtonClearentry();
	afx_msg void OnBnClickedButtonClearall();
	afx_msg void OnBnClickedButtonJia();
	afx_msg void OnBnClickedButtonJian();
	afx_msg void OnBnClickedButtonChen();
	afx_msg void OnBnClickedButtonChu();
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonAns();
	afx_msg void OnBnClickedButtonMo();
};
