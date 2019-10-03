// Welcome_DLG.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "Welcome_DLG.h"
#include "Login_DLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Welcome_DLG dialog


Welcome_DLG::Welcome_DLG(CWnd* pParent /*=NULL*/)
	: CDialog(Welcome_DLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(Welcome_DLG)
	//}}AFX_DATA_INIT
}


void Welcome_DLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Welcome_DLG)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Welcome_DLG, CDialog)
	//{{AFX_MSG_MAP(Welcome_DLG)
	ON_BN_CLICKED(IDLogout, OnLogout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Welcome_DLG message handlers

void Welcome_DLG::OnLogout() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
	Login_DLG d;
	d.DoModal();
	
	//Login_DLG d= new Login_DLG;
	//d.Create(IDD_Login,this);
	//d.ShowWindow(SW_SHOW);
}

BOOL Welcome_DLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
