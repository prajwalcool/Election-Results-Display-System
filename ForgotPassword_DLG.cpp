// ForgotPassword_DLG.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "ForgotPassword_DLG.h"
#include  "btree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ForgotPassword_DLG dialog


ForgotPassword_DLG::ForgotPassword_DLG(CWnd* pParent /*=NULL*/)
	: CDialog(ForgotPassword_DLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(ForgotPassword_DLG)
	//}}AFX_DATA_INIT
}


void ForgotPassword_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ForgotPassword_DLG)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ForgotPassword_DLG, CDialog)
	//{{AFX_MSG_MAP(ForgotPassword_DLG)
	ON_BN_CLICKED(IDOK, OnChangePassword)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ForgotPassword_DLG message handlers

void ForgotPassword_DLG::OnChangePassword() 
{
	// TODO: Add your control notification handler code here
/*	UpdateData();
	btree bt;
	Password p;
	fstream f1("eresults.txt",ios::in);
	while(!f1.eof())
	{
		p.read(f1);
		bt.insert(p);
	}
	f1.close();
	if(m_ == "")
	{
		AfxMessageBox("You forgot to Enter your username");
		m_EditUsername.SetFocus();
		return;
	}
	if(m_passphrase == "")
	{
		AfxMessageBox("You forgot to Enter your new password");
		m_EditPassphrase.SetFocus();
		return;
	}
	if(m_newpassword == "")
	{
		AfxMessageBox("You forgot to Enter your old password");
		m_EditNewPassword.SetFocus();
		return;
	}
	
	strcpy(p.username,m_username);
	strcpy(p.passphrase,m_passphrase);
	strcpy(p.password,m_newpassword);
	int flag = bt.modifypass(p);
	if(flag==1)
	{
		MessageBox("You have Successfully changed your Password");
		return;
	}
	else
	{
		AfxMessageBox("Sorry Your attempt was unsuccessful");
		m_EditUsername.SetFocus();
		return;
	}
*/
}

BOOL ForgotPassword_DLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
//	m_Edit.SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
