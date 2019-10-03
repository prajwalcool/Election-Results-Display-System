// Login_DLG.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "Login_DLG.h"
#include "btree.h"
#include "ForgotPassword_DLG.h"
#include "passDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Login_DLG dialog


Login_DLG::Login_DLG(CWnd* pParent /*=NULL*/)
	: CDialog(Login_DLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(Login_DLG)
	//}}AFX_DATA_INIT
}


void Login_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Login_DLG)
	DDX_Control(pDX, IDC_LISTVIEW, m_ViewList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Login_DLG, CDialog)
	//{{AFX_MSG_MAP(Login_DLG)
	ON_BN_CLICKED(IDOK, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Login_DLG message handlers

void Login_DLG::OnLogin() 
{
	// TODO: Add your control notification handler code here
/*	UpdateData();
	btree bt;
	Password p;
	fstream f1("username.txt",ios::in);
	while(!f1.eof())
	{
		p.read(f1);
		bt.insert(p);
	}
	f1.close();
	if(m_username == "")
	{
		AfxMessageBox("You forgot to Enter your username");
		m_EditUsername.SetFocus();
		return;
	}
	if(m_password == "")
	{
		AfxMessageBox("You forgot to Enter your password");
		m_EditPassword.SetFocus();
		return;
	}
	strcpy(p.username,m_username);
	strcpy(p.password,m_password);
	int flag = bt.search(p);
	if(flag==1)
	{
		AfxMessageBox("You have Successfully Loged in");
		CDialog::OnOK();
		Welcome_DLG d;
		d.DoModal();
		return;
	}
	else
	{
		AfxMessageBox("You Log in was unsuccessful");
		m_EditUsername.SetFocus();
		return;
	}*/
}





BOOL Login_DLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_EditUsername.SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
