#pragma once

#include "wx/wx.h"
#include "wx/frame.h"
#include "Application.h"
#include "Game.h"

class appMain : public wxFrame
{
public:
	appMain();
	~appMain();
	void OnButtonClicked(wxCommandEvent &evt);
	Game game;
	void update();

public:
	wxButton** buttons;
};

