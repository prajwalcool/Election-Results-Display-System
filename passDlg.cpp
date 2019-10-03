// passDlg.cpp : implementation file
//

#include "stdafx.h"
#include "pass.h"
#include "passDlg.h"
#include "btree.h"
#include "AddDlg.h"
#include "DeleteDLG.h"
#include "LoginDlg.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPassDlg dialog

CPassDlg::CPassDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPassDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPassDlg)
	m_search = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPassDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPassDlg)
	DDX_Control(pDX, IDC_BUTTONLogout, m_logoutbutton);
	DDX_Control(pDX, IDC_BUTTONLogin, m_loginbutton);
	DDX_Control(pDX, IDC_ADD, m_addbutton);
	DDX_Control(pDX, IDC_DELETE, m_deleteButton);
	DDX_Control(pDX, IDC_EDITSEARCH, m_EditSearch);
	DDX_Control(pDX, IDC_LISTVIEW, m_ViewList);
	DDX_Text(pDX, IDC_EDITSEARCH, m_search);
	DDX_Control(pDX, IDC_TITL, m_stText);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPassDlg, CDialog)
	//{{AFX_MSG_MAP(CPassDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_NOTIFY(NM_CLICK, IDC_LISTVIEW, OnClickListview)
	ON_EN_SETFOCUS(IDC_EDITSEARCH, OnSetfocusEditsearch)
	ON_EN_KILLFOCUS(IDC_EDITSEARCH, OnKillfocusEditsearch)
	ON_BN_CLICKED(IDC_Search, OnSearch)
	ON_BN_CLICKED(IDC_BUTTONLogin, OnLogin)
	ON_BN_CLICKED(IDC_BUTTONLogout, OnLogout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPassDlg message handlers

BOOL CPassDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_deleteButton.ShowWindow(SW_HIDE);
	m_addbutton.ShowWindow(SW_HIDE);
	m_logoutbutton.ShowWindow(SW_HIDE);
	updatePlaceholder();
//	m_Editconstituency.SetFocus();
	m_ViewList.InsertColumn(0,_T("Candidate"),LVCFMT_CENTER,175);
	m_ViewList.InsertColumn(1,_T("Party"),LVCFMT_CENTER,125);
	m_ViewList.InsertColumn(2,_T("Constituency"),LVCFMT_CENTER,175);
	m_ViewList.InsertColumn(3,_T("Votes"),LVCFMT_CENTER,125);
	updateDisplay();

	

//	m_ViewList.Set;
//	m_brush.CreateSolidBrush(RGB(25, 255, 255));
//	CPassDlg::SetDialogBkColor(RGB(255,255,255),RGB(0,0,0));


	CFont *m_Font1 = new CFont;
	m_Font1->CreateFont(30,0,0,0,FW_BOLD,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS, "Arial Bold");
//	GetDlgItem(IDC_TITLE)->;
	m_stText.SetFont(m_Font1);

//	m_stText.SubclassDlgItem(IDC_TITL,this);
	//m_stText.SubclassDlgItem(IDC_TITLE,this);
	//m_stText.SetTextColor(RGB(  0,  0,255)); //Changes the Static Text to Red
	//m_stText.SetBkColor(RGB(127,  0,  0)); //You probably will not use it, but it's here.

//	m_voteSPIN.A;
	
	return FALSE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPassDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPassDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPassDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	AddDlg d;
	d.DoModal();
}

void CPassDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	DeleteDLG d;
	d.DoModal();
	updateDisplay();
	
}

void CPassDlg::updateDisplay()
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

void CPassDlg::OnClickListview(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	updateDisplay();
	
	*pResult = 0;
}


void CPassDlg::OnSetfocusEditsearch() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_search=="Candidate Name")
	{
		m_search="";
	}
	UpdateData(FALSE);
}



void CPassDlg::updatePlaceholder()
{
	CString s;
	s.Format("Candidate Name");
	SetDlgItemText(IDC_EDITSEARCH, s);
}

void CPassDlg::OnKillfocusEditsearch() 
{
	// TODO: Add your control notification handler code here

	UpdateData();
	if(m_search=="")
	{
		updatePlaceholder();
	}
}

void CPassDlg::OnSearch() 
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
	strcpy(p.candidate,m_search);
	
	if(m_search == "")
	{
		AfxMessageBox("You forgot to Enter the candidate name");
		m_EditSearch.SetFocus();
		return;
	}
	int flag = bt.search(p);
	if(flag==1)
	{
		m_ViewList.DeleteAllItems();
		int nItem = m_ViewList.InsertItem(0, _T(p.candidate));
		m_ViewList.SetItemText(nItem, 1, _T(p.party));
		m_ViewList.SetItemText(nItem, 2, _T(p.constituency));
		CString vote;
		vote.Format("%d",p.votes);
		m_ViewList.SetItemText(nItem, 3, _T(vote));
		return;
	}
	else
	{
		AfxMessageBox("Not Found");
	}
}

void CPassDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
	//m_deleteButton.SetState();
//	CWnd* itemb=GetDlgItem(IDC_DELETE);
//	itemb.ShowWindow(SW_HIDE);
	LoginDlg d;
	int resp=d.DoModal();
	if(resp == IDOK)
	{
		m_loginbutton.ShowWindow(SW_HIDE);
		m_deleteButton.ShowWindow(SW_SHOW);
		m_addbutton.ShowWindow(SW_SHOW);
		m_logoutbutton.ShowWindow(SW_SHOW);
	}
}

void CPassDlg::OnLogout() 
{
	// TODO: Add your control notification handler code here
	m_logoutbutton.ShowWindow(SW_HIDE);
	m_deleteButton.ShowWindow(SW_HIDE);
	m_addbutton.ShowWindow(SW_HIDE);
	m_loginbutton.ShowWindow(SW_SHOW);
}


HBRUSH CPassDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
/*
** No need to do this!
**
*/
// HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
 m_brush.CreateSolidBrush(RGB(25, 25, 255));

/*
** Return the white brush.
*/
return m_brush;
}