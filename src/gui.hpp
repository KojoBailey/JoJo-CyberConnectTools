#pragma once

#include <wx/wx.h>
#include <nucc/xfbin.hpp>
#include <filesystem>
#include <format>

enum class ID {
    LOAD_XFBIN
};

class MainFrame : public wxFrame {
public:
    MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
        wxPanel* panel = new wxPanel{this};
        wxButton* load_xfbin_button = new wxButton{panel, (int)ID::LOAD_XFBIN, "Load XFBIN", wxPoint{150, 50}, wxSize{100, 35}};
        CreateStatusBar();

        wxBoxSizer* box_sizer = new wxBoxSizer{wxHORIZONTAL};
        wxSizerFlags flag = wxSizerFlags{}.CenterVertical().Border(wxALL, 25);
        box_sizer->AddStretchSpacer();
        box_sizer->Add(load_xfbin_button, flag);
        box_sizer->AddStretchSpacer();

        panel->SetSizer(box_sizer);
        box_sizer->SetSizeHints(this);
    }
private:
    void OnButtonClicked(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();

    nucc::XFBIN xfbin;
};

class App : public wxApp {
public:
    bool OnInit() override {
        MainFrame* mainFrame = new MainFrame{"JoJo CyberConnectTools"};
        // mainFrame->SetClientSize(800, 600);
        mainFrame->Center();
        mainFrame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(App);

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_BUTTON((int)ID::LOAD_XFBIN, MainFrame::OnButtonClicked)
wxEND_EVENT_TABLE()