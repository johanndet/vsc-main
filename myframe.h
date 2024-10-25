#pragma once
#include "myframe.h"
#include <wx/wx.h>

enum Id{
    ID_BUTTON,
    ID_TEXT_BENZIN,
    ID_TEXT_OEL,
    ID_COMBO_BOX
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
private: 
  wxButton *butt;
  wxTextCtrl *text_benzin;
  wxTextCtrl *text_oel;
  wxComboBox *combo_box;
  wxStaticText *label;
  void button_calculate(wxCommandEvent& event);
};

