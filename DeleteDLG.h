#if !defined(AFX_DELETEDLG_H__6A46C4D9_5F20_4B2C_B97B_8660DFE22875__INCLUDED_)
#define AFX_DELETEDLG_H__6A46C4D9_5F20_4B2C_B97B_8660DFE22875__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteDLG.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DeleteDLG dialog

class DeleteDLG : public CDialog
{
// Construction
public:
	void updateDeleteList();
	void updateDisplay();
	DeleteDLG(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DeleteDLG)
	enum { IDD = IDD_DELETE };
	CStatic	m_title;
	CListBox	m_deletelist;
	CListCtrl	m_ViewList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DeleteDLG)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DeleteDLG)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemdblclickListview(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeListdelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEDLG_H__6A46C4D9_5F20_4B2C_B97B_8660DFE22875__INCLUDED_)
