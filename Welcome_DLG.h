#if !defined(AFX_WELCOME_DLG_H__55D24395_C98D_4571_BC95_A02F87D885C3__INCLUDED_)
#define AFX_WELCOME_DLG_H__55D24395_C98D_4571_BC95_A02F87D885C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Welcome_DLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Welcome_DLG dialog

class Welcome_DLG : public CDialog
{
// Construction
public:
	Welcome_DLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Welcome_DLG)
	enum { IDD = IDD_Welcome };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Welcome_DLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Welcome_DLG)
	afx_msg void OnLogout();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WELCOME_DLG_H__55D24395_C98D_4571_BC95_A02F87D885C3__INCLUDED_)
