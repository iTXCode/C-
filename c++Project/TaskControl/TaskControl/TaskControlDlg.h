
// TaskControlDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// CTaskControlDlg �Ի���
class CTaskControlDlg : public CDialogEx
{
// ����
public:
	CTaskControlDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TASKCONTROL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


	void BrowseProcess();   //��������
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;   //�б�ؼ�
};
