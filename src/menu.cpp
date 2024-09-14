#include <nucc/xfbin.hpp>

#include "gui.hpp"

static bool isTextShown = false;

void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    if (!isTextShown) {
        wxLogStatus("Button clicked!");
        isTextShown = true;
    } else {
        wxLogStatus("");
        isTextShown = false;
    }
}