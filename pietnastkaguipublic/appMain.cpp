#include "appMain.h"

appMain::appMain() : wxFrame(nullptr, wxID_ANY, "Pietnastka")
{

	game.randomizeFields();

	buttons = new wxButton * [16];
	wxGridSizer* grid = new wxGridSizer(4, 4, 0, 0);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			buttons[i * 4 + j] = new wxButton(this, 100 + (i * 4 + j));
			grid->Add(buttons[i * 4 + j], 1, wxEXPAND | wxALL);
			if (game.fields[i][j] != 16) {
				buttons[i * 4 + j]->SetLabel(std::to_string(game.fields[i][j]));
			}
			else {
				buttons[i * 4 + j]->SetLabel("");
			}
			buttons[i * 4 + j]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &appMain::OnButtonClicked, this);
		}
	}
	this->SetSizer(grid);
}

appMain::~appMain()
{
}

void appMain::OnButtonClicked(wxCommandEvent& evt)
{
	wxWindow* btn = FindWindowById(evt.GetId());
	int s = wxAtoi(btn->GetLabel());
	if (game.isPossible(s)) {
		std::vector<int> blockCoords = game.checkCoordinates(s);
		std::vector<int> blankCoords = game.checkCoordinates(16);
		game.fields[blockCoords[0]][blockCoords[1]] = 16;
		game.fields[blankCoords[0]][blankCoords[1]] = s;
		buttons[blockCoords[0] * 4 + blockCoords[1]]->SetLabel(" ");
		buttons[blankCoords[0] * 4 + blankCoords[1]]->SetLabel(std::to_string(s));
		if (game.checkWin()) {
			wxMessageBox("Wygrales!", "Gratulacje!");
		}
	}
	evt.Skip();
}

void appMain::update()
{

}

