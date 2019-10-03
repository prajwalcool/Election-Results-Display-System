#if !defined(AFX_ADDDLG_H__7CCB5F60_AB24_463A_8BB4_3ADB6F3E7F05__INCLUDED_)
#define AFX_ADDDLG_H__7CCB5F60_AB24_463A_8BB4_3ADB6F3E7F05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddDlg dialog

class AddDlg : public CDialog
{
// Construction
public:
	AddDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddDlg)
	enum { IDD = IDD_ADD };
	CStatic	m_title;
	CSpinButtonCtrl	m_voteSPIN;
	CEdit	m_Editvotes;
	CEdit	m_Editparty;
	CEdit	m_Editconstituency;
	CEdit	m_Editcandidate;
	CString	m_candidate;
	CString	m_constituency;
	CString	m_party;
	int		m_votes;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddDlg)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDLG_H__7CCB5F60_AB24_463A_8BB4_3ADB6F3E7F05__INCLUDED_)
