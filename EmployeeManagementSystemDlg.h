#include "Team.h"
#include "Employee.h"

// EmployeeManagementSystemDlg.h : header file
//

#pragma once


// CEmployeeManagementSystemDlg dialog
class CEmployeeManagementSystemDlg : public CDialogEx
{
// Construction
public:
	CEmployee* tempEmp;
	CEmployeeManagementSystemDlg(CWnd* pParent = nullptr);	// standard constructor
	CString GetSelectedGender();
	CTeam* GetSelectedTeam();
	void ClearFields();
	void PopulateEmployeesList();
	void PopulatePhoneList();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EMPLOYEEMANAGEMENTSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	CComboBox m_comboInitial;
	afx_msg void OnBnClickedButtonNewNumber();
	CEdit m_editFirstName;
	CEdit m_editMiddleName;
	CEdit m_editLastName;
	CButton m_radioMale;
	CButton m_radioFemale;
	CEdit m_editAge;
	CDateTimeCtrl m_dateTimeDOB;
	CComboBox m_comboDesignation;
	CEdit m_editRoles;
	CListCtrl m_listPhoneNumbers;
	CListCtrl m_listEmployees;
	CEdit m_editLogs;
	afx_msg void OnBnClickedButtonAddEmployee();
	CButton m_checkDIS;
	CButton m_checkFTS;
	CButton m_checkJTAC;
	CButton m_checkATC;
	CButton m_checkVCC;
	CButton m_checkAEW;
	CButton m_checkGBADS;
	CButton m_checkIG;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnLvnItemchangedListEmployees(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelchangeComboDesignation();
	afx_msg void OnBnClickedButtonDeleteEmployee();
	afx_msg void OnBnClickedButtonUpdateEmployee();
	afx_msg void OnBnClickedButtonDeleteNumber();
	afx_msg void OnBnClickedButtonUpadteNumber();
};
