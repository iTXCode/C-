
// TaskControlDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TaskControl.h"
#include "TaskControlDlg.h"
#include "afxdialogex.h"
#include<tlhelp32.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTaskControlDlg �Ի���



CTaskControlDlg::CTaskControlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTaskControlDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list);
}

BEGIN_MESSAGE_MAP(CTaskControlDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTaskControlDlg ��Ϣ�������

BOOL CTaskControlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	//���б������
	m_list.InsertColumn(0, _T("���"),LVCFMT_LEFT,200);
	//����(�кţ�_T("����",�����,���е�����)

	m_list.InsertColumn(1, _T("������"), LVCFMT_LEFT, 400);
	
	m_list.InsertColumn(2, _T("PID"), LVCFMT_LEFT, 200);

	//LVCFMT_LEFT���б��ͷ�ķ�������

	m_list.SetExtendedStyle(LVS_EX_GRIDLINES);//���������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTaskControlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTaskControlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�Լ���ӵĺ�������������
void CTaskControlDlg::BrowseProcess(){
//��ý��̵Ŀ���
	HANDLE hProcessSnap =CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
}

