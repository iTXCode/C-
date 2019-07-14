
// TaskControlDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"


// CTaskControlDlg 对话框
class CTaskControlDlg : public CDialogEx
{
// 构造
public:
	CTaskControlDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TASKCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


	void BrowseProcess();   //遍历进程
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;   //列表控件
};
