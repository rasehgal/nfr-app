# nfr-app
OpenOrbiter 2016. Application to document non-functional requirements for project conception, management, and development.
rsehgal95@gmail.com

Contents:

LICENSE
Makefile
README
qaTree: n-way vector tree data structure utilized in this project
  functions
    gfunc.cpp
    gfunc.h
  structure
    qattr.cpp
    qattr.h
  
main_gui: main for gui, main window ui and commands, new attribute tab (not integrated, but created for further action)
  attributetab.cpp
  attributetab.h
  attributetab.ui
  main.cpp
  mainwindow.cpp
  mainwindow.h
  mainwindow.ui
  
dialog_h: header files for all functions in all dialogs, tabs, windows that pop up outside of main screen in gui
  closeconf.h
  createnewattribute.h
  createnewproject.h
  deleteattr.h
  deleteproj.h
  printclose.h
  printproject.h
  projectgone.h
  projexists.h
  
dialog_cpp: cpp files for all functions in all dialogs, tabs, windows that pop up outside of main screen in gui
  closeconf.cpp
  createnewattribute.cpp
  createnewproject.cpp
  deleteattr.cpp
  deleteproj.cpp
  printclose.cpp
  printproject.cpp
  projectgone.cpp
  projexists.cpp
  
dialog_ui: ui files for all functions in all dialogs, tabs, windows that pop up outside of main screen in gui
  closeconf.ui
  createnewattribute.ui
  createnewproject.ui
  deleteattr.ui
  deleteproj.ui
  printclose.ui
  printproject.ui
  projectgone.ui
  projexists.ui
