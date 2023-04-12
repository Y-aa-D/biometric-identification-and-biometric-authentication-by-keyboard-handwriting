#include "LoginForm.h"
#include <filesystem>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	KeystrokeDynamicIdentification::LoginForm form;
	Application::Run(% form);
}