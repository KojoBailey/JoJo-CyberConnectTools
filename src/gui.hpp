#pragma once

#include <wx/wx.h>

enum class ID {
    BUTTON = 2
};

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title) :  wxFrame(nullptr, wxID_ANY, title) {
        wxPanel* panel = new wxPanel{this};
        wxButton* button = new wxButton{panel, (int)ID::BUTTON, "Bazinga!", wxPoint(150, 50), wxSize(100, 35)};
        CreateStatusBar();
    }
private:
    void OnButtonClicked(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

class App : public wxApp {
public:
    bool OnInit() override {
        MainFrame* mainFrame = new MainFrame{"JoJo CC2 Toolbox"};
        mainFrame->SetClientSize(800, 600);
        mainFrame->Center();
        mainFrame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON((int)ID::BUTTON, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()