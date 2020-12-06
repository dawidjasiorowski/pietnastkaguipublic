#include "Application.h"
wxIMPLEMENT_APP(Application);

Application::Application()
{
}

Application::~Application()
{
}

bool Application::OnInit()
{
	appMain *frame1 = new appMain();
	frame1->Show();
	return true;
}
