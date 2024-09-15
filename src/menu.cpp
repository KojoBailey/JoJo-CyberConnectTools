#include <nucc/xfbin.hpp>

#include "gui.hpp"

void MainFrame::OnButtonClicked(wxCommandEvent& event) {
    if ((ID)event.GetId() == ID::LOAD_XFBIN) {
        wxFileDialog openFileDialog{
            this, "Open XFBIN file", "", "", "XFBIN file (*.xfbin)|*.xfbin", wxFD_OPEN | wxFD_FILE_MUST_EXIST
        };
        if (openFileDialog.ShowModal() == wxID_CANCEL) return;
        std::filesystem::path xfbin_path = openFileDialog.GetPath().ToStdString();

        xfbin.load(xfbin_path);
        nucc::XFBIN::Status xfbin_status = xfbin.get_status();
        if (xfbin_status.code != nucc::XFBIN::Error_Code::OK) {
            wxMessageBox(
                std::format("Could not load file.\nError code {:03}:\n{}", xfbin_status.number, xfbin_status.message),
                "", wxICON_ERROR | wxOK, this
            );
            return;
        }

        wxMessageBox(
            std::format("File `{}` has been loaded with `{}`.", xfbin_path.string(), xfbin.fetch(nucc::Chunk_Type::Binary)->type_as_string()),
            "", wxICON_INFORMATION | wxOK, this
        );
    }
}