#if !defined(AFX_FORGOTPASSWORD_DLG_H__FD89AB42_4927_4F46_8147_EFE2859C4842__INCLUDED_)
#define AFX_FORGOTPASSWORD_DLG_H__FD89AB42_4927_4F46_8147_EFE2859C4842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ForgotPassword_DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ForgotPassword_DLG dialog

class ForgotPassword_DLG : public CDialog
{
// Construction
public:
	ForgotPassword_DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ForgotPassword_DLG)
	enum { IDD = IDD_UPDATE };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ForgotPassword_DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ForgotPassword_DLG)
	afx_msg void OnChangePassword();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORGOTPASSWORD_DLG_H__FD89AB42_4927_4F46_8147_EFE2859C4842__INCLUDED_)
