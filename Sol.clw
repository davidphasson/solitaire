; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSolDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Sol.h"

ClassCount=4
Class1=CSolApp
Class2=CSolDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_CARDBACK
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_SOL_DIALOG
Class4=CBackSelDlg
Resource5=IDR_MENU1

[CLS:CSolApp]
Type=0
HeaderFile=Sol.h
ImplementationFile=Sol.cpp
Filter=N
LastObject=CSolApp

[CLS:CSolDlg]
Type=0
HeaderFile=SolDlg.h
ImplementationFile=SolDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CSolDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=SolDlg.h
ImplementationFile=SolDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_SOL_DIALOG]
Type=1
Class=CSolDlg
ControlCount=2
Control1=IDC_StatusText,static,1342308364
Control2=IDC_StatusText2,static,1342308352

[MNU:IDR_MENU1]
Type=1
Class=CSolDlg
Command1=ID_NEW_GAME
Command2=IDR_CARDBACK
Command3=ID_CHGBACKGRND
Command4=IDCANCEL
Command5=ID_ABOUT
CommandCount=5

[DLG:IDD_CARDBACK]
Type=1
Class=CBackSelDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342177294
Control4=IDC_STATIC,static,1342177294
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342177294
Control7=IDC_RADIO1,button,1342308361
Control8=IDC_RADIO2,button,1342177289
Control9=IDC_RADIO3,button,1342177289
Control10=IDC_STATIC,static,1342177294
Control11=IDC_STATIC,static,1342177294
Control12=IDC_STATIC,static,1342177294
Control13=IDC_STATIC,static,1342177294
Control14=IDC_RADIO4,button,1342177289
Control15=IDC_RADIO5,button,1342177289
Control16=IDC_RADIO6,button,1342177289
Control17=IDC_RADIO7,button,1342177289

[CLS:CBackSelDlg]
Type=0
HeaderFile=BackSelDlg.h
ImplementationFile=BackSelDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CBackSelDlg
VirtualFilter=dWC

