; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=AddDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "pass.h"

ClassCount=10
Class1=CPassApp
Class2=CPassDlg

ResourceCount=6
Resource1=IDR_MAINFRAME
Resource2=IDD_DELETE
Class3=Login_DLG
Resource3=IDD_UPDATE
Class4=Welcome_DLG
Resource4=IDD_ADD
Class5=ForgotPassword_DLG
Resource5=IDD_MAIN
Class6=AddDlg
Class7=DeleteDLG
Class8=LoginDlg
Class9=ColorStatic
Class10=CColorStatic
Resource6=IDD_LOGIN

[CLS:CPassApp]
Type=0
HeaderFile=pass.h
ImplementationFile=pass.cpp
Filter=N

[CLS:CPassDlg]
Type=0
HeaderFile=passDlg.h
ImplementationFile=passDlg.cpp
Filter=D
LastObject=CPassDlg
BaseClass=CDialog
VirtualFilter=dWC



[CLS:Login_DLG]
Type=0
HeaderFile=Login_DLG.h
ImplementationFile=Login_DLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Login_DLG

[CLS:Welcome_DLG]
Type=0
HeaderFile=Welcome_DLG.h
ImplementationFile=Welcome_DLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=Welcome_DLG

[CLS:ForgotPassword_DLG]
Type=0
HeaderFile=ForgotPassword_DLG.h
ImplementationFile=ForgotPassword_DLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ForgotPassword_DLG

[CLS:AddDlg]
Type=0
HeaderFile=AddDlg.h
ImplementationFile=AddDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDITCandidatename
VirtualFilter=dWC

[DLG:IDD_UPDATE]
Type=1
Class=ForgotPassword_DLG
ControlCount=11
Control1=IDC_EDITConstituency,edit,1350631552
Control2=IDC_EDITPartyname,edit,1350631552
Control3=IDC_EDITCandidatename,edit,1350631424
Control4=IDC_EDITVotes,edit,1350639744
Control5=IDOK,button,1342242817
Control6=IDCANCEL,button,1342242816
Control7=IDC_SPIN1,msctls_updown32,1342177558
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_Passphrase,static,1342308352
Control11=IDC_Votes,static,1342308353

[CLS:DeleteDLG]
Type=0
HeaderFile=DeleteDLG.h
ImplementationFile=DeleteDLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TITL

[DLG:IDD_LOGIN]
Type=1
Class=LoginDlg
ControlCount=7
Control1=IDC_EDITUsername,edit,1350631552
Control2=IDC_EDITPassword,edit,1350631584
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_TITLE,static,1342308865

[CLS:LoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=LoginDlg
VirtualFilter=dWC

[DLG:IDD_DELETE]
Type=1
Class=DeleteDLG
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LISTVIEW,SysListView32,1350666265
Control4=IDC_LISTDELETE,listbox,1352728835
Control5=IDC_STATICN,static,1342308865
Control6=IDC_STATICR,static,1342308865
Control7=IDC_TITLE,static,1342308865

[DLG:IDD_MAIN]
Type=1
Class=CPassDlg
ControlCount=9
Control1=IDC_EDITSEARCH,edit,1350631552
Control2=IDC_Search,button,1342259201
Control3=IDC_ADD,button,1342242816
Control4=IDC_DELETE,button,1342242816
Control5=IDCANCEL,button,1342242816
Control6=IDC_LISTVIEW,SysListView32,1350633505
Control7=IDC_TITL,static,1350566401
Control8=IDC_BUTTONLogin,button,1342242816
Control9=IDC_BUTTONLogout,button,1342242816

[DLG:IDD_ADD]
Type=1
Class=AddDlg
ControlCount=16
Control1=IDC_EDITCandidatename,edit,1350631424
Control2=IDC_EDITPartyname,edit,1350631552
Control3=IDC_EDITConstituency,edit,1350631552
Control4=IDC_EDITVotes,edit,1350639744
Control5=IDC_SPIN1,msctls_updown32,1342177558
Control6=IDD_ADD,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_Passphrase,static,1342308864
Control9=IDC_STATIC,static,1342308864
Control10=IDC_STATIC,static,1342308864
Control11=IDC_Votes,static,1342308864
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_TITLE,static,1342308865

[CLS:ColorStatic]
Type=0
HeaderFile=olorStatic.h
ImplementationFile=olorStatic.cpp
BaseClass=CStatic
Filter=W

[CLS:CColorStatic]
Type=0
HeaderFile=ColorStatic.h
ImplementationFile=ColorStatic.cpp
BaseClass=CStatic
Filter=W

