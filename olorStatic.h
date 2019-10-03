#if !defined(AFX_OLORSTATIC_H__1546ED04_9413_4F79_B14F_C49AA2BF00E5__INCLUDED_)
#define AFX_OLORSTATIC_H__1546ED04_9413_4F79_B14F_C49AA2BF00E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// olorStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ColorStatic window

class ColorStatic : public CStatic
{
// Construction
public:
	void SetTextColor(COLORREF crColor); // This Function is to set the Color for the Text.
	void SetBkColor(COLORREF crColor); // This Function is to set the BackGround Color for the Text.
	ColorStatic();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ColorStatic)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ColorStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(ColorStatic)
		// NOTE - the ClassWizard will add and remove member functions here
	CBrush m_brBkgnd; // Holds Brush Color for the Static Text
	COLORREF m_crBkColor; // Holds the Background Color for the Text
	COLORREF m_crTextColor; // Holds the Color for the Text

	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OLORSTATIC_H__1546ED04_9413_4F79_B14F_C49AA2BF00E5__INCLUDED_)
