// AddDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "AddDlg.h"
#include "btree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddDlg dialog


AddDlg::AddDlg(CWnd* pParent /*=NULL*/)
	: CDialog(AddDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddDlg)
	m_candidate = _T("");
	m_constituency = _T("");
	m_party = _T("");
	m_votes = 0;
	//}}AFX_DATA_INIT
}


void AddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddDlg)
	DDX_Control(pDX, IDC_TITLE, m_title);
	DDX_Control(pDX, IDC_SPIN1, m_voteSPIN);
	DDX_Control(pDX, IDC_EDITVotes, m_Editvotes);
	DDX_Control(pDX, IDC_EDITPartyname, m_Editparty);
	DDX_Control(pDX, IDC_EDITConstituency, m_Editconstituency);
	DDX_Control(pDX, IDC_EDITCandidatename, m_Editcandidate);
	DDX_Text(pDX, IDC_EDITCandidatename, m_candidate);
	DDV_MaxChars(pDX, m_candidate, 18);
	DDX_Text(pDX, IDC_EDITConstituency, m_constituency);
	DDV_MaxChars(pDX, m_constituency, 18);
	DDX_Text(pDX, IDC_EDITPartyname, m_party);
	DDV_MaxChars(pDX, m_party, 18);
	DDX_Text(pDX, IDC_EDITVotes, m_votes);
	DDV_MinMaxInt(pDX, m_votes, 1, 1000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddDlg, CDialog)
	//{{AFX_MSG_MAP(AddDlg)
	ON_BN_CLICKED(IDD_ADD, OnAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddDlg message handlers

void AddDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	Election p;
	btree bt;
	fstream f1("election.txt",ios::in);
	if(!f1.fail())
	{
		while(!f1.eof())
		{
			p.read(f1);
			if(strlen(p.candidate)==0 || p.candidate[0]=='$')
				continue;
			bt.insert(p);
		}
		f1.close();
	}
	else
	{
			MessageBox("File is not opened");
			f1.close();
			return;
	}
	
	if(m_candidate == "")
	{
		AfxMessageBox("You forgot to Enter the candidate name");
		m_Editcandidate.SetFocus();
		return;
	}
	if(m_party == "")
	{
		AfxMessageBox("You forgot to Enter the party");
		m_Editparty.SetFocus();
		return;
	}
	if(m_constituency == "")
	{
		AfxMessageBox("You forgot to Enter the constituency");
		m_Editconstituency.SetFocus();
		return;
	}
	if(m_votes == 0)
	{
		AfxMessageBox("You forgot to Enter the votes");
		m_Editcandidate.SetFocus();
		return;
	}
	
	strcpy(p.constituency,m_constituency);
	strcpy(p.party,m_party);
	strcpy(p.candidate,m_candidate);
	p.votes=m_votes;

	int flag=bt.isDuplicate(p);
	if(flag==0)
	{
		p.insert();
		MessageBox("The candidate result is added!!");
	//	CDialog::OnOK();
	//	Login_DLG d;
	//	d.DoModal();
	}
	else
	{
		AfxMessageBox("The candidate name Already exists!!\nPlease try another");
		m_Editconstituency.Clear();
		m_Editparty.Clear();
		m_Editcandidate.Clear();
		m_Editvotes.Clear();
		m_Editcandidate.SetFocus();
	}
}

BOOL AddDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Editcandidate.SetFocus();
	m_voteSPIN.SetRange(0, 1000);
    m_voteSPIN.SetPos(0);
    m_voteSPIN.SetWindowText("0");
	CFont *m_Font1 = new CFont;
	m_Font1->CreateFont(30,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS, "Arial Bold");
//	GetDlgItem(IDC_TITLE)->;
	m_title.SetFont(m_Font1);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
