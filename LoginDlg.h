#if !defined(AFX_LOGINDLG_H__52A151B6_D644_42DE_80F5_83277594360D__INCLUDED_)
#define AFX_LOGINDLG_H__52A151B6_D644_42DE_80F5_83277594360D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LoginDlg dialog

class LoginDlg : public CDialog
{
// Construction
public:
	LoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LoginDlg)
	enum { IDD = IDD_LOGIN };
	CStatic	m_title;
	CEdit	m_Editpassword;
	CEdit	m_Editusername;
	CString	m_username;
	CString	m_password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(LoginDlg)
	afx_msg void OnLogin();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__52A151B6_D644_42DE_80F5_83277594360D__INCLUDED_)
