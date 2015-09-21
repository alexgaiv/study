using namespace System;
using namespace System::Windows::Forms;

#include "MyForm.h"

[STAThread]
void Main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    bitfield::MyForm myForm;        //NameOfProject::NameOfForm instanceOfForm;
    Application::Run(%myForm);
}