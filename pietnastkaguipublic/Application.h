#pragma once

#include "wx/wx.h"
#include "appMain.h"

class Application : public wxApp
{
public:
	Application();
	~Application();

public:
	virtual bool OnInit();
};

