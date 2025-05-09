
// EmployeeManagementSystemDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "EmployeeManagementSystem.h"
#include "EmployeeManagementSystemDlg.h"
#include "afxdialogex.h"
#include "PhoneNumberDlg.h"
#include "EmployeeFactory.h"
#include "Employee.h"
#include <atlstr.h>
#include "EmployeeManager.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About
int count = 0;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CEmployeeManagementSystemDlg dialog



CEmployeeManagementSystemDlg::CEmployeeManagementSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EMPLOYEEMANAGEMENTSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEmployeeManagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_INITIAL, m_comboInitial);
	DDX_Control(pDX, IDC_EDIT_FIRST_NAME, m_editFirstName);
	DDX_Control(pDX, IDC_EDIT_MIDDLE_NAME, m_editMiddleName);
	DDX_Control(pDX, IDC_EDIT_LAST_NAME, m_editLastName);
	DDX_Control(pDX, IDC_RADIO_MALE, m_radioMale);
	DDX_Control(pDX, IDC_RADIO_FEMALE, m_radioFemale);
	DDX_Control(pDX, IDC_EDIT_AGE, m_editAge);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DOB, m_dateTimeDOB);
	DDX_Control(pDX, IDC_COMBO_DESIGNATION, m_comboDesignation);
	DDX_Control(pDX, IDC_EDIT_ROLES, m_editRoles);
	DDX_Control(pDX, IDC_LIST_PHONE_NUMBERS, m_listPhoneNumbers);
	DDX_Control(pDX, IDC_LIST_EMPLOYEES, m_listEmployees);
	DDX_Control(pDX, IDC_EDIT_LOGS, m_editLogs);
	DDX_Control(pDX, IDC_CHECK_DIS, m_checkDIS);
	DDX_Control(pDX, IDC_CHECK_FTS, m_checkFTS);
	DDX_Control(pDX, IDC_CHECK_JTAC, m_checkJTAC);
	DDX_Control(pDX, IDC_CHECK_ATC, m_checkATC);
	DDX_Control(pDX, IDC_CHECK_VCC, m_checkVCC);
	DDX_Control(pDX, IDC_CHECK_AEW, m_checkAEW);
	DDX_Control(pDX, IDC_CHECK_GBADS, m_checkGBADS);
	DDX_Control(pDX, IDC_CHECK_IG, m_checkIG);
}

BEGIN_MESSAGE_MAP(CEmployeeManagementSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// ON_BN_CLICKED(IDC_BUTTON3, &CEmployeeManagementSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_NEW_NUMBER, &CEmployeeManagementSystemDlg::OnBnClickedButtonNewNumber)
	ON_BN_CLICKED(IDC_BUTTON_ADD_EMPLOYEE, &CEmployeeManagementSystemDlg::OnBnClickedButtonAddEmployee)
	//ON_BN_CLICKED(IDC_BUTTON1, &CEmployeeManagementSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CEmployeeManagementSystemDlg::OnBnClickedButtonClear)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_EMPLOYEES, &CEmployeeManagementSystemDlg::OnLvnItemchangedListEmployees)
	ON_CBN_SELCHANGE(IDC_COMBO_DESIGNATION, &CEmployeeManagementSystemDlg::OnCbnSelchangeComboDesignation)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_EMPLOYEE, &CEmployeeManagementSystemDlg::OnBnClickedButtonDeleteEmployee)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_EMPLOYEE, &CEmployeeManagementSystemDlg::OnBnClickedButtonUpdateEmployee)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_NUMBER, &CEmployeeManagementSystemDlg::OnBnClickedButtonDeleteNumber)
	ON_BN_CLICKED(IDC_BUTTON_UPADTE_NUMBER, &CEmployeeManagementSystemDlg::OnBnClickedButtonUpadteNumber)
END_MESSAGE_MAP()


// CEmployeeManagementSystemDlg message handlers

BOOL CEmployeeManagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	// phone number list column population
	m_listPhoneNumbers.InsertColumn(0, _T("Sr. #"), LVCFMT_CENTER, 50);
	m_listPhoneNumbers.InsertColumn(1, _T("Label"), LVCFMT_CENTER, 70);
	m_listPhoneNumbers.InsertColumn(2, _T("Number"), LVCFMT_CENTER, 90);

	// employees list column population
	m_listEmployees.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 50);
	m_listEmployees.InsertColumn(1, _T("Full Name"), LVCFMT_CENTER, 80);
	m_listEmployees.InsertColumn(2, _T("Gender"), LVCFMT_CENTER, 50);
	m_listEmployees.InsertColumn(3, _T("Age"), LVCFMT_CENTER, 50);
	m_listEmployees.InsertColumn(4, _T("DOB"), LVCFMT_CENTER, 90);
	m_listEmployees.InsertColumn(5, _T("Phone"), LVCFMT_CENTER, 100);
	m_listEmployees.InsertColumn(6, _T("Designation"), LVCFMT_CENTER, 90);
	m_listEmployees.InsertColumn(7, _T("Team(s)"), LVCFMT_CENTER, 90);

	m_listEmployees.SetExtendedStyle(m_listEmployees.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_listPhoneNumbers.SetExtendedStyle(m_listPhoneNumbers.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	//initial combo box population
	m_comboInitial.AddString(_T("Mr"));
	m_comboInitial.AddString(_T("Ms"));
	//default selection
	m_comboInitial.SetCurSel(-1);

	//designation combo box population
	m_comboDesignation.AddString(_T("Project Manager"));
	m_comboDesignation.AddString(_T("Team Lead"));
	m_comboDesignation.AddString(_T("Software Developer"));
	//default selection
	m_comboDesignation.SetCurSel(-1);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEmployeeManagementSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CEmployeeManagementSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CEmployeeManagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEmployeeManagementSystemDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
}


void CEmployeeManagementSystemDlg::OnBnClickedButtonNewNumber()
{

	CPhoneNumberDlg phoneNumberDlg;
	if (phoneNumberDlg.DoModal() == IDOK)
	{
		CString label = phoneNumberDlg.m_label;
		CString number = phoneNumberDlg.m_number;

		int rowIndex = m_listPhoneNumbers.GetItemCount();
		CString srNo;
		srNo.Format(_T("%d"), rowIndex + 1);

		int insertedIndex = m_listPhoneNumbers.InsertItem(rowIndex, srNo); // Sr. # column
		m_listPhoneNumbers.SetItemText(insertedIndex, 1, label);  // Label column
		m_listPhoneNumbers.SetItemText(insertedIndex, 2, number); // Number column
		tempEmp->AddPhones(CPhone(std::string(CT2A(label)), std::string(CT2A(number))));
		PopulateEmployeesList();
	}
}

CString CEmployeeManagementSystemDlg::GetSelectedGender() {
	if (m_radioMale.GetCheck() == BST_CHECKED) {
		return _T("Male");
	}
	else if (m_radioFemale.GetCheck() == BST_CHECKED) {
		return _T("Female");
	}
	else {
		return _T("none selected");
	}
}

CTeam* CEmployeeManagementSystemDlg::GetSelectedTeam() {

	int index = 0;
	count = 0;
	CTeam* selectedTeams = new CTeam[8];

	if (m_checkDIS.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("DIS");
	}
	if (m_checkFTS.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("FTS");
	}
	if (m_checkJTAC.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("JTAC");
	}
	if (m_checkATC.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("ATC");
	}
	if (m_checkVCC.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("VCC");
	}
	if (m_checkAEW.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("AEW");
	}
	if (m_checkGBADS.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("GBADS");
	}
	if (m_checkIG.GetCheck() == BST_CHECKED) {
		selectedTeams[count++] = CTeam("IG");
	}

	return selectedTeams;
}

void CEmployeeManagementSystemDlg::ClearFields()
{
	m_comboDesignation.SetCurSel(-1);
	m_editFirstName.SetWindowText(_T(""));
	m_editMiddleName.SetWindowText(_T(""));
	m_editLastName.SetWindowText(_T(""));
	m_editAge.SetWindowText(_T(""));
	m_editRoles.SetWindowText(_T(""));
	m_comboDesignation.SetCurSel(-1);
	m_comboInitial.SetCurSel(-1);
	m_checkDIS.SetCheck(BST_UNCHECKED);
	m_checkFTS.SetCheck(BST_UNCHECKED);
	m_checkJTAC.SetCheck(BST_UNCHECKED);
	m_checkATC.SetCheck(BST_UNCHECKED);
	m_checkVCC.SetCheck(BST_UNCHECKED);
	m_checkAEW.SetCheck(BST_UNCHECKED);
	m_checkGBADS.SetCheck(BST_UNCHECKED);
	m_checkIG.SetCheck(BST_UNCHECKED);
	m_radioFemale.SetCheck(BST_UNCHECKED);
	m_radioMale.SetCheck(BST_UNCHECKED);
	m_listPhoneNumbers.DeleteAllItems();
}

void CEmployeeManagementSystemDlg::OnBnClickedButtonAddEmployee()
{
	//getting data from all controls.
	CString initial, firstName, middleName, lastName, age, dob, designation, roles, gender;
	
	//initial
	m_comboInitial.GetLBText(m_comboInitial.GetCurSel(), initial);

	//names
	m_editFirstName.GetWindowText(firstName);
	m_editMiddleName.GetWindowText(middleName);
	m_editLastName.GetWindowText(lastName);
	CString fullName = firstName + " " + middleName + " " + lastName;

	//gender
	gender = GetSelectedGender();

	//age
	m_editAge.GetWindowText(age);

	//dob
	m_dateTimeDOB.GetWindowText(dob);

	//roles
	m_editRoles.GetWindowText(roles);
	//teams
	CTeam* selectedTeam = GetSelectedTeam();
	//setters

	tempEmp->SetInitial(std::string(CT2A(initial)));
	tempEmp->SetFullName(std::string(CT2A(fullName)));
	tempEmp->SetGender(std::string(CT2A(gender)));
	int ageValue = _ttoi(age);
	tempEmp->SetAge(ageValue);
	tempEmp->SetDOB(std::string(CT2A(dob)));
	tempEmp->SetRoles((tempEmp->GetRoles()));
	tempEmp->SetTeamCount(count);                                                           
	tempEmp->SetTeams(selectedTeam);

	CEmployeeManager::GetInstance()->Add(tempEmp);
	MessageBox(CString(tempEmp->GetString().c_str()));
	ClearFields();
	PopulateEmployeesList();
	tempEmp = nullptr;
}

void CEmployeeManagementSystemDlg::PopulateEmployeesList() {
	std::list<CEmployee*> listEmployees = CEmployeeManager::GetInstance()->GetAllEmployees();
	m_listEmployees.DeleteAllItems();
	int index = 0;
	for (CEmployee* pEmployee : listEmployees) {

		if (pEmployee == nullptr) {
			continue;
		}
		CString strID;
		strID.Format(_T("%d"), pEmployee->GetID());

		CString strFullName = CString(pEmployee->GetFullName().c_str());
		CString strGender = CString(pEmployee->GetGender().c_str());
		CString strAge = CString(std::to_string(pEmployee->GetAge()).c_str());
		CString strDOB = CString(pEmployee->GetDOB().c_str());
		CString strPhones;
		std::vector<CPhone> tempVecPhones = pEmployee->GetPhones();
		for (CPhone phone : tempVecPhones) {
			strPhones += CString(phone.GetString().c_str()) + _T(", ");
		}
		CString strDesignation = CString(pEmployee->GetDesignation().c_str());
		CString strRoles = CString(pEmployee->GetRoles().c_str());
		CString strTeams;
		CTeam* pTeams = pEmployee->GetTeams();
		int teamSize = pEmployee->GetTeamCount();
		for (int i = 0; i < teamSize; i++) {
			strTeams += CString(pTeams[i].GetName().c_str()) + _T(", ");
		}

		// Insert row
		m_listEmployees.InsertItem(index, strID);
		m_listEmployees.SetItemText(index, 1, strFullName);
		m_listEmployees.SetItemText(index, 2, strGender);
		m_listEmployees.SetItemText(index, 3, strAge);
		m_listEmployees.SetItemText(index, 4, strDOB);
		m_listEmployees.SetItemText(index, 5, strPhones);
		m_listEmployees.SetItemText(index, 6, strDesignation);
		m_listEmployees.SetItemText(index, 7, strTeams);

		++index;
	}
}

void CEmployeeManagementSystemDlg::OnBnClickedButtonClear()
{
	ClearFields();
}


void CEmployeeManagementSystemDlg::OnLvnItemchangedListEmployees(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	int selected = m_listEmployees.GetSelectionMark();
	if (selected != -1)
	{
		//just get the id and call the get employee method and update and delete <3
		CString strId = m_listEmployees.GetItemText(selected, 0);
		int id = _ttoi(strId);
		tempEmp = CEmployeeManager::GetInstance()->GetEmployeeById(id);

		//getting all the attributes from the selected object.
		CString initial = CString(tempEmp->GetInitial().c_str());
		CString fullName = CString(tempEmp->GetFullName().c_str());
		CString gender = CString(tempEmp->GetGender().c_str());
		CString ageStr = CString(std::to_string(tempEmp->GetAge()).c_str());
		CString dob = CString(tempEmp->GetDOB().c_str());
		CString role = CString(tempEmp->GetRoles().c_str());
		std::vector<CPhone> vecPhones = tempEmp->GetPhones();
		CString designation = CString(tempEmp->GetDesignation().c_str());
		CTeam* teams = tempEmp->GetTeams();
		int teamCount = tempEmp->GetTeamCount();

		// Split full name
		std::vector<CString> nameParts;
		CString token;
		int curPos = 0;
		token = fullName.Tokenize(_T(" "), curPos);
		while (!token.IsEmpty())
		{
			nameParts.push_back(token);
			token = fullName.Tokenize(_T(" "), curPos);
		}

		if (nameParts.size() >= 2)
		{
			m_editFirstName.SetWindowText(nameParts[0]);
			m_editMiddleName.SetWindowText(nameParts[1]);
			m_editLastName.SetWindowText(nameParts[2]);
		}
		

		m_editAge.SetWindowText(ageStr);
		m_dateTimeDOB.SetWindowText(dob);
		//populating phone number in the list cntrl.
		m_listPhoneNumbers.DeleteAllItems();
		int phoneIndex = 0;

		for (CPhone phone : vecPhones) {

			CString label = CString(phone.GetLabel().c_str());
			CString number = CString(phone.GetNumber().c_str());

			CString serialNumber = CString(std::to_string(phoneIndex+1).c_str());
			m_listPhoneNumbers.InsertItem(phoneIndex, serialNumber);
			m_listPhoneNumbers.SetItemText(phoneIndex, 1, label);
			m_listPhoneNumbers.SetItemText(phoneIndex, 2, number);

			++phoneIndex;
		}
		//initial combobox
		if (initial == "Mr") {
			m_comboInitial.SetCurSel(0);
		}
		else if (initial == "Ms") {
			m_comboInitial.SetCurSel(1);
		}

		//team combobox
		if (designation == "Project Manager") {
			m_comboDesignation.SetCurSel(0);
		}
		else if (designation == "Software Developer") {
			m_comboDesignation.SetCurSel(1);
		}
		else if (designation == "Team Lead") {
			m_comboDesignation.SetCurSel(2);
		}

		m_editRoles.SetWindowText(role);

		//gender combobox
		if (gender == _T("Male"))
		{
			m_radioMale.SetCheck(BST_CHECKED);
		}
		else if (gender == _T("Female"))
		{
			m_radioFemale.SetCheck(BST_CHECKED);
		}

		for (int i = 0; i < teamCount; i++) {
			if (teams[i].GetName() == "DIS") {
				m_checkDIS.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "FTS") {
				m_checkFTS.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "JTAC") {
				m_checkJTAC.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "ATC") {
				m_checkATC.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "VCC") {
				m_checkVCC.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "AEW") {
				m_checkAEW.SetCheck(BST_CHECKED);
			}
			if (teams[i].GetName() == "GBADS") {
				m_checkGBADS.SetCheck(BST_CHECKED);
			}
		}
	}

	*pResult = 0;
}


void CEmployeeManagementSystemDlg::OnCbnSelchangeComboDesignation()
{
	EMPLOYEETYPE type;
	CString designation;
	m_comboDesignation.GetLBText(m_comboDesignation.GetCurSel(), designation);
	if (designation == "Project Manager") {
		type = EMPLOYEETYPE::ProjectManager;
	}
	else if (designation == "Team Lead") {
		type = EMPLOYEETYPE::TeamLead;
	}
	else if (designation == "Software Developer") {
		type = EMPLOYEETYPE::SoftwareDeveloper;
	}
	
	tempEmp = CEmployeeFactory::createEmployee(type);
	CString role = CString(tempEmp->GetRoles().c_str());
	m_editRoles.SetWindowText(role);
	tempEmp->SetDesignation(std::string(CT2A(designation)));
}


void CEmployeeManagementSystemDlg::OnBnClickedButtonDeleteEmployee()
{
	int selected = m_listEmployees.GetSelectionMark();
	if (selected != -1)
	{
		//just get the id and call the get employee method and update and delete <3
		CString strId = m_listEmployees.GetItemText(selected, 0);
		int id = _ttoi(strId);

		CEmployeeManager::GetInstance()->Delete(id);
		PopulateEmployeesList();
	}
}


void CEmployeeManagementSystemDlg::OnBnClickedButtonUpdateEmployee()
{
	int selected = m_listEmployees.GetSelectionMark();
	if (selected != -1)
	{
		//just get the id and call the get employee method and update and delete <3
		// EMPLOYEETYPE type;
		CString strId = m_listEmployees.GetItemText(selected, 0);
		int id = _ttoi(strId);

		// CEmployee* newEmp = CEmployeeFactory::createEmployee(type);
		CString initial, firstName, middleName, lastName, fullName, gender, age, dob, designation;
		CTeam* team;
		std::vector<CPhone> newPhones;

		//-----Getting all data from the fields-------
		m_comboInitial.GetLBText(m_comboInitial.GetCurSel(), initial);
		m_editFirstName.GetWindowText(firstName);
		m_editMiddleName.GetWindowText(middleName);
		m_editLastName.GetWindowText(lastName);
		fullName = firstName + " " + middleName + " " + lastName;
		gender = GetSelectedGender();
		m_editAge.GetWindowTextW(age);
		int ageValue = _ttoi(age);
		m_dateTimeDOB.GetWindowText(dob);
		m_comboDesignation.GetLBText(m_comboDesignation.GetCurSel(), designation);
		team = GetSelectedTeam();

		
		//getting phones from the phone control list
		int phoneCount = m_listPhoneNumbers.GetItemCount();
		for (int i = 0; i < phoneCount; i++) {
			CString label = m_listPhoneNumbers.GetItemText(i, 1);  // Column 1 = Label
			CString number = m_listPhoneNumbers.GetItemText(i, 2); // Column 2 = Number

			newPhones.push_back(CPhone(std::string(CT2A(label)), std::string(CT2A(number))));
		}

		EMPLOYEETYPE type;
		if (designation == "Project Manager") {
			type = EMPLOYEETYPE::ProjectManager;
		}
		else if (designation == "Team Lead") {
			type = EMPLOYEETYPE::TeamLead;
		}
		else {
			type = EMPLOYEETYPE::SoftwareDeveloper;
		}

		CEmployee* newEmp = CEmployeeFactory::createEmployee(type);

		// Copy all fields to newEmp
		newEmp->SetInitial(std::string(CT2A(initial)));
		newEmp->SetFullName(std::string(CT2A(fullName)));
		newEmp->SetGender(std::string(CT2A(gender)));
		newEmp->SetAge(ageValue);
		newEmp->SetDOB(std::string(CT2A(dob)));
		newEmp->SetDesignation(std::string(CT2A(designation)));
		newEmp->SetPhones(newPhones);
		newEmp->SetTeams(team);
		newEmp->SetTeamCount(count); // if needed

		// Set correct role
		CString role = CString(newEmp->GetRoles().c_str());
		m_editRoles.SetWindowText(role);

		////-----Setting all the new data-------
		//tempEmp->SetFullName(std::string(CT2A(fullName)));
		//tempEmp->SetInitial(std::string(CT2A(initial)));
		//tempEmp->SetGender(std::string(CT2A(gender)));
		//tempEmp->SetAge(ageValue);
		//tempEmp->SetDOB(std::string(CT2A(dob)));
		//tempEmp->SetDesignation(tempEmp->GetDesignation());
		//m_editRoles.SetWindowText(CString(tempEmp->GetRoles().c_str()));
		//tempEmp->SetPhones(newPhones);
		//tempEmp->SetTeams(team);

		//calling the update function.
		CEmployeeManager::GetInstance()->Update(newEmp, id);
		PopulateEmployeesList();
	}
}

void CEmployeeManagementSystemDlg::PopulatePhoneList() {
	m_listPhoneNumbers.DeleteAllItems();
	std::vector<CPhone> phones = tempEmp->GetPhones();
	for (int i = 0; i < phones.size(); ++i) {
		CString serial;
		serial.Format(_T("%d"), i + 1);
		m_listPhoneNumbers.InsertItem(i, serial);
		m_listPhoneNumbers.SetItemText(i, 1, CString(phones[i].GetLabel().c_str()));
		m_listPhoneNumbers.SetItemText(i, 2, CString(phones[i].GetNumber().c_str()));
	}
}

void CEmployeeManagementSystemDlg::OnBnClickedButtonDeleteNumber()
{
	int selectedPhone = m_listPhoneNumbers.GetSelectionMark();
	if (selectedPhone != -1)
	{
		if (tempEmp != nullptr)
		{
			tempEmp->DeletePhone(selectedPhone); 
			PopulatePhoneList();     
			PopulateEmployeesList();
		}
	}
}

void CEmployeeManagementSystemDlg::OnBnClickedButtonUpadteNumber()
{
	int selectedPhone = m_listPhoneNumbers.GetSelectionMark();
	if (selectedPhone != -1)
	{
		CString label = m_listPhoneNumbers.GetItemText(selectedPhone, 1);
		CString number = m_listPhoneNumbers.GetItemText(selectedPhone, 2);

		CPhoneNumberDlg phoneNumberDlg;
		phoneNumberDlg.m_label = label;
		phoneNumberDlg.m_number = number;

		if (phoneNumberDlg.DoModal() == IDOK) {
			label = phoneNumberDlg.m_label;
			number = phoneNumberDlg.m_number;

			CEmployeeManager::GetInstance()->GetEmployeeById(tempEmp->GetID())->UpdatePhone(CPhone(std::string(CT2A(label)), std::string(CT2A(number))), selectedPhone);
			PopulatePhoneList();
			PopulateEmployeesList();
		}
	}
}
