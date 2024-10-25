#include "myframe.h"



MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Zwei Takt Rechner")
{
    this->SetSize(320,120);
    butt = new wxButton(this, ID_BUTTON,"Berechnen",wxPoint(200,10),wxSize(100,30));
    text_benzin = new wxTextCtrl(this, ID_TEXT_BENZIN,"",wxPoint(10,10),wxSize(70,24));
    text_oel = new wxTextCtrl(this, ID_TEXT_OEL,"",wxPoint(10,50),wxSize(150,24));
    combo_box = new wxComboBox(this,ID_COMBO_BOX,"",wxPoint(180,50),wxSize(100,25));
    label = new wxStaticText(this,ID_BUTTON,"Liter Benzin",wxPoint(100,15),wxSize(100,25));
    
    combo_box->Append("1 : 25");
    combo_box->Append("1 : 30");
    combo_box->Append("1 : 50");
    combo_box->SetSelection(2);
    Bind(wxEVT_BUTTON, &MyFrame::button_calculate, this, ID_BUTTON);
    Bind(wxEVT_COMBOBOX, &MyFrame::button_calculate, this, ID_COMBO_BOX);
}
void MyFrame::button_calculate(wxCommandEvent& event){
     double misch = 0.0;

            switch (combo_box->GetSelection()) {
                case 0:
                    misch = 0.025;
                    break;
                case 1:
                    misch = 0.030;
                    break;
                case 2:
                    misch = 0.050;
                    break;

                default:
                    misch = 0;
            }
            double benzin = 0.0;
            try {
                text_benzin->GetValue().ToDouble(&benzin);

                benzin /= misch;   //Mililiter Öl"
            
                text_oel->SetValue(wxString::Format(wxT("%.2f Mililiter Öl"), benzin));
              
            } catch (...) {
                
            }

}
