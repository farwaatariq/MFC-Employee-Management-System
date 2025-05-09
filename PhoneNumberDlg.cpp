// PhoneNumber.cpp : implementation file
//

#include "pch.h"
#include "EmployeeManagementSystem.h"
#include "PhoneNumberDlg.h"
#include "afxdialogex.h"


// PhoneNumber dialog

IMPLEMENT_DYNAMIC(CPhoneNumberDlg, CDialogEx)

CPhoneNumberDlg::CPhoneNumberDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_PHONE_NUMBER, pParent)
{

}

CPhoneNumberDlg::~CPhoneNumberDlg()
{
}

void CPhoneNumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_LABEL, m_comboLabel);
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_editNumber);
}


BEGIN_MESSAGE_MAP(CPhoneNumberDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CPhoneNumberDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// PhoneNumber message handlers


BOOL CPhoneNumberDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	//label combo box population
	m_comboLabel.AddString(_T("Home"));
	m_comboLabel.AddString(_T("Office"));
	m_comboLabel.AddString(_T("Other"));
	//default selection
	m_comboLabel.SetCurSel(-1);

	m_editNumber.SetWindowText(m_number);
	if (m_label == _T("Home")) {
		m_comboLabel.SetCurSel(0);
	}
	else if (m_label == _T("Office")) {
		m_comboLabel.SetCurSel(1);
	}
	else {
		m_comboLabel.SetCurSel(2);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CPhoneNumberDlg::OnBnClickedButton1()
{
	m_comboLabel.GetLBText(m_comboLabel.GetCurSel(), m_label);
	m_editNumber.GetWindowText(m_number);

	EndDialog(IDOK);
}
