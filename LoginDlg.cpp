// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LoginDlg dialog


LoginDlg::LoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(LoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(LoginDlg)
	m_username = _T("");
	m_password = _T("");
	//}}AFX_DATA_INIT
}


void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LoginDlg)
	DDX_Control(pDX, IDC_TITLE, m_title);
	DDX_Control(pDX, IDC_EDITPassword, m_Editpassword);
	DDX_Control(pDX, IDC_EDITUsername, m_Editusername);
	DDX_Text(pDX, IDC_EDITUsername, m_username);
	DDX_Text(pDX, IDC_EDITPassword, m_password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialog)
	//{{AFX_MSG_MAP(LoginDlg)
	ON_BN_CLICKED(IDOK, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LoginDlg message handlers

void LoginDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_username == "")
	{
		AfxMessageBox("You forgot to Enter your username");
		m_Editusername.SetFocus();
		return;
	}
	if(m_password == "")
	{
		AfxMessageBox("You forgot to Enter your password");
		m_Editpassword.SetFocus();
		return;
	}
	if(m_username == "prajwal" && m_password == "fsp")
	{
		AfxMessageBox("Login successful");
		CDialog::OnOK();
		return;
	}
	else
	{
		AfxMessageBox("Login unsuccessful!!\nRetry");
		m_Editusername.Clear();
		m_Editpassword.Clear();
		m_Editusername.SetFocus();
		return;
	}
	

	
}

BOOL LoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Editusername.SetFocus();
	CFont *m_Font1 = new CFont;
	m_Font1->CreateFont(30,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS, "Arial Bold");
//	GetDlgItem(IDC_TITLE)->;
	m_title.SetFont(m_Font1);
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
