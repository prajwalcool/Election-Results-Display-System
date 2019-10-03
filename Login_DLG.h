#if !defined(AFX_LOGIN_DLG_H__D718ABAB_D0CE_44C4_80AC_5758A60DDB08__INCLUDED_)
#define AFX_LOGIN_DLG_H__D718ABAB_D0CE_44C4_80AC_5758A60DDB08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Login_DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Login_DLG dialog

class Login_DLG : public CDialog
{
// Construction
public:
	Login_DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Login_DLG)
	enum { IDD = IDD_DELETE };
	CListCtrl	m_ViewList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Login_DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Login_DLG)
	afx_msg void OnLogin();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGIN_DLG_H__D718ABAB_D0CE_44C4_80AC_5758A60DDB08__INCLUDED_)
