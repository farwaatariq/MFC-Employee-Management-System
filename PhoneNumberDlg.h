#pragma once


// PhoneNumber dialog

class CPhoneNumberDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPhoneNumberDlg)

public:
	CPhoneNumberDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CPhoneNumberDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_PHONE_NUMBER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_comboLabel;
	CEdit m_editNumber;
	afx_msg void OnBnClickedButton1();
	CString m_label;
	CString m_number;
};
