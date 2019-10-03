// DeleteDLG.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "DeleteDLG.h"
#include "btree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DeleteDLG dialog


DeleteDLG::DeleteDLG(CWnd* pParent /*=NULL*/)
	: CDialog(DeleteDLG::IDD, pParent)
{
	//{{AFX_DATA_INIT(DeleteDLG)
	//}}AFX_DATA_INIT
}


void DeleteDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DeleteDLG)
	DDX_Control(pDX, IDC_TITLE, m_title);
	DDX_Control(pDX, IDC_LISTDELETE, m_deletelist);
	DDX_Control(pDX, IDC_LISTVIEW, m_ViewList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DeleteDLG, CDialog)
	//{{AFX_MSG_MAP(DeleteDLG)
	ON_NOTIFY(HDN_ITEMDBLCLICK, IDC_LISTVIEW, OnItemdblclickListview)
	ON_LBN_SELCHANGE(IDC_LISTDELETE, OnSelchangeListdelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DeleteDLG message handlers

BOOL DeleteDLG::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFont *m_Font1 = new CFont;
	m_Font1->CreateFont(30,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS, "Arial Bold");
//	GetDlgItem(IDC_TITLE)->;
	m_title.SetFont(m_Font1);
	CFont *m_Font2 = new CFont;
	m_Font2->CreateFont(20,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS, "Arial Bold");
	GetDlgItem(IDC_STATICR)->SetFont(m_Font2);
	GetDlgItem(IDC_STATICN)->SetFont(m_Font2);
	m_ViewList.InsertColumn(0,_T("Candidate"),LVCFMT_CENTER,155);
	m_ViewList.InsertColumn(1,_T("Party"),LVCFMT_CENTER,125);
	m_ViewList.InsertColumn(2,_T("Constituency"),LVCFMT_CENTER,175);
	m_ViewList.InsertColumn(3,_T("Votes"),LVCFMT_CENTER,125);
	updateDeleteList();
	updateDisplay();
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DeleteDLG::updateDisplay()
{
	int nItem;
	Election p;
	m_ViewList.DeleteAllItems();
	fstream f1("election.txt",ios::in);
	if(!f1.fail())
	{
		while(!f1.eof())
		{
			p.read(f1);
			if(strlen(p.candidate)==0 || p.candidate[0]=='$')
				continue;
			nItem = m_ViewList.InsertItem(0, _T(p.candidate));
			m_ViewList.SetItemText(nItem, 1, _T(p.party));
			m_ViewList.SetItemText(nItem, 2, _T(p.constituency));
			CString vote;
			vote.Format("%d",p.votes);
			m_ViewList.SetItemText(nItem, 3, _T(vote));

		}
		f1.close();
	}
	else
	{
			MessageBox("File is not opened");
			f1.close();
	}
}

void DeleteDLG::OnItemdblclickListview(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	
	
	*pResult = 0;
}

void DeleteDLG::updateDeleteList()
{
	Election p;
	m_deletelist.ResetContent();
	fstream f1("election.txt",ios::in);
	if(!f1.fail())
	{
		while(!f1.eof())
		{
			p.read(f1);
			if(strlen(p.candidate)==0 || p.candidate[0]=='$')
				continue;
			m_deletelist.AddString(p.candidate);
		}
		f1.close();
	}
	else
	{
			MessageBox("File is not opened");
			f1.close();
	}
	
}

void DeleteDLG::OnSelchangeListdelete() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int flag;
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
	m_deletelist.GetText(m_deletelist.GetCurSel(),p.candidate);
	flag=bt.search(p);
	if(flag==1)
	{
		p.del(p.recaddr);
		
	}
	else
	{
		AfxMessageBox("Not Found");
	}
	updateDeleteList();
	updateDisplay();
}
