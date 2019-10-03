// passDlg.h : header file
//

#if !defined(AFX_PASSDLG_H__3E7406C2_E84E_4D81_A334_90BDDB153913__INCLUDED_)
#define AFX_PASSDLG_H__3E7406C2_E84E_4D81_A334_90BDDB153913__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ColorStatic.h"

/////////////////////////////////////////////////////////////////////////////
// CPassDlg dialog

class CPassDlg : public CDialog
{
// Construction
public:
	CColorStatic m_stText;
	void updatePlaceholder();
	void updateDisplay();
	CPassDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPassDlg)
	enum { IDD = IDD_PASS_DIALOG };
	CButton	m_logoutbutton;
	CButton	m_loginbutton;
	CButton	m_addbutton;
	CButton	m_deleteButton;
	CEdit	m_EditSearch;
	CListCtrl	m_ViewList;
	CStatic	m_TITLE;
	CString	m_search;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPassDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CBrush m_brush;
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	// Generated message map functions
	//{{AFX_MSG(CPassDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnClickListview(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusEditsearch();
	afx_msg void OnKillfocusEditsearch();
	afx_msg void OnSearch();
	afx_msg void OnLogin();
	afx_msg void OnLogout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PASSDLG_H__3E7406C2_E84E_4D81_A334_90BDDB153913__INCLUDED_)
